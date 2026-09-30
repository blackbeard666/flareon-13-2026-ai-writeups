// ==== thunk_FUN_140016b3a size=5

void thunk_FUN_140016b3a(longlong param_1,LPVOID param_2)

{
  ulonglong *puVar1;
  ulonglong uStack_10;
  longlong lStack_8;
  
  puVar1 = &uStack_10;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    uStack_10 = 1;
    puVar1 = (ulonglong *)&lStack_8;
  }
  *puVar1 = param_1;
  if (uStack_10 != 0) {
    FUN_1400013ae(param_2,uStack_10,lStack_8);
    return;
  }
  return;
}


// ==== FUN_140016b3a size=66

void FUN_140016b3a(longlong param_1,LPVOID param_2)

{
  ulonglong *puVar1;
  ulonglong local_10;
  longlong local_8;
  
  puVar1 = &local_10;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    local_10 = 1;
    puVar1 = (ulonglong *)&local_8;
  }
  *puVar1 = param_1;
  if (local_10 != 0) {
    FUN_1400013ae(param_2,local_10,local_8);
    return;
  }
  return;
}


// ==== FUN_14007f597 size=181

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00014009724d) overlaps instruction at (ram,0x00014009724c)
    */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

fd_set * FUN_14007f597(fd_set *param_1,undefined **param_2,fd_set *param_3,fd_set *param_4)

{
  undefined4 *puVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  LPVOID pvVar7;
  SOCKET SVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  SOCKET SVar11;
  SOCKET SVar12;
  undefined8 uVar13;
  u_int uVar14;
  u_int uVar15;
  fd_set *pfVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  undefined8 *puVar20;
  undefined8 *puVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  undefined8 *puVar25;
  undefined8 *puVar26;
  undefined8 *puVar27;
  undefined8 *puVar28;
  undefined8 *puVar29;
  undefined8 *puVar30;
  undefined8 *puVar31;
  undefined8 *puVar32;
  undefined1 *puVar33;
  undefined8 *puVar34;
  undefined8 *puVar35;
  undefined8 *puVar36;
  undefined8 *puVar37;
  undefined8 *puVar38;
  undefined8 *puVar39;
  undefined8 *puVar40;
  undefined8 *puVar41;
  undefined8 *puVar42;
  undefined8 *puVar43;
  undefined8 *puVar44;
  undefined8 *puVar45;
  undefined8 *puVar46;
  undefined8 *puVar47;
  undefined8 *puVar48;
  undefined8 *puVar49;
  undefined8 *puVar50;
  undefined1 *puVar51;
  undefined1 *puVar52;
  undefined1 *puVar53;
  undefined1 *puVar54;
  undefined1 *puVar55;
  undefined1 *puVar56;
  undefined1 *puVar57;
  undefined1 *puVar58;
  undefined1 *puVar59;
  undefined1 *puVar60;
  undefined1 *puVar61;
  fd_set *pfVar62;
  undefined1 uVar63;
  byte bVar64;
  ushort uVar65;
  int iVar66;
  DWORD DVar67;
  BOOL BVar68;
  uint uVar69;
  uint uVar70;
  ulonglong uVar71;
  code *UNRECOVERED_JUMPTABLE;
  undefined7 extraout_var;
  fd_set *pfVar72;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined **ppuVar73;
  void *pvVar74;
  HANDLE hObject;
  void *pvVar75;
  SOCKET SVar76;
  uint7 uVar86;
  undefined7 uVar87;
  fd_set *pfVar77;
  char *pcVar78;
  char *pcVar79;
  int *piVar80;
  ulonglong uVar81;
  SOCKET SVar82;
  char *pcVar83;
  fd_set *pfVar84;
  longlong lVar85;
  char cVar88;
  char cVar89;
  byte bVar90;
  undefined1 *puVar91;
  undefined8 *puVar92;
  fd_set *pfVar93;
  fd_set *pfVar94;
  ulonglong *puVar95;
  longlong lVar96;
  uint *_Dst;
  uint *puVar97;
  int iVar98;
  ulonglong uVar99;
  longlong *plVar100;
  fd_set *pfVar101;
  undefined *puVar102;
  char *pcVar103;
  uint *_Src;
  char cVar104;
  SOCKET unaff_RBX;
  longlong lVar105;
  undefined8 *puVar106;
  fd_set *pfVar107;
  undefined8 *puVar108;
  undefined8 *puVar109;
  undefined8 *puVar110;
  undefined1 *puVar111;
  undefined1 *puVar112;
  undefined8 *puVar113;
  undefined8 *puVar114;
  undefined8 *puVar115;
  undefined8 *puVar116;
  undefined1 *puVar117;
  undefined1 *puVar118;
  undefined1 *puVar119;
  undefined1 *puVar120;
  undefined1 *puVar121;
  undefined8 *puVar122;
  fd_set *pfVar123;
  undefined8 *puVar124;
  undefined8 *puVar125;
  undefined8 *puVar126;
  undefined8 *puVar127;
  undefined8 *puVar128;
  undefined8 *puVar129;
  undefined8 *puVar130;
  undefined8 *puVar131;
  undefined1 *puVar132;
  undefined1 *puVar133;
  undefined8 *puVar134;
  undefined8 *puVar135;
  undefined8 *puVar136;
  undefined8 *puVar137;
  undefined8 *puVar138;
  undefined8 *puVar139;
  undefined8 *puVar140;
  fd_set *pfVar141;
  undefined1 *puVar142;
  undefined8 *puVar143;
  undefined8 *puVar144;
  undefined8 *puVar145;
  undefined8 *puVar146;
  undefined8 *puVar147;
  fd_set **ppfVar148;
  undefined8 *puVar149;
  undefined8 *puVar150;
  undefined8 *puVar151;
  undefined8 *puVar152;
  undefined8 *puVar153;
  undefined8 *puVar154;
  undefined8 *puVar155;
  undefined8 *puVar156;
  undefined8 *puVar157;
  undefined8 *puVar158;
  fd_set *pfVar159;
  fd_set *pfVar160;
  undefined1 *puVar161;
  undefined8 *puVar162;
  SOCKET *pSVar163;
  undefined8 *puVar164;
  undefined8 *puVar165;
  undefined8 *puVar166;
  undefined8 *puVar167;
  fd_set *pfVar168;
  undefined1 *puVar169;
  undefined1 *puVar170;
  undefined8 *puVar171;
  undefined1 *puVar172;
  undefined1 *puVar173;
  undefined8 *puVar174;
  undefined1 *puVar175;
  undefined8 *puVar176;
  undefined8 *puVar177;
  undefined1 *puVar178;
  undefined1 *puVar179;
  undefined8 *puVar180;
  undefined8 *puVar181;
  undefined1 *puVar182;
  undefined8 *puVar183;
  undefined1 *puVar184;
  undefined8 *puVar185;
  undefined8 *puVar186;
  undefined1 *puVar187;
  undefined8 *puVar188;
  undefined8 *puVar189;
  undefined8 *puVar190;
  undefined8 *puVar191;
  undefined8 *puVar192;
  undefined8 *puVar193;
  undefined1 *puVar194;
  fd_set *pfVar195;
  SOCKET *pSVar196;
  undefined1 *puVar197;
  undefined8 *puVar198;
  undefined8 *puVar199;
  undefined1 *puVar200;
  undefined8 *puVar201;
  undefined1 *puVar202;
  undefined8 *puVar204;
  fd_set *pfVar205;
  undefined8 *puVar206;
  undefined8 *puVar207;
  undefined1 *puVar208;
  undefined8 *puVar209;
  undefined8 *puVar210;
  undefined8 *puVar211;
  undefined8 *puVar212;
  fd_set **ppfVar213;
  undefined8 *puVar214;
  undefined8 *puVar215;
  undefined8 *puVar216;
  undefined8 *puVar217;
  undefined8 *puVar218;
  undefined8 *puVar219;
  undefined8 *puVar220;
  undefined8 *puVar221;
  undefined8 *puVar222;
  SOCKET unaff_RBP;
  uint *puVar223;
  fd_set *pfVar224;
  uint *puVar225;
  uint uVar226;
  fd_set *unaff_RDI;
  fd_set *pfVar227;
  SOCKET *pSVar228;
  fd_set *pfVar229;
  longlong lVar230;
  undefined **ppuVar231;
  uint *writefds;
  size_t sVar232;
  fd_set *in_R10;
  fd_set *pfVar233;
  fd_set *pfVar234;
  fd_set *pfVar235;
  SOCKET SVar236;
  undefined2 in_ES;
  undefined2 in_FS;
  bool bVar237;
  byte bVar238;
  byte in_AF;
  bool bVar239;
  byte in_TF;
  byte in_IF;
  bool bVar240;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  float10 in_ST0;
  undefined8 uVar241;
  undefined8 extraout_XMM0_Qb;
  SOCKET extraout_XMM0_Qb_00;
  undefined1 auVar242 [16];
  SOCKET extraout_XMM0_Qb_01;
  SOCKET extraout_XMM0_Qb_02;
  undefined8 uVar243;
  undefined4 uVar244;
  undefined8 in_XMM1_Qa;
  undefined4 uVar245;
  undefined4 in_XMM1_Dc;
  undefined4 in_XMM1_Dd;
  uint in_stack_00000078;
  undefined1 auStackY_168 [72];
  undefined8 uStackY_120;
  undefined1 auStackY_118 [40];
  fd_set *pfStackY_f0;
  fd_set *apfStackY_e8 [6];
  fd_set *pfStackY_b8;
  undefined *puStackY_b0;
  fd_set *pfStackY_a8;
  fd_set *pfStackY_a0;
  undefined1 auStackY_98 [8];
  fd_set *pfStackY_90;
  undefined1 auStackY_88 [32];
  ulonglong in_stack_ffffffffffffff98;
  undefined1 local_60 [16];
  fd_set *local_50;
  fd_set *local_48;
  undefined8 *puVar203;
  
  uVar245 = (undefined4)((ulonglong)in_XMM1_Qa >> 0x20);
  uVar244 = (undefined4)in_XMM1_Qa;
  puVar118 = auStackY_88;
  puVar119 = auStackY_88;
  puVar120 = auStackY_88;
  puVar121 = auStackY_88;
  puVar122 = (undefined8 *)auStackY_88;
  pfVar234 = (fd_set *)auStackY_88;
  puVar132 = auStackY_88;
  ppfVar148 = (fd_set **)auStackY_88;
  puVar169 = auStackY_88;
  puVar175 = auStackY_88;
  puVar112 = auStackY_88;
  puVar91 = auStackY_88;
  puVar133 = auStackY_88;
  puVar167 = (undefined8 *)auStackY_88;
  puVar173 = auStackY_88;
  puVar92 = (undefined8 *)auStackY_88;
  puVar178 = auStackY_88;
  puVar151 = (undefined8 *)auStackY_88;
  pfVar84 = (fd_set *)&local_48;
  pfVar233 = (fd_set *)local_60;
  puVar223 = (uint *)&DAT_14010fce0;
  pcVar83 = (char *)param_4;
LAB_14007f5c4:
  if ((fd_set *)pcVar83 == (fd_set *)0x0) {
    pfVar227 = (fd_set *)0x0;
LAB_14007f63d:
    return pfVar227;
  }
  pfStackY_90 = (fd_set *)0x14007f5d5;
  pfVar227 = param_3;
  writefds = (uint *)pcVar83;
  local_50 = (fd_set *)(*(code *)((fd_set *)param_2)->fd_array[10])(param_1);
  local_48 = pfVar227;
  if (((ulonglong)local_50 & 1) == 0) goto LAB_14007f60a;
  pfStackY_90 = (fd_set *)0x14007f5f1;
  _Dst = (uint *)pfVar233;
  _Src = &pfVar227->fd_count;
  uVar241 = FUN_1400762c3((undefined1 *)pfVar233,(longlong)pfVar227);
  uVar81 = local_60._0_8_ & 0xff;
  uVar71 = (ulonglong)*(int *)(&DAT_14010fce0 + uVar81 * 4);
  bVar237 = 0xfffffffebfef031f < uVar71;
  bVar240 = SCARRY8(uVar71,0x14010fce0);
  UNRECOVERED_JUMPTABLE = (code *)(&DAT_14010fce0 + uVar71);
  bVar239 = (fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0;
  bVar238 = (byte)UNRECOVERED_JUMPTABLE;
  uVar69 = (uint)UNRECOVERED_JUMPTABLE;
  uVar87 = (undefined7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8);
  uVar70 = (uint)param_2;
  pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
  puVar97 = _Dst;
  pfVar72 = (fd_set *)_Dst;
  pcVar103 = (char *)_Src;
  pfVar101 = (fd_set *)_Src;
  pfVar77 = (fd_set *)param_2;
  puVar111 = auStackY_88;
  puVar161 = auStackY_88;
  puVar156 = (undefined8 *)auStackY_88;
  pSVar163 = (SOCKET *)auStackY_88;
  pfVar107 = (fd_set *)auStackY_88;
  pfVar205 = (fd_set *)auStackY_88;
  pfVar195 = (fd_set *)auStackY_88;
  pfVar16 = (fd_set *)auStackY_88;
  pfVar159 = (fd_set *)auStackY_88;
  puVar33 = auStackY_88;
  puVar197 = auStackY_88;
  puVar194 = auStackY_88;
  puVar190 = (undefined8 *)auStackY_88;
  puVar192 = (undefined8 *)auStackY_88;
  puVar181 = (undefined8 *)auStackY_88;
  puVar210 = (undefined8 *)auStackY_88;
  puVar211 = (undefined8 *)auStackY_88;
  puVar51 = auStackY_88;
  puVar52 = auStackY_88;
  puVar117 = auStackY_88;
  puVar53 = auStackY_88;
  puVar54 = auStackY_88;
  puVar184 = auStackY_88;
  puVar187 = auStackY_88;
  puVar55 = auStackY_88;
  puVar172 = auStackY_88;
  puVar56 = auStackY_88;
  puVar142 = auStackY_88;
  puVar179 = auStackY_88;
  puVar57 = auStackY_88;
  puVar182 = auStackY_88;
  puVar58 = auStackY_88;
  puVar59 = auStackY_88;
  puVar208 = auStackY_88;
  puVar60 = auStackY_88;
  puVar61 = auStackY_88;
  pfVar224 = (fd_set *)puVar223;
  puVar225 = (uint *)pcVar83;
  pfVar93 = (fd_set *)pcVar83;
  pfVar94 = param_3;
  uVar243 = extraout_XMM0_Qb;
  switch(uVar81) {
  case 0:
    goto LAB_14007f63d;
  case 1:
code_r0x00014007f61f:
    cVar89 = local_60[1];
    goto code_r0x00014007f623;
  case 2:
  case 3:
code_r0x00014007f600:
    cVar89 = (char)((SOCKET *)(local_60._8_8_ + 8))[1];
code_r0x00014007f623:
    if (cVar89 != '#') {
      return pfVar227;
    }
    pfStackY_90 = (fd_set *)&UNK_14007f62f;
    FUN_1400759ea((ulonglong *)pfVar84);
    goto LAB_14007f5c4;
  case 4:
code_r0x00014007f733:
    pbVar2 = (byte *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x189);
    *pbVar2 = *pbVar2 >> 5 | *pbVar2 << 3;
    return (fd_set *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff58);
  case 5:
code_r0x00014007f6e1:
    LOCK();
    uVar3 = *(undefined4 *)(&UNK_14010fce1 + uVar71);
    *(int *)(&UNK_14010fce1 + uVar71) = (int)_Dst;
    _Dst = (uint *)CONCAT44((int)((ulonglong)_Dst >> 0x20),uVar3);
    UNLOCK();
    bVar237 = false;
    puVar97 = _Dst;
    pfVar72 = (fd_set *)_Dst;
    pcVar103 = (char *)_Src;
    pfVar101 = (fd_set *)_Src;
    puVar111 = auStackY_88;
    puVar161 = auStackY_88;
    puVar156 = (undefined8 *)auStackY_88;
    pSVar163 = (SOCKET *)auStackY_88;
    pfVar107 = (fd_set *)auStackY_88;
    pfVar205 = (fd_set *)auStackY_88;
    pfVar195 = (fd_set *)auStackY_88;
    pfVar16 = (fd_set *)auStackY_88;
    pfVar159 = (fd_set *)auStackY_88;
    puVar33 = auStackY_88;
    puVar197 = auStackY_88;
    puVar194 = auStackY_88;
    puVar190 = (undefined8 *)auStackY_88;
    puVar192 = (undefined8 *)auStackY_88;
    puVar181 = (undefined8 *)auStackY_88;
    puVar210 = (undefined8 *)auStackY_88;
    puVar211 = (undefined8 *)auStackY_88;
    puVar51 = auStackY_88;
    puVar52 = auStackY_88;
    puVar117 = auStackY_88;
    puVar53 = auStackY_88;
    puVar54 = auStackY_88;
    puVar184 = auStackY_88;
    puVar187 = auStackY_88;
    puVar55 = auStackY_88;
    puVar172 = auStackY_88;
    puVar56 = auStackY_88;
    puVar142 = auStackY_88;
    puVar179 = auStackY_88;
    puVar57 = auStackY_88;
    puVar182 = auStackY_88;
    puVar58 = auStackY_88;
    puVar59 = auStackY_88;
    puVar208 = auStackY_88;
    puVar60 = auStackY_88;
    puVar61 = auStackY_88;
    switch(uVar81) {
    case 0:
      goto LAB_14007f63d;
    case 1:
      goto code_r0x00014007f61f;
    case 2:
    case 3:
      goto code_r0x00014007f600;
    case 4:
      goto code_r0x00014007f733;
    case 5:
      goto code_r0x00014007f6e1;
    case 6:
    case 7:
      goto code_r0x00014007f6d7;
    case 8:
      goto code_r0x00014007f7fc;
    case 9:
      goto code_r0x00014007f7e2;
    case 10:
    case 0xb:
      goto code_r0x00014007f7c6;
    case 0xc:
      goto code_r0x00014007f96d;
    case 0xd:
      goto code_r0x00014007f953;
    case 0xe:
    case 0xf:
      goto code_r0x00014007f937;
    case 0x10:
      goto code_r0x00014007fda3;
    case 0x11:
      goto code_r0x00014007fe0e;
    case 0x12:
      goto switchD_14007f6e5_caseD_15;
    case 0x13:
      goto code_r0x00014007fdf5;
    case 0x14:
      goto switchD_14007f6e5_caseD_17;
    case 0x15:
      goto switchD_14007f6e5_caseD_d;
    case 0x16:
      goto switchD_14007f6e5_caseD_11;
    case 0x17:
      goto switchD_14007f6e5_caseD_f;
    case 0x18:
switchD_14007f6e5_caseD_16:
      _Src = (uint *)((longlong)&DAT_14010958e + 7);
      writefds = (uint *)0xe;
      puVar97 = _Dst;
      pfVar72 = (fd_set *)_Dst;
      pcVar103 = (char *)_Src;
      pfVar101 = (fd_set *)_Src;
      puVar111 = auStackY_88;
      puVar161 = auStackY_88;
      puVar156 = (undefined8 *)auStackY_88;
      pSVar163 = (SOCKET *)auStackY_88;
      pfVar107 = (fd_set *)auStackY_88;
      pfVar205 = (fd_set *)auStackY_88;
      pfVar195 = (fd_set *)auStackY_88;
      pfVar16 = (fd_set *)auStackY_88;
      pfVar159 = (fd_set *)auStackY_88;
      puVar33 = auStackY_88;
      puVar197 = auStackY_88;
      puVar194 = auStackY_88;
      puVar190 = (undefined8 *)auStackY_88;
      puVar192 = (undefined8 *)auStackY_88;
      puVar181 = (undefined8 *)auStackY_88;
      puVar210 = (undefined8 *)auStackY_88;
      puVar211 = (undefined8 *)auStackY_88;
      puVar51 = auStackY_88;
      puVar52 = auStackY_88;
      puVar117 = auStackY_88;
      puVar53 = auStackY_88;
      puVar54 = auStackY_88;
      puVar184 = auStackY_88;
      puVar187 = auStackY_88;
      puVar55 = auStackY_88;
      puVar172 = auStackY_88;
      puVar56 = auStackY_88;
      puVar142 = auStackY_88;
      puVar179 = auStackY_88;
      puVar57 = auStackY_88;
      puVar182 = auStackY_88;
      puVar58 = auStackY_88;
      puVar59 = auStackY_88;
      puVar208 = auStackY_88;
      puVar60 = auStackY_88;
      puVar61 = auStackY_88;
      switch(uVar81) {
      case 0:
        goto LAB_14007f63d;
      case 1:
        goto code_r0x00014007f61f;
      case 2:
      case 3:
        goto code_r0x00014007f600;
      case 4:
        goto code_r0x00014007f733;
      case 5:
        goto code_r0x00014007f6e1;
      case 6:
      case 7:
        goto code_r0x00014007f6d7;
      case 8:
        goto code_r0x00014007f7fc;
      case 9:
        goto code_r0x00014007f7e2;
      case 10:
      case 0xb:
        goto code_r0x00014007f7c6;
      case 0xc:
        goto code_r0x00014007f96d;
      case 0xd:
        goto code_r0x00014007f953;
      case 0xe:
      case 0xf:
        goto code_r0x00014007f937;
      case 0x10:
        goto code_r0x00014007fda3;
      case 0x11:
        goto code_r0x00014007fe0e;
      case 0x12:
        goto switchD_14007f6e5_caseD_15;
      case 0x13:
        goto code_r0x00014007fdf5;
      case 0x14:
        goto switchD_14007f6e5_caseD_17;
      case 0x15:
        goto switchD_14007f6e5_caseD_d;
      case 0x16:
        goto switchD_14007f6e5_caseD_11;
      case 0x17:
        goto switchD_14007f6e5_caseD_f;
      case 0x18:
        goto switchD_14007f6e5_caseD_16;
      case 0x19:
        goto switchD_14007f6e5_caseD_18;
      case 0x1a:
switchD_14007f6e5_caseD_12:
        *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
        pbVar2 = &UNK_14010fcdf + uVar71;
        bVar90 = (byte)_Dst;
        bVar237 = CARRY1(*pbVar2,bVar90);
        bVar240 = SCARRY1(*pbVar2,bVar90);
        *pbVar2 = *pbVar2 + bVar90;
        bVar239 = *pbVar2 == 0;
        _Dst = (uint *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1ff);
        if ((fd_set *)_Dst == (fd_set *)0x0 || bVar239) goto LAB_14007fe75;
        _Src = (uint *)&DAT_140109612;
        writefds = (uint *)&DAT_0000000d;
        puVar97 = _Dst;
        pfVar72 = (fd_set *)_Dst;
        pcVar103 = (char *)_Src;
        pfVar101 = (fd_set *)_Src;
        puVar111 = auStackY_88;
        puVar161 = auStackY_88;
        puVar156 = (undefined8 *)auStackY_88;
        pSVar163 = (SOCKET *)auStackY_88;
        pfVar107 = (fd_set *)auStackY_88;
        pfVar205 = (fd_set *)auStackY_88;
        pfVar195 = (fd_set *)auStackY_88;
        pfVar16 = (fd_set *)auStackY_88;
        pfVar159 = (fd_set *)auStackY_88;
        puVar33 = auStackY_88;
        puVar197 = auStackY_88;
        puVar194 = auStackY_88;
        puVar190 = (undefined8 *)auStackY_88;
        puVar192 = (undefined8 *)auStackY_88;
        puVar181 = (undefined8 *)auStackY_88;
        puVar210 = (undefined8 *)auStackY_88;
        puVar211 = (undefined8 *)auStackY_88;
        puVar51 = auStackY_88;
        puVar52 = auStackY_88;
        puVar117 = auStackY_88;
        puVar53 = auStackY_88;
        puVar54 = auStackY_88;
        puVar184 = auStackY_88;
        puVar187 = auStackY_88;
        puVar55 = auStackY_88;
        puVar172 = auStackY_88;
        puVar56 = auStackY_88;
        puVar142 = auStackY_88;
        puVar179 = auStackY_88;
        puVar57 = auStackY_88;
        puVar182 = auStackY_88;
        puVar58 = auStackY_88;
        puVar59 = auStackY_88;
        puVar208 = auStackY_88;
        puVar60 = auStackY_88;
        puVar61 = auStackY_88;
        switch(uVar81) {
        case 0:
          goto LAB_14007f63d;
        case 1:
          goto code_r0x00014007f61f;
        case 2:
        case 3:
          goto code_r0x00014007f600;
        case 4:
          goto code_r0x00014007f733;
        case 5:
          goto code_r0x00014007f6e1;
        case 6:
        case 7:
          goto code_r0x00014007f6d7;
        case 8:
          goto code_r0x00014007f7fc;
        case 9:
          goto code_r0x00014007f7e2;
        case 10:
        case 0xb:
          goto code_r0x00014007f7c6;
        case 0xc:
          goto code_r0x00014007f96d;
        case 0xd:
          goto code_r0x00014007f953;
        case 0xe:
        case 0xf:
          goto code_r0x00014007f937;
        case 0x10:
          goto code_r0x00014007fda3;
        case 0x11:
          goto code_r0x00014007fe0e;
        case 0x12:
          goto switchD_14007f6e5_caseD_15;
        case 0x13:
          goto code_r0x00014007fdf5;
        case 0x14:
          goto switchD_14007f6e5_caseD_17;
        case 0x15:
          goto switchD_14007f6e5_caseD_d;
        case 0x16:
          goto switchD_14007f6e5_caseD_11;
        case 0x17:
          goto switchD_14007f6e5_caseD_f;
        case 0x18:
          goto switchD_14007f6e5_caseD_16;
        case 0x19:
          goto switchD_14007f6e5_caseD_18;
        case 0x1a:
          goto switchD_14007f6e5_caseD_12;
        case 0x1b:
          goto switchD_14007f6e5_caseD_c;
        case 0x1c:
          goto code_r0x00014007fdcc;
        case 0x1d:
          goto LAB_140085c9c;
        case 0x1e:
          goto code_r0x000140085d0b;
        case 0x1f:
          goto code_r0x000140085cb1;
        case 0x20:
          goto code_r0x000140085cc2;
        case 0x21:
          goto code_r0x000140086a2d;
        case 0x22:
          goto code_r0x000140086980;
        case 0x23:
        case 0x24:
          goto code_r0x000140086973;
        case 0x25:
          goto code_r0x000140089986;
        case 0x26:
          goto code_r0x0001400898fa;
        case 0x27:
        case 0x28:
          goto code_r0x0001400898f0;
        case 0x29:
          goto code_r0x00014008a981;
        case 0x2a:
          goto switchD_14007f7e4_caseD_23;
        case 0x2b:
          goto code_r0x00014008a9a5;
        case 0x2c:
          goto code_r0x00014008a9b3;
        case 0x2d:
          goto code_r0x00014009308a;
        case 0x2e:
          goto code_r0x0001400930a7;
        case 0x2f:
          goto code_r0x00014009308f;
        case 0x30:
          break;
        case 0x31:
          goto code_r0x0001400931ea;
        case 0x32:
          goto switchD_14007f6e5_caseD_34;
        case 0x33:
          goto switchD_14007f6e5_caseD_36;
        case 0x34:
          goto switchD_14007f6e5_caseD_2f;
        case 0x35:
          goto switchD_14007f6e5_caseD_2d;
        case 0x36:
          goto switchD_14007f6e5_caseD_2e;
        case 0x37:
          goto switchD_14007f6e5_caseD_32;
        case 0x38:
          goto switchD_14007f6e5_caseD_30;
        case 0x39:
          goto switchD_14007f6e5_caseD_33;
        case 0x3a:
          goto code_r0x000140093203;
        default:
          goto code_r0x000140093458;
        case 0x3f:
          goto code_r0x000140093499;
        case 0x57:
          goto code_r0x000140093486;
        case 0x66:
        case 0x68:
          goto code_r0x000140093460;
        case 0x6a:
          goto LAB_1400933fd;
        case 0x6c:
          goto code_r0x0001400935b8;
        case 0x6d:
          goto code_r0x0001400938fd;
        case 0x6e:
          goto code_r0x000140093832;
        case 0x6f:
          goto code_r0x000140093889;
        case 0x70:
          goto code_r0x000140093ac9;
        case 0x71:
          goto code_r0x0001400937bd;
        case 0x72:
          goto code_r0x000140093a94;
        case 0x73:
          goto code_r0x000140093a9a;
        case 0x74:
          goto code_r0x000140093a86;
        case 0x75:
          goto code_r0x000140093aa8;
        case 0x76:
          goto code_r0x000140093aae;
        case 0x77:
          goto code_r0x000140093aa0;
        case 0x78:
          goto switchD_14007f6e5_caseD_72;
        case 0x79:
          goto code_r0x000140093a8c;
        case 0x7a:
          goto code_r0x000140093ab6;
        case 0x7b:
          goto code_r0x000140093a7e;
        case 0x7c:
          goto code_r0x000140093bca;
        case 0x7d:
          goto code_r0x000140093c9e;
        case 0x7e:
          goto code_r0x000140093be3;
        case 0x7f:
          goto code_r0x000140093c3a;
        case 0x80:
          goto code_r0x000140093eee;
        case 0x81:
          goto code_r0x000140093fd8;
        case 0x82:
          goto code_r0x000140093f1d;
        case 0x83:
          goto code_r0x000140093f74;
        case 0x84:
          goto code_r0x0001400942b2;
        case 0x85:
          goto code_r0x0001400943a4;
        case 0x86:
          goto code_r0x00014009431b;
        case 0x87:
          goto code_r0x000140094351;
        case 0x88:
          goto code_r0x0001400942ed;
        case 0x89:
          goto code_r0x00014009470c;
        case 0x8a:
          goto code_r0x000140094809;
        case 0x8b:
          goto code_r0x00014009474e;
        case 0x8c:
          goto code_r0x0001400947a5;
        case 0x8d:
        case 0x94:
          goto switchD_14007f7e4_caseD_8d;
        case 0x8e:
          goto code_r0x0001400946d4;
        case 0x8f:
        case 0x90:
        case 0x91:
          goto switchD_14007f7e4_caseD_8e;
        case 0x92:
          goto code_r0x00014009485c;
        case 0x93:
          goto switchD_14007f6e5_caseD_95;
        case 0x95:
        case 0x98:
        case 0x9a:
          goto switchD_14007fde0_caseD_7e;
        case 0x96:
        case 0x97:
          goto code_r0x000140094844;
        case 0x99:
          goto code_r0x000140094850;
        case 0x9b:
          goto code_r0x0001400951d1;
        case 0x9c:
          goto code_r0x000140095492;
        case 0x9d:
          goto code_r0x0001400953a5;
        case 0x9e:
          goto code_r0x00014009540f;
        case 0x9f:
          goto code_r0x000140095809;
        case 0xa0:
          goto code_r0x000140095bb4;
        case 0xa1:
          goto code_r0x000140095acf;
        case 0xa2:
          goto code_r0x000140095b34;
        case 0xa3:
          goto code_r0x000140095362;
        case 0xa4:
          goto code_r0x000140095753;
        case 0xa5:
          goto code_r0x000140095681;
        case 0xa6:
          goto code_r0x0001400956df;
        case 0xa7:
          goto code_r0x000140095c0e;
        case 0xa8:
          goto code_r0x000140095d57;
        case 0xa9:
          goto code_r0x000140095c7f;
        case 0xaa:
          goto code_r0x000140095ce1;
        case 0xab:
          goto switchD_140096440_default;
        case 0xac:
          goto code_r0x000140096748;
        case 0xad:
          goto code_r0x000140096661;
        case 0xae:
          goto code_r0x0001400966c8;
        case 0xaf:
          goto code_r0x000140096186;
        case 0xb0:
          goto code_r0x000140096318;
        case 0xb1:
          goto code_r0x000140096238;
        case 0xb2:
          goto code_r0x00014009629c;
        case 0xb3:
          goto code_r0x0001400967f6;
        case 0xb4:
          goto code_r0x0001400969bf;
        case 0xb5:
          goto code_r0x000140096973;
        case 0xb6:
          goto code_r0x000140096991;
        case 0xb7:
          goto code_r0x000140096907;
        case 0xb8:
          goto code_r0x000140096a0a;
        case 0xb9:
          goto code_r0x000140096a3f;
        case 0xba:
          goto code_r0x0001400969a8;
        case 0xbb:
          goto code_r0x000140096a6c;
        case 0xbc:
          goto code_r0x000140096946;
        case 0xbd:
          goto code_r0x000140096a5d;
        case 0xbe:
          goto code_r0x0001400968d9;
        case 0xbf:
          goto code_r0x000140096937;
        case 0xc0:
          goto code_r0x000140096a30;
        case 0xc1:
          goto code_r0x0001400968ac;
        case 0xc2:
          goto code_r0x000140096982;
        case 0xc3:
          goto code_r0x00014009688e;
        case 0xc4:
          goto code_r0x0001400969dd;
        case 0xc5:
          goto code_r0x000140096a4e;
        case 0xc6:
          goto code_r0x000140096adc;
        case 199:
          goto code_r0x0001400969fb;
        case 200:
          goto code_r0x000140096a21;
        case 0xc9:
          goto switchD_14009313c_caseD_8b;
        case 0xca:
          goto code_r0x000140096afa;
        case 0xcb:
          goto code_r0x000140096964;
        case 0xcc:
          goto code_r0x000140096955;
        case 0xcd:
          goto code_r0x000140096bc2;
        case 0xce:
          goto code_r0x000140096870;
        case 0xcf:
          goto code_r0x000140096b09;
        case 0xd0:
          goto code_r0x000140096baa;
        case 0xd1:
          goto code_r0x000140096a7b;
        case 0xd2:
          goto code_r0x0001400969ce;
        case 0xd3:
          goto code_r0x000140096a90;
        case 0xd4:
          goto code_r0x0001400968bb;
        case 0xd5:
          goto code_r0x00014009687f;
        case 0xd6:
          goto code_r0x000140096852;
        case 0xd7:
          goto code_r0x000140096861;
        case 0xd8:
          goto code_r0x000140096824;
        case 0xd9:
          goto code_r0x000140096bb6;
        case 0xda:
          goto code_r0x000140096acd;
        case 0xdb:
          goto switchD_14007fde0_caseD_d4;
        case 0xdc:
          goto code_r0x0001400969ec;
        case 0xdd:
          goto code_r0x000140096aeb;
        case 0xde:
          goto code_r0x000140096805;
        case 0xdf:
          goto code_r0x00014009689d;
        case 0xe0:
          goto code_r0x000140096a9f;
        case 0xe1:
          goto code_r0x000140096bce;
        case 0xe2:
          goto code_r0x000140096833;
        case 0xe3:
          goto code_r0x0001400968ca;
        case 0xe4:
          goto code_r0x0001400968e8;
        case 0xe5:
          goto code_r0x000140096f79;
        case 0xe6:
          goto code_r0x00014009705b;
        case 0xe7:
          goto code_r0x000140096fa0;
        case 0xe8:
          goto code_r0x000140096ff7;
        case 0xe9:
          goto code_r0x000140097135;
        case 0xea:
          goto code_r0x00014009748a;
        case 0xeb:
          goto code_r0x000140097384;
        case 0xec:
          goto code_r0x0001400973b8;
        case 0xed:
          goto code_r0x0001400972d9;
        case 0xee:
          goto switchD_1400944c0_caseD_8d;
        case 0xef:
          goto code_r0x0001400975bd;
        case 0xf0:
          goto code_r0x000140097421;
        case 0xf1:
          goto code_r0x00014009760e;
        case 0xf2:
          goto code_r0x000140097339;
        case 0xf3:
          goto code_r0x0001400975f1;
        case 0xf4:
          goto code_r0x000140097298;
        case 0xf5:
          goto code_r0x00014009731c;
        case 0xf6:
          goto code_r0x0001400975a0;
        case 0xf7:
          goto code_r0x00014009724d;
        case 0xf8:
          goto code_r0x00014009739b;
        case 0xf9:
          goto code_r0x00014009721f;
        case 0xfa:
          goto code_r0x0001400974c4;
        case 0xfb:
          goto code_r0x0001400975da;
        case 0xfc:
          goto code_r0x0001400976cd;
        case 0xfd:
          goto code_r0x0001400974f8;
        case 0xfe:
          goto code_r0x000140097583;
        case 0xff:
          goto code_r0x00014009769c;
        }
      case 0x1b:
        goto switchD_14007f6e5_caseD_c;
      case 0x1c:
        goto code_r0x00014007fdcc;
      case 0x1d:
        goto LAB_140085c9c;
      case 0x1e:
        goto code_r0x000140085d0b;
      case 0x1f:
        goto code_r0x000140085cb1;
      case 0x20:
        goto code_r0x000140085cc2;
      case 0x21:
        goto code_r0x000140086a2d;
      case 0x22:
        goto code_r0x000140086980;
      case 0x23:
      case 0x24:
        goto code_r0x000140086973;
      case 0x25:
        goto code_r0x000140089986;
      case 0x26:
        goto code_r0x0001400898fa;
      case 0x27:
      case 0x28:
        goto code_r0x0001400898f0;
      case 0x29:
        goto code_r0x00014008a981;
      case 0x2a:
        goto switchD_14007f7e4_caseD_23;
      case 0x2b:
        goto code_r0x00014008a9a5;
      case 0x2c:
        goto code_r0x00014008a9b3;
      case 0x2d:
        goto code_r0x00014009308a;
      case 0x2e:
        goto code_r0x0001400930a7;
      case 0x2f:
        goto code_r0x00014009308f;
      case 0x30:
        break;
      case 0x31:
        goto code_r0x0001400931ea;
      case 0x32:
        goto switchD_14007f6e5_caseD_34;
      case 0x33:
        goto switchD_14007f6e5_caseD_36;
      case 0x34:
        goto switchD_14007f6e5_caseD_2f;
      case 0x35:
        goto switchD_14007f6e5_caseD_2d;
      case 0x36:
        goto switchD_14007f6e5_caseD_2e;
      case 0x37:
        goto switchD_14007f6e5_caseD_32;
      case 0x38:
        goto switchD_14007f6e5_caseD_30;
      case 0x39:
        goto switchD_14007f6e5_caseD_33;
      case 0x3a:
        goto code_r0x000140093203;
      default:
        goto code_r0x000140093458;
      case 0x3f:
        goto code_r0x000140093499;
      case 0x57:
        goto code_r0x000140093486;
      case 0x66:
      case 0x68:
        goto code_r0x000140093460;
      case 0x6a:
        goto LAB_1400933fd;
      case 0x6c:
        goto code_r0x0001400935b8;
      case 0x6d:
        goto code_r0x0001400938fd;
      case 0x6e:
        goto code_r0x000140093832;
      case 0x6f:
        goto code_r0x000140093889;
      case 0x70:
        goto code_r0x000140093ac9;
      case 0x71:
        goto code_r0x0001400937bd;
      case 0x72:
        goto code_r0x000140093a94;
      case 0x73:
        goto code_r0x000140093a9a;
      case 0x74:
        goto code_r0x000140093a86;
      case 0x75:
        goto code_r0x000140093aa8;
      case 0x76:
        goto code_r0x000140093aae;
      case 0x77:
        goto code_r0x000140093aa0;
      case 0x78:
        goto switchD_14007f6e5_caseD_72;
      case 0x79:
        goto code_r0x000140093a8c;
      case 0x7a:
        goto code_r0x000140093ab6;
      case 0x7b:
        goto code_r0x000140093a7e;
      case 0x7c:
        goto code_r0x000140093bca;
      case 0x7d:
        goto code_r0x000140093c9e;
      case 0x7e:
        goto code_r0x000140093be3;
      case 0x7f:
        goto code_r0x000140093c3a;
      case 0x80:
        goto code_r0x000140093eee;
      case 0x81:
        goto code_r0x000140093fd8;
      case 0x82:
        goto code_r0x000140093f1d;
      case 0x83:
        goto code_r0x000140093f74;
      case 0x84:
        goto code_r0x0001400942b2;
      case 0x85:
        goto code_r0x0001400943a4;
      case 0x86:
        goto code_r0x00014009431b;
      case 0x87:
        goto code_r0x000140094351;
      case 0x88:
        goto code_r0x0001400942ed;
      case 0x89:
        goto code_r0x00014009470c;
      case 0x8a:
        goto code_r0x000140094809;
      case 0x8b:
        goto code_r0x00014009474e;
      case 0x8c:
        goto code_r0x0001400947a5;
      case 0x8d:
      case 0x94:
        goto switchD_14007f7e4_caseD_8d;
      case 0x8e:
        goto code_r0x0001400946d4;
      case 0x8f:
      case 0x90:
      case 0x91:
        goto switchD_14007f7e4_caseD_8e;
      case 0x92:
        goto code_r0x00014009485c;
      case 0x93:
        goto switchD_14007f6e5_caseD_95;
      case 0x95:
      case 0x98:
      case 0x9a:
        goto switchD_14007fde0_caseD_7e;
      case 0x96:
      case 0x97:
        goto code_r0x000140094844;
      case 0x99:
        goto code_r0x000140094850;
      case 0x9b:
        goto code_r0x0001400951d1;
      case 0x9c:
        goto code_r0x000140095492;
      case 0x9d:
        goto code_r0x0001400953a5;
      case 0x9e:
        goto code_r0x00014009540f;
      case 0x9f:
        goto code_r0x000140095809;
      case 0xa0:
        goto code_r0x000140095bb4;
      case 0xa1:
        goto code_r0x000140095acf;
      case 0xa2:
        goto code_r0x000140095b34;
      case 0xa3:
        goto code_r0x000140095362;
      case 0xa4:
        goto code_r0x000140095753;
      case 0xa5:
        goto code_r0x000140095681;
      case 0xa6:
        goto code_r0x0001400956df;
      case 0xa7:
        goto code_r0x000140095c0e;
      case 0xa8:
        goto code_r0x000140095d57;
      case 0xa9:
        goto code_r0x000140095c7f;
      case 0xaa:
        goto code_r0x000140095ce1;
      case 0xab:
        goto switchD_140096440_default;
      case 0xac:
        goto code_r0x000140096748;
      case 0xad:
        goto code_r0x000140096661;
      case 0xae:
        goto code_r0x0001400966c8;
      case 0xaf:
        goto code_r0x000140096186;
      case 0xb0:
        goto code_r0x000140096318;
      case 0xb1:
        goto code_r0x000140096238;
      case 0xb2:
        goto code_r0x00014009629c;
      case 0xb3:
        goto code_r0x0001400967f6;
      case 0xb4:
        goto code_r0x0001400969bf;
      case 0xb5:
        goto code_r0x000140096973;
      case 0xb6:
        goto code_r0x000140096991;
      case 0xb7:
        goto code_r0x000140096907;
      case 0xb8:
        goto code_r0x000140096a0a;
      case 0xb9:
        goto code_r0x000140096a3f;
      case 0xba:
        goto code_r0x0001400969a8;
      case 0xbb:
        goto code_r0x000140096a6c;
      case 0xbc:
        goto code_r0x000140096946;
      case 0xbd:
        goto code_r0x000140096a5d;
      case 0xbe:
        goto code_r0x0001400968d9;
      case 0xbf:
        goto code_r0x000140096937;
      case 0xc0:
        goto code_r0x000140096a30;
      case 0xc1:
        goto code_r0x0001400968ac;
      case 0xc2:
        goto code_r0x000140096982;
      case 0xc3:
        goto code_r0x00014009688e;
      case 0xc4:
        goto code_r0x0001400969dd;
      case 0xc5:
        goto code_r0x000140096a4e;
      case 0xc6:
        goto code_r0x000140096adc;
      case 199:
        goto code_r0x0001400969fb;
      case 200:
        goto code_r0x000140096a21;
      case 0xc9:
        goto switchD_14009313c_caseD_8b;
      case 0xca:
        goto code_r0x000140096afa;
      case 0xcb:
        goto code_r0x000140096964;
      case 0xcc:
        goto code_r0x000140096955;
      case 0xcd:
        goto code_r0x000140096bc2;
      case 0xce:
        goto code_r0x000140096870;
      case 0xcf:
        goto code_r0x000140096b09;
      case 0xd0:
        goto code_r0x000140096baa;
      case 0xd1:
        goto code_r0x000140096a7b;
      case 0xd2:
        goto code_r0x0001400969ce;
      case 0xd3:
        goto code_r0x000140096a90;
      case 0xd4:
        goto code_r0x0001400968bb;
      case 0xd5:
        goto code_r0x00014009687f;
      case 0xd6:
        goto code_r0x000140096852;
      case 0xd7:
        goto code_r0x000140096861;
      case 0xd8:
        goto code_r0x000140096824;
      case 0xd9:
        goto code_r0x000140096bb6;
      case 0xda:
        goto code_r0x000140096acd;
      case 0xdb:
        goto switchD_14007fde0_caseD_d4;
      case 0xdc:
        goto code_r0x0001400969ec;
      case 0xdd:
        goto code_r0x000140096aeb;
      case 0xde:
        goto code_r0x000140096805;
      case 0xdf:
        goto code_r0x00014009689d;
      case 0xe0:
        goto code_r0x000140096a9f;
      case 0xe1:
        goto code_r0x000140096bce;
      case 0xe2:
        goto code_r0x000140096833;
      case 0xe3:
        goto code_r0x0001400968ca;
      case 0xe4:
        goto code_r0x0001400968e8;
      case 0xe5:
        goto code_r0x000140096f79;
      case 0xe6:
        goto code_r0x00014009705b;
      case 0xe7:
        goto code_r0x000140096fa0;
      case 0xe8:
        goto code_r0x000140096ff7;
      case 0xe9:
        goto code_r0x000140097135;
      case 0xea:
        goto code_r0x00014009748a;
      case 0xeb:
        goto code_r0x000140097384;
      case 0xec:
        goto code_r0x0001400973b8;
      case 0xed:
        goto code_r0x0001400972d9;
      case 0xee:
        goto switchD_1400944c0_caseD_8d;
      case 0xef:
        goto code_r0x0001400975bd;
      case 0xf0:
        goto code_r0x000140097421;
      case 0xf1:
        goto code_r0x00014009760e;
      case 0xf2:
        goto code_r0x000140097339;
      case 0xf3:
        goto code_r0x0001400975f1;
      case 0xf4:
        goto code_r0x000140097298;
      case 0xf5:
        goto code_r0x00014009731c;
      case 0xf6:
        goto code_r0x0001400975a0;
      case 0xf7:
        goto code_r0x00014009724d;
      case 0xf8:
        goto code_r0x00014009739b;
      case 0xf9:
        goto code_r0x00014009721f;
      case 0xfa:
        goto code_r0x0001400974c4;
      case 0xfb:
        goto code_r0x0001400975da;
      case 0xfc:
        goto code_r0x0001400976cd;
      case 0xfd:
        goto code_r0x0001400974f8;
      case 0xfe:
        goto code_r0x000140097583;
      case 0xff:
        goto code_r0x00014009769c;
      }
    case 0x19:
      goto switchD_14007f6e5_caseD_18;
    case 0x1a:
      goto switchD_14007f6e5_caseD_12;
    case 0x1b:
      goto switchD_14007f6e5_caseD_c;
    case 0x1c:
      goto code_r0x00014007fdcc;
    case 0x1d:
      goto LAB_140085c9c;
    case 0x1e:
      goto code_r0x000140085d0b;
    case 0x1f:
      goto code_r0x000140085cb1;
    case 0x20:
      goto code_r0x000140085cc2;
    case 0x21:
      goto code_r0x000140086a2d;
    case 0x22:
      goto code_r0x000140086980;
    case 0x23:
    case 0x24:
      goto code_r0x000140086973;
    case 0x25:
      goto code_r0x000140089986;
    case 0x26:
      goto code_r0x0001400898fa;
    case 0x27:
    case 0x28:
      goto code_r0x0001400898f0;
    case 0x29:
      goto code_r0x00014008a981;
    case 0x2a:
      goto switchD_14007f7e4_caseD_23;
    case 0x2b:
      goto code_r0x00014008a9a5;
    case 0x2c:
      goto code_r0x00014008a9b3;
    case 0x2d:
      goto code_r0x00014009308a;
    case 0x2e:
      goto code_r0x0001400930a7;
    case 0x2f:
      goto code_r0x00014009308f;
    case 0x30:
      break;
    case 0x31:
      goto code_r0x0001400931ea;
    case 0x32:
      goto switchD_14007f6e5_caseD_34;
    case 0x33:
      goto switchD_14007f6e5_caseD_36;
    case 0x34:
      goto switchD_14007f6e5_caseD_2f;
    case 0x35:
      goto switchD_14007f6e5_caseD_2d;
    case 0x36:
      goto switchD_14007f6e5_caseD_2e;
    case 0x37:
      goto switchD_14007f6e5_caseD_32;
    case 0x38:
      goto switchD_14007f6e5_caseD_30;
    case 0x39:
      goto switchD_14007f6e5_caseD_33;
    case 0x3a:
      goto code_r0x000140093203;
    default:
      goto code_r0x000140093458;
    case 0x3f:
      goto code_r0x000140093499;
    case 0x57:
      goto code_r0x000140093486;
    case 0x66:
    case 0x68:
      goto code_r0x000140093460;
    case 0x6a:
      goto LAB_1400933fd;
    case 0x6c:
      goto code_r0x0001400935b8;
    case 0x6d:
      goto code_r0x0001400938fd;
    case 0x6e:
      goto code_r0x000140093832;
    case 0x6f:
      goto code_r0x000140093889;
    case 0x70:
      goto code_r0x000140093ac9;
    case 0x71:
      goto code_r0x0001400937bd;
    case 0x72:
      goto code_r0x000140093a94;
    case 0x73:
      goto code_r0x000140093a9a;
    case 0x74:
      goto code_r0x000140093a86;
    case 0x75:
      goto code_r0x000140093aa8;
    case 0x76:
      goto code_r0x000140093aae;
    case 0x77:
      goto code_r0x000140093aa0;
    case 0x78:
      goto switchD_14007f6e5_caseD_72;
    case 0x79:
      goto code_r0x000140093a8c;
    case 0x7a:
      goto code_r0x000140093ab6;
    case 0x7b:
      goto code_r0x000140093a7e;
    case 0x7c:
      goto code_r0x000140093bca;
    case 0x7d:
      goto code_r0x000140093c9e;
    case 0x7e:
      goto code_r0x000140093be3;
    case 0x7f:
      goto code_r0x000140093c3a;
    case 0x80:
      goto code_r0x000140093eee;
    case 0x81:
      goto code_r0x000140093fd8;
    case 0x82:
      goto code_r0x000140093f1d;
    case 0x83:
      goto code_r0x000140093f74;
    case 0x84:
      goto code_r0x0001400942b2;
    case 0x85:
      goto code_r0x0001400943a4;
    case 0x86:
      goto code_r0x00014009431b;
    case 0x87:
      goto code_r0x000140094351;
    case 0x88:
      goto code_r0x0001400942ed;
    case 0x89:
      goto code_r0x00014009470c;
    case 0x8a:
      goto code_r0x000140094809;
    case 0x8b:
      goto code_r0x00014009474e;
    case 0x8c:
      goto code_r0x0001400947a5;
    case 0x8d:
    case 0x94:
      goto switchD_14007f7e4_caseD_8d;
    case 0x8e:
      goto code_r0x0001400946d4;
    case 0x8f:
    case 0x90:
    case 0x91:
      goto switchD_14007f7e4_caseD_8e;
    case 0x92:
      goto code_r0x00014009485c;
    case 0x93:
      goto switchD_14007f6e5_caseD_95;
    case 0x95:
    case 0x98:
    case 0x9a:
      goto switchD_14007fde0_caseD_7e;
    case 0x96:
    case 0x97:
      goto code_r0x000140094844;
    case 0x99:
      goto code_r0x000140094850;
    case 0x9b:
      goto code_r0x0001400951d1;
    case 0x9c:
      goto code_r0x000140095492;
    case 0x9d:
      goto code_r0x0001400953a5;
    case 0x9e:
      goto code_r0x00014009540f;
    case 0x9f:
      goto code_r0x000140095809;
    case 0xa0:
      goto code_r0x000140095bb4;
    case 0xa1:
      goto code_r0x000140095acf;
    case 0xa2:
      goto code_r0x000140095b34;
    case 0xa3:
      goto code_r0x000140095362;
    case 0xa4:
      goto code_r0x000140095753;
    case 0xa5:
      goto code_r0x000140095681;
    case 0xa6:
      goto code_r0x0001400956df;
    case 0xa7:
      goto code_r0x000140095c0e;
    case 0xa8:
      goto code_r0x000140095d57;
    case 0xa9:
      goto code_r0x000140095c7f;
    case 0xaa:
      goto code_r0x000140095ce1;
    case 0xab:
      goto switchD_140096440_default;
    case 0xac:
      goto code_r0x000140096748;
    case 0xad:
      goto code_r0x000140096661;
    case 0xae:
      goto code_r0x0001400966c8;
    case 0xaf:
      goto code_r0x000140096186;
    case 0xb0:
      goto code_r0x000140096318;
    case 0xb1:
      goto code_r0x000140096238;
    case 0xb2:
      goto code_r0x00014009629c;
    case 0xb3:
      goto code_r0x0001400967f6;
    case 0xb4:
      goto code_r0x0001400969bf;
    case 0xb5:
      goto code_r0x000140096973;
    case 0xb6:
      goto code_r0x000140096991;
    case 0xb7:
      goto code_r0x000140096907;
    case 0xb8:
      goto code_r0x000140096a0a;
    case 0xb9:
      goto code_r0x000140096a3f;
    case 0xba:
      goto code_r0x0001400969a8;
    case 0xbb:
      goto code_r0x000140096a6c;
    case 0xbc:
      goto code_r0x000140096946;
    case 0xbd:
      goto code_r0x000140096a5d;
    case 0xbe:
      goto code_r0x0001400968d9;
    case 0xbf:
      goto code_r0x000140096937;
    case 0xc0:
      goto code_r0x000140096a30;
    case 0xc1:
      goto code_r0x0001400968ac;
    case 0xc2:
      goto code_r0x000140096982;
    case 0xc3:
      goto code_r0x00014009688e;
    case 0xc4:
      goto code_r0x0001400969dd;
    case 0xc5:
      goto code_r0x000140096a4e;
    case 0xc6:
      goto code_r0x000140096adc;
    case 199:
      goto code_r0x0001400969fb;
    case 200:
      goto code_r0x000140096a21;
    case 0xc9:
      goto switchD_14009313c_caseD_8b;
    case 0xca:
      goto code_r0x000140096afa;
    case 0xcb:
      goto code_r0x000140096964;
    case 0xcc:
      goto code_r0x000140096955;
    case 0xcd:
      goto code_r0x000140096bc2;
    case 0xce:
      goto code_r0x000140096870;
    case 0xcf:
      goto code_r0x000140096b09;
    case 0xd0:
      goto code_r0x000140096baa;
    case 0xd1:
      goto code_r0x000140096a7b;
    case 0xd2:
      goto code_r0x0001400969ce;
    case 0xd3:
      goto code_r0x000140096a90;
    case 0xd4:
      goto code_r0x0001400968bb;
    case 0xd5:
      goto code_r0x00014009687f;
    case 0xd6:
      goto code_r0x000140096852;
    case 0xd7:
      goto code_r0x000140096861;
    case 0xd8:
      goto code_r0x000140096824;
    case 0xd9:
      goto code_r0x000140096bb6;
    case 0xda:
      goto code_r0x000140096acd;
    case 0xdb:
      goto switchD_14007fde0_caseD_d4;
    case 0xdc:
      goto code_r0x0001400969ec;
    case 0xdd:
      goto code_r0x000140096aeb;
    case 0xde:
      goto code_r0x000140096805;
    case 0xdf:
      goto code_r0x00014009689d;
    case 0xe0:
      goto code_r0x000140096a9f;
    case 0xe1:
      goto code_r0x000140096bce;
    case 0xe2:
      goto code_r0x000140096833;
    case 0xe3:
      goto code_r0x0001400968ca;
    case 0xe4:
      goto code_r0x0001400968e8;
    case 0xe5:
      goto code_r0x000140096f79;
    case 0xe6:
      goto code_r0x00014009705b;
    case 0xe7:
      goto code_r0x000140096fa0;
    case 0xe8:
      goto code_r0x000140096ff7;
    case 0xe9:
      goto code_r0x000140097135;
    case 0xea:
      goto code_r0x00014009748a;
    case 0xeb:
      goto code_r0x000140097384;
    case 0xec:
      goto code_r0x0001400973b8;
    case 0xed:
      goto code_r0x0001400972d9;
    case 0xee:
      goto switchD_1400944c0_caseD_8d;
    case 0xef:
      goto code_r0x0001400975bd;
    case 0xf0:
      goto code_r0x000140097421;
    case 0xf1:
      goto code_r0x00014009760e;
    case 0xf2:
      goto code_r0x000140097339;
    case 0xf3:
      goto code_r0x0001400975f1;
    case 0xf4:
      goto code_r0x000140097298;
    case 0xf5:
      goto code_r0x00014009731c;
    case 0xf6:
      goto code_r0x0001400975a0;
    case 0xf7:
      goto code_r0x00014009724d;
    case 0xf8:
      goto code_r0x00014009739b;
    case 0xf9:
      goto code_r0x00014009721f;
    case 0xfa:
      goto code_r0x0001400974c4;
    case 0xfb:
      goto code_r0x0001400975da;
    case 0xfc:
      goto code_r0x0001400976cd;
    case 0xfd:
      goto code_r0x0001400974f8;
    case 0xfe:
      goto code_r0x000140097583;
    case 0xff:
      goto code_r0x00014009769c;
    }
  case 6:
  case 7:
code_r0x00014007f6d7:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 8:
code_r0x00014007f7fc:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 9:
code_r0x00014007f7e2:
    goto code_r0x00014007f7cc;
  case 10:
  case 0xb:
code_r0x00014007f7c6:
    pfVar234 = (fd_set *)0x0;
    while (((ulonglong)pfVar234 & 1) == 0) {
      if (pfVar84 == (fd_set *)0x0) {
        return pfVar233;
      }
      pfStackY_90 = (fd_set *)0x14007f800;
      FUN_14007f82f((longlong *)param_3,(ulonglong)pfVar84);
      if (local_50 == (fd_set *)0x0) {
        return (fd_set *)0x0;
      }
      pfStackY_90 = (fd_set *)0x14007f7bb;
      pfVar84 = (fd_set *)local_60._8_8_;
      pfVar234 = (fd_set *)
                 FUN_14007e807((longlong)pcVar83,local_60._8_8_,(longlong)local_50,
                               &param_4->fd_count);
      local_48 = pfVar234;
    }
code_r0x00014007f7cc:
    pfStackY_90 = (fd_set *)0x14007f7d7;
    FUN_1400762c3((undefined1 *)param_1,(longlong)pfVar84);
                    /* WARNING: Could not recover jumptable at 0x00014007f7e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pfVar84 = (fd_set *)
              (*(code *)((longlong)pfVar227->fd_array +
                        (longlong)
                        *(int *)((longlong)pfVar227->fd_array +
                                (in_stack_ffffffffffffff98 & 0xff) * 4 + -8) + -8))();
    return pfVar84;
  case 0xc:
code_r0x00014007f96d:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xd:
    goto code_r0x00014007f953;
  case 0xe:
  case 0xf:
    goto code_r0x00014007f937;
  case 0x10:
code_r0x00014007fda3:
    return (fd_set *)((ulonglong)param_2 & 0xffffffff);
  case 0x11:
code_r0x00014007fe0e:
    uVar69 = uVar69 + 0x8985a + (uint)bVar237;
    goto LAB_14007fe13;
  case 0x12:
switchD_14007f6e5_caseD_15:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x13:
code_r0x00014007fdf5:
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
    switch(uVar69 + 0x8984b + (uint)bVar237) {
    case 0x40108e4c:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108e6b:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108e89:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108f23:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108f2d:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108f7f:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109012:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010902e:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109048:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109183:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010919f:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401091b9:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095ef:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095ff:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010960f:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109618:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109628:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109638:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109641:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109651:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010965a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010966a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010967a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010968a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010969a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f4e8:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f4fd:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f50e:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f557:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401101bf:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401101cc:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40110279:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4011313c:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40113146:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401131d2:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401141cd:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401141f1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401141ff:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40114211:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  case 0x14:
switchD_14007f6e5_caseD_17:
    writefds = (uint *)(ulonglong)(byte)((fd_set *)_Dst)->fd_count;
    _Src = &switchD_14007fde0::switchdataD_14010fd20;
    goto code_r0x00014007fdd9;
  case 0x15:
switchD_14007f6e5_caseD_d:
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
    switch(uVar69 + 0x897fc + (uint)bVar237) {
    case 0x40108dfd:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108e1c:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108e3a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108ed4:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108ede:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108f30:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108fc3:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108fdf:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40108ff9:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109134:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109150:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010916a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095a0:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095b0:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095c0:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095c9:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095d9:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095e9:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401095f2:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40109602:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010960b:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010961b:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010962b:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010963b:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010964b:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f499:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f4ae:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f4bf:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4010f508:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40110170:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4011017d:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4011022a:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401130ed:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401130f7:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x40113183:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x4011417e:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401141a2:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401141b0:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 0x401141c2:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  case 0x16:
switchD_14007f6e5_caseD_11:
    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 + 0x89770 + (uint)bVar237);
LAB_14007fe75:
                    /* WARNING: Could not recover jumptable at 0x00014007fe7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
    return pfVar84;
  case 0x17:
switchD_14007f6e5_caseD_f:
    uVar69 = uVar69 + 0x897d1 + (uint)bVar237;
LAB_14007fe13:
                    /* WARNING: Could not recover jumptable at 0x00014007fe19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pfVar84 = (fd_set *)(*(code *)(ulonglong)uVar69)();
    return pfVar84;
  case 0x18:
    goto switchD_14007f6e5_caseD_16;
  case 0x19:
switchD_14007f6e5_caseD_18:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x1a:
    goto switchD_14007f6e5_caseD_12;
  case 0x1b:
switchD_14007f6e5_caseD_c:
    pfVar84 = (fd_set *)switchD_14007fe5b::caseD_4000b3e0(*(ushort **)_Dst,(undefined8 *)_Src);
    return pfVar84;
  case 0x1c:
code_r0x00014007fdcc:
    (&UNK_14010fc6b)[uVar71] = (&UNK_14010fc6b)[uVar71] | (byte)_Dst;
    (&UNK_14010fc6d)[uVar71] = (&UNK_14010fc6d)[uVar71] - (byte)_Dst;
code_r0x00014007fdd9:
                    /* WARNING: Could not recover jumptable at 0x00014007fde0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pfVar84 = (fd_set *)
              (*(code *)((longlong)((fd_set *)_Src)->fd_array +
                        (longlong)
                        *(int *)((longlong)((fd_set *)_Src)->fd_array + (longlong)writefds * 4 + -8)
                        + -8))();
    return pfVar84;
  case 0x1d:
LAB_140085c9c:
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x1e:
code_r0x000140085d0b:
    UNRECOVERED_JUMPTABLE =
         (code *)((longlong)((fd_set *)_Dst)->fd_array +
                 (longlong)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x3f)
                 );
                    /* WARNING: Could not recover jumptable at 0x000140085d0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
    return pfVar84;
  case 0x1f:
code_r0x000140085cb1:
    pfStackY_90 = (fd_set *)0x140085cba;
    thunk_FUN_140016b3a((longlong)_Dst,(LPVOID)((fd_set *)pcVar83)->fd_array[0]);
    _Dst = (uint *)((fd_set *)pcVar83)->fd_array[2];
    _Src = (uint *)((fd_set *)pcVar83)->fd_array[3];
  case 0x20:
code_r0x000140085cc2:
    pfStackY_90 = (fd_set *)0x140085cc7;
    thunk_FUN_140016b3a((longlong)_Dst,_Src);
    pfVar84 = (fd_set *)FUN_140080640((longlong *)(((fd_set *)pcVar83)->fd_array + 5));
    return pfVar84;
  case 0x21:
code_r0x000140086a2d:
    cVar88 = (char)_Src;
    pcVar103 = (char *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff90);
    *pcVar103 = *pcVar103 + (char)pcVar103;
    pcVar103 = pcVar103 + -0x75;
    cVar89 = *pcVar103;
    *pcVar103 = *pcVar103 + (char)_Dst;
    if (SCARRY1(cVar89,(char)_Dst) == *pcVar103 < '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    cRam00000000c5506a66 = cRam00000000c5506a66 + '\x01';
    pfVar107 = (fd_set *)&UNK_14010fce8;
    pfVar72 = (fd_set *)writefds;
code_r0x000140086a64:
    if ((fd_set *)_Dst == (fd_set *)0x0) goto LAB_140086ac0;
    pfVar84 = (fd_set *)0xffffffffffffffff;
    if ((cVar88 == '\0') ||
       (pfVar84 = pfVar72,
       (fd_set *)_Dst != *(fd_set **)((longlong)pfVar107 + 0xe0) || pcVar83 < pfVar72)) {
      puVar225 = *(uint **)((longlong)pfVar107 + 0xa0);
    }
    else {
      puVar225 = *(uint **)((longlong)pfVar107 + 0xa0);
      pfVar84 = (fd_set *)0xffffffffffffffff;
      if (-1 < (longlong)pfVar72) {
        pfVar72 = (fd_set *)((longlong)pfVar72 * 2);
        pfVar84 = pfVar72;
      }
    }
LAB_14008682d:
    if ((param_1 == (fd_set *)puVar225) &&
       ((fd_set *)puVar225 == *(fd_set **)((longlong)pfVar107 + 0x98))) {
      pfVar227 = (fd_set *)((longlong)pfVar107 + 0x38);
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x14008684e;
      uVar81 = FUN_14007e6dd((undefined1 *)((longlong)pfVar107 + 0x80));
      if ((uVar81 & 1) != 0) goto LAB_140087062;
      param_1 = *(fd_set **)((longlong)pfVar107 + 0x48);
      if (pfVar227 == (fd_set *)0x0) {
LAB_140086ac0:
        lVar96 = (longlong)param_1 - (longlong)param_3;
        do {
          *(longlong *)((longlong)pfVar107 + 0x68) = lVar96;
          *(undefined1 **)((longlong)pfVar107 + 0x208) = (undefined1 *)((longlong)pfVar107 + 0x68);
          *(code **)((longlong)pfVar107 + 0x210) = FUN_140009af0;
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086b00;
          FUN_1400811fe((ulonglong *)param_2,(ushort *)&DAT_1400f868e,
                        (ulonglong)((longlong)pfVar107 + 0x208));
          uVar81 = *(ulonglong *)((longlong)pfVar107 + 0x100);
          if (6 < uVar81) {
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x14008747a;
            FUN_1400c3d10("assertion failed: header.len() <= CHUNK_HEADER_MAX_SIZE",0x37);
                    /* WARNING: Does not return */
            UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
            (*UNRECOVERED_JUMPTABLE)();
          }
          lVar85 = *(longlong *)((longlong)pfVar107 + 0xf0);
          pvVar74 = *(void **)((longlong)pfVar107 + 0xf8);
          uVar71 = *(ulonglong *)((longlong)pfVar107 + 0x40);
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086b44;
          pvVar75 = (void *)FUN_14000ff76(6 - uVar81,uVar71,
                                          *(ulonglong *)((longlong)pfVar107 + 0x48),
                                          &PTR_s_C__Users_flare__cargo_registry_s_1400f8740);
          uVar99 = uVar81;
          if (uVar71 < uVar81) {
            uVar99 = uVar71;
          }
          *(undefined **)((longlong)pfVar107 + 0x20) = &DAT_1400f7e40;
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086b6b;
          FUN_14001a0fe(pvVar75,uVar99,pvVar74,uVar99,*(undefined8 *)((longlong)pfVar107 + 0x20));
          if (uVar71 < uVar81) {
            *(undefined8 *)((longlong)pfVar107 + 0xf0) =
                 &PTR_s_failed_to_write_whole_buffer_1400f7e78;
            *(undefined ***)((longlong)pfVar107 + 0x20) =
                 &PTR_s_C__Users_flare__cargo_registry_s_1400f8758;
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400874b2;
            FUN_1400c3e10("called `Result::unwrap()` on an `Err` value",0x2b,
                          (undefined8 *)((longlong)pfVar107 + 0xf0),&PTR_FUN_1400f8460,
                          *(undefined8 *)((longlong)pfVar107 + 0x20));
                    /* WARNING: Does not return */
            UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
            (*UNRECOVERED_JUMPTABLE)();
          }
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086b8b;
          FUN_140069373((ulonglong *)((longlong)pfVar107 + 0x38),&DAT_1400f8770,2);
          pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x40);
          uVar71 = *(ulonglong *)((longlong)pfVar107 + 0x48);
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086baa;
          param_4 = pfVar84;
          pfVar72 = (fd_set *)
                    FUN_14000ff76(6 - uVar81,(longlong)pfVar84,uVar71,
                                  &PTR_s_C__Users_flare__cargo_registry_s_1400f8778);
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086bc5;
          pfVar227 = (fd_set *)
                     FUN_14007f597(*(undefined8 *)((longlong)pfVar107 + 0x3d8),
                                   *(undefined8 *)((longlong)pfVar107 + 0x3e0));
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086bd3;
          thunk_FUN_140016b3a(lVar85,pvVar74);
          if (pfVar227 != (fd_set *)0x0) goto LAB_140087067;
          puVar92 = *(undefined8 **)((longlong)pfVar107 + 0xd8);
          if (lVar96 == 0) goto LAB_14008706f;
          param_3 = (fd_set *)&DAT_00000006;
          if (uVar71 < 6) {
            lVar96 = *(longlong *)((longlong)pfVar107 + 0x38);
            if (lVar96 - uVar71 < 6 - uVar71) {
              pfVar84 = (fd_set *)(lVar96 * 2);
              puVar91 = &DAT_00000008;
              if (pfVar84 < (fd_set *)&DAT_00000009) {
                pfVar84 = (fd_set *)&DAT_00000008;
              }
              if ((longlong)pfVar84 < 0) {
                pfVar84 = (fd_set *)0x0;
LAB_1400874b7:
                **(undefined8 **)((longlong)pfVar107 + 0xe8) = pfVar84;
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400874d4;
                FUN_1400c389e(*(longlong *)((longlong)pfVar107 + 0x80),
                              *(ulonglong *)((longlong)pfVar107 + 0x68));
                    /* WARNING: Does not return */
                UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
                (*UNRECOVERED_JUMPTABLE)();
              }
              if (lVar96 == 0) {
                plVar100 = (longlong *)((longlong)pfVar107 + 0xf0);
                lVar96 = 0;
              }
              else {
                puVar91 = *(undefined1 **)((longlong)pfVar107 + 0x40);
                *(undefined8 *)((longlong)pfVar107 + 0xf0) = 1;
                plVar100 = (longlong *)((longlong)pfVar107 + 0x208);
              }
              *plVar100 = lVar96;
              if ((*(longlong *)((longlong)pfVar107 + 0xf0) == 0) ||
                 (*(ulonglong *)((longlong)pfVar107 + 0x208) == 0)) {
                pfVar72 = (fd_set *)0x0;
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086c79;
                pvVar74 = (void *)FUN_140014775(1,(longlong)pfVar84,'\0');
              }
              else {
                pfVar72 = (fd_set *)((longlong)&uRam0000000000000000 + 1);
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086c67;
                param_4 = pfVar84;
                pvVar74 = FUN_140005793(puVar91,*(ulonglong *)((longlong)pfVar107 + 0x208),1,
                                        (ulonglong)pfVar84);
              }
              if (pvVar74 == (void *)0x0) {
                *(undefined8 *)((longlong)pfVar107 + 0x80) = 1;
                *(undefined1 **)((longlong)pfVar107 + 0xe8) =
                     (undefined1 *)((longlong)pfVar107 + 0x68);
                goto LAB_1400874b7;
              }
              *(void **)((longlong)pfVar107 + 0x40) = pvVar74;
              *(fd_set **)((longlong)pfVar107 + 0x38) = pfVar84;
            }
            else {
              pvVar74 = *(void **)((longlong)pfVar107 + 0x40);
            }
            uVar81 = 0;
            while (uVar81 + 1 < 6 - uVar71) {
              *(undefined1 *)((longlong)pvVar74 + uVar81 + uVar71) = 0;
              uVar81 = uVar81 + 1;
            }
            *(undefined1 *)((longlong)pvVar74 + uVar81 + uVar71) = 0;
            param_3 = (fd_set *)(uVar71 + uVar81 + 1);
          }
          param_2 = (undefined **)((longlong)pfVar107 + 0xf0);
          *(fd_set **)((longlong)pfVar107 + 0x48) = param_3;
          *(undefined1 **)((longlong)pfVar107 + 0x80) = (undefined1 *)((longlong)pfVar107 + 0xc0);
          *(undefined8 *)((longlong)pfVar107 + 0x88) = 0x3ff8;
          *(undefined8 *)((longlong)pfVar107 + 0x90) = 0x3ff8;
          puVar225 = *(uint **)((longlong)pfVar107 + 0x38);
          *(uint **)((longlong)pfVar107 + 0x98) = puVar225;
          param_1 = param_3;
          if (0x1f < (ulonglong)((longlong)puVar225 - (longlong)param_3)) goto LAB_140086822;
          pfVar227 = (fd_set *)((longlong)pfVar107 + 0x38);
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086804;
          uVar81 = FUN_14007e6dd((undefined1 *)((longlong)pfVar107 + 0x80));
          if ((uVar81 & 1) != 0) goto LAB_140087062;
          if (pfVar227 != (fd_set *)0x0) goto code_r0x000140086818;
          lVar96 = 0;
        } while( true );
      }
      puVar225 = *(uint **)((longlong)pfVar107 + 0x38);
    }
    writefds = &pfVar72->fd_count;
    if (param_1 == (fd_set *)puVar225) {
      writefds = (uint *)&DAT_00000020;
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086884;
      uVar81 = FUN_140076938((ulonglong *)((longlong)pfVar107 + 0x38),(ulonglong)puVar225,0x20);
      if (uVar81 != 0x8000000000000001) {
        pfVar227 = (fd_set *)0x2600000003;
LAB_140087062:
        pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x40);
LAB_140087067:
        puVar92 = *(undefined8 **)((longlong)pfVar107 + 0xd8);
LAB_14008706f:
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x14008707c;
        thunk_FUN_140016b3a(*(longlong *)((longlong)pfVar107 + 0x38),pfVar84);
        lVar96 = *(longlong *)((longlong)pfVar107 + 0x58);
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140087096;
        FUN_14008066a(*(LPVOID *)((longlong)pfVar107 + 0xc0),
                      *(undefined8 **)((longlong)pfVar107 + 200));
        if (pfVar227 == (fd_set *)0x0) {
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400870cb;
          FUN_1400884f7((ulonglong *)((longlong)pfVar107 + 0xf0),lVar96);
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400870e6;
          FUN_140088644((undefined1 (*) [16])((longlong)pfVar107 + 0x408),
                        (undefined8 *)((longlong)pfVar107 + 0x300),
                        (longlong *)((longlong)pfVar107 + 0xf0));
          pfVar84 = *(fd_set **)*(undefined1 (*) [16])((longlong)pfVar107 + 0x408);
          if ((((pfVar84 != (fd_set *)0x8000000000000001) &&
               (bVar239 = SBORROW8(0,(longlong)pfVar84), pfVar84 = (fd_set *)-(longlong)pfVar84,
               bVar239)) && (*(char *)((longlong)pfVar107 + 0x490) == '\b')) &&
             (puVar122 = *(undefined8 **)((longlong)pfVar107 + 0x480), puVar122 != (undefined8 *)0x0
             )) {
            UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)((longlong)pfVar107 + 0x488) + 0x38);
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140087144;
            (*UNRECOVERED_JUMPTABLE)((char *)((longlong)pfVar107 + 0xf0),puVar122);
            auVar242[0] = -(*(char *)((longlong)pfVar107 + 0xf0) == DAT_1400c9110);
            auVar242[1] = -(*(char *)((longlong)pfVar107 + 0xf1) == UNK_1400c9111);
            auVar242[2] = -(*(char *)((longlong)pfVar107 + 0xf2) == UNK_1400c9112);
            auVar242[3] = -(*(char *)((longlong)pfVar107 + 0xf3) == UNK_1400c9113);
            auVar242[4] = -(*(char *)((longlong)pfVar107 + 0xf4) == UNK_1400c9114);
            auVar242[5] = -(*(char *)((longlong)pfVar107 + 0xf5) == UNK_1400c9115);
            auVar242[6] = -(*(char *)((longlong)pfVar107 + 0xf6) == UNK_1400c9116);
            auVar242[7] = -(*(char *)((longlong)pfVar107 + 0xf7) == UNK_1400c9117);
            auVar242[8] = -(*(char *)((longlong)pfVar107 + 0xf8) == UNK_1400c9118);
            auVar242[9] = -(*(char *)((longlong)pfVar107 + 0xf9) == UNK_1400c9119);
            auVar242[10] = -(*(char *)((longlong)pfVar107 + 0xfa) == UNK_1400c911a);
            auVar242[0xb] = -(*(char *)((longlong)pfVar107 + 0xfb) == UNK_1400c911b);
            auVar242[0xc] = -(*(char *)((longlong)pfVar107 + 0xfc) == UNK_1400c911c);
            auVar242[0xd] = -(*(char *)((longlong)pfVar107 + 0xfd) == UNK_1400c911d);
            auVar242[0xe] = -(*(char *)((longlong)pfVar107 + 0xfe) == UNK_1400c911e);
            auVar242[0xf] = -(*(char *)((longlong)pfVar107 + 0xff) == UNK_1400c911f);
            uVar65 = (ushort)(SUB161(auVar242 >> 7,0) & 1) |
                     (ushort)(SUB161(auVar242 >> 0xf,0) & 1) << 1 |
                     (ushort)(SUB161(auVar242 >> 0x17,0) & 1) << 2 |
                     (ushort)(SUB161(auVar242 >> 0x1f,0) & 1) << 3 |
                     (ushort)(SUB161(auVar242 >> 0x27,0) & 1) << 4 |
                     (ushort)(SUB161(auVar242 >> 0x2f,0) & 1) << 5 |
                     (ushort)(SUB161(auVar242 >> 0x37,0) & 1) << 6 |
                     (ushort)(SUB161(auVar242 >> 0x3f,0) & 1) << 7 |
                     (ushort)(SUB161(auVar242 >> 0x47,0) & 1) << 8 |
                     (ushort)(SUB161(auVar242 >> 0x4f,0) & 1) << 9 |
                     (ushort)(SUB161(auVar242 >> 0x57,0) & 1) << 10 |
                     (ushort)(SUB161(auVar242 >> 0x5f,0) & 1) << 0xb |
                     (ushort)(SUB161(auVar242 >> 0x67,0) & 1) << 0xc |
                     (ushort)(SUB161(auVar242 >> 0x6f,0) & 1) << 0xd |
                     (ushort)(SUB161(auVar242 >> 0x77,0) & 1) << 0xe |
                     (ushort)(auVar242[0xf] >> 7) << 0xf;
            pfVar84 = (fd_set *)(ulonglong)uVar65;
            if (uVar65 == 0xffff) {
              uVar241 = *puVar122;
              *(undefined8 *)((longlong)pfVar107 + -8) = 0x140087163;
              cVar89 = FUN_140076505(uVar241);
              bVar239 = cVar89 == '\x06' || cVar89 == '\x03';
              pfVar84 = (fd_set *)(ulonglong)bVar239;
              if ((*(byte *)((longlong)pfVar107 + 0x37) &
                  (byte)*(undefined4 *)((longlong)pfVar107 + 0x50) & bVar239) != 0) {
                *(longlong *)((longlong)pfVar107 + 0xf0) = -0x8000000000000000;
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400871a4;
                FUN_140085cd8((undefined1 *)((longlong)pfVar107 + 1000),
                              (longlong *)((longlong)pfVar107 + 0xf0));
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400871b7;
                FUN_140086253(puVar92,*(undefined8 *)((longlong)pfVar107 + 0x58),0,
                              (undefined1 *)((longlong)pfVar107 + 1000));
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400871c4;
                pfVar84 = (fd_set *)FUN_14007faab((longlong *)((longlong)pfVar107 + 0x408));
                return pfVar84;
              }
            }
          }
          puVar91 = (undefined1 *)((longlong)pfVar107 + 0x408);
          for (lVar96 = 0x110; lVar96 != 0; lVar96 = lVar96 + -1) {
            *(undefined1 *)puVar92 = *puVar91;
            puVar91 = puVar91 + 1;
            puVar92 = (undefined8 *)((longlong)puVar92 + 1);
          }
        }
        else {
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400870a6;
          FUN_1400884b6(puVar92,(ulonglong)pfVar227);
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400870b3;
          pfVar84 = (fd_set *)FUN_140076208((undefined8 *)((longlong)pfVar107 + 0x300));
        }
        return pfVar84;
      }
      puVar225 = *(uint **)((longlong)pfVar107 + 0x38);
      param_1 = *(fd_set **)((longlong)pfVar107 + 0x48);
    }
    *(uint **)((longlong)pfVar107 + 0xa0) = puVar225;
    puVar225 = (uint *)((longlong)puVar225 - (longlong)param_1);
    *(fd_set **)((longlong)pfVar107 + 0xa8) = pfVar84;
    pfVar233 = (fd_set *)puVar225;
    if (pfVar84 < puVar225) {
      pfVar233 = pfVar84;
    }
    *(longlong *)((longlong)pfVar107 + 0x208) =
         (longlong)param_1->fd_array + *(longlong *)((longlong)pfVar107 + 0x40) + -8;
    *(fd_set **)((longlong)pfVar107 + 0xe0) = pfVar233;
    *(fd_set **)((longlong)pfVar107 + 0x210) = pfVar233;
    *(undefined8 *)((longlong)pfVar107 + 0x218) = 0;
    *(undefined1 *)((longlong)pfVar107 + 0x220) = 0;
    puVar223 = *(uint **)((longlong)pfVar107 + 0x80);
    pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x90);
    do {
      pcVar83 = (char *)puVar225;
      if (pfVar84 == (fd_set *)0x0) {
        pfVar84 = (fd_set *)0x0;
LAB_140086a27:
        bVar239 = false;
        pfVar227 = (fd_set *)0x0;
        goto LAB_140086a30;
      }
      pfVar233 = *(fd_set **)((longlong)pfVar107 + 0x210);
      param_3 = *(fd_set **)((longlong)pfVar107 + 0x218);
      if (pfVar84 < (fd_set *)((longlong)pfVar233 - (longlong)param_3)) {
        pfVar77 = *(fd_set **)((longlong)pfVar107 + 0x208);
        *(longlong *)((longlong)pfVar107 + 0xf0) =
             (longlong)pfVar77->fd_array + (longlong)(param_3[-1].fd_array + 0x3f);
        *(fd_set **)((longlong)pfVar107 + 0xf8) = pfVar84;
        *(undefined8 *)((longlong)pfVar107 + 0x100) = 0;
        *(undefined1 *)((longlong)pfVar107 + 0x108) = *(undefined1 *)((longlong)pfVar107 + 0x220);
        uVar241 = *(undefined8 *)puVar223;
        UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)puVar223)->fd_array[0] + 0x48);
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140086964;
        pfVar227 = (fd_set *)(*UNRECOVERED_JUMPTABLE)(uVar241,param_2);
        UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar107 + 0x100);
        cVar89 = *(char *)((longlong)pfVar107 + 0x108);
code_r0x000140086977:
        if (cVar89 != '\0') {
          _Dst = (uint *)((longlong)pfVar84->fd_array + (longlong)(param_3[-1].fd_array + 0x3f));
          while( true ) {
            bVar239 = pfVar233 == (fd_set *)_Dst;
            puVar53 = (undefined1 *)pfVar107;
code_r0x000140086980:
            pfVar107 = (fd_set *)puVar53;
            if (bVar239) break;
            *(undefined1 *)
             ((longlong)pfVar77->fd_array +
             (longlong)(((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x3f)) = 0;
            _Dst = (uint *)((longlong)&((fd_set *)_Dst)->fd_count + 1);
          }
          *(undefined1 *)((longlong)pfVar107 + 0x220) = 1;
        }
        param_3 = (fd_set *)
                  ((longlong)param_3->fd_array +
                  (longlong)
                  (((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x3f));
        *(fd_set **)((longlong)pfVar107 + 0x218) = param_3;
        param_2 = (undefined **)((longlong)pfVar107 + 0xf0);
        puVar145 = (undefined8 *)pfVar107;
        pfVar84 = (fd_set *)((longlong)pfVar84 - (longlong)UNRECOVERED_JUMPTABLE);
      }
      else {
        uVar241 = *(undefined8 *)puVar223;
        UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)puVar223)->fd_array[0] + 0x48);
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x14008699e;
        pfVar227 = (fd_set *)
                   (*UNRECOVERED_JUMPTABLE)(uVar241,(undefined1 *)((longlong)pfVar107 + 0x208));
        param_3 = (fd_set *)
                  ((longlong)param_3->fd_array +
                  (longlong)pfVar84[-1].fd_array +
                  (0x1f8 - *(longlong *)((longlong)pfVar107 + 0x218)));
        puVar145 = (undefined8 *)pfVar107;
        pfVar84 = param_3;
      }
      pfVar107 = (fd_set *)puVar145;
      if (pfVar227 == (fd_set *)0x0) goto LAB_140086a27;
      *(undefined8 *)((longlong)puVar145 + -8) = 0x1400869df;
      pcVar103 = (char *)pfVar227;
      SVar82 = FUN_1400762c3((undefined1 *)param_2,(longlong)pfVar227);
      _Dst = &UINT_14010fd64;
      uVar81 = (ulonglong)(int)(&UINT_14010fd64)[*(byte *)((longlong)puVar145 + 0xf0)];
      bVar238 = 0xfffffffebfef029b < uVar81;
      bVar240 = SCARRY8(uVar81,0x14010fd64);
      UNRECOVERED_JUMPTABLE = (code *)((longlong)&UINT_14010fd64 + uVar81);
      bVar237 = (longlong)UNRECOVERED_JUMPTABLE < 0;
      bVar239 = (fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0;
      pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
      puVar97 = _Dst;
      puVar225 = _Dst;
      _Src = (uint *)pcVar103;
      puVar126 = puVar145;
      pfVar234 = (fd_set *)puVar145;
      pfVar101 = (fd_set *)puVar145;
      pfVar16 = (fd_set *)puVar145;
      pfVar159 = (fd_set *)puVar145;
      pfVar93 = (fd_set *)puVar145;
      pfVar123 = (fd_set *)puVar145;
      pfVar141 = (fd_set *)puVar145;
      pfVar205 = (fd_set *)puVar145;
      pfVar77 = (fd_set *)puVar145;
      pfVar94 = (fd_set *)puVar145;
      pfVar160 = (fd_set *)puVar145;
      puVar17 = puVar145;
      puVar18 = puVar145;
      puVar204 = puVar145;
      puVar19 = puVar145;
      puVar20 = puVar145;
      puVar92 = puVar145;
      puVar115 = puVar145;
      puVar125 = puVar145;
      puVar221 = puVar145;
      puVar21 = puVar145;
      puVar22 = puVar145;
      puVar206 = puVar145;
      puVar23 = puVar145;
      puVar24 = puVar145;
      puVar25 = puVar145;
      puVar26 = puVar145;
      puVar215 = puVar145;
      puVar211 = puVar145;
      puVar27 = puVar145;
      pSVar196 = puVar145;
      puVar28 = puVar145;
      puVar29 = puVar145;
      pfVar195 = (fd_set *)puVar145;
      puVar180 = puVar145;
      puVar193 = puVar145;
      puVar183 = puVar145;
      puVar174 = puVar145;
      puVar166 = puVar145;
      puVar30 = puVar145;
      puVar162 = puVar145;
      puVar31 = puVar145;
      puVar149 = puVar145;
      puVar32 = puVar145;
      puVar134 = puVar145;
      puVar136 = puVar145;
      puVar139 = puVar145;
      puVar140 = puVar145;
      puVar137 = puVar145;
      puVar131 = puVar145;
      puVar114 = puVar145;
      puVar110 = puVar145;
      puVar199 = puVar145;
      puVar34 = puVar145;
      puVar122 = puVar145;
      puVar198 = puVar145;
      puVar207 = puVar145;
      puVar209 = puVar145;
      puVar212 = puVar145;
      puVar214 = puVar145;
      puVar35 = puVar145;
      puVar191 = puVar145;
      puVar177 = puVar145;
      puVar165 = puVar145;
      puVar36 = puVar145;
      puVar151 = puVar145;
      puVar150 = puVar145;
      puVar135 = puVar145;
      puVar138 = puVar145;
      puVar37 = puVar145;
      puVar116 = puVar145;
      puVar124 = puVar145;
      puVar222 = puVar145;
      puVar203 = puVar145;
      puVar38 = puVar145;
      puVar217 = puVar145;
      puVar220 = puVar145;
      puVar39 = puVar145;
      puVar219 = puVar145;
      puVar218 = puVar145;
      puVar216 = puVar145;
      puVar201 = puVar145;
      puVar210 = puVar145;
      puVar40 = puVar145;
      puVar41 = puVar145;
      puVar181 = puVar145;
      puVar42 = puVar145;
      puVar192 = puVar145;
      puVar43 = puVar145;
      puVar188 = puVar145;
      puVar44 = puVar145;
      puVar185 = puVar145;
      puVar186 = puVar145;
      puVar190 = puVar145;
      puVar189 = puVar145;
      puVar171 = puVar145;
      puVar167 = puVar145;
      puVar176 = puVar145;
      puVar158 = puVar145;
      puVar45 = puVar145;
      pSVar163 = puVar145;
      puVar164 = puVar145;
      puVar46 = puVar145;
      puVar157 = puVar145;
      puVar156 = puVar145;
      puVar155 = puVar145;
      puVar154 = puVar145;
      puVar152 = puVar145;
      puVar153 = puVar145;
      puVar146 = puVar145;
      puVar47 = puVar145;
      puVar147 = puVar145;
      puVar144 = puVar145;
      puVar143 = puVar145;
      puVar48 = puVar145;
      puVar128 = puVar145;
      puVar130 = puVar145;
      puVar129 = puVar145;
      puVar127 = puVar145;
      puVar113 = puVar145;
      puVar109 = puVar145;
      puVar49 = puVar145;
      puVar50 = puVar145;
      puVar106 = puVar145;
      puVar108 = puVar145;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pcVar83 = (char *)(fd_set *)pcVar83;
      pcVar83 = (char *)(fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pcVar83 = (char *)(fd_set *)pcVar83;
      pcVar83 = (char *)(fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar62 = (fd_set *)pcVar83;
      pfVar229 = param_3;
      pfVar72 = (fd_set *)writefds;
      SVar76 = extraout_XMM0_Qb_00;
      pfVar224 = (fd_set *)puVar223;
      pfVar235 = pfVar227;
      switch(*(byte *)((longlong)puVar145 + 0xf0)) {
      case 0:
code_r0x000140086ab1:
        *(fd_set **)((longlong)puVar108 + 0x90) = pfVar84;
        bVar239 = true;
        pfVar107 = (fd_set *)puVar108;
        goto code_r0x000140086a38;
      case 1:
code_r0x000140086a04:
        cVar89 = *(char *)((longlong)puVar106 + 0xf1);
        pfVar107 = (fd_set *)puVar106;
        puVar225 = (uint *)pcVar83;
        break;
      case 2:
      case 3:
code_r0x0001400869f7:
        puVar225 = &pfVar62->fd_count;
        pfVar107 = (fd_set *)puVar50;
        UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar107 + 0xf8);
code_r0x0001400869ff:
        cVar89 = (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array[1];
        writefds = &pfVar72->fd_count;
        break;
      case 4:
code_r0x000140089a0a:
        puVar225 = &pfVar62->fd_count;
        pfVar107 = (fd_set *)puVar49;
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)(uint)((int)UNRECOVERED_JUMPTABLE + (int)pfVar107);
        goto code_r0x0001400899fd;
      case 5:
code_r0x00014008997e:
        pcVar103 = (char *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 1);
        *pcVar103 = *pcVar103 + (char)_Dst;
        *(undefined **)((longlong)puVar110 + -8) = &UNK_140089986;
        UNRECOVERED_JUMPTABLE = (code *)func_0xcb517a85();
        puVar51 = (undefined1 *)puVar110;
        puVar225 = (uint *)pcVar83;
        goto code_r0x000140089986;
      case 6:
      case 7:
code_r0x000140089974:
        param_3->fd_count = param_3->fd_count - 1;
        goto code_r0x00014008995a;
      case 8:
        goto switchD_14007fde0_caseD_1a;
      case 9:
code_r0x00014008aa49:
        *(undefined **)((longlong)puVar114 + -8) = &UNK_14008aa55;
        uVar241 = FUN_1400711e0((int)((ulonglong)param_2 >> 0x20));
        if ((char)uVar241 != '\r') goto LAB_14008ab66;
code_r0x00014008aa74:
        uVar65 = (ushort)pfVar84;
        if ((param_3 == (fd_set *)0x0) &&
           (param_2 = &PTR_s_cannot_set_a_0_duration_timeout_1400f5f60, (uint)pfVar233 == 0))
        goto LAB_14008ab52;
        pfVar84 = (fd_set *)0x7fffffff;
        if (param_3 < (fd_set *)0x7fffffff) {
          pfVar84 = param_3;
        }
        ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[8] = 0;
        iVar66 = (int)(((ulonglong)pfVar233 & 0xffffffff) / 1000);
        *(undefined8 *)((longlong)puVar114 + -8) = 1;
        uVar241 = *(undefined8 *)((longlong)puVar114 + -8);
        iVar98 = iVar66;
        if ((uint)pfVar233 < 1000) {
          iVar98 = (int)uVar241;
        }
        *(int *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8) = (int)pfVar84;
        if (param_3 != (fd_set *)0x0) {
          iVar98 = iVar66;
        }
        *(int *)((longlong)((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x44) = iVar98;
        pSVar163 = ((fd_set *)puVar223)->fd_array + 0x3c;
        for (lVar96 = 0x1f8; lVar96 != 0; lVar96 = lVar96 + -1) {
          *(undefined1 *)pSVar163 = 0;
          pSVar163 = (SOCKET *)((longlong)pSVar163 + 1);
        }
        *(undefined8 *)((longlong)puVar114 + -8) = 1;
        SVar82 = *(SOCKET *)((longlong)puVar114 + -8);
        ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] = SVar82;
        ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[8] = (SOCKET)pcVar83;
        pSVar163 = ((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 9;
        for (lVar96 = 0x1f8; lVar96 != 0; lVar96 = lVar96 + -1) {
          *(undefined1 *)pSVar163 = 0;
          pSVar163 = (SOCKET *)((longlong)pSVar163 + 1);
        }
        ((fd_set *)puVar223)->fd_array[0x3a] = SVar82;
        ((fd_set *)puVar223)->fd_array[0x3b] = (SOCKET)pcVar83;
        *(SOCKET **)((longlong)puVar114 + 0x20) =
             ((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8;
        pcVar103 = (char *)0x0;
        writefds = (uint *)(((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7);
        *(undefined **)((longlong)puVar114 + -8) = &UNK_14008ab32;
        param_4 = param_1;
        iVar66 = select((int)uVar241,(fd_set *)0x0,(fd_set *)writefds,param_1,
                        *(timeval **)((longlong)puVar114 + 0x20));
        uVar241 = CONCAT44(extraout_var_00,iVar66);
        param_2 = (undefined **)&UNK_1400f5f90;
        if (iVar66 != 0) {
          if (iVar66 == -1) {
code_r0x00014008ab42:
            *(undefined **)((longlong)puVar114 + -8) = &UNK_14008ab48;
            uVar69 = WSAGetLastError();
code_r0x00014008ab4a:
            param_2 = (undefined **)((ulonglong)uVar69 << 0x20 | 2);
            goto LAB_14008ab52;
          }
          if ((int)((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] != 1) {
            *(undefined4 *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x3b) = 0;
            *(undefined4 *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 9) = 4;
            *(SOCKET **)((longlong)puVar114 + 0x20) =
                 ((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 9;
            pcVar103 = (char *)0xffff;
            writefds = (uint *)0x1007;
            param_4 = (fd_set *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x3b);
            *(undefined **)((longlong)puVar114 + -8) = &UNK_14008ac05;
            iVar66 = getsockopt((SOCKET)pcVar83,0xffff,0x1007,(char *)param_4,
                                *(int **)((longlong)puVar114 + 0x20));
            uVar241 = CONCAT44(extraout_var_01,iVar66);
            if (iVar66 == -1) goto code_r0x00014008ab42;
            uVar69 = (uint)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3b];
            if (uVar69 != 0) goto code_r0x00014008ab4a;
          }
          ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[8] =
               CONCAT71((int7)((ulonglong)uVar241 >> 8),1);
          param_2 = (undefined **)0x0;
        }
        ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3d] = (SOCKET)pcVar83;
        *(undefined **)((longlong)puVar114 + -8) = &UNK_14008abbe;
        FUN_14006a7d0(((fd_set *)puVar223)->fd_array + 0x24);
        pfVar233 = (fd_set *)pcVar83;
        if ((char)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[8] == '\0') goto LAB_14008ab66;
        goto LAB_14008af9c;
      case 10:
code_r0x00014008aa29:
        *(undefined8 *)((longlong)puVar113 + -8) = 0x14008aa30;
        uVar69 = WSAGetLastError();
        pfVar84 = (fd_set *)param_2;
        puVar114 = puVar113;
        goto code_r0x00014008aa30;
      case 0xb:
code_r0x00014008aa37:
        *(int *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x189)
             = (int)in_ST0;
        return (fd_set *)UNRECOVERED_JUMPTABLE;
      case 0xc:
code_r0x00014009310e:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xd:
code_r0x00014009312b:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xe:
code_r0x000140093113:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pcVar78 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x189)
        ;
        bVar90 = (byte)_Dst;
        *pcVar78 = *pcVar78 + bVar90;
        puVar225 = (uint *)((longlong)
                            ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x183
                           );
        *puVar225 = *puVar225 >> 4 | *puVar225 << 0x1c;
        bVar64 = (byte)((ulonglong)_Dst >> 8);
        bVar238 = bVar90 < bVar64;
        cVar89 = bVar90 - bVar64;
        puVar225 = (uint *)CONCAT71((int7)((ulonglong)_Dst >> 8),cVar89);
        bVar239 = cVar89 == '\0';
        _Src = (uint *)pcVar103;
        puVar116 = puVar115;
code_r0x00014009311e:
        if (!(bool)bVar238 && !bVar239) {
          pcVar83 = (char *)((longlong)
                             ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                            0x183);
          *pcVar83 = *pcVar83 + (char)puVar225 + bVar238;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        UNRECOVERED_JUMPTABLE = (code *)((fd_set *)pcVar83)->fd_array[8];
        *(undefined8 *)((longlong)puVar116 + -8) = 0x140093124;
        SVar82 = (*UNRECOVERED_JUMPTABLE)();
        uVar70 = (int)puVar116 - 0x20;
        pfVar168 = (fd_set *)(ulonglong)uVar70;
        bVar90 = (byte)((fd_set *)_Src)->fd_array[7];
        puVar97 = &switchD_14009313c::caseD_fe;
        uVar81 = (ulonglong)(int)(&switchD_14009313c::caseD_fe)[bVar90];
        bVar238 = 0xfffffffebfef026b < uVar81;
        bVar240 = SCARRY8(uVar81,0x14010fd94);
        UNRECOVERED_JUMPTABLE = (code *)((longlong)&switchD_14009313c::caseD_fe + uVar81);
        bVar237 = (longlong)UNRECOVERED_JUMPTABLE < 0;
        bVar239 = (fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0;
        bVar64 = (byte)UNRECOVERED_JUMPTABLE;
        uVar69 = (uint)UNRECOVERED_JUMPTABLE;
        uVar86 = (uint7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8);
        uVar226 = (uint)param_3;
        _Dst = puVar97;
        pfVar72 = (fd_set *)_Src;
        pfVar234 = pfVar168;
        pfVar101 = pfVar168;
        pfVar16 = pfVar168;
        pfVar159 = pfVar168;
        pfVar93 = pfVar168;
        pfVar123 = pfVar168;
        pfVar107 = pfVar168;
        pfVar141 = pfVar168;
        pcVar83 = (char *)puVar225;
        pfVar94 = param_3;
        pfVar77 = param_3;
        SVar76 = extraout_XMM0_Qb_01;
        switch(bVar90) {
        case 0:
switchD_14009313c_caseD_0:
          *(undefined1 *)&((fd_set *)puVar225)->fd_count = 3;
          break;
        case 1:
switchD_14009313c_caseD_1:
          uVar69 = *(uint *)((longlong)((fd_set *)_Src)->fd_array + 0x2c);
          SVar76 = ((fd_set *)_Src)->fd_array[6];
          SVar82 = ((fd_set *)_Src)->fd_array[0];
          uVar81 = ((fd_set *)_Src)->fd_array[1];
          pfVar168[-1].fd_array[0x3f] = 0x140093170;
          UNRECOVERED_JUMPTABLE =
               (code *)FUN_140093083(SVar82,uVar81,(ulonglong)uVar69,(ulonglong)(uint)SVar76);
          *(undefined1 *)&((fd_set *)puVar225)->fd_count = 0;
          ((fd_set *)puVar225)->fd_array[0] = (SOCKET)UNRECOVERED_JUMPTABLE;
          ((fd_set *)puVar225)->fd_array[1] = uVar81;
          break;
        case 2:
switchD_14009313c_caseD_2:
          uVar69 = *(uint *)((longlong)((fd_set *)_Src)->fd_array + 0x39);
          UNRECOVERED_JUMPTABLE = (code *)(ulonglong)uVar69;
          *(undefined1 *)&((fd_set *)puVar225)->fd_count = 1;
          *(uint *)((longlong)&((fd_set *)puVar225)->fd_count + 1) = uVar69;
          break;
        case 3:
switchD_14009313c_caseD_3:
          uVar241 = *(undefined8 *)((longlong)((fd_set *)_Src)->fd_array + 0x41);
          *(undefined8 *)((longlong)&((fd_set *)puVar225)->fd_count + 1) =
               *(undefined8 *)((longlong)((fd_set *)_Src)->fd_array + 0x39);
          *(undefined8 *)((longlong)((fd_set *)puVar225)->fd_array + 1) = uVar241;
          *(undefined1 *)&((fd_set *)puVar225)->fd_count = 2;
          break;
        case 4:
switchD_14009313c_caseD_4:
          pcVar103 = (char *)0x4010fda4;
          goto code_r0x0001400932a4;
        case 5:
          goto switchD_14009313c_caseD_5;
        case 6:
          goto switchD_14009313c_caseD_6;
        case 7:
          goto switchD_14009313c_caseD_7;
        case 8:
switchD_14009313c_caseD_8:
          _Src = (uint *)&DAT_14010a9ca;
          pfVar72 = (fd_set *)&DAT_0000000a;
          goto code_r0x0001400932bb;
        case 9:
switchD_14009313c_caseD_9:
          _Src = (uint *)&DAT_14010a9d4;
          writefds = (uint *)&DAT_00000021;
          pfVar72 = (fd_set *)_Src;
          switch(bVar90) {
          case 0:
            goto switchD_14009313c_caseD_0;
          case 1:
            goto switchD_14009313c_caseD_1;
          case 2:
            goto switchD_14009313c_caseD_2;
          case 3:
            goto switchD_14009313c_caseD_3;
          case 4:
            goto switchD_14009313c_caseD_4;
          case 5:
            goto switchD_14009313c_caseD_5;
          case 6:
            goto switchD_14009313c_caseD_6;
          case 7:
            goto switchD_14009313c_caseD_7;
          case 8:
            goto switchD_14009313c_caseD_8;
          case 9:
            goto switchD_14009313c_caseD_9;
          case 10:
switchD_14009313c_caseD_a:
            _Src = (uint *)((longlong)&DAT_14010aa2d + 3);
            writefds = (uint *)&DAT_00000018;
            pfVar72 = (fd_set *)_Src;
            switch(bVar90) {
            case 0:
              goto switchD_14009313c_caseD_0;
            case 1:
              goto switchD_14009313c_caseD_1;
            case 2:
              goto switchD_14009313c_caseD_2;
            case 3:
              goto switchD_14009313c_caseD_3;
            case 4:
              goto switchD_14009313c_caseD_4;
            case 5:
              goto switchD_14009313c_caseD_5;
            case 6:
              goto switchD_14009313c_caseD_6;
            case 7:
              goto switchD_14009313c_caseD_7;
            case 8:
              goto switchD_14009313c_caseD_8;
            case 9:
              goto switchD_14009313c_caseD_9;
            case 10:
              goto switchD_14009313c_caseD_a;
            case 0xb:
              goto switchD_14009313c_caseD_b;
            case 0xc:
switchD_14009313c_caseD_c:
              _Src = (uint *)&DAT_14010aa48;
              writefds = (uint *)0x1b;
              pfVar72 = (fd_set *)_Src;
              switch(bVar90) {
              case 0:
                goto switchD_14009313c_caseD_0;
              case 1:
                goto switchD_14009313c_caseD_1;
              case 2:
                goto switchD_14009313c_caseD_2;
              case 3:
                goto switchD_14009313c_caseD_3;
              case 4:
                goto switchD_14009313c_caseD_4;
              case 5:
                goto switchD_14009313c_caseD_5;
              case 6:
                goto switchD_14009313c_caseD_6;
              case 7:
                goto switchD_14009313c_caseD_7;
              case 8:
                goto switchD_14009313c_caseD_8;
              case 9:
                goto switchD_14009313c_caseD_9;
              case 10:
                goto switchD_14009313c_caseD_a;
              case 0xb:
                goto switchD_14009313c_caseD_b;
              case 0xc:
                goto switchD_14009313c_caseD_c;
              case 0xd:
                goto switchD_14009313c_caseD_d;
              default:
                goto switchD_14009313c_caseD_e;
              case 0x12:
                goto switchD_14009313c_caseD_12;
              case 0x2a:
                goto switchD_14009313c_caseD_2a;
              case 0x39:
              case 0x3b:
                goto switchD_14009313c_caseD_39;
              case 0x3d:
                goto switchD_14009313c_caseD_3d;
              case 0x3f:
                goto switchD_14009313c_caseD_3f;
              case 0x40:
                goto switchD_14009313c_caseD_40;
              case 0x41:
                goto switchD_14009313c_caseD_41;
              case 0x42:
                goto switchD_14009313c_caseD_42;
              case 0x43:
                goto switchD_14009313c_caseD_43;
              case 0x44:
                goto switchD_14009313c_caseD_44;
              case 0x45:
                goto switchD_14009313c_caseD_45;
              case 0x46:
                goto code_r0x000140093b4f;
              case 0x47:
                goto switchD_14009313c_caseD_47;
              case 0x48:
                goto switchD_14009313c_caseD_48;
              case 0x49:
                goto switchD_14009313c_caseD_49;
              case 0x4a:
                goto switchD_14009313c_caseD_4a;
              case 0x4b:
                goto switchD_14009313c_caseD_4b;
              case 0x4c:
                goto switchD_14009313c_caseD_4c;
              case 0x4d:
                goto switchD_14009313c_caseD_4d;
              case 0x4e:
                goto switchD_14009313c_caseD_4e;
              case 0x4f:
                goto switchD_14009313c_caseD_4f;
              case 0x50:
                goto switchD_14009313c_caseD_50;
              case 0x51:
                goto switchD_14009313c_caseD_51;
              case 0x52:
                goto switchD_14009313c_caseD_52;
              case 0x53:
                goto switchD_14009313c_caseD_53;
              case 0x54:
                goto switchD_14009313c_caseD_54;
              case 0x55:
                goto switchD_14009313c_caseD_55;
              case 0x56:
                goto switchD_14009313c_caseD_56;
              case 0x57:
                goto switchD_14009313c_caseD_57;
              case 0x58:
                goto switchD_14009313c_caseD_58;
              case 0x59:
                goto switchD_14009313c_caseD_59;
              case 0x5a:
                goto switchD_14009313c_caseD_5a;
              case 0x5b:
                goto switchD_14009313c_caseD_5b;
              case 0x5c:
                goto switchD_14009313c_caseD_5c;
              case 0x5d:
                goto switchD_14009313c_caseD_5d;
              case 0x5e:
                goto switchD_14009313c_caseD_5e;
              case 0x5f:
                goto switchD_14009313c_caseD_5f;
              case 0x60:
              case 0x67:
                goto switchD_14009313c_caseD_60;
              case 0x61:
                goto switchD_14009313c_caseD_61;
              case 0x62:
              case 99:
              case 100:
                goto switchD_14009313c_caseD_62;
              case 0x65:
                goto switchD_14009313c_caseD_65;
              case 0x66:
                goto switchD_14009313c_caseD_66;
              case 0x68:
              case 0x6b:
              case 0x6d:
                goto switchD_14009313c_caseD_68;
              case 0x69:
              case 0x6a:
                goto switchD_14009313c_caseD_69;
              case 0x6c:
                goto switchD_14009313c_caseD_6c;
              case 0x6e:
                goto switchD_14009313c_caseD_6e;
              case 0x6f:
                goto switchD_14009313c_caseD_6f;
              case 0x70:
                goto switchD_14009313c_caseD_70;
              case 0x71:
                goto switchD_14009313c_caseD_71;
              case 0x72:
                goto switchD_14009313c_caseD_72;
              case 0x73:
                goto switchD_14009313c_caseD_73;
              case 0x74:
                goto switchD_14009313c_caseD_74;
              case 0x75:
                goto switchD_14009313c_caseD_75;
              case 0x76:
                goto switchD_14009313c_caseD_76;
              case 0x77:
                goto switchD_14009313c_caseD_77;
              case 0x78:
                goto switchD_14009313c_caseD_78;
              case 0x79:
                goto switchD_14009313c_caseD_79;
              case 0x7a:
                goto switchD_14009313c_caseD_7a;
              case 0x7b:
                goto switchD_14009313c_caseD_7b;
              case 0x7c:
                goto switchD_14009313c_caseD_7c;
              case 0x7d:
                goto switchD_14009313c_caseD_7d;
              case 0x7e:
                goto switchD_14009313c_caseD_7e;
              case 0x7f:
                goto switchD_14009313c_caseD_7f;
              case 0x80:
                goto switchD_14009313c_caseD_80;
              case 0x81:
                goto switchD_14009313c_caseD_81;
              case 0x82:
                goto switchD_14009313c_caseD_82;
              case 0x83:
                goto switchD_14009313c_caseD_83;
              case 0x84:
                goto switchD_14009313c_caseD_84;
              case 0x85:
                goto switchD_14009313c_caseD_85;
              case 0x86:
                goto switchD_14009313c_caseD_86;
              case 0x87:
                goto switchD_14009313c_caseD_87;
              case 0x88:
                goto switchD_14009313c_caseD_88;
              case 0x89:
                goto switchD_14009313c_caseD_89;
              case 0x8a:
                goto switchD_14009313c_caseD_8a;
              case 0x8b:
                goto switchD_14009313c_caseD_8b;
              case 0x8c:
                goto switchD_14009313c_caseD_8c;
              case 0x8d:
                goto switchD_14009313c_caseD_8d;
              case 0x8e:
                goto switchD_14009313c_caseD_8e;
              case 0x8f:
                goto switchD_14009313c_caseD_8f;
              case 0x90:
                goto switchD_14009313c_caseD_90;
              case 0x91:
                goto switchD_14009313c_caseD_91;
              case 0x92:
                goto code_r0x0001400969f5;
              case 0x93:
                goto switchD_14009313c_caseD_93;
              case 0x94:
                goto switchD_14009313c_caseD_94;
              case 0x95:
                goto switchD_14009313c_caseD_95;
              case 0x96:
                goto switchD_14009313c_caseD_96;
              case 0x97:
                goto switchD_14009313c_caseD_97;
              case 0x98:
                goto switchD_14009313c_caseD_98;
              case 0x99:
                goto switchD_14009313c_caseD_99;
              case 0x9a:
                goto switchD_14009313c_caseD_9a;
              case 0x9b:
                goto switchD_14009313c_caseD_9b;
              case 0x9c:
                goto switchD_14009313c_caseD_9c;
              case 0x9d:
                goto switchD_14009313c_caseD_9d;
              case 0x9e:
                goto switchD_14009313c_caseD_9e;
              case 0x9f:
                goto switchD_14009313c_caseD_9f;
              case 0xa0:
                goto switchD_14009313c_caseD_a0;
              case 0xa1:
                goto switchD_14009313c_caseD_a1;
              case 0xa2:
                goto switchD_14009313c_caseD_a2;
              case 0xa3:
                goto switchD_14009313c_caseD_a3;
              case 0xa4:
                goto switchD_14009313c_caseD_a4;
              case 0xa5:
                goto code_r0x000140096a82;
              case 0xa6:
                goto switchD_14009313c_caseD_a6;
              case 0xa7:
                goto switchD_14009313c_caseD_a7;
              case 0xa8:
                goto switchD_14009313c_caseD_a8;
              case 0xa9:
                goto switchD_14009313c_caseD_a9;
              case 0xaa:
                goto switchD_14009313c_caseD_aa;
              case 0xab:
                goto switchD_14009313c_caseD_ab;
              case 0xac:
                goto switchD_14009313c_caseD_ac;
              case 0xad:
                goto switchD_14009313c_caseD_ad;
              case 0xae:
                goto switchD_14009313c_caseD_ae;
              case 0xaf:
                goto switchD_14009313c_caseD_af;
              case 0xb0:
                goto switchD_14009313c_caseD_b0;
              case 0xb1:
                goto switchD_14009313c_caseD_b1;
              case 0xb2:
                goto switchD_14009313c_caseD_b2;
              case 0xb3:
                goto switchD_14009313c_caseD_b3;
              case 0xb4:
                goto switchD_14009313c_caseD_b4;
              case 0xb5:
                goto switchD_14009313c_caseD_b5;
              case 0xb6:
                goto switchD_14009313c_caseD_b6;
              case 0xb7:
                goto switchD_14009313c_caseD_b7;
              case 0xb8:
                goto LAB_140096ff6;
              case 0xb9:
                goto switchD_14009313c_caseD_b9;
              case 0xba:
                goto switchD_14009313c_caseD_ba;
              case 0xbb:
                goto switchD_14009313c_caseD_bb;
              case 0xbc:
                goto switchD_14009313c_caseD_bc;
              case 0xbd:
                goto switchD_14009313c_caseD_bd;
              case 0xbe:
                goto switchD_14009313c_caseD_be;
              case 0xbf:
                goto switchD_14009313c_caseD_bf;
              case 0xc0:
                goto switchD_14009313c_caseD_c0;
              case 0xc1:
                goto switchD_14009313c_caseD_c1;
              case 0xc2:
                goto switchD_14009313c_caseD_c2;
              case 0xc3:
                goto switchD_14009313c_caseD_c3;
              case 0xc4:
                goto switchD_14009313c_caseD_c4;
              case 0xc5:
                goto switchD_14009313c_caseD_c5;
              case 0xc6:
                goto switchD_14009313c_caseD_c6;
              case 199:
                goto switchD_14009313c_caseD_c7;
              case 200:
                goto switchD_14009313c_caseD_c8;
              case 0xc9:
                goto switchD_14009313c_caseD_c9;
              case 0xca:
                goto switchD_14009313c_caseD_ca;
              case 0xcb:
                goto switchD_14009313c_caseD_cb;
              case 0xcc:
                goto switchD_14009313c_caseD_cc;
              case 0xcd:
                goto switchD_14009313c_caseD_cd;
              case 0xce:
                goto switchD_14009313c_caseD_ce;
              case 0xcf:
                goto switchD_14009313c_caseD_cf;
              case 0xd0:
                goto switchD_14009313c_caseD_d0;
              case 0xd1:
                goto switchD_14009313c_caseD_d1;
              case 0xd2:
                goto switchD_14009313c_caseD_d2;
              case 0xd3:
                goto switchD_14009313c_caseD_d3;
              case 0xd4:
                goto switchD_14009313c_caseD_d4;
              case 0xd5:
                goto switchD_14009313c_caseD_d5;
              case 0xd6:
                goto switchD_14009313c_caseD_d6;
              case 0xd7:
                goto switchD_14009313c_caseD_d7;
              case 0xd8:
                goto switchD_14009313c_caseD_d8;
              case 0xd9:
                goto switchD_14009313c_caseD_d9;
              case 0xda:
                goto switchD_14009313c_caseD_da;
              case 0xdb:
                goto switchD_14009313c_caseD_db;
              case 0xdc:
                goto switchD_14009313c_caseD_dc;
              case 0xdd:
                goto switchD_14009313c_caseD_dd;
              case 0xde:
                goto switchD_14009313c_caseD_de;
              case 0xdf:
                goto switchD_14009313c_caseD_df;
              case 0xe0:
                goto switchD_14009313c_caseD_e0;
              case 0xe1:
                goto switchD_14009313c_caseD_e1;
              case 0xe2:
                goto code_r0x00018809782f;
              case 0xe3:
                goto switchD_14009313c_caseD_e3;
              case 0xe4:
                goto switchD_14009313c_caseD_e4;
              case 0xe5:
                goto switchD_14009313c_caseD_e5;
              case 0xe6:
                goto switchD_14009313c_caseD_e6;
              case 0xe7:
                goto switchD_14009313c_caseD_e7;
              case 0xe8:
                goto switchD_14009313c_caseD_e8;
              case 0xe9:
                goto switchD_14009313c_caseD_e9;
              case 0xea:
                goto switchD_14009313c_caseD_ea;
              case 0xeb:
                goto switchD_14009313c_caseD_eb;
              case 0xec:
                goto switchD_14009313c_caseD_ec;
              case 0xed:
                goto switchD_14009313c_caseD_ed;
              case 0xee:
                goto switchD_14009313c_caseD_ee;
              case 0xef:
              case 0xf1:
                goto switchD_14009313c_caseD_ef;
              case 0xf0:
                goto switchD_14009313c_caseD_f0;
              case 0xf2:
                goto switchD_14009313c_caseD_f2;
              case 0xf3:
                goto switchD_14009313c_caseD_f3;
              case 0xf4:
                goto switchD_14009313c_caseD_f4;
              case 0xf5:
                goto code_r0x000129041db4;
              case 0xf6:
                goto switchD_14009313c_caseD_f6;
              case 0xf7:
                goto switchD_14009313c_caseD_f7;
              case 0xf8:
                goto switchD_14009313c_caseD_f8;
              case 0xf9:
              case 0xfa:
                goto switchD_14009313c_caseD_f9;
              case 0xfb:
                goto switchD_14009313c_caseD_fb;
              case 0xfc:
                goto switchD_14009313c_caseD_fc;
              case 0xfd:
                goto switchD_14009313c_caseD_fd;
              case 0xfe:
              case 0xff:
                goto code_r0x00014010fd94;
              }
            case 0xd:
              goto switchD_14009313c_caseD_d;
            default:
              goto switchD_14009313c_caseD_e;
            case 0x12:
              goto switchD_14009313c_caseD_12;
            case 0x2a:
              goto switchD_14009313c_caseD_2a;
            case 0x39:
            case 0x3b:
              goto switchD_14009313c_caseD_39;
            case 0x3d:
              goto switchD_14009313c_caseD_3d;
            case 0x3f:
              goto switchD_14009313c_caseD_3f;
            case 0x40:
              goto switchD_14009313c_caseD_40;
            case 0x41:
              goto switchD_14009313c_caseD_41;
            case 0x42:
              goto switchD_14009313c_caseD_42;
            case 0x43:
              goto switchD_14009313c_caseD_43;
            case 0x44:
              goto switchD_14009313c_caseD_44;
            case 0x45:
              goto switchD_14009313c_caseD_45;
            case 0x46:
              goto code_r0x000140093b4f;
            case 0x47:
              goto switchD_14009313c_caseD_47;
            case 0x48:
              goto switchD_14009313c_caseD_48;
            case 0x49:
              goto switchD_14009313c_caseD_49;
            case 0x4a:
              goto switchD_14009313c_caseD_4a;
            case 0x4b:
              goto switchD_14009313c_caseD_4b;
            case 0x4c:
              goto switchD_14009313c_caseD_4c;
            case 0x4d:
              goto switchD_14009313c_caseD_4d;
            case 0x4e:
              goto switchD_14009313c_caseD_4e;
            case 0x4f:
              goto switchD_14009313c_caseD_4f;
            case 0x50:
              goto switchD_14009313c_caseD_50;
            case 0x51:
              goto switchD_14009313c_caseD_51;
            case 0x52:
              goto switchD_14009313c_caseD_52;
            case 0x53:
              goto switchD_14009313c_caseD_53;
            case 0x54:
              goto switchD_14009313c_caseD_54;
            case 0x55:
              goto switchD_14009313c_caseD_55;
            case 0x56:
              goto switchD_14009313c_caseD_56;
            case 0x57:
              goto switchD_14009313c_caseD_57;
            case 0x58:
              goto switchD_14009313c_caseD_58;
            case 0x59:
              goto switchD_14009313c_caseD_59;
            case 0x5a:
              goto switchD_14009313c_caseD_5a;
            case 0x5b:
              goto switchD_14009313c_caseD_5b;
            case 0x5c:
              goto switchD_14009313c_caseD_5c;
            case 0x5d:
              goto switchD_14009313c_caseD_5d;
            case 0x5e:
              goto switchD_14009313c_caseD_5e;
            case 0x5f:
              goto switchD_14009313c_caseD_5f;
            case 0x60:
            case 0x67:
              goto switchD_14009313c_caseD_60;
            case 0x61:
              goto switchD_14009313c_caseD_61;
            case 0x62:
            case 99:
            case 100:
              goto switchD_14009313c_caseD_62;
            case 0x65:
              goto switchD_14009313c_caseD_65;
            case 0x66:
              goto switchD_14009313c_caseD_66;
            case 0x68:
            case 0x6b:
            case 0x6d:
              goto switchD_14009313c_caseD_68;
            case 0x69:
            case 0x6a:
              goto switchD_14009313c_caseD_69;
            case 0x6c:
              goto switchD_14009313c_caseD_6c;
            case 0x6e:
              goto switchD_14009313c_caseD_6e;
            case 0x6f:
              goto switchD_14009313c_caseD_6f;
            case 0x70:
              goto switchD_14009313c_caseD_70;
            case 0x71:
              goto switchD_14009313c_caseD_71;
            case 0x72:
              goto switchD_14009313c_caseD_72;
            case 0x73:
              goto switchD_14009313c_caseD_73;
            case 0x74:
              goto switchD_14009313c_caseD_74;
            case 0x75:
              goto switchD_14009313c_caseD_75;
            case 0x76:
              goto switchD_14009313c_caseD_76;
            case 0x77:
              goto switchD_14009313c_caseD_77;
            case 0x78:
              goto switchD_14009313c_caseD_78;
            case 0x79:
              goto switchD_14009313c_caseD_79;
            case 0x7a:
              goto switchD_14009313c_caseD_7a;
            case 0x7b:
              goto switchD_14009313c_caseD_7b;
            case 0x7c:
              goto switchD_14009313c_caseD_7c;
            case 0x7d:
              goto switchD_14009313c_caseD_7d;
            case 0x7e:
              goto switchD_14009313c_caseD_7e;
            case 0x7f:
              goto switchD_14009313c_caseD_7f;
            case 0x80:
              goto switchD_14009313c_caseD_80;
            case 0x81:
              goto switchD_14009313c_caseD_81;
            case 0x82:
              goto switchD_14009313c_caseD_82;
            case 0x83:
              goto switchD_14009313c_caseD_83;
            case 0x84:
              goto switchD_14009313c_caseD_84;
            case 0x85:
              goto switchD_14009313c_caseD_85;
            case 0x86:
              goto switchD_14009313c_caseD_86;
            case 0x87:
              goto switchD_14009313c_caseD_87;
            case 0x88:
              goto switchD_14009313c_caseD_88;
            case 0x89:
              goto switchD_14009313c_caseD_89;
            case 0x8a:
              goto switchD_14009313c_caseD_8a;
            case 0x8b:
              goto switchD_14009313c_caseD_8b;
            case 0x8c:
              goto switchD_14009313c_caseD_8c;
            case 0x8d:
              goto switchD_14009313c_caseD_8d;
            case 0x8e:
              goto switchD_14009313c_caseD_8e;
            case 0x8f:
              goto switchD_14009313c_caseD_8f;
            case 0x90:
              goto switchD_14009313c_caseD_90;
            case 0x91:
              goto switchD_14009313c_caseD_91;
            case 0x92:
              goto code_r0x0001400969f5;
            case 0x93:
              goto switchD_14009313c_caseD_93;
            case 0x94:
              goto switchD_14009313c_caseD_94;
            case 0x95:
              goto switchD_14009313c_caseD_95;
            case 0x96:
              goto switchD_14009313c_caseD_96;
            case 0x97:
              goto switchD_14009313c_caseD_97;
            case 0x98:
              goto switchD_14009313c_caseD_98;
            case 0x99:
              goto switchD_14009313c_caseD_99;
            case 0x9a:
              goto switchD_14009313c_caseD_9a;
            case 0x9b:
              goto switchD_14009313c_caseD_9b;
            case 0x9c:
              goto switchD_14009313c_caseD_9c;
            case 0x9d:
              goto switchD_14009313c_caseD_9d;
            case 0x9e:
              goto switchD_14009313c_caseD_9e;
            case 0x9f:
              goto switchD_14009313c_caseD_9f;
            case 0xa0:
              goto switchD_14009313c_caseD_a0;
            case 0xa1:
              goto switchD_14009313c_caseD_a1;
            case 0xa2:
              goto switchD_14009313c_caseD_a2;
            case 0xa3:
              goto switchD_14009313c_caseD_a3;
            case 0xa4:
              goto switchD_14009313c_caseD_a4;
            case 0xa5:
              goto code_r0x000140096a82;
            case 0xa6:
              goto switchD_14009313c_caseD_a6;
            case 0xa7:
              goto switchD_14009313c_caseD_a7;
            case 0xa8:
              goto switchD_14009313c_caseD_a8;
            case 0xa9:
              goto switchD_14009313c_caseD_a9;
            case 0xaa:
              goto switchD_14009313c_caseD_aa;
            case 0xab:
              goto switchD_14009313c_caseD_ab;
            case 0xac:
              goto switchD_14009313c_caseD_ac;
            case 0xad:
              goto switchD_14009313c_caseD_ad;
            case 0xae:
              goto switchD_14009313c_caseD_ae;
            case 0xaf:
              goto switchD_14009313c_caseD_af;
            case 0xb0:
              goto switchD_14009313c_caseD_b0;
            case 0xb1:
              goto switchD_14009313c_caseD_b1;
            case 0xb2:
              goto switchD_14009313c_caseD_b2;
            case 0xb3:
              goto switchD_14009313c_caseD_b3;
            case 0xb4:
              goto switchD_14009313c_caseD_b4;
            case 0xb5:
              goto switchD_14009313c_caseD_b5;
            case 0xb6:
              goto switchD_14009313c_caseD_b6;
            case 0xb7:
              goto switchD_14009313c_caseD_b7;
            case 0xb8:
              goto LAB_140096ff6;
            case 0xb9:
              goto switchD_14009313c_caseD_b9;
            case 0xba:
              goto switchD_14009313c_caseD_ba;
            case 0xbb:
              goto switchD_14009313c_caseD_bb;
            case 0xbc:
              goto switchD_14009313c_caseD_bc;
            case 0xbd:
              goto switchD_14009313c_caseD_bd;
            case 0xbe:
              goto switchD_14009313c_caseD_be;
            case 0xbf:
              goto switchD_14009313c_caseD_bf;
            case 0xc0:
              goto switchD_14009313c_caseD_c0;
            case 0xc1:
              goto switchD_14009313c_caseD_c1;
            case 0xc2:
              goto switchD_14009313c_caseD_c2;
            case 0xc3:
              goto switchD_14009313c_caseD_c3;
            case 0xc4:
              goto switchD_14009313c_caseD_c4;
            case 0xc5:
              goto switchD_14009313c_caseD_c5;
            case 0xc6:
              goto switchD_14009313c_caseD_c6;
            case 199:
              goto switchD_14009313c_caseD_c7;
            case 200:
              goto switchD_14009313c_caseD_c8;
            case 0xc9:
              goto switchD_14009313c_caseD_c9;
            case 0xca:
              goto switchD_14009313c_caseD_ca;
            case 0xcb:
              goto switchD_14009313c_caseD_cb;
            case 0xcc:
              goto switchD_14009313c_caseD_cc;
            case 0xcd:
              goto switchD_14009313c_caseD_cd;
            case 0xce:
              goto switchD_14009313c_caseD_ce;
            case 0xcf:
              goto switchD_14009313c_caseD_cf;
            case 0xd0:
              goto switchD_14009313c_caseD_d0;
            case 0xd1:
              goto switchD_14009313c_caseD_d1;
            case 0xd2:
              goto switchD_14009313c_caseD_d2;
            case 0xd3:
              goto switchD_14009313c_caseD_d3;
            case 0xd4:
              goto switchD_14009313c_caseD_d4;
            case 0xd5:
              goto switchD_14009313c_caseD_d5;
            case 0xd6:
              goto switchD_14009313c_caseD_d6;
            case 0xd7:
              goto switchD_14009313c_caseD_d7;
            case 0xd8:
              goto switchD_14009313c_caseD_d8;
            case 0xd9:
              goto switchD_14009313c_caseD_d9;
            case 0xda:
              goto switchD_14009313c_caseD_da;
            case 0xdb:
              goto switchD_14009313c_caseD_db;
            case 0xdc:
              goto switchD_14009313c_caseD_dc;
            case 0xdd:
              goto switchD_14009313c_caseD_dd;
            case 0xde:
              goto switchD_14009313c_caseD_de;
            case 0xdf:
              goto switchD_14009313c_caseD_df;
            case 0xe0:
              goto switchD_14009313c_caseD_e0;
            case 0xe1:
              goto switchD_14009313c_caseD_e1;
            case 0xe2:
              goto code_r0x00018809782f;
            case 0xe3:
              goto switchD_14009313c_caseD_e3;
            case 0xe4:
              goto switchD_14009313c_caseD_e4;
            case 0xe5:
              goto switchD_14009313c_caseD_e5;
            case 0xe6:
              goto switchD_14009313c_caseD_e6;
            case 0xe7:
              goto switchD_14009313c_caseD_e7;
            case 0xe8:
              goto switchD_14009313c_caseD_e8;
            case 0xe9:
              goto switchD_14009313c_caseD_e9;
            case 0xea:
              goto switchD_14009313c_caseD_ea;
            case 0xeb:
              goto switchD_14009313c_caseD_eb;
            case 0xec:
              goto switchD_14009313c_caseD_ec;
            case 0xed:
              goto switchD_14009313c_caseD_ed;
            case 0xee:
              goto switchD_14009313c_caseD_ee;
            case 0xef:
            case 0xf1:
              goto switchD_14009313c_caseD_ef;
            case 0xf0:
              goto switchD_14009313c_caseD_f0;
            case 0xf2:
              goto switchD_14009313c_caseD_f2;
            case 0xf3:
              goto switchD_14009313c_caseD_f3;
            case 0xf4:
              goto switchD_14009313c_caseD_f4;
            case 0xf5:
              goto code_r0x000129041db4;
            case 0xf6:
              goto switchD_14009313c_caseD_f6;
            case 0xf7:
              goto switchD_14009313c_caseD_f7;
            case 0xf8:
              goto switchD_14009313c_caseD_f8;
            case 0xf9:
            case 0xfa:
              goto switchD_14009313c_caseD_f9;
            case 0xfb:
              goto switchD_14009313c_caseD_fb;
            case 0xfc:
              goto switchD_14009313c_caseD_fc;
            case 0xfd:
              goto switchD_14009313c_caseD_fd;
            case 0xfe:
            case 0xff:
              goto code_r0x00014010fd94;
            }
          case 0xb:
            goto switchD_14009313c_caseD_b;
          case 0xc:
            goto switchD_14009313c_caseD_c;
          case 0xd:
            goto switchD_14009313c_caseD_d;
          default:
            goto switchD_14009313c_caseD_e;
          case 0x12:
            goto switchD_14009313c_caseD_12;
          case 0x2a:
            goto switchD_14009313c_caseD_2a;
          case 0x39:
          case 0x3b:
            goto switchD_14009313c_caseD_39;
          case 0x3d:
            goto switchD_14009313c_caseD_3d;
          case 0x3f:
            goto switchD_14009313c_caseD_3f;
          case 0x40:
            goto switchD_14009313c_caseD_40;
          case 0x41:
            goto switchD_14009313c_caseD_41;
          case 0x42:
            goto switchD_14009313c_caseD_42;
          case 0x43:
            goto switchD_14009313c_caseD_43;
          case 0x44:
            goto switchD_14009313c_caseD_44;
          case 0x45:
            goto switchD_14009313c_caseD_45;
          case 0x46:
            goto code_r0x000140093b4f;
          case 0x47:
            goto switchD_14009313c_caseD_47;
          case 0x48:
            goto switchD_14009313c_caseD_48;
          case 0x49:
            goto switchD_14009313c_caseD_49;
          case 0x4a:
            goto switchD_14009313c_caseD_4a;
          case 0x4b:
            goto switchD_14009313c_caseD_4b;
          case 0x4c:
            goto switchD_14009313c_caseD_4c;
          case 0x4d:
            goto switchD_14009313c_caseD_4d;
          case 0x4e:
            goto switchD_14009313c_caseD_4e;
          case 0x4f:
            goto switchD_14009313c_caseD_4f;
          case 0x50:
            goto switchD_14009313c_caseD_50;
          case 0x51:
            goto switchD_14009313c_caseD_51;
          case 0x52:
            goto switchD_14009313c_caseD_52;
          case 0x53:
            goto switchD_14009313c_caseD_53;
          case 0x54:
            goto switchD_14009313c_caseD_54;
          case 0x55:
            goto switchD_14009313c_caseD_55;
          case 0x56:
            goto switchD_14009313c_caseD_56;
          case 0x57:
            goto switchD_14009313c_caseD_57;
          case 0x58:
            goto switchD_14009313c_caseD_58;
          case 0x59:
            goto switchD_14009313c_caseD_59;
          case 0x5a:
            goto switchD_14009313c_caseD_5a;
          case 0x5b:
            goto switchD_14009313c_caseD_5b;
          case 0x5c:
            goto switchD_14009313c_caseD_5c;
          case 0x5d:
            goto switchD_14009313c_caseD_5d;
          case 0x5e:
            goto switchD_14009313c_caseD_5e;
          case 0x5f:
            goto switchD_14009313c_caseD_5f;
          case 0x60:
          case 0x67:
            goto switchD_14009313c_caseD_60;
          case 0x61:
            goto switchD_14009313c_caseD_61;
          case 0x62:
          case 99:
          case 100:
            goto switchD_14009313c_caseD_62;
          case 0x65:
            goto switchD_14009313c_caseD_65;
          case 0x66:
            goto switchD_14009313c_caseD_66;
          case 0x68:
          case 0x6b:
          case 0x6d:
            goto switchD_14009313c_caseD_68;
          case 0x69:
          case 0x6a:
            goto switchD_14009313c_caseD_69;
          case 0x6c:
            goto switchD_14009313c_caseD_6c;
          case 0x6e:
            goto switchD_14009313c_caseD_6e;
          case 0x6f:
            goto switchD_14009313c_caseD_6f;
          case 0x70:
            goto switchD_14009313c_caseD_70;
          case 0x71:
            goto switchD_14009313c_caseD_71;
          case 0x72:
            goto switchD_14009313c_caseD_72;
          case 0x73:
            goto switchD_14009313c_caseD_73;
          case 0x74:
            goto switchD_14009313c_caseD_74;
          case 0x75:
            goto switchD_14009313c_caseD_75;
          case 0x76:
            goto switchD_14009313c_caseD_76;
          case 0x77:
            goto switchD_14009313c_caseD_77;
          case 0x78:
            goto switchD_14009313c_caseD_78;
          case 0x79:
            goto switchD_14009313c_caseD_79;
          case 0x7a:
            goto switchD_14009313c_caseD_7a;
          case 0x7b:
            goto switchD_14009313c_caseD_7b;
          case 0x7c:
            goto switchD_14009313c_caseD_7c;
          case 0x7d:
            goto switchD_14009313c_caseD_7d;
          case 0x7e:
            goto switchD_14009313c_caseD_7e;
          case 0x7f:
            goto switchD_14009313c_caseD_7f;
          case 0x80:
            goto switchD_14009313c_caseD_80;
          case 0x81:
            goto switchD_14009313c_caseD_81;
          case 0x82:
            goto switchD_14009313c_caseD_82;
          case 0x83:
            goto switchD_14009313c_caseD_83;
          case 0x84:
            goto switchD_14009313c_caseD_84;
          case 0x85:
            goto switchD_14009313c_caseD_85;
          case 0x86:
            goto switchD_14009313c_caseD_86;
          case 0x87:
            goto switchD_14009313c_caseD_87;
          case 0x88:
            goto switchD_14009313c_caseD_88;
          case 0x89:
            goto switchD_14009313c_caseD_89;
          case 0x8a:
            goto switchD_14009313c_caseD_8a;
          case 0x8b:
            goto switchD_14009313c_caseD_8b;
          case 0x8c:
            goto switchD_14009313c_caseD_8c;
          case 0x8d:
            goto switchD_14009313c_caseD_8d;
          case 0x8e:
            goto switchD_14009313c_caseD_8e;
          case 0x8f:
            goto switchD_14009313c_caseD_8f;
          case 0x90:
            goto switchD_14009313c_caseD_90;
          case 0x91:
            goto switchD_14009313c_caseD_91;
          case 0x92:
            goto code_r0x0001400969f5;
          case 0x93:
            goto switchD_14009313c_caseD_93;
          case 0x94:
            goto switchD_14009313c_caseD_94;
          case 0x95:
            goto switchD_14009313c_caseD_95;
          case 0x96:
            goto switchD_14009313c_caseD_96;
          case 0x97:
            goto switchD_14009313c_caseD_97;
          case 0x98:
            goto switchD_14009313c_caseD_98;
          case 0x99:
            goto switchD_14009313c_caseD_99;
          case 0x9a:
            goto switchD_14009313c_caseD_9a;
          case 0x9b:
            goto switchD_14009313c_caseD_9b;
          case 0x9c:
            goto switchD_14009313c_caseD_9c;
          case 0x9d:
            goto switchD_14009313c_caseD_9d;
          case 0x9e:
            goto switchD_14009313c_caseD_9e;
          case 0x9f:
            goto switchD_14009313c_caseD_9f;
          case 0xa0:
            goto switchD_14009313c_caseD_a0;
          case 0xa1:
            goto switchD_14009313c_caseD_a1;
          case 0xa2:
            goto switchD_14009313c_caseD_a2;
          case 0xa3:
            goto switchD_14009313c_caseD_a3;
          case 0xa4:
            goto switchD_14009313c_caseD_a4;
          case 0xa5:
            goto code_r0x000140096a82;
          case 0xa6:
            goto switchD_14009313c_caseD_a6;
          case 0xa7:
            goto switchD_14009313c_caseD_a7;
          case 0xa8:
            goto switchD_14009313c_caseD_a8;
          case 0xa9:
            goto switchD_14009313c_caseD_a9;
          case 0xaa:
            goto switchD_14009313c_caseD_aa;
          case 0xab:
            goto switchD_14009313c_caseD_ab;
          case 0xac:
            goto switchD_14009313c_caseD_ac;
          case 0xad:
            goto switchD_14009313c_caseD_ad;
          case 0xae:
            goto switchD_14009313c_caseD_ae;
          case 0xaf:
            goto switchD_14009313c_caseD_af;
          case 0xb0:
            goto switchD_14009313c_caseD_b0;
          case 0xb1:
            goto switchD_14009313c_caseD_b1;
          case 0xb2:
            goto switchD_14009313c_caseD_b2;
          case 0xb3:
            goto switchD_14009313c_caseD_b3;
          case 0xb4:
            goto switchD_14009313c_caseD_b4;
          case 0xb5:
            goto switchD_14009313c_caseD_b5;
          case 0xb6:
            goto switchD_14009313c_caseD_b6;
          case 0xb7:
            goto switchD_14009313c_caseD_b7;
          case 0xb8:
            goto LAB_140096ff6;
          case 0xb9:
            goto switchD_14009313c_caseD_b9;
          case 0xba:
            goto switchD_14009313c_caseD_ba;
          case 0xbb:
            goto switchD_14009313c_caseD_bb;
          case 0xbc:
            goto switchD_14009313c_caseD_bc;
          case 0xbd:
            goto switchD_14009313c_caseD_bd;
          case 0xbe:
            goto switchD_14009313c_caseD_be;
          case 0xbf:
            goto switchD_14009313c_caseD_bf;
          case 0xc0:
            goto switchD_14009313c_caseD_c0;
          case 0xc1:
            goto switchD_14009313c_caseD_c1;
          case 0xc2:
            goto switchD_14009313c_caseD_c2;
          case 0xc3:
            goto switchD_14009313c_caseD_c3;
          case 0xc4:
            goto switchD_14009313c_caseD_c4;
          case 0xc5:
            goto switchD_14009313c_caseD_c5;
          case 0xc6:
            goto switchD_14009313c_caseD_c6;
          case 199:
            goto switchD_14009313c_caseD_c7;
          case 200:
            goto switchD_14009313c_caseD_c8;
          case 0xc9:
            goto switchD_14009313c_caseD_c9;
          case 0xca:
            goto switchD_14009313c_caseD_ca;
          case 0xcb:
            goto switchD_14009313c_caseD_cb;
          case 0xcc:
            goto switchD_14009313c_caseD_cc;
          case 0xcd:
            goto switchD_14009313c_caseD_cd;
          case 0xce:
            goto switchD_14009313c_caseD_ce;
          case 0xcf:
            goto switchD_14009313c_caseD_cf;
          case 0xd0:
            goto switchD_14009313c_caseD_d0;
          case 0xd1:
            goto switchD_14009313c_caseD_d1;
          case 0xd2:
            goto switchD_14009313c_caseD_d2;
          case 0xd3:
            goto switchD_14009313c_caseD_d3;
          case 0xd4:
            goto switchD_14009313c_caseD_d4;
          case 0xd5:
            goto switchD_14009313c_caseD_d5;
          case 0xd6:
            goto switchD_14009313c_caseD_d6;
          case 0xd7:
            goto switchD_14009313c_caseD_d7;
          case 0xd8:
            goto switchD_14009313c_caseD_d8;
          case 0xd9:
            goto switchD_14009313c_caseD_d9;
          case 0xda:
            goto switchD_14009313c_caseD_da;
          case 0xdb:
            goto switchD_14009313c_caseD_db;
          case 0xdc:
            goto switchD_14009313c_caseD_dc;
          case 0xdd:
            goto switchD_14009313c_caseD_dd;
          case 0xde:
            goto switchD_14009313c_caseD_de;
          case 0xdf:
            goto switchD_14009313c_caseD_df;
          case 0xe0:
            goto switchD_14009313c_caseD_e0;
          case 0xe1:
            goto switchD_14009313c_caseD_e1;
          case 0xe2:
            goto code_r0x00018809782f;
          case 0xe3:
            goto switchD_14009313c_caseD_e3;
          case 0xe4:
            goto switchD_14009313c_caseD_e4;
          case 0xe5:
            goto switchD_14009313c_caseD_e5;
          case 0xe6:
            goto switchD_14009313c_caseD_e6;
          case 0xe7:
            goto switchD_14009313c_caseD_e7;
          case 0xe8:
            goto switchD_14009313c_caseD_e8;
          case 0xe9:
            goto switchD_14009313c_caseD_e9;
          case 0xea:
            goto switchD_14009313c_caseD_ea;
          case 0xeb:
            goto switchD_14009313c_caseD_eb;
          case 0xec:
            goto switchD_14009313c_caseD_ec;
          case 0xed:
            goto switchD_14009313c_caseD_ed;
          case 0xee:
            goto switchD_14009313c_caseD_ee;
          case 0xef:
          case 0xf1:
            goto switchD_14009313c_caseD_ef;
          case 0xf0:
            goto switchD_14009313c_caseD_f0;
          case 0xf2:
            goto switchD_14009313c_caseD_f2;
          case 0xf3:
            goto switchD_14009313c_caseD_f3;
          case 0xf4:
            goto switchD_14009313c_caseD_f4;
          case 0xf5:
            goto code_r0x000129041db4;
          case 0xf6:
            goto switchD_14009313c_caseD_f6;
          case 0xf7:
            goto switchD_14009313c_caseD_f7;
          case 0xf8:
            goto switchD_14009313c_caseD_f8;
          case 0xf9:
          case 0xfa:
            goto switchD_14009313c_caseD_f9;
          case 0xfb:
            goto switchD_14009313c_caseD_fb;
          case 0xfc:
            goto switchD_14009313c_caseD_fc;
          case 0xfd:
            goto switchD_14009313c_caseD_fd;
          case 0xfe:
          case 0xff:
            goto code_r0x00014010fd94;
          }
        case 10:
          goto switchD_14009313c_caseD_a;
        case 0xb:
          goto switchD_14009313c_caseD_b;
        case 0xc:
          goto switchD_14009313c_caseD_c;
        case 0xd:
          goto switchD_14009313c_caseD_d;
        default:
switchD_14009313c_caseD_e:
          puVar97 = (uint *)((longlong)&UINT_14010fd90 + 3);
          if (bVar239) {
            pfVar168[-1].fd_array[0x3f] = (SOCKET)param_3;
            pfVar168[-1].fd_array[0x3e] = (SOCKET)param_2;
            pfVar168 = (fd_set *)(pfVar168[-1].fd_array + 0x3a);
            goto switchD_14009313c_caseD_39;
          }
          goto switchD_140093542_caseD_2f;
        case 0x12:
switchD_14009313c_caseD_12:
          pfVar84 = (fd_set *)FUN_1400935f3((undefined8 *)(ulonglong)((int)puVar225 + 8));
          return pfVar84;
        case 0x2a:
switchD_14009313c_caseD_2a:
          pcVar83 = (char *)((longlong)&UINT_14010fdf4 + uVar81 + 3);
          *pcVar83 = *pcVar83 + -0x6c;
          UNRECOVERED_JUMPTABLE = (code *)CONCAT71(uVar86,bVar64 + 0x81);
          goto code_r0x000140093534;
        case 0x39:
        case 0x3b:
switchD_14009313c_caseD_39:
          _Dst = *(uint **)puVar97;
          puVar126 = (undefined8 *)pfVar168;
          pcVar83 = (char *)puVar97;
          param_3 = (fd_set *)_Dst;
          goto code_r0x00014009351d;
        case 0x3d:
switchD_14009313c_caseD_3d:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          pcVar83 = (char *)((longlong)&UINT_14010fda0 + uVar81 + 3);
          *pcVar83 = *pcVar83 + -0x6c;
          puVar95 = (ulonglong *)((longlong)&UINT_14010fd14 + uVar81 + 3);
          *puVar95 = *puVar95 >> 0x38 | *puVar95 << 8;
          pbVar2 = (byte *)((longlong)param_3->fd_array + 0x23);
          *pbVar2 = *pbVar2 ^ (byte)((ulonglong)_Src >> 8);
          goto code_r0x000140093534;
        case 0x3f:
          goto switchD_14009313c_caseD_3f;
        case 0x40:
          goto switchD_14009313c_caseD_40;
        case 0x41:
switchD_14009313c_caseD_41:
          goto code_r0x0001400938e4;
        case 0x42:
          goto switchD_14009313c_caseD_42;
        case 0x43:
switchD_14009313c_caseD_43:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(char *)&param_3->fd_count = (char)param_3->fd_count + -0x6c;
          *(int *)(pfVar168->fd_array + 7) = (int)pfVar168->fd_array[7] + -0x4010fd94;
          goto LAB_140093b63;
        case 0x44:
switchD_14009313c_caseD_44:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto code_r0x000140093863;
        case 0x45:
switchD_14009313c_caseD_45:
          UNRECOVERED_JUMPTABLE = (code *)CONCAT71(uVar86,bVar64 - 0x10);
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (bVar64 - 0x10);
        case 0x46:
          goto code_r0x000140093b4f;
        case 0x47:
          goto switchD_14009313c_caseD_47;
        case 0x48:
          goto switchD_14009313c_caseD_48;
        case 0x49:
          goto switchD_14009313c_caseD_49;
        case 0x4a:
switchD_14009313c_caseD_4a:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto switchD_14009313c_caseD_48;
        case 0x4b:
switchD_14009313c_caseD_4b:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          uVar15 = param_3->fd_count;
          *(char *)&param_3->fd_count = (char)param_3->fd_count + -0x6c;
          *(char *)(pfVar168->fd_array + 0x11) =
               (char)pfVar168->fd_array[0x11] + -0x6c + (0x6b < (byte)uVar15);
          goto LAB_140093b63;
        case 0x4c:
switchD_14009313c_caseD_4c:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x4d:
switchD_14009313c_caseD_4d:
          pcVar83 = (char *)((longlong)&UINT_14010fd1c + uVar81 + 1);
          *pcVar83 = *pcVar83 + -0x6c;
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff50);
          goto LAB_140093b63;
        case 0x4e:
          goto switchD_14009313c_caseD_4e;
        case 0x4f:
switchD_14009313c_caseD_4f:
          uVar81 = uVar81 + 0x14010fe6b;
          goto LAB_140093c84;
        case 0x50:
switchD_14009313c_caseD_50:
          if (bVar240) {
            cRam00000001319a4a6b = cRam00000001319a4a6b + -0x6c;
            goto code_r0x000140093d5b;
          }
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          puVar97 = &param_1->fd_count;
          goto code_r0x000140093d56;
        case 0x51:
          goto switchD_14009313c_caseD_51;
        case 0x52:
switchD_14009313c_caseD_52:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x53:
switchD_14009313c_caseD_53:
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff31);
          goto LAB_140093fa0;
        case 0x54:
switchD_14009313c_caseD_54:
          *(uint *)(pfVar168->fd_array + 0xb) = uVar69;
          goto code_r0x00014009408b;
        case 0x55:
switchD_14009313c_caseD_55:
          uVar15 = param_3->fd_count;
          *(char *)&param_3->fd_count = (char)param_3->fd_count + 'l';
          *(uint *)(((fd_set *)puVar225)->fd_array + 2) =
               (int)((fd_set *)puVar225)->fd_array[2] + uVar69 + (uint)((byte)uVar15 < 0x94);
          goto LAB_140093fc4;
        case 0x56:
switchD_14009313c_caseD_56:
          cRam000000004010fd94 = cRam000000004010fd94 + -0x6c;
          pcVar103 = (char *)((ulonglong)_Src & 0xff);
          piVar80 = (int *)(((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff) - 0x73);
          *piVar80 = *piVar80 + uVar69;
          goto code_r0x00014009402c;
        case 0x57:
switchD_14009313c_caseD_57:
          writefds = (uint *)(0x4010fd94 % (ulonglong)writefds);
          param_4 = (fd_set *)0x190;
          goto code_r0x000140094376;
        case 0x58:
switchD_14009313c_caseD_58:
          *(byte *)(pfVar168->fd_array + 3) = (char)pfVar168->fd_array[3] + bVar64 + bVar238;
LAB_14009444e:
          pfVar84 = *(fd_set **)((longlong)pfVar168 + 0x50);
          ((fd_set *)puVar225)->fd_array[5] = (SOCKET)pfVar84;
          uVar241 = *(undefined8 *)((longlong)pfVar168 + 0x20);
          SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x28);
          SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x30);
          SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x38);
          SVar8 = *(SOCKET *)((longlong)pfVar168 + 0x48);
          ((fd_set *)puVar225)->fd_array[3] = *(SOCKET *)((longlong)pfVar168 + 0x40);
          ((fd_set *)puVar225)->fd_array[4] = SVar8;
          ((fd_set *)puVar225)->fd_array[1] = SVar76;
          ((fd_set *)puVar225)->fd_array[2] = SVar236;
          *(undefined8 *)puVar225 = uVar241;
          ((fd_set *)puVar225)->fd_array[0] = SVar82;
          return pfVar84;
        case 0x59:
switchD_14009313c_caseD_59:
          pfVar107 = (fd_set *)(pfVar168[-1].fd_array + 0x3b);
          _Src = (uint *)CONCAT53(ram0x00014010fda7,(undefined3)UINT_14010fda4);
          pfVar84 = (fd_set *)
                    (CONCAT71(ram0x00014010fd95,(undefined1)switchD_14009313c::caseD_fe) -
                    (longlong)_Src);
          if (pfVar72 <= pfVar84) {
            return pfVar84;
          }
          pfVar168[-1].fd_array[0x3f] = 0x18;
          param_4 = (fd_set *)&DAT_00000008;
code_r0x0001400943f9:
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400943fe;
          pfVar84 = (fd_set *)
                    FUN_1400c6110((ulonglong *)puVar97,(ulonglong)_Src,(ulonglong)pfVar72,
                                  (ulonglong)param_4,*(ulonglong *)((longlong)pfVar107 + 0x20));
          return pfVar84;
        case 0x5a:
switchD_14009313c_caseD_5a:
          pfVar84 = pfVar168 + -1;
          puVar225 = &switchD_14009313c::caseD_fe;
          param_1 = (fd_set *)0x8000000000000033;
          if (*(longlong *)_Src != 0) {
            UNRECOVERED_JUMPTABLE = (code *)((fd_set *)_Src)->fd_array[1];
            param_3 = (fd_set *)_Src;
            if ((fd_set *)UNRECOVERED_JUMPTABLE != (fd_set *)((fd_set *)_Src)->fd_array[0]) {
              pfVar233 = pfVar168 + -1;
              pfVar168[-1].fd_array[0x34] = 0x140094442;
              FUN_14009488e(pfVar233->fd_array + 0x39,(longlong *)_Src);
              pfVar168 = (fd_set *)(pfVar168[-1].fd_array + 0x35);
              if (pfVar233->fd_array[0x39] != 0x8000000000000032) {
                *(undefined8 *)_Src = 0;
                pfVar168 = (fd_set *)(pfVar84->fd_array + 0x35);
              }
              goto LAB_14009444e;
            }
code_r0x000140094429:
            *(undefined8 *)param_3 = 0;
          }
          *(fd_set **)puVar225 = param_1;
          return (fd_set *)UNRECOVERED_JUMPTABLE;
        case 0x5b:
          goto switchD_14009313c_caseD_5b;
        case 0x5c:
switchD_14009313c_caseD_5c:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x5d:
switchD_14009313c_caseD_5d:
          param_2 = (undefined **)((ulonglong)_Src & 0xffffffff);
          *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400948c7;
          uVar81 = FUN_140019e50((longlong)param_3);
          bVar239 = (uVar81 & 1) == 0;
code_r0x0001400948c9:
          if (!bVar239) goto switchD_14009492e_default;
code_r0x0001400948cf:
          uVar69 = (uint)_Src;
          bVar238 = (byte)_Src;
          pcVar83 = (char *)puVar225;
          if ((char)bVar238 < '\0') goto LAB_14009490f;
          goto LAB_1400948d3;
        case 0x5e:
          goto switchD_14009313c_caseD_5e;
        case 0x5f:
switchD_14009313c_caseD_5f:
          UNRECOVERED_JUMPTABLE = (code *)swi(1);
          pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
          return pfVar84;
        case 0x60:
        case 0x67:
switchD_14009313c_caseD_60:
          ((fd_set *)((longlong)puVar223 + 0x50043f6c0))->field_0x4 =
               ((fd_set *)((longlong)puVar223 + 0x50043f6c0))->field_0x4 + -0x6c;
          bVar239 = false;
          goto LAB_1400947ee;
        case 0x61:
switchD_14009313c_caseD_61:
          pfVar234 = (fd_set *)((longlong)&param_3->fd_count + 1);
          uVar63 = in((short)_Src);
          *(undefined1 *)&param_3->fd_count = uVar63;
          goto LAB_140094786;
        case 0x62:
        case 99:
        case 100:
switchD_14009313c_caseD_62:
          LOCK();
          puVar223 = (uint *)((longlong)&((fd_set *)puVar223)->fd_count + 1);
          uVar70 = *puVar223;
          *puVar223 = uVar69;
          pcVar83 = (char *)CONCAT44((int)((ulonglong)UNRECOVERED_JUMPTABLE >> 0x20),uVar70);
          UNLOCK();
          *pcVar83 = *pcVar83 + (char)uVar70;
          goto code_r0x000140094920;
        case 0x65:
switchD_14009313c_caseD_65:
          uVar69 = (uint)_Src & 0xff;
LAB_14009490f:
          uVar69 = (uVar69 & 0xff) - 0x81;
          pcVar83 = (char *)(ulonglong)uVar69;
          if (uVar69 < 4) {
code_r0x000140094920:
                    /* WARNING: Could not recover jumptable at 0x00014009492e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            pfVar84 = (fd_set *)
                      (*(code *)((longlong)&switchD_14009492e::switchdataD_14010ff04 +
                                (longlong)
                                (int)(&switchD_14009492e::switchdataD_14010ff04)[(longlong)pcVar83])
                      )();
            return pfVar84;
          }
          goto switchD_14009492e_default;
        case 0x66:
switchD_14009313c_caseD_66:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x68:
        case 0x6b:
        case 0x6d:
          goto switchD_14009313c_caseD_68;
        case 0x69:
        case 0x6a:
switchD_14009313c_caseD_69:
          _Dst = (uint *)0x4010ff14;
          goto code_r0x0001400948fe;
        case 0x6c:
switchD_14009313c_caseD_6c:
          pfVar168[-1].fd_array[0x3f] = (SOCKET)puVar223;
          goto switchD_140094905_caseD_82;
        case 0x6e:
switchD_14009313c_caseD_6e:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x6f:
switchD_14009313c_caseD_6f:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x70:
          goto switchD_14009313c_caseD_70;
        case 0x71:
          goto switchD_14009313c_caseD_71;
        case 0x72:
switchD_14009313c_caseD_72:
          *(undefined2 *)
           ((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array + (longlong)puVar223 * 4 + -8) =
               in_FS;
          ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
          pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Src + 0x2182390))->fd_array + 0xf4);
          *pcVar83 = *pcVar83 + -0x6c;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          pfVar160 = pfVar168;
          goto code_r0x00014009588d;
        case 0x73:
          goto switchD_14009313c_caseD_73;
        case 0x74:
switchD_14009313c_caseD_74:
          piVar80 = (int *)((longlong)((fd_set *)((longlong)puVar223 + -0x208))->fd_array + 0x184);
          *piVar80 = *piVar80 + uVar69;
          pfVar224 = *(fd_set **)puVar223;
          pSVar163 = ((fd_set *)puVar223)->fd_array;
          goto code_r0x000140095b76;
        case 0x75:
switchD_14009313c_caseD_75:
          pcVar83 = (char *)((longlong)&switchD_14007fde0::switchdataD_14010fd20 + uVar81 + 1);
          *pcVar83 = *pcVar83 + -0x6c;
          pSVar163 = (SOCKET *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
          _Src = (uint *)CONCAT62((int6)((ulonglong)_Src >> 0x10),
                                  CONCAT11((char)((ulonglong)_Src >> 8) + (char)uVar70,(char)_Src));
          *(byte *)&((fd_set *)param_2)->fd_count = (byte)((fd_set *)param_2)->fd_count | 0x94;
          pcVar83 = (char *)(fd_set *)puVar225;
          goto code_r0x000140095bb4;
        case 0x76:
switchD_14009313c_caseD_76:
          *(longlong *)writefds =
               (longlong)((fd_set *)writefds)->fd_array + *(longlong *)writefds + -8;
          *(char *)&param_3->fd_count = (char)param_3->fd_count + -0x6f;
          _Dst = (uint *)CONCAT62((int6)((ulonglong)_Src >> 0x10),CONCAT11(0xc0,(char)_Src));
          switch(uVar69) {
          case 0x81:
            if (pfVar233 < (fd_set *)((longlong)&uRam0000000000000000 + 3))
            goto switchD_14009543b_default;
            pfVar168->fd_array[0x2f] = 3;
            bVar238 = *(byte *)((longlong)&pfVar84->fd_count + 2);
            UNRECOVERED_JUMPTABLE = (code *)(ulonglong)bVar238;
            bVar237 = (char)bVar238 < '\0';
            _Src = _Dst;
switchD_14009313c_caseD_70:
            _Dst = _Src;
            if (!bVar237) goto switchD_14009543b_default;
LAB_1400952e8:
            _Dst = (uint *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xff);
            pcVar83 = (char *)puVar225;
            goto LAB_1400952eb;
          case 0x82:
            if ((pfVar233 < (fd_set *)((longlong)&uRam0000000000000000 + 3)) ||
               (pfVar168->fd_array[0x2f] = 3,
               pfVar233 == (fd_set *)((longlong)&uRam0000000000000000 + 3)))
            goto switchD_14009543b_default;
            cVar89 = *(char *)((longlong)&pfVar84->fd_count + 2);
            goto code_r0x000140095723;
          case 0x83:
            if ((pfVar233 < (fd_set *)((longlong)&uRam0000000000000000 + 3)) ||
               (pfVar168->fd_array[0x2f] = 3,
               pfVar233 == (fd_set *)((longlong)&uRam0000000000000000 + 3)))
            goto switchD_14009543b_default;
            bVar238 = *(byte *)((longlong)&pfVar84->fd_count + 2);
            pfVar168->fd_array[0x2f] = 4;
            if (pfVar233 < (fd_set *)&DAT_00000005) goto switchD_14009543b_default;
            bVar90 = *(byte *)((longlong)&pfVar84->fd_count + 3);
            _Dst = (uint *)(ulonglong)bVar90;
            pfVar168->fd_array[0x2f] = 5;
            if (bVar238 == 0) goto switchD_14009543b_default;
            _Dst = (uint *)((ulonglong)((uint)bVar90 << 8 | (uint)bVar238 << 0x10) |
                           (ulonglong)(byte)pfVar84->field_0x4);
            goto LAB_140095743;
          case 0x84:
            if ((pfVar233 < (fd_set *)((longlong)&uRam0000000000000000 + 3)) ||
               (pfVar168->fd_array[0x2f] = 3,
               pfVar233 == (fd_set *)((longlong)&uRam0000000000000000 + 3)))
            goto switchD_14009543b_default;
            UNRECOVERED_JUMPTABLE = (code *)(ulonglong)*(byte *)((longlong)&pfVar84->fd_count + 2);
            pfVar168->fd_array[0x2f] = 4;
            if (pfVar233 < (fd_set *)&DAT_00000005) goto switchD_14009543b_default;
            uVar70 = (uint)*(byte *)((longlong)&pfVar84->fd_count + 3);
            pfVar168->fd_array[0x2f] = 5;
            if (pfVar233 == (fd_set *)&DAT_00000005) goto switchD_14009543b_default;
            _Src = (uint *)(ulonglong)(byte)pfVar84->field_0x4;
            pfVar168->fd_array[0x2f] = 6;
            bVar239 = (fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0;
            break;
          default:
            goto switchD_14009543b_default;
          }
          goto code_r0x0001400956e1;
        case 0x77:
switchD_14009313c_caseD_77:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto code_r0x000140095809;
        case 0x78:
switchD_14009313c_caseD_78:
          uVar81 = (longlong)
                   ((longlong)_Src << 0x20 | (ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff) %
                   (longlong)(int)uVar226 & 0xffffffff;
          unique0x0000d400 = ram0x00014010fda3 + 1;
          *(char *)&param_3->fd_count = (char)param_3->fd_count + -0x6d;
          puVar1 = (undefined4 *)(CONCAT62((int6)(uVar81 >> 0x10),CONCAT11(0x47,(char)uVar81)) + -9)
          ;
          *puVar1 = *puVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x79:
switchD_14009313c_caseD_79:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x7a:
switchD_14009313c_caseD_7a:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto LAB_140095cbc;
        case 0x7b:
switchD_14009313c_caseD_7b:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x7c:
switchD_14009313c_caseD_7c:
          cVar89 = bVar64 + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
          pcVar83 = (char *)CONCAT71(uVar86,cVar89);
          pcVar83[-0x77] = pcVar83[-0x77] + -0x6c;
          *(undefined2 *)(pcVar83 + (longlong)param_2 * 4) = in_FS;
          *pcVar83 = *pcVar83 + cVar89;
          pcVar83[-0x77] = pcVar83[-0x77] + -0x6c;
          *pcVar83 = *pcVar83 + cVar89;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x7d:
          goto switchD_14009313c_caseD_7d;
        case 0x7e:
switchD_14009313c_caseD_7e:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto code_r0x0001400966cd;
        case 0x7f:
switchD_14009313c_caseD_7f:
          goto code_r0x0001400967fa;
        case 0x80:
switchD_14009313c_caseD_80:
          cVar89 = bVar64 + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
          uVar81 = CONCAT71(uVar86,cVar89);
          *(char *)(((fd_set *)((longlong)param_2 + 0x1e741eb8))->fd_array + 7) =
               (char)((fd_set *)((longlong)param_2 + 0x1e741eb8))->fd_array[7] + cVar89;
          goto code_r0x00014009671d;
        case 0x81:
          goto switchD_14009313c_caseD_81;
        case 0x82:
          goto switchD_14009313c_caseD_82;
        case 0x83:
switchD_14009313c_caseD_83:
          pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Src + 0x11023d0))->fd_array + 0xac);
          *pcVar83 = *pcVar83 + -0x6c;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto code_r0x00014009635d;
        case 0x84:
switchD_14009313c_caseD_84:
          *(undefined4 *)(pfVar168->fd_array + 0x17) = 0x4010fd94;
          goto code_r0x0001400962df;
        case 0x85:
switchD_14009313c_caseD_85:
          pcVar83 = (char *)((longlong)&UINT_14010fd1c + uVar81 + 1);
          *pcVar83 = *pcVar83 + -0x6c;
          puVar170 = (undefined1 *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)pfVar168 & 0xffffffffffffff80);
          ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
          switchD_14007fde0::switchdataD_14010fd20._1_1_ =
               switchD_14007fde0::switchdataD_14010fd20._1_1_ + -0x6c;
          pfVar168 = (fd_set *)puVar170;
          if (switchD_14007fde0::switchdataD_14010fd20._1_1_ == '\0') goto code_r0x00014009635d;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x86:
          goto switchD_14009313c_caseD_86;
        case 0x87:
switchD_14009313c_caseD_87:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x88:
          goto switchD_14009313c_caseD_88;
        case 0x89:
switchD_14009313c_caseD_89:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x8a:
          goto switchD_14009313c_caseD_8a;
        case 0x8b:
          goto switchD_14009313c_caseD_8b;
        case 0x8c:
switchD_14009313c_caseD_8c:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto switchD_1400944c0_caseD_3a;
        case 0x8d:
switchD_14009313c_caseD_8d:
          cRam0000000140b12218 = cRam0000000140b12218 + -0x6c;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto LAB_140096a64;
        case 0x8e:
          goto switchD_14009313c_caseD_8e;
        case 0x8f:
switchD_14009313c_caseD_8f:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x90:
switchD_14009313c_caseD_90:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x91:
switchD_14009313c_caseD_91:
          goto code_r0x00014009699a;
        case 0x92:
code_r0x0001400969f5:
          bVar239 = uVar226 < 2;
          bVar237 = uVar226 == 2;
          goto code_r0x0001400969f8;
        case 0x93:
switchD_14009313c_caseD_93:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          puVar97 = (uint *)0xe0;
          UNRECOVERED_JUMPTABLE =
               (code *)(ulonglong)(uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
switchD_1400944c0_caseD_3a:
          pcVar83 = (char *)((longlong)
                             ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x3b498))->fd_array +
                            0x49);
          *pcVar83 = *pcVar83 + (char)UNRECOVERED_JUMPTABLE;
          *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
               (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] +
               (char)puVar97;
          _Dst = (uint *)(ulonglong)(byte)((char)puVar97 + 0x5b);
          UNRECOVERED_JUMPTABLE = (code *)(ulonglong)uRam0000000000000000;
switchD_14007fde0_caseD_b9:
          pcVar83 = (char *)((longlong)
                             ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                            0x183);
          *pcVar83 = *pcVar83 + (char)_Dst;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x94:
          goto switchD_14009313c_caseD_94;
        case 0x95:
switchD_14009313c_caseD_95:
          return (fd_set *)UNRECOVERED_JUMPTABLE;
        case 0x96:
switchD_14009313c_caseD_96:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0x97:
          goto switchD_14009313c_caseD_97;
        case 0x98:
switchD_14009313c_caseD_98:
          pbVar2 = (byte *)((longlong)&switchD_14007fde0::switchdataD_14010fd20 + uVar81 + 1);
          *pbVar2 = *pbVar2 | 0x94;
          pbVar2 = (byte *)((longlong)&UINT_14010fd1c + uVar81 + 1);
          *pbVar2 = *pbVar2 | (byte)param_4;
          pfVar195 = pfVar168;
          goto code_r0x000140096b09;
        case 0x99:
switchD_14009313c_caseD_99:
          _Dst = (uint *)0x86;
          UNRECOVERED_JUMPTABLE =
               (code *)(ulonglong)(uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
          goto code_r0x000140096b8d;
        case 0x9a:
          goto switchD_14009313c_caseD_9a;
        case 0x9b:
          goto switchD_14009313c_caseD_9b;
        case 0x9c:
switchD_14009313c_caseD_9c:
          _Dst = (uint *)0x68;
          UNRECOVERED_JUMPTABLE =
               (code *)(ulonglong)(uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
          goto code_r0x000140096b6f;
        case 0x9d:
          goto switchD_14009313c_caseD_9d;
        case 0x9e:
          goto switchD_14009313c_caseD_9e;
        case 0x9f:
switchD_14009313c_caseD_9f:
          pcVar83 = (char *)((longlong)
                             ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                            0x183);
          *pcVar83 = *pcVar83 + (char)puVar97;
          ((fd_set *)param_2)->fd_count = ((fd_set *)param_2)->fd_count + 1;
          pfVar16 = pfVar168;
          goto code_r0x000140096a0a;
        case 0xa0:
switchD_14009313c_caseD_a0:
          *(byte *)&pfVar84->fd_count = (byte)pfVar84->fd_count | (byte)param_4;
          *(uint *)((fd_set *)puVar225)->fd_array = (int)((fd_set *)puVar225)->fd_array[0] + uVar69;
        case 0xac:
switchD_14009313c_caseD_ac:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          uVar15 = ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
          uVar14 = param_3->fd_count;
          *(char *)&param_3->fd_count = (char)param_3->fd_count + 'd';
          *(byte *)param_3->fd_array =
               (char)param_3->fd_array[0] + bVar64 + (char)uVar15 + (0x9b < (byte)uVar14);
          ((fd_set *)puVar225)->fd_array[0] = SVar82;
          ((fd_set *)puVar225)->fd_array[1] = extraout_XMM0_Qb_01;
          UNRECOVERED_JUMPTABLE = (code *)0x8000000000000007;
          goto LAB_140096ea4;
        case 0xa1:
switchD_14009313c_caseD_a1:
          goto switchD_14007f6e5_caseD_b3;
        case 0xa2:
switchD_14009313c_caseD_a2:
          pfVar168[-1].fd_array[0x3f] = 0x140096bc4;
          FUN_14009708b((undefined8 *)&switchD_14009313c::caseD_fe,(ulonglong)param_3 & 0xffffffff);
          goto code_r0x000140096bc4;
        case 0xa3:
          goto switchD_14009313c_caseD_a3;
        case 0xa4:
          goto switchD_14009313c_caseD_a4;
        case 0xa5:
code_r0x000140096a82:
          pfVar168[-1].fd_array[0x3f] = (SOCKET)pfVar84;
          pfVar168[-1].fd_array[0x3e] = (SOCKET)param_1;
          pfVar168[-1].fd_array[0x3d] = (SOCKET)pfVar227;
          pfVar168[-1].fd_array[0x3c] = (SOCKET)pfVar233;
          pfVar168[-1].fd_array[0x3b] = (SOCKET)puVar225;
          pfVar168[-1].fd_array[0x3a] = (SOCKET)param_3;
          pfVar168[-1].fd_array[0x39] = (SOCKET)puVar223;
          pfVar168[-1].fd_array[0x38] = (SOCKET)param_2;
          goto switchD_14007fde0_caseD_b5;
        case 0xa6:
          goto switchD_14009313c_caseD_a6;
        case 0xa7:
          goto switchD_14009313c_caseD_a7;
        case 0xa8:
          goto switchD_14009313c_caseD_a8;
        case 0xa9:
          goto switchD_14009313c_caseD_a9;
        case 0xaa:
switchD_14009313c_caseD_aa:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xab:
          goto switchD_14009313c_caseD_ab;
        case 0xad:
switchD_14009313c_caseD_ad:
          _Dst = (uint *)0x77;
          UNRECOVERED_JUMPTABLE =
               (code *)(ulonglong)(uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
          goto code_r0x000140096b7e;
        case 0xae:
switchD_14009313c_caseD_ae:
          piVar80 = (int *)((longlong)param_3[0x9d9235].fd_array + 0x19a);
          *piVar80 = *piVar80 + 1;
          bVar239 = 0x3ee71f3e < uVar69;
          UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 + 0xc118e0c1);
          bVar237 = uVar69 + 0xc118e0c1 == 0;
          _Dst = (uint *)((longlong)&UINT_14010fd90 + 3);
          pfVar94 = pfVar168;
          if (!bVar237) goto switchD_14007fde0_caseD_aa;
code_r0x0001400969f8:
          pfVar233 = pfVar168;
          if (bVar239 || bVar237) goto switchD_1400968c1_default;
          pfVar168->fd_array[0x1a] = 3;
          goto code_r0x000140096a0a;
        case 0xaf:
switchD_14009313c_caseD_af:
          pcVar103 = (char *)0x85483ffa;
          goto code_r0x000140096aa5;
        case 0xb0:
switchD_14009313c_caseD_b0:
          _Dst = (uint *)0x95;
          UNRECOVERED_JUMPTABLE =
               (code *)CONCAT71(uVar86,bVar64 + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
          goto code_r0x000140096b8d;
        case 0xb1:
switchD_14009313c_caseD_b1:
          pcVar83 = (char *)((longlong)&UINT_14010fdf4 + uVar81 + 3);
          *pcVar83 = *pcVar83 + -0x6c;
          uVar81 = CONCAT71(uVar86,bVar64 + 0x81);
          goto code_r0x0001400968be;
        case 0xb2:
switchD_14009313c_caseD_b2:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 + 0x48000000);
          goto switchD_14007f7e4_caseD_b7;
        case 0xb3:
          goto switchD_14009313c_caseD_b3;
        case 0xb4:
switchD_14009313c_caseD_b4:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          (&UNK_14013177d)[uVar81] = (&UNK_14013177d)[uVar81] + bVar64;
          *(char *)((longlong)&UINT_14010fd4c + uVar81) =
               *(char *)((longlong)&UINT_14010fd4c + uVar81) + -0x6c;
          ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          (&UNK_14013087d)[uVar81] = (&UNK_14013087d)[uVar81] + bVar64;
          *(char *)((longlong)&UINT_14010fd4c + uVar81) =
               *(char *)((longlong)&UINT_14010fd4c + uVar81) + -0x6c;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xb5:
          goto switchD_14009313c_caseD_b5;
        case 0xb6:
          goto switchD_14009313c_caseD_b6;
        case 0xb7:
switchD_14009313c_caseD_b7:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
code_r0x00014009699a:
          cVar89 = (char)UNRECOVERED_JUMPTABLE;
          *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
          *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) =
               *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) + cVar89;
          *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
          pcVar83 = (char *)puVar225;
          goto code_r0x000140096994;
        case 0xb8:
          goto LAB_140096ff6;
        case 0xb9:
switchD_14009313c_caseD_b9:
          return (fd_set *)UNRECOVERED_JUMPTABLE;
        case 0xba:
switchD_14009313c_caseD_ba:
          pSVar196 = pfVar168->fd_array;
          goto LAB_140097032;
        case 0xbb:
switchD_14009313c_caseD_bb:
          pbVar2 = (byte *)((longlong)((fd_set *)((longlong)param_2 + 0x50043f4b8))->fd_array +
                           0x1d6);
          *pbVar2 = *pbVar2 & 0x94;
          pcVar83 = (char *)((longlong)&UINT_14010fd1c + uVar81 + 1);
          *pcVar83 = *pcVar83 + 'l';
          pfVar84 = (fd_set *)
                    FUN_140029ca0((undefined8 *)&switchD_14009313c::caseD_fe,_Src,
                                  (ulonglong)writefds);
          return pfVar84;
        case 0xbc:
switchD_14009313c_caseD_bc:
          pfVar84 = (fd_set *)param_2;
          goto LAB_1400971e3;
        case 0xbd:
switchD_14009313c_caseD_bd:
          *(ulonglong *)param_4 = (ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff60;
          UNRECOVERED_JUMPTABLE = FUN_140097b6b;
          goto code_r0x00014009754a;
        case 0xbe:
          goto switchD_14009313c_caseD_be;
        case 0xbf:
switchD_14009313c_caseD_bf:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xc0:
switchD_14009313c_caseD_c0:
          goto switchD_14009730b_caseD_84;
        case 0xc1:
switchD_14009313c_caseD_c1:
          UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
          goto LAB_140097b64;
        case 0xc2:
switchD_14009313c_caseD_c2:
          UINT_14010fd4c._0_1_ = (char)UINT_14010fd4c + bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count ^ bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          pcVar83 = (char *)UNRECOVERED_JUMPTABLE;
          goto LAB_140097aed;
        case 0xc3:
switchD_14009313c_caseD_c3:
          pfVar84 = (fd_set *)(ulonglong)(uVar69 + 0x4010fd94);
code_r0x0001400974c9:
                    /* WARNING: Could not recover jumptable at 0x0001400974d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)
                    (*(code *)((longlong)&UINT_140110084 +
                              (longlong)(int)(&UINT_140110084)[(longlong)pfVar84]))
                              ((code *)((longlong)&UINT_140110084 +
                                       (longlong)(int)(&UINT_140110084)[(longlong)pfVar84]));
          return pfVar84;
        case 0xc4:
switchD_14009313c_caseD_c4:
          bVar238 = *(byte *)((longlong)&UINT_14010fd1c + uVar81 + 3) | 0x94;
          pbVar2 = (byte *)((longlong)&UINT_14010fd1c + uVar81 + 3);
          *pbVar2 = *pbVar2 | bVar238;
          pbVar2 = (byte *)((longlong)&switchD_14007fde0::switchdataD_14010fd20 + uVar81 + 1);
          bVar237 = *pbVar2 < bVar238;
          *pbVar2 = *pbVar2 - bVar238;
          goto code_r0x0001400976cd;
        case 0xc5:
          goto switchD_14009313c_caseD_c5;
        case 0xc6:
switchD_14009313c_caseD_c6:
          bVar90 = (byte)puVar97 |
                   *(byte *)((longlong)
                             ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                            0x18b);
          pbVar2 = (byte *)((longlong)
                            ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18b
                           );
          *pbVar2 = *pbVar2 | bVar90;
          pbVar2 = (byte *)((longlong)
                            ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18d
                           );
          bVar238 = *pbVar2;
          *pbVar2 = *pbVar2 - bVar90;
          UNRECOVERED_JUMPTABLE =
               (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x73b91 + (uint)(bVar238 < bVar90));
          goto code_r0x0001400976af;
        case 199:
switchD_14009313c_caseD_c7:
                    /* WARNING: Could not emulate address calculation at 0x00014009734e */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)(*(code *)(ulonglong)*(uint *)(uVar81 + 0x110960c95))();
          return pfVar84;
        case 200:
          goto switchD_14009313c_caseD_c8;
        case 0xc9:
switchD_14009313c_caseD_c9:
          param_4 = (fd_set *)(pfVar168->fd_array + 0xb);
          *(ulonglong *)param_4 = (ulonglong)(uVar69 + 8);
code_r0x00014009765f:
          UNRECOVERED_JUMPTABLE = FUN_140097b6b;
          goto code_r0x000140097666;
        case 0xca:
switchD_14009313c_caseD_ca:
          uVar81 = (ulonglong)param_3 & 0xffffffff;
          *(char *)(uVar81 + 99) = *(char *)(uVar81 + 99) + -0x6c;
          UNRECOVERED_JUMPTABLE = (code *)CONCAT71((int7)(uVar81 >> 8),(char)uVar81 + -0x7f);
          goto code_r0x0001400972fd;
        case 0xcb:
          goto switchD_14009313c_caseD_cb;
        case 0xcc:
switchD_14009313c_caseD_cc:
          *(char *)&param_3->fd_count = (char)param_3->fd_count + -0x6c;
          ((fd_set *)puVar225)->fd_count = uVar70;
          goto LAB_1400972dd;
        case 0xcd:
switchD_14009313c_caseD_cd:
          out(5,bVar64);
          goto code_r0x00014009757c;
        case 0xce:
switchD_14009313c_caseD_ce:
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff20);
          goto code_r0x00014009767b;
        case 0xcf:
switchD_14009313c_caseD_cf:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xd0:
switchD_14009313c_caseD_d0:
          UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
          goto LAB_140097b64;
        case 0xd1:
          goto switchD_14009313c_caseD_d1;
        case 0xd2:
switchD_14009313c_caseD_d2:
          UINT_14010fd4c._0_1_ = (char)UINT_14010fd4c + bVar64;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xd3:
switchD_14009313c_caseD_d3:
          goto code_r0x0001400977ac;
        case 0xd4:
          goto switchD_14009313c_caseD_d4;
        case 0xd5:
switchD_14009313c_caseD_d5:
                    /* WARNING: Could not emulate address calculation at 0x000140097404 */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)(*(code *)(ulonglong)*(uint *)(uVar81 + 0x1802f7295))();
          return pfVar84;
        case 0xd6:
switchD_14009313c_caseD_d6:
          bVar64 = bVar64 | (byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
          UNRECOVERED_JUMPTABLE = (code *)CONCAT71(uVar86,bVar64);
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto code_r0x00014009782c;
        case 0xd7:
switchD_14009313c_caseD_d7:
          if (bVar240) {
            if (!bVar239 && -0x14010fd95 < (longlong)uVar81) {
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          goto code_r0x00014009729c;
        case 0xd8:
switchD_14009313c_caseD_d8:
          ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count | uVar69;
          pcVar83 = (char *)((longlong)&UINT_14010fd1c + uVar81 + 1);
          *pcVar83 = *pcVar83 + -0x6c;
          pfVar77 = pfVar168;
          goto code_r0x0001400977de;
        case 0xd9:
switchD_14009313c_caseD_d9:
          pcVar83 = (char *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff20);
          *pcVar83 = *pcVar83 + (char)pcVar83;
          goto code_r0x000140097815;
        case 0xda:
          goto switchD_14009313c_caseD_da;
        case 0xdb:
switchD_14009313c_caseD_db:
          bVar238 = *(byte *)((longlong)&UINT_14010fd1c + uVar81 + 3) | 0x91;
          pbVar2 = (byte *)((longlong)&UINT_14010fd1c + uVar81 + 3);
          uRam00000000cb517563 = in_ES;
          *pbVar2 = *pbVar2 | bVar238;
          pcVar83 = (char *)((longlong)&switchD_14007fde0::switchdataD_14010fd20 + uVar81 + 1);
          *pcVar83 = *pcVar83 - bVar238;
          goto code_r0x000140097565;
        case 0xdc:
switchD_14009313c_caseD_dc:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
          goto LAB_140097b64;
        case 0xdd:
switchD_14009313c_caseD_dd:
          pcVar103 = (char *)(ulonglong)(uint)((int)uVar69 >> 0x1f);
          ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count >> 1 |
               ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count << 0x1f;
          pfVar205 = pfVar168;
          goto code_r0x00014009731c;
        case 0xde:
switchD_14009313c_caseD_de:
          UNRECOVERED_JUMPTABLE = (code *)CONCAT71(uVar86,uRam1574d28548000000);
          goto code_r0x0001400972c5;
        case 0xdf:
switchD_14009313c_caseD_df:
                    /* WARNING: Could not emulate address calculation at 0x000140097272 */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)(*(code *)(ulonglong)*(uint *)(uVar81 + 0xec960c95))();
          return pfVar84;
        case 0xe0:
switchD_14009313c_caseD_e0:
          *(uint *)(pfVar168->fd_array + 0xc) = uVar69;
          goto code_r0x00014009729c;
        case 0xe1:
          goto switchD_14009313c_caseD_e1;
        case 0xe2:
code_r0x00018809782f:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xe3:
switchD_14009313c_caseD_e3:
          UNRECOVERED_JUMPTABLE = (code *)0x4009811a;
          goto code_r0x000140097773;
        case 0xe4:
switchD_14009313c_caseD_e4:
                    /* WARNING: Could not emulate address calculation at 0x0001400973b3 */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)(*(code *)(ulonglong)*(uint *)(uVar81 + 0x181807295))();
          return pfVar84;
        case 0xe5:
          goto switchD_14009313c_caseD_e5;
        case 0xe6:
switchD_14009313c_caseD_e6:
          ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count | uVar69;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto code_r0x000140097773;
        case 0xe7:
switchD_14009313c_caseD_e7:
          if (!bVar237) {
            return (fd_set *)UNRECOVERED_JUMPTABLE;
          }
          goto code_r0x000140097263;
        case 0xe8:
          goto switchD_14009313c_caseD_e8;
        case 0xe9:
          goto switchD_14009313c_caseD_e9;
        case 0xea:
switchD_14009313c_caseD_ea:
          UINT_14010fd4c._0_1_ = (char)UINT_14010fd4c + bVar64;
          uVar69 = CONCAT31((int3)((uVar69 | 0xe9000000) >> 8),
                            bVar64 + *(char *)(ulonglong)(uVar69 | 0xe9000000));
          uVar81 = (ulonglong)uVar69;
          *(char *)(uVar81 - 0x75) = *(char *)(uVar81 - 0x75) + -0x6c;
          bVar90 = *(byte *)(uVar81 - 0x75) | 0x94;
          *(byte *)(uVar81 - 0x75) = *(byte *)(uVar81 - 0x75) | bVar90;
          pbVar2 = (byte *)(uVar81 - 0x73);
          bVar238 = *pbVar2;
          *pbVar2 = *pbVar2 - bVar90;
          UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 + 0x737af + (uint)(bVar238 < bVar90));
          goto LAB_140097b64;
        case 0xeb:
          goto switchD_14009313c_caseD_eb;
        case 0xec:
          goto switchD_14009313c_caseD_ec;
        case 0xed:
          goto switchD_14009313c_caseD_ed;
        case 0xee:
switchD_14009313c_caseD_ee:
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)uVar86 << 8);
          *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
          goto code_r0x000140098ff7;
        case 0xef:
        case 0xf1:
switchD_14009313c_caseD_ef:
          UNRECOVERED_JUMPTABLE = (code *)swi(1);
          pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
          return pfVar84;
        case 0xf0:
switchD_14009313c_caseD_f0:
          *(undefined4 *)(((fd_set *)puVar225)->fd_array + 4) = uVar244;
          *(undefined4 *)((longlong)((fd_set *)puVar225)->fd_array + 0x24) = uVar245;
          *(undefined4 *)(((fd_set *)puVar225)->fd_array + 5) = in_XMM1_Dc;
          *(undefined4 *)((longlong)((fd_set *)puVar225)->fd_array + 0x2c) = in_XMM1_Dd;
          ((fd_set *)puVar225)->fd_array[2] = SVar82;
          ((fd_set *)puVar225)->fd_array[3] = extraout_XMM0_Qb_01;
          *(fd_set **)puVar225 = (fd_set *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff78);
          ((fd_set *)puVar225)->fd_array[0] = (SOCKET)param_2;
          ((fd_set *)puVar225)->fd_array[1] = (SOCKET)param_1;
          return (fd_set *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff78);
        case 0xf2:
switchD_14009313c_caseD_f2:
          uVar81 = (ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff20;
          goto code_r0x000140098f97;
        case 0xf3:
switchD_14009313c_caseD_f3:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          goto code_r0x000140099437;
        case 0xf4:
          goto switchD_14009313c_caseD_f4;
        case 0xf5:
code_r0x000129041db4:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xf6:
switchD_14009313c_caseD_f6:
          pfVar107 = (fd_set *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)pfVar168 & 0xffffffffffffffe8);
          *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
          switchD_14009313c::caseD_fe._0_1_ = 0;
          goto LAB_1400994c8;
        case 0xf7:
switchD_14009313c_caseD_f7:
          pcVar83 = (char *)((longlong)((fd_set *)param_2)->fd_array + 0x55);
          *pcVar83 = *pcVar83 + (char)param_2;
          return (fd_set *)UNRECOVERED_JUMPTABLE;
        case 0xf8:
          goto switchD_14009313c_caseD_f8;
        case 0xf9:
        case 0xfa:
switchD_14009313c_caseD_f9:
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar64;
          *(char *)(uVar81 + 0x1645d88dc) = *(char *)(uVar81 + 0x1645d88dc) + bVar64;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 0xfb:
switchD_14009313c_caseD_fb:
          goto LAB_1400996d4;
        case 0xfc:
switchD_14009313c_caseD_fc:
          pbVar2 = (byte *)((longlong)&UINT_14010fd1c + uVar81 + 3);
          *pbVar2 = *pbVar2 ^ 0x94;
          goto LAB_1400996d4;
        case 0xfd:
switchD_14009313c_caseD_fd:
                    /* WARNING: Could not recover jumptable at 0x00014010fd93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)
                    (*(code *)(ulonglong)
                              *(uint *)((longlong)
                                        ((fd_set *)((longlong)_Src + -0x380007e8))->fd_array + 0x13)
                    )();
          return pfVar84;
        case 0xfe:
        case 0xff:
code_r0x00014010fd94:
          *(byte *)&param_3->fd_count = bVar64;
                    /* WARNING: Could not recover jumptable at 0x00014010fd9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)
                    (*(code *)(ulonglong)
                              *(uint *)((ulonglong)((uVar226 + 1 ^ uVar69) + 1 ^ uVar69) -
                                       0x450007cd))();
          return pfVar84;
        }
code_r0x00014009317f:
        return (fd_set *)UNRECOVERED_JUMPTABLE;
      case 0xf:
        goto code_r0x00014009311e;
      case 0x10:
        goto code_r0x00014009326e;
      case 0x11:
        goto switchD_14009313c_caseD_6;
      case 0x12:
code_r0x000140093297:
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        *pbVar2 = *pbVar2 | (byte)_Dst;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18d)
        ;
        *pcVar83 = *pcVar83 - (byte)_Dst;
code_r0x0001400932a4:
                    /* WARNING: Could not recover jumptable at 0x0001400932ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pfVar84 = (fd_set *)
                  (*(code *)((longlong)((fd_set *)pcVar103)->fd_array +
                            (longlong)
                            *(int *)((longlong)((fd_set *)pcVar103)->fd_array +
                                    (longlong)writefds * 4 + -8) + -8))();
        return pfVar84;
      case 0x13:
code_r0x0001400932a7:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x14:
code_r0x00014009327e:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x15:
        goto switchD_14009313c_caseD_7;
      case 0x16:
        goto switchD_14009313c_caseD_b;
      case 0x17:
        goto switchD_14009313c_caseD_d;
      case 0x18:
        goto switchD_14009313c_caseD_5;
      case 0x19:
code_r0x000140093287:
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x183);
        bVar238 = (byte)_Dst & 7;
        *pbVar2 = *pbVar2 >> bVar238 | *pbVar2 << 8 - bVar238;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      default:
        goto code_r0x0001400934dc;
      case 0x1e:
code_r0x00014009351d:
        UNRECOVERED_JUMPTABLE = (code *)&DAT_00000004;
        if ((longlong)param_3 < 0) {
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)_Dst ^ 0x8000000000000000);
        }
        pfVar168 = (fd_set *)puVar126;
        puVar225 = (uint *)pcVar83;
        if ((fd_set *)&DAT_00000030 < UNRECOVERED_JUMPTABLE) {
switchD_140093542_caseD_2f:
          pfVar84 = (fd_set *)FUN_14003116e(((fd_set *)puVar225)->fd_array);
          return pfVar84;
        }
code_r0x000140093534:
        UNRECOVERED_JUMPTABLE =
             (code *)((longlong)&switchD_140093542::switchdataD_14010fdcc +
                     (longlong)
                     (int)(&switchD_140093542::switchdataD_14010fdcc)
                          [(longlong)UNRECOVERED_JUMPTABLE]);
        switch(UNRECOVERED_JUMPTABLE) {
        case (code *)0x140093544:
code_r0x00014009354a:
          return (fd_set *)UNRECOVERED_JUMPTABLE;
        case (code *)0x140093572:
          pfVar84 = (fd_set *)FUN_1400935c9((longlong *)(((fd_set *)puVar225)->fd_array + 3));
          return pfVar84;
        case (code *)0x140093585:
          if (((char)((fd_set *)puVar225)->fd_array[2] == '\0') &&
             (SVar82 = ((fd_set *)puVar225)->fd_array[3], SVar82 != 0x8000000000000000)) {
            SVar76 = ((fd_set *)puVar225)->fd_array[4];
            *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400935a7;
            FUN_140093619(SVar82,SVar76);
          }
          param_2 = (undefined **)((fd_set *)puVar225)->fd_array[0];
          SVar82 = ((fd_set *)puVar225)->fd_array[1];
          *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400935b7;
          FUN_1400465fd((longlong)param_2,SVar82);
        }
        goto code_r0x0001400935ba;
      case 0x36:
        goto code_r0x00014009350a;
      case 0x45:
      case 0x47:
code_r0x0001400934e4:
        UNRECOVERED_JUMPTABLE = (code *)swi(1);
        pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
        return pfVar84;
      case 0x49:
        goto code_r0x0001400934f7;
      case 0x4b:
code_r0x00014009363c:
        if (((fd_set *)_Src)->fd_array[1] < ((fd_set *)_Src)->fd_array[0]) {
          bVar239 = *(char *)(*(longlong *)param_3 + ((fd_set *)_Src)->fd_array[1]) == '\x17';
          pfVar227 = (fd_set *)(ulonglong)bVar239;
          pfVar84 = (fd_set *)(ulonglong)(byte)(0x18 - bVar239);
        }
        else {
          pfVar84 = (fd_set *)&DAT_00000018;
          pfVar227 = (fd_set *)0x0;
        }
        pfVar233 = (fd_set *)0x8000000000000032;
        pfVar234 = (fd_set *)puVar127;
        puVar225 = _Dst;
        pfVar94 = param_3;
switchD_14009313c_caseD_3f:
        cVar89 = (char)pfVar227;
        cVar88 = (char)pfVar84;
        *(undefined1 *)((longlong)pfVar234 + 0xd0) = 0x12;
        *(undefined1 **)((longlong)pfVar234 + 200) =
             (undefined1 *)((longlong)pfVar233[-1].fd_array + 0x1ec);
        *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093689;
        uVar81 = FUN_140019e50((longlong)pfVar94);
        pcVar83 = (char *)puVar225;
        if ((~(byte)_Src & 0x1f) == 0 || (uVar81 & 1) != 0) goto switchD_140093766_default;
        param_2 = (undefined **)((ulonglong)_Src & 0xffffffff);
        cVar104 = (char)param_2;
        *(undefined8 *)((longlong)pfVar234 + -8) = 0x1400936a8;
        uVar81 = FUN_140019e50((longlong)pfVar94);
        bVar238 = (byte)_Src;
        if ((uVar81 & 1) != 0) goto switchD_140093766_default;
        if ((char)bVar238 < '\0') {
          switch((uint)_Src & 0xff) {
          case 0x81:
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093770;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            if (-1 < (char)bVar238 || (uVar81 & 1) != 0) goto switchD_140093766_default;
            break;
          case 0x82:
            _Dst = &pfVar94->fd_count;
            goto switchD_14007f6e5_caseD_73;
          case 0x83:
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x1400939ea;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            if ((uVar81 & 1) != 0) goto switchD_140093766_default;
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x1400939fd;
            pfVar84 = (fd_set *)_Src;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            if ((uVar81 & 1) != 0) goto switchD_140093766_default;
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093a0f;
            pfVar227 = pfVar84;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            if (((uVar81 & 1) != 0) || (((ulonglong)_Src & 0xff) == 0))
            goto switchD_140093766_default;
            uVar71 = (ulonglong)(uint)((int)((ulonglong)_Src & 0xff) << 0x10);
            uVar81 = (ulonglong)(((uint)pfVar84 & 0xff) << 8) | (ulonglong)pfVar227 & 0xff;
            goto switchD_14007f7e4_caseD_72;
          case 0x84:
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093a41;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            if ((uVar81 & 1) != 0) goto switchD_140093766_default;
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093a53;
            pfVar101 = (fd_set *)_Src;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            if ((uVar81 & 1) != 0) goto switchD_140093766_default;
            param_1 = (fd_set *)((ulonglong)pfVar101 & 0xffffffff);
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093a66;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            if ((uVar81 & 1) != 0) goto switchD_140093766_default;
            *(char *)((longlong)pfVar234 + 0xa8) = (char)pfVar101;
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093a79;
            uVar81 = FUN_140019e50((longlong)pfVar94);
            param_4 = (fd_set *)(ulonglong)*(byte *)((longlong)pfVar234 + 0xa8);
            if ((uVar81 & 1) != 0) goto switchD_140093766_default;
            goto code_r0x000140093a89;
          default:
            goto switchD_140093766_default;
          }
        }
        uVar81 = (ulonglong)bVar238;
        goto LAB_1400936bb;
      case 0x4c:
code_r0x000140093981:
        cVar88 = (char)_Dst + (char)((ulonglong)_Dst >> 8);
        _Dst = (uint *)CONCAT71((int7)((ulonglong)_Dst >> 8),cVar88);
        uVar87 = (undefined7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8);
        cVar89 = (char)UNRECOVERED_JUMPTABLE + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        pcVar103 = (char *)CONCAT71(uVar87,cVar89);
        pcVar103[-0x75] = pcVar103[-0x75] + cVar88;
        *(undefined2 *)pcVar103 = in_FS;
        *pcVar103 = *pcVar103 + cVar89;
        pcVar103[-0x77] = pcVar103[-0x77] + cVar88;
        UNRECOVERED_JUMPTABLE = (code *)(CONCAT71(uVar87,cVar89) & 0xffffffffffffff50);
        pfVar107 = (fd_set *)puVar131;
        goto code_r0x00014009398f;
      case 0x4d:
code_r0x0001400938b6:
        puVar225 = &pfVar62->fd_count;
        pcVar83 = (char *)((ulonglong)
                           ((int)UNRECOVERED_JUMPTABLE + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count
                           ) - 0x73);
        *pcVar83 = *pcVar83 + (char)_Dst;
        pfVar168 = (fd_set *)*puVar129;
        goto code_r0x0001400938b9;
      case 0x4e:
switchD_14007f6e5_caseD_69:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x189)
        ;
        *pcVar83 = *pcVar83 + (char)_Dst;
        pcVar83 = (char *)((ulonglong)puVar130 & 0xffffffc0);
        *pcVar83 = *pcVar83 + (char)pcVar83;
        pcVar83[-0x7f] = pcVar83[-0x7f] + (char)_Dst;
        *(undefined8 *)(((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff) - 8) =
             *(undefined8 *)
              ((longlong)((fd_set *)((longlong)pcVar103 + 0xeffffb0))->fd_array + 0x4f);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x4f:
code_r0x000140093b4d:
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x38c47fb0))->fd_array + 0x32) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x38c47fb0))->fd_array[0x32] +
             (char)pcVar103;
        ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
        pcVar83 = (char *)((longlong)((fd_set *)param_2)->fd_array + 0x55);
        *pcVar83 = *pcVar83 + (char)param_2;
        goto switchD_14009313c_caseD_48;
      case 0x50:
code_r0x000140093841:
        pfVar168 = (fd_set *)puVar128;
        puVar225 = (uint *)pcVar83;
        goto LAB_14009383b;
      case 0x51:
code_r0x000140093b18:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        goto LAB_140093b12;
      case 0x52:
        goto code_r0x000140093b1e;
      case 0x53:
        goto code_r0x000140093b0a;
      case 0x54:
code_r0x000140093b2c:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pfVar107 = (fd_set *)puVar140;
        goto code_r0x000140093b26;
      case 0x55:
switchD_14009313c_caseD_4e:
        iVar66 = (int)_Src;
        *(undefined8 *)((longlong)pfVar141 + -8) = 0x140093b37;
        SVar82 = func_0x00014f093b37();
        *(uint *)(((fd_set *)pcVar83)->fd_array + 3) =
             (int)((fd_set *)pcVar83)->fd_array[3] + iVar66 + (uint)bVar238;
        pfVar234 = pfVar141;
        SVar76 = extraout_XMM0_Qb_02;
        goto switchD_14009313c_caseD_47;
      case 0x56:
code_r0x000140093b24:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pfVar107 = (fd_set *)puVar139;
        goto code_r0x000140093b26;
      case 0x57:
code_r0x000140093b42:
        pfVar107 = (fd_set *)puVar48;
        goto LAB_140093b41;
      case 0x58:
code_r0x000140093b10:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        puVar137 = puVar136;
        goto LAB_140093b12;
      case 0x59:
        goto switchD_14009313c_caseD_47;
      case 0x5a:
code_r0x000140093b02:
        pcVar103 = (char *)((longlong)
                            ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x10f23e0))->fd_array +
                           0x9c);
        *pcVar103 = *pcVar103 + (char)_Dst;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        puVar135 = puVar134;
        goto code_r0x000140093b0a;
      case 0x5b:
code_r0x000140093c4e:
        puVar225 = &pfVar62->fd_count;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        param_2 = (undefined **)
                  CONCAT71((int7)((ulonglong)param_2 >> 8),
                           (char)param_2 + (char)((ulonglong)_Dst >> 8));
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x183);
        *pbVar2 = *pbVar2 ^ (byte)_Dst;
        bVar238 = (byte)param_3->fd_count;
        *(byte *)&param_3->fd_count = bVar238 >> 2 | bVar238 << 7;
        *(char *)&((fd_set *)puVar225)->fd_count = (char)((fd_set *)puVar225)->fd_count >> 0xb;
        uVar81 = (ulonglong)(((uint)UNRECOVERED_JUMPTABLE & 0xffffff48) + 0xb8);
        pfVar168 = (fd_set *)puVar143;
        goto LAB_140093c84;
      case 0x5c:
code_r0x000140093d22:
        pfVar168 = (fd_set *)((longlong)puVar145 + -0x28);
        param_2 = (undefined **)((ulonglong)pfVar72 & 0xffffffff);
        pfVar227 = (fd_set *)0x8000000000000000;
        *(undefined8 *)((longlong)puVar145 + -0x30) = 0x140093d41;
        _Src = (uint *)pcVar103;
        uVar81 = FUN_140019e50((longlong)pcVar103);
        puVar225 = _Dst;
        puVar97 = (uint *)pcVar103;
        if ((~(byte)_Src & 0x1f) == 0 || (uVar81 & 1) != 0) goto switchD_140093db8_default;
code_r0x000140093d56:
        param_3 = (fd_set *)((ulonglong)_Src & 0xffffffff);
        param_1 = (fd_set *)puVar97;
code_r0x000140093d5b:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140093d60;
        uVar81 = FUN_140019e50((longlong)puVar97);
        if ((uVar81 & 1) != 0) goto switchD_140093db8_default;
        bVar237 = (char)_Src < '\0';
        pfVar107 = pfVar168;
code_r0x000140093d6a:
        bVar238 = (byte)_Src;
        if (bVar237) {
          switch((uint)_Src & 0xff) {
          case 0x81:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093dc2;
            uVar81 = FUN_140019e50((longlong)param_1);
            if (-1 < (char)bVar238 || (uVar81 & 1) != 0) goto switchD_140093db8_default;
            goto LAB_140093d6c;
          case 0x82:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093e96;
            uVar81 = FUN_140019e50((longlong)param_1);
            if ((uVar81 & 1) != 0) goto switchD_140093db8_default;
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093ea4;
            pfVar84 = (fd_set *)_Src;
            uVar81 = FUN_140019e50((longlong)param_1);
            if (((uVar81 & 1) != 0) || ((char)_Src == '\0')) goto switchD_140093db8_default;
            uVar81 = (ulonglong)pfVar84 & 0xff;
            uVar71 = (ulonglong)(((uint)_Src & 0xff) << 8);
            break;
          case 0x83:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093ddb;
            uVar81 = FUN_140019e50((longlong)param_1);
            if ((uVar81 & 1) != 0) goto switchD_140093db8_default;
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093dee;
            pfVar84 = (fd_set *)_Src;
            uVar81 = FUN_140019e50((longlong)param_1);
            if ((uVar81 & 1) != 0) goto switchD_140093db8_default;
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093e00;
            pfVar233 = pfVar84;
            uVar81 = FUN_140019e50((longlong)param_1);
            if (((uVar81 & 1) != 0) || (((ulonglong)_Src & 0xff) == 0))
            goto switchD_140093db8_default;
            uVar81 = (ulonglong)(uint)((int)((ulonglong)_Src & 0xff) << 0x10);
            uVar71 = (ulonglong)(((uint)pfVar84 & 0xff) << 8) | (ulonglong)pfVar233 & 0xff;
            break;
          case 0x84:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093e32;
            uVar81 = FUN_140019e50((longlong)param_1);
            uVar69 = (uint)_Src;
            if ((uVar81 & 1) != 0) goto switchD_140093db8_default;
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093e44;
            uVar81 = FUN_140019e50((longlong)param_1);
            if ((uVar81 & 1) != 0) goto switchD_140093db8_default;
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093e53;
            uVar70 = uVar69;
            uVar81 = FUN_140019e50((longlong)param_1);
            bVar238 = (byte)uVar70;
            if ((uVar81 & 1) != 0) goto switchD_140093db8_default;
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093e62;
            uVar81 = FUN_140019e50((longlong)param_1);
            if (((uVar81 & 1) != 0) || (((ulonglong)_Src & 0xff) == 0))
            goto switchD_140093db8_default;
            SVar82 = (ulonglong)((uVar70 & 0xff) << 8) | (ulonglong)bVar238 |
                     (ulonglong)((uVar69 & 0xff) << 0x10 | (int)((ulonglong)_Src & 0xff) << 0x18);
            goto LAB_140093eba;
          default:
            goto switchD_140093db8_default;
          }
          SVar82 = uVar71 | uVar81;
LAB_140093eba:
          if (0xfffe < (uint)SVar82) goto switchD_140093db8_default;
        }
        else {
LAB_140093d6c:
          SVar82 = (SOCKET)bVar238;
        }
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093d77;
        pfVar84 = (fd_set *)FUN_140019a0b((longlong *)param_1,SVar82);
        if (pfVar84 != (fd_set *)0x0) {
          if ((char)param_2 == (char)param_3) {
            ((fd_set *)puVar225)->fd_array[0] = (SOCKET)pfVar84;
            ((fd_set *)puVar225)->fd_array[1] = SVar82;
            pfVar227 = (fd_set *)((longlong)pfVar227->fd_array + 0x2a);
          }
          *(fd_set **)puVar225 = pfVar227;
          return pfVar84;
        }
switchD_140093db8_default:
        *(fd_set **)puVar225 = pfVar227;
        *(undefined1 *)((fd_set *)puVar225)->fd_array = 0;
        *(undefined2 *)((longlong)((fd_set *)puVar225)->fd_array + 5) = 0;
        *(undefined1 *)((longlong)((fd_set *)puVar225)->fd_array + 7) = 0;
        *(undefined4 *)((longlong)((fd_set *)puVar225)->fd_array + 1) = 0;
        return (fd_set *)0x0;
      case 0x5d:
code_r0x000140093c67:
        puVar225 = &pfVar62->fd_count;
        uVar81 = (ulonglong)
                 ((int)CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),
                                ((char)UNRECOVERED_JUMPTABLE + -0x48) - bVar238) + 0x7b);
        pfVar168 = (fd_set *)puVar144;
LAB_140093c84:
        *(ulonglong *)((longlong)pfVar168 + 0x28) = uVar81;
        puVar137 = (undefined8 *)pfVar168;
        pcVar83 = (char *)puVar225;
        if ((fd_set *)param_2 != *(fd_set **)((longlong)pfVar168 + 0xa8)) goto LAB_140093b12;
switchD_14009313c_caseD_51:
        ((fd_set *)puVar225)->fd_array[0] =
             (((longlong)puVar223 +
              *(longlong *)((longlong)pfVar168 + 0x28) +
              (((longlong)param_3 * 0x16d +
               ((ulonglong)((longlong)param_3[-1].fd_array + 0x1ffU) >> 2)) -
              *(longlong *)((longlong)pfVar168 + 0xb8)) + *(longlong *)((longlong)pfVar168 + 0xb0) +
              -0xafaa7) * 0x15180 +
             (longlong)pfVar84 * 0x3c + (longlong)param_1 * 0xe10 +
             *(longlong *)((longlong)pfVar168 + 0xc0)) - 0x15180;
        *(fd_set **)puVar225 = pfVar233;
        goto LAB_1400939d0;
      case 0x5e:
switchD_14007f7e4_caseD_75:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x5f:
code_r0x000140093f72:
        puVar225 = &pfVar62->fd_count;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x189)
        ;
        *pcVar83 = (*pcVar83 - (char)param_4) - bVar238;
        _Src = (uint *)pcVar103;
code_r0x000140093f76:
        *(byte *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x31) =
             (byte)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x31] &
             (byte)pfVar72;
        out((char)((fd_set *)puVar225)->fd_count,(short)_Src);
        pcVar83 = (char *)((longlong)_Dst * 5 + 0x36);
        *pcVar83 = *pcVar83 - (char)_Dst;
        return (fd_set *)UNRECOVERED_JUMPTABLE;
      case 0x60:
code_r0x00014009405c:
        _Src = (uint *)pcVar103;
        pfVar107 = (fd_set *)puVar147;
        puVar225 = (uint *)pcVar83;
code_r0x000140094058:
        param_2 = (undefined **)((ulonglong)_Src & 0xffffffff);
        cVar89 = (char)param_2;
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094062;
        uVar81 = FUN_140019e50((longlong)param_3);
        bVar238 = (byte)_Src;
        if ((uVar81 & 1) != 0) goto switchD_1400940ec_default;
        if ((char)bVar238 < '\0') {
          switch((uint)_Src & 0xff) {
          case 0x81:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400940f6;
            uVar241 = FUN_140019e50((longlong)param_3);
            _Dst = (uint *)(ulonglong)(byte)(-1 < (char)_Src | (byte)uVar241);
code_r0x0001400940fd:
            cVar89 = (char)param_2;
            bVar238 = (byte)_Src;
            if (((ulonglong)_Dst & 1) == 0) goto LAB_14009406e;
            break;
          case 0x82:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400941e0;
            uVar81 = FUN_140019e50((longlong)param_3);
            if ((uVar81 & 1) == 0) {
              *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400941ee;
              pfVar84 = (fd_set *)_Src;
              uVar81 = FUN_140019e50((longlong)param_3);
              if (((uVar81 & 1) == 0) && ((char)_Src != '\0')) {
                uVar81 = (ulonglong)pfVar84 & 0xff;
                uVar71 = (ulonglong)(((uint)_Src & 0xff) << 8);
LAB_140094201:
                _Src = (uint *)(uVar71 | uVar81);
LAB_140094204:
                if ((uint)_Src < 0xffff) goto LAB_140094071;
              }
            }
            break;
          case 0x83:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094125;
            uVar81 = FUN_140019e50((longlong)param_3);
            if ((uVar81 & 1) == 0) {
              *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094138;
              pfVar84 = (fd_set *)_Src;
              uVar81 = FUN_140019e50((longlong)param_3);
              if ((uVar81 & 1) == 0) {
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009414a;
                pfVar234 = pfVar84;
                uVar81 = FUN_140019e50((longlong)param_3);
                if (((uVar81 & 1) == 0) && (((ulonglong)_Src & 0xff) != 0)) {
                  uVar81 = (ulonglong)(uint)((int)((ulonglong)_Src & 0xff) << 0x10);
                  uVar71 = (ulonglong)(((uint)pfVar84 & 0xff) << 8) | (ulonglong)pfVar234 & 0xff;
                  goto LAB_140094201;
                }
              }
            }
            break;
          case 0x84:
            *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009417c;
            uVar81 = FUN_140019e50((longlong)param_3);
            uVar69 = (uint)_Src;
            if ((uVar81 & 1) == 0) {
              *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009418e;
              uVar81 = FUN_140019e50((longlong)param_3);
              if ((uVar81 & 1) == 0) {
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009419d;
                uVar70 = uVar69;
                uVar81 = FUN_140019e50((longlong)param_3);
                bVar238 = (byte)uVar70;
                if ((uVar81 & 1) == 0) {
                  *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400941ac;
                  uVar81 = FUN_140019e50((longlong)param_3);
                  if (((uVar81 & 1) == 0) && (((ulonglong)_Src & 0xff) != 0)) {
                    _Src = (uint *)((ulonglong)((uVar70 & 0xff) << 8) | (ulonglong)bVar238 |
                                   (ulonglong)
                                   ((uVar69 & 0xff) << 0x10 | (int)((ulonglong)_Src & 0xff) << 0x18)
                                   );
                    goto LAB_140094204;
                  }
                }
              }
            }
          }
          goto switchD_1400940ec_default;
        }
LAB_14009406e:
        _Src = (uint *)(ulonglong)bVar238;
LAB_140094071:
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094079;
        UNRECOVERED_JUMPTABLE = (code *)FUN_140019a0b((longlong *)param_3,(ulonglong)_Src);
        if ((fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0) goto switchD_1400940ec_default;
        pfVar168 = pfVar107;
        if (cVar89 == '\x01') {
code_r0x00014009408b:
          *(code **)((longlong)pfVar168 + 0x60) = UNRECOVERED_JUMPTABLE;
          *(uint **)((longlong)pfVar168 + 0x68) = _Src;
          puVar91 = (undefined1 *)((longlong)pfVar233->fd_array + 0x2a);
          *(undefined1 **)((longlong)pfVar168 + 0x58) = puVar91;
          if ((fd_set *)_Src == (fd_set *)0x0) {
LAB_140094115:
            *(fd_set **)puVar225 = pfVar233;
          }
          else {
            cVar89 = (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
            if (cVar89 == '\0') {
              uVar63 = 0;
            }
            else {
              if (cVar89 != -1) goto LAB_140094115;
              uVar63 = 1;
            }
            if ((fd_set *)_Src != (fd_set *)((longlong)&uRam0000000000000000 + 1))
            goto LAB_14009422a;
            *(undefined1 *)((fd_set *)puVar225)->fd_array = uVar63;
            *(undefined1 **)puVar225 = puVar91;
          }
          *(undefined8 *)((longlong)pfVar168 + -8) = 0x140094282;
          FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x20));
          goto LAB_14009424d;
        }
        *(fd_set **)((longlong)pfVar107 + 0x58) = pfVar233;
        goto LAB_14009422a;
      case 0x61:
code_r0x000140093fa1:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar47;
        *(char *)((longlong)pfVar168 + 0x31) =
             *(char *)((longlong)pfVar168 + 0x31) + (char)UNRECOVERED_JUMPTABLE + bVar238;
        goto LAB_140093fa0;
      case 0x62:
switchD_14007f7e4_caseD_79:
        *(uint **)((longlong)puVar146 + -8) = puVar223;
        *(undefined ***)((longlong)puVar146 + -0x10) = param_2;
        pfVar233 = (fd_set *)0x8000000000000000;
        pfVar84 = (fd_set *)((fd_set *)pcVar103)->fd_array[1];
        if (((fd_set *)((fd_set *)pcVar103)->fd_array[0] <= pfVar84) ||
           (pfVar107 = (fd_set *)((longlong)puVar146 + -0xa0), puVar225 = _Dst,
           param_3 = (fd_set *)pcVar103,
           *(char *)((longlong)pfVar84->fd_array + *(longlong *)pcVar103 + -8) != '\x01')) {
          *(undefined1 *)((fd_set *)_Dst)->fd_array = 0;
          *(undefined8 *)_Dst = 0x8000000000000032;
          return pfVar84;
        }
code_r0x00014009402c:
        *(undefined1 *)((longlong)pfVar107 + 0x28) = 1;
        *(undefined1 **)((longlong)pfVar107 + 0x20) =
             (undefined1 *)((longlong)pfVar233->fd_array + 0x16);
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094043;
        uVar81 = FUN_140019e50((longlong)param_3);
        _Src = (uint *)pcVar103;
        if ((~(byte)pcVar103 & 0x1f) != 0 && (uVar81 & 1) == 0) goto code_r0x000140094058;
switchD_1400940ec_default:
        *(fd_set **)((longlong)pfVar107 + 0x58) = pfVar233;
        *(undefined1 *)((longlong)pfVar107 + 0x60) = 0;
        *(undefined2 *)((longlong)pfVar107 + 0x65) = 0;
        *(undefined1 *)((longlong)pfVar107 + 0x67) = 0;
        *(undefined4 *)((longlong)pfVar107 + 0x61) = 0;
        pfVar168 = pfVar107;
LAB_14009422a:
        ((fd_set *)puVar225)->fd_array[5] = *(SOCKET *)((longlong)pfVar168 + 0x50);
        uVar241 = *(undefined8 *)((longlong)pfVar168 + 0x20);
        SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x28);
        SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x30);
        SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x38);
        SVar8 = *(SOCKET *)((longlong)pfVar168 + 0x48);
        ((fd_set *)puVar225)->fd_array[3] = *(SOCKET *)((longlong)pfVar168 + 0x40);
        ((fd_set *)puVar225)->fd_array[4] = SVar8;
        ((fd_set *)puVar225)->fd_array[1] = SVar76;
        ((fd_set *)puVar225)->fd_array[2] = SVar236;
        *(undefined8 *)puVar225 = uVar241;
        ((fd_set *)puVar225)->fd_array[0] = SVar82;
LAB_14009424d:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140094257;
        pfVar84 = (fd_set *)FUN_14009487a((ulonglong *)((longlong)pfVar168 + 0x58));
        return pfVar84;
      case 99:
        goto code_r0x000140094336;
      case 100:
code_r0x000140094428:
        puVar223 = (uint *)((longlong)
                            ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x183
                           );
        *puVar223 = *puVar223 | (uint)_Dst;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x65:
code_r0x00014009439f:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar32;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_5b:
        cVar89 = (char)_Src;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x189);
        *pbVar2 = *pbVar2 | 0xd1;
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400943ae;
        pfVar84 = (fd_set *)FUN_140019e50((longlong)puVar97);
        if ((((ulonglong)pfVar84 & 1) == 0) && ((byte)(cVar89 - 0x30U) < 10)) {
          pfVar84 = (fd_set *)(ulonglong)(byte)(cVar89 - 0x30U);
          ((fd_set *)puVar225)->fd_array[0] = (SOCKET)pfVar84;
          param_3 = (fd_set *)((longlong)param_3->fd_array + 0x29);
        }
        *(fd_set **)puVar225 = param_3;
        return pfVar84;
      case 0x66:
code_r0x0001400943d5:
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        *pbVar2 = *pbVar2 >> 1 | *pbVar2 << 7;
        puVar223 = (uint *)((longlong)
                            ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18b
                           );
        uVar69 = *puVar223;
        *puVar223 = *puVar223 + (uint)_Dst;
        *(uint **)((longlong)puVar149 + -8) = _Dst;
        pcVar83 = (char *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array + 0x21);
        *pcVar83 = *pcVar83 + (char)_Dst + CARRY4(uVar69,(uint)_Dst);
        pbVar2 = (byte *)((longlong)((fd_set *)_Dst)->fd_array + 0x31);
        *pbVar2 = *pbVar2 >> 1 | *pbVar2 << 7;
        param_3->field_0x5 = 0;
        return (fd_set *)UNRECOVERED_JUMPTABLE;
      case 0x67:
switchD_14007f7e4_caseD_7f:
        puVar97 = (uint *)0x190;
code_r0x000140094376:
        pfVar84 = (fd_set *)&DAT_0000001d;
        if (((fd_set *)writefds == (fd_set *)0x0) && ((ulonglong)puVar97 % (ulonglong)param_4 != 0))
        {
          pfVar84 = (fd_set *)0x1c;
        }
        return pfVar84;
      case 0x68:
        goto code_r0x000140094790;
      case 0x69:
code_r0x00014009488d:
        return (fd_set *)UNRECOVERED_JUMPTABLE;
      case 0x6a:
code_r0x0001400947d2:
        pfVar168 = (fd_set *)puVar31;
        *(byte *)&param_3->fd_count = (byte)param_3->fd_count >> 5 | (char)param_3->fd_count << 3;
        LOCK();
        cVar89 = (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count = (char)UNRECOVERED_JUMPTABLE;
        pcVar103 = (char *)CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),cVar89);
        UNLOCK();
        *pcVar103 = *pcVar103 + cVar89;
        puVar225 = (uint *)pcVar83;
        goto code_r0x0001400947d9;
      case 0x6b:
switchD_14007f7e4_caseD_82:
        puVar91 = (undefined1 *)((ulonglong)param_2 & 0xffffffff);
        pfVar168 = (fd_set *)puVar153;
        puVar225 = (uint *)pcVar83;
        goto code_r0x000140094818;
      case 0x6c:
      case 0x73:
code_r0x0001400947b8:
        puVar225 = &pfVar62->fd_count;
        param_3 = (fd_set *)(ulonglong)(uint)param_3->fd_array[2];
        pfVar168 = (fd_set *)puVar152;
code_r0x0001400947bb:
switchD_14009313c_caseD_68:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400947ce;
        cVar89 = (*(code *)pfVar84)(puVar225);
        puVar223 = (uint *)0x1;
        if (cVar89 != '\0') goto LAB_14009485f;
code_r0x0001400947d9:
        bVar239 = true;
        puVar223 = (uint *)&LAB_1400699dc;
        param_2 = (undefined **)&DAT_14010bbb4;
        param_1 = (fd_set *)((longlong)pfVar168 + 0x20);
        goto LAB_1400947ee;
      case 0x6d:
        goto code_r0x000140094758;
      case 0x6e:
      case 0x6f:
      case 0x70:
        goto code_r0x0001400948e8;
      case 0x71:
code_r0x0001400948e0:
        cVar89 = (char)_Dst;
        *(byte *)&param_3->fd_count = (byte)param_3->fd_count >> 4 | (char)param_3->fd_count << 4;
        _Src = (uint *)pcVar103;
        if (bVar239 || bVar240 != bVar237) goto code_r0x0001400948e6;
code_r0x0001400948e5:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        puVar225 = (uint *)pcVar83;
        goto code_r0x0001400948e7;
      case 0x72:
switchD_1400944c0_caseD_a:
        cVar89 = (char)_Dst;
        ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
code_r0x0001400948e6:
        *(char *)&param_3->fd_count = (char)param_3->fd_count + cVar89;
code_r0x0001400948e8:
        _Src = (uint *)CONCAT62((int6)((ulonglong)pcVar103 >> 0x10),CONCAT11(0xcb,(char)pcVar103));
        puVar225 = (uint *)pcVar83;
code_r0x0001400948e7:
        bVar238 = (byte)param_2;
        uVar69 = (uint)param_2 & 0xff;
        uVar70 = uVar69 - 0x81;
        pfVar72 = (fd_set *)(ulonglong)uVar70;
        if (uVar70 < 8) {
code_r0x0001400948f7:
          _Dst = &switchD_140094905::switchdataD_14010ff14;
          writefds = &pfVar72->fd_count;
code_r0x0001400948fe:
          bVar238 = (byte)param_2;
          switch((longlong)((fd_set *)_Dst)->fd_array +
                 (longlong)
                 *(int *)((longlong)((fd_set *)_Dst)->fd_array + (longlong)writefds * 4 + -8) + -8)
          {
          case 0x140094908:
switchD_140094905_caseD_82:
            bVar238 = (byte)param_2;
            uVar63 = 0;
            break;
          case 0x140094968:
switchD_140094905_caseD_81:
            bVar238 = bVar238 & 0x5f;
            uVar63 = 4;
            break;
          case 0x140094a90:
            uVar63 = 3;
            break;
          case 0x140094a94:
            uVar63 = 2;
            break;
          case 0x140094a98:
switchD_140094905_caseD_83:
            pfVar84 = (fd_set *)0x8000000000000000;
            goto LAB_140094ac2;
          }
        }
        else {
          switch(uVar69) {
          case 0xa0:
          case 0xa3:
          case 0xa5:
            goto switchD_140094905_caseD_81;
          default:
            goto switchD_140094905_caseD_83;
          case 0xa4:
            uVar63 = 1;
          }
        }
        *(undefined1 *)((fd_set *)puVar225)->fd_array = uVar63;
        *(byte *)((longlong)((fd_set *)puVar225)->fd_array + 1) = bVar238;
        ((fd_set *)puVar225)->fd_array[1] = (SOCKET)UNRECOVERED_JUMPTABLE;
        ((fd_set *)puVar225)->fd_array[2] = (SOCKET)_Src;
        pfVar84 = (fd_set *)0x8000000000000032;
LAB_140094ac2:
        *(fd_set **)puVar225 = pfVar84;
        return pfVar84;
      case 0x74:
      case 0x77:
      case 0x79:
code_r0x000140094798:
        UNRECOVERED_JUMPTABLE = (code *)swi(1);
        pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
        return pfVar84;
      case 0x75:
      case 0x76:
code_r0x0001400948c8:
        bVar238 = (byte)pcVar103;
        param_3->fd_count = param_3->fd_count + (int)_Dst;
        pcVar103 = (char *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array + 0x34);
        *pcVar103 = *pcVar103 >> ((byte)_Dst & 0x1f);
        pfVar168 = (fd_set *)puVar154;
LAB_1400948d3:
        _Src = (uint *)(ulonglong)bVar238;
        puVar225 = (uint *)pcVar83;
        goto LAB_1400948d6;
      case 0x78:
code_r0x0001400948d4:
        _Src = (uint *)CONCAT62((int6)((ulonglong)pcVar103 >> 0x10),CONCAT11(0xd2,(char)pcVar103));
        pfVar168 = (fd_set *)puVar155;
        puVar225 = (uint *)pcVar83;
LAB_1400948d6:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400948de;
        UNRECOVERED_JUMPTABLE = (code *)FUN_140019a0b((longlong *)param_3,(ulonglong)_Src);
        if ((fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0) {
switchD_14009492e_default:
          *(undefined8 *)puVar225 = 0x8000000000000000;
          *(undefined1 *)((fd_set *)puVar225)->fd_array = 0;
          *(undefined2 *)((longlong)((fd_set *)puVar225)->fd_array + 5) = 0;
          *(undefined1 *)((longlong)((fd_set *)puVar225)->fd_array + 7) = 0;
          *(undefined4 *)((longlong)((fd_set *)puVar225)->fd_array + 1) = 0;
          return (fd_set *)0x0;
        }
        goto code_r0x0001400948e7;
      case 0x7a:
code_r0x000140095255:
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)*(uint *)((longlong)puVar156 + 0x40);
        goto code_r0x0001400951d1;
      case 0x7b:
code_r0x000140095516:
        pcVar103 = (char *)((longlong)((fd_set *)param_2)->fd_array + (longlong)_Dst * 4 + 0x37);
        *pcVar103 = *pcVar103 + (char)_Dst;
        pfVar107 = (fd_set *)puVar157;
        puVar225 = (uint *)pcVar83;
        goto code_r0x00014009551c;
      case 0x7c:
code_r0x000140095429:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x7d:
code_r0x000140095493:
        pfVar107 = (fd_set *)puVar46;
        goto code_r0x000140095492;
      case 0x7e:
        goto code_r0x00014009588d;
      case 0x7f:
code_r0x000140095c38:
        puVar91 = (undefined1 *)
                  ((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x2f02448))->fd_array +
                  0x34);
        *puVar91 = *puVar91;
        pcVar103 = (char *)((longlong)((fd_set *)((longlong)pcVar83 + -0x208))->fd_array + 0x183);
        *pcVar103 = *pcVar103 + (char)((ulonglong)UNRECOVERED_JUMPTABLE >> 8);
        *(char *)&param_3->fd_count = (char)((fd_set *)pcVar83)->fd_count;
        pcVar83 = (char *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xfffffffffffffff5);
        cVar89 = (char)pcVar83 + *pcVar83;
        pcVar83 = (char *)CONCAT71((int7)((ulonglong)pcVar83 >> 8),cVar89);
        *pcVar83 = *pcVar83 + cVar89;
        pfVar233 = (fd_set *)puVar164;
        goto switchD_1400968c1_default;
      case 0x80:
code_r0x000140095b53:
        piVar80 = (int *)((longlong)_Dst * 5 + 0x44);
        *piVar80 = *piVar80 + (int)_Dst;
        UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff40);
        _Src = (uint *)pcVar103;
        pSVar163 = puVar162;
        goto code_r0x000140095b4b;
      case 0x81:
code_r0x000140095bb8:
        *(char *)&pfVar168->fd_count = (char)pfVar168->fd_count + (char)pfVar168;
        pfVar94 = param_3;
        goto code_r0x000140095bb4;
      case 0x82:
code_r0x0001400953e6:
        uVar87 = (undefined7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8);
        cVar89 = (char)UNRECOVERED_JUMPTABLE + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        pcVar78 = (char *)(CONCAT71(uVar87,cVar89) + -0x75);
        *pcVar78 = *pcVar78 + (char)_Dst;
        pfVar107 = (fd_set *)0x21024;
        pcVar78 = (char *)((longlong)((fd_set *)pcVar103)->fd_array + (longlong)_Dst * 4 + -0x7c);
        *pcVar78 = *pcVar78 + cVar89;
        pcVar78 = (char *)(CONCAT71(uVar87,cVar89) & 0xffffffffffffff18);
        cVar89 = (char)pcVar78 + *pcVar78;
        pcVar79 = (char *)CONCAT71((int7)((ulonglong)pcVar78 >> 8),cVar89);
        pcVar78 = (char *)((longlong)((fd_set *)((longlong)param_2 + 0x2192380))->fd_array + 0xfc);
        *pcVar78 = *pcVar78 + (char)_Dst;
        *pcVar79 = *pcVar79 + cVar89;
        goto switchD_1400944c0_caseD_17;
      case 0x83:
        goto code_r0x0001400957d7;
      case 0x84:
code_r0x000140095705:
        pfVar168 = (fd_set *)puVar45;
        uVar81 = (longlong)
                 ((longlong)pcVar103 << 0x20 | (ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff) /
                 (longlong)(int)param_3;
        piVar80 = (int *)(uVar81 & 0xffffffff);
        *(int *)((longlong)piVar80 + -0x39) = *(int *)((longlong)piVar80 + -0x39) + -1;
        *piVar80 = *piVar80 + (int)uVar81;
        *(char *)&((fd_set *)param_2)->fd_count =
             (char)((fd_set *)param_2)->fd_count + (char)piVar80;
        *(char *)piVar80 = (char)*piVar80 + (char)piVar80;
        pcVar103 = (char *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x183);
        *pcVar103 = *pcVar103 + (char)_Dst;
        cVar89 = *(char *)((longlong)&param_3->fd_count + 2);
code_r0x000140095723:
        *(undefined8 *)((longlong)pfVar168 + 0x180) = 4;
        _Dst = (uint *)0x0;
        if (cVar89 == '\0') goto switchD_14009543b_default;
        _Dst = (uint *)(ulonglong)CONCAT11(cVar89,*(undefined1 *)((longlong)&pfVar84->fd_count + 3))
        ;
        goto LAB_140095743;
      case 0x85:
switchD_14007f6e5_caseD_a0:
        ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)pcVar103)->fd_count =
             (char)((fd_set *)pcVar103)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pcVar83 = (char *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array + 7);
        bVar238 = (byte)_Dst;
        *pcVar83 = *pcVar83 + bVar238;
        pcVar83 = (char *)0x85480150;
        *(byte *)&param_3->fd_count =
             (byte)param_3->fd_count >> (bVar238 & 7) | (char)param_3->fd_count << 8 - (bVar238 & 7)
        ;
        uVar87 = (undefined7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8);
        cVar89 = (char)((ulonglong)_Dst >> 8);
        piVar80 = (int *)CONCAT71(uVar87,cVar89 + *(char *)CONCAT71(uVar87,cVar89));
        *(char *)((longlong)piVar80 + -0x73) = *(char *)((longlong)piVar80 + -0x73) + bVar238;
        *(undefined2 *)piVar80 = in_FS;
        *piVar80 = *piVar80 + (int)piVar80;
        *(int *)(((fd_set *)((longlong)pcVar103 + -0x208))->fd_array + 0x3f) =
             (int)((fd_set *)((longlong)pcVar103 + -0x208))->fd_array[0x3f] + -1;
        pfVar168 = (fd_set *)puVar158;
        goto LAB_14009577b;
      case 0x86:
code_r0x000140095c92:
        pfVar168 = (fd_set *)puVar30;
        pcVar83 = (char *)((longlong)((fd_set *)((longlong)param_2 + 0x38922d8))->fd_array + 0x1a4);
        *pcVar83 = *pcVar83 + (char)_Dst;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        goto switchD_14009313c_caseD_73;
      case 0x87:
code_r0x000140095ddb:
        *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) =
             *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) + (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        goto code_r0x000140095dd0;
      case 0x88:
code_r0x000140095d03:
        piVar80 = (int *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x189);
        *piVar80 = *piVar80 + -1;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      case 0x89:
        goto code_r0x000140095d65;
      case 0x8a:
code_r0x00014009669b:
        ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x189)
        ;
        *pcVar83 = *pcVar83 + (char)_Dst;
        pfVar168 = (fd_set *)puVar174;
        goto LAB_1400966a3;
      case 0x8b:
        goto code_r0x0001400967cc;
      case 0x8c:
        goto code_r0x0001400966e5;
      case 0x8d:
code_r0x00014009674c:
        puVar225 = (uint *)((longlong)&((fd_set *)pcVar83)->fd_count + 1);
        bVar238 = (byte)((fd_set *)pcVar83)->fd_count;
        piVar80 = (int *)(CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),bVar238) &
                         0xffffffffffffff20);
        *piVar80 = *piVar80 + (int)piVar80;
        *(char *)((longlong)piVar80 + -0x75) = *(char *)((longlong)piVar80 + -0x75) + (char)_Dst;
        bVar238 = bVar238 & 0x20;
        _Src = (uint *)pcVar103;
        pfVar168 = (fd_set *)puVar176;
        goto LAB_14009674a;
      case 0x8e:
code_r0x00014009620a:
        piVar80 = (int *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        *piVar80 = *piVar80 + -1;
        piVar80 = (int *)(CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),
                                   (char)((fd_set *)pcVar83)->fd_count) & 0xffffffffffffffa0);
        uVar69 = (int)piVar80 + *piVar80;
        puVar91 = (undefined1 *)
                  ((longlong)((fd_set *)((longlong)param_2 + 0x3c12368))->fd_array + 0x114);
        *puVar91 = *puVar91;
        *(char *)(ulonglong)uVar69 = *(char *)(ulonglong)uVar69 + (char)uVar69;
        goto LAB_14009620e;
      case 0x8f:
code_r0x00014009639c:
        puVar225 = (uint *)(ulonglong)*(uint *)((longlong)puVar171 + 0xf0);
        pfVar168 = (fd_set *)puVar171;
        goto code_r0x00014009635d;
      case 0x90:
switchD_14007f7e4_caseD_aa:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x91:
        goto code_r0x000140096320;
      case 0x92:
        goto code_r0x00014009687a;
      case 0x93:
        goto switchD_1400944c0_caseD_5e;
      case 0x94:
code_r0x0001400969f7:
        LOCK();
        *(char *)CONCAT71((int7)((ulonglong)_Dst >> 8),(char)_Dst + (char)param_3->fd_count) =
             (char)((ulonglong)pcVar103 >> 8);
        UNLOCK();
        halt_baddata();
      case 0x95:
switchD_1400944c0_caseD_5a:
        _Src = (uint *)CONCAT62((int6)((ulonglong)pcVar103 >> 0x10),CONCAT11(0x56,(char)pcVar103));
        cVar89 = (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) =
             *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) + cVar89;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        pfVar168 = (fd_set *)puVar189;
        puVar225 = (uint *)pcVar83;
        goto code_r0x000140096a24;
      case 0x96:
code_r0x00014009698b:
        goto code_r0x00014009698a;
      case 0x97:
switchD_14007fde0_caseD_b5:
        goto code_r0x000140096a95;
      case 0x98:
code_r0x000140096ac3:
        uVar81 = 0;
switchD_14007fde0_caseD_c3:
        *(char *)(uVar81 - 0x7d) = *(char *)(uVar81 - 0x7d) + (char)_Dst;
code_r0x000140096ad3:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x99:
switchD_14007fde0_caseD_cc:
        param_3->fd_count = param_3->fd_count - 1;
        _Src = (uint *)CONCAT62((int6)((ulonglong)pcVar103 >> 0x10),CONCAT11(0x46,(char)pcVar103));
        goto code_r0x000140096a30;
      case 0x9a:
code_r0x000140096af0:
        UNRECOVERED_JUMPTABLE = (code *)0x8000000000000025;
        puVar225 = (uint *)pcVar83;
        goto code_r0x000140096afa;
      case 0x9b:
code_r0x0001400969ca:
        cVar89 = (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        *(char *)&((fd_set *)pcVar83)->fd_count = (char)((fd_set *)pcVar83)->fd_count + cVar89;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x185)
        ;
        *pcVar83 = *pcVar83 + (char)_Dst;
        *(byte *)&param_3->fd_count = (byte)param_3->fd_count >> 4 | (char)param_3->fd_count << 4;
        puVar186 = puVar185;
      case 0xab:
code_r0x0001400969d9:
        *(char **)((longlong)puVar186 + -8) = pcVar103;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x9c:
        goto code_r0x000140096ae1;
      case 0x9d:
code_r0x00014009695d:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0x9e:
switchD_14009313c_caseD_8a:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        *(char *)&param_3->fd_count = (char)param_3->fd_count + (char)puVar97;
        halt_baddata();
      case 0x9f:
code_r0x000140096ab4:
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)((uint)UNRECOVERED_JUMPTABLE | 0x794f3);
        goto switchD_14009313c_caseD_9a;
      case 0xa0:
code_r0x000140096930:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar44;
switchD_14009313c_caseD_a8:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) =
             *(char *)((longlong)UNRECOVERED_JUMPTABLE * 2) + (char)UNRECOVERED_JUMPTABLE;
        goto code_r0x00014009693b;
      case 0xa1:
switchD_1400944c0_caseD_2f:
        puVar225 = &pfVar62->fd_count;
        uVar69 = (int)UNRECOVERED_JUMPTABLE + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        *(char *)(ulonglong)uVar69 = *(char *)(ulonglong)uVar69 + (char)uVar69;
        pfVar16 = (fd_set *)puVar188;
        goto code_r0x000140096a0a;
      case 0xa2:
code_r0x000140096912:
        LOCK();
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count = (char)param_2;
        UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xa3:
switchD_14007fde0_caseD_b8:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18d)
        ;
        *pcVar83 = *pcVar83 + (char)_Dst;
        *(undefined2 *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count = in_FS;
        bVar238 = (char)UNRECOVERED_JUMPTABLE + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        bVar64 = (byte)((ulonglong)_Dst >> 8);
        bVar90 = bVar238 + bVar64;
        *(ulonglong *)((longlong)puVar193 + -8) =
             (ulonglong)(in_NT & 1) * 0x4000 | (ulonglong)SCARRY1(bVar238,bVar64) * 0x800 |
             (ulonglong)(in_IF & 1) * 0x200 | (ulonglong)(in_TF & 1) * 0x100 |
             (ulonglong)((char)bVar90 < '\0') * 0x80 | (ulonglong)(bVar90 == 0) * 0x40 |
             (ulonglong)(in_AF & 1) * 0x10 | (ulonglong)((POPCOUNT(bVar90) & 1U) == 0) * 4 |
             (ulonglong)CARRY1(bVar238,bVar64) | (ulonglong)(in_ID & 1) * 0x200000 |
             (ulonglong)(in_VIP & 1) * 0x100000 | (ulonglong)(in_VIF & 1) * 0x80000 |
             (ulonglong)(in_AC & 1) * 0x40000;
        return (fd_set *)(ulonglong)bVar90;
      case 0xa4:
code_r0x000140096ad2:
        pfVar168 = (fd_set *)puVar43;
        param_3 = (fd_set *)(ulonglong)((int)param_3 + 8);
        goto switchD_14009313c_caseD_9b;
      case 0xa5:
        goto code_r0x000140096b60;
      case 0xa6:
switchD_14007fde0_caseD_a9:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xa7:
code_r0x000140096aa5:
        puVar91 = &((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4;
        *puVar91 = (char)*puVar91 >> 8;
        UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
        if ((char)*puVar91 < '\0') {
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)pcVar103 & 0xffffffff);
        }
        goto switchD_14009313c_caseD_9a;
      case 0xa8:
        goto code_r0x000140096b42;
      case 0xa9:
code_r0x000140096b7e:
        cVar89 = (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x31c40))->fd_array + 0x1a1
                          );
        *pcVar83 = *pcVar83 + cVar89;
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] +
             (char)_Dst;
        ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count & (uint)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
      case 0xae:
code_r0x000140096b8d:
        bVar238 = (byte)UNRECOVERED_JUMPTABLE;
        *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x30e08))->fd_array + 0xd9)
        ;
        *pcVar83 = *pcVar83 + bVar238;
        cVar89 = (char)_Dst;
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] + cVar89;
        *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count ^ bVar238;
        *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
        *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x2ffd0))->fd_array + 0x11)
        ;
        *pcVar83 = *pcVar83 + bVar238;
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] + cVar89;
        uVar69 = (uint)UNRECOVERED_JUMPTABLE | ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        pcVar83 = (char *)(ulonglong)uVar69;
        cVar88 = (char)uVar69;
        *pcVar83 = *pcVar83 + cVar88;
        *pcVar83 = *pcVar83 + cVar88;
        pcVar83[0x2f0e9] = pcVar83[0x2f0e9] + cVar88;
        goto code_r0x000140096bb3;
      case 0xaa:
        goto switchD_14007fde0_caseD_aa;
      case 0xac:
code_r0x000140096c46:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        uVar87 = (undefined7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8);
        cVar89 = (char)UNRECOVERED_JUMPTABLE + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        pcVar103 = (char *)CONCAT71(uVar87,cVar89);
        pcVar103[-0x48] = pcVar103[-0x48] + (char)_Dst + -0x56;
        uVar244 = LocalDescriptorTableRegister();
        *(undefined4 *)pcVar103 = uVar244;
        *pcVar103 = *pcVar103 + cVar89;
        *pcVar103 = *pcVar103 + cVar89;
        _Dst = (uint *)(ulonglong)(byte)((char)_Dst + 99);
        UNRECOVERED_JUMPTABLE = (code *)CONCAT71(uVar87,cVar89 + *pcVar103);
        pfVar62 = (fd_set *)pcVar83;
      case 0xc0:
code_r0x000140096c52:
        puVar225 = &pfVar62->fd_count;
        cVar89 = (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x246f8))->fd_array + 0xe9)
        ;
        *pcVar83 = *pcVar83 + cVar89;
        bVar238 = CARRY1((byte)param_3->fd_count,(byte)_Dst);
        *(byte *)&param_3->fd_count = (char)param_3->fd_count + (byte)_Dst;
switchD_14009313c_caseD_a3:
        *(byte *)param_3->fd_array =
             (char)param_3->fd_array[0] + (char)UNRECOVERED_JUMPTABLE + bVar238;
        ((fd_set *)puVar225)->fd_array[0] = SVar82;
        ((fd_set *)puVar225)->fd_array[1] = SVar76;
        UNRECOVERED_JUMPTABLE = (code *)0x8000000000000003;
        goto LAB_140096ea4;
      case 0xad:
code_r0x0001400968f4:
        *(char *)&param_3->fd_count = (char)param_3->fd_count + (char)_Dst;
        *(undefined8 **)((longlong)puVar180 + -8) = puVar180;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xaf:
code_r0x000140096c2e:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        UNRECOVERED_JUMPTABLE = (code *)0x8000000000000018;
        pfVar62 = (fd_set *)pcVar83;
      case 0xb8:
code_r0x000140096c3a:
        puVar225 = &pfVar62->fd_count;
        goto LAB_140096ea4;
      case 0xb0:
code_r0x000140096aff:
        _Src = (uint *)param_3->fd_array;
        puVar97 = (uint *)((fd_set *)pcVar83)->fd_array;
        puVar225 = (uint *)pcVar83;
        goto switchD_14007f6e5_caseD_c6;
      case 0xb1:
code_r0x000140096a52:
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        goto code_r0x000140096a4e;
      case 0xb2:
code_r0x000140096b14:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        bVar238 = (char)_Dst + 0x7a;
        puVar97 = (uint *)(ulonglong)bVar238;
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)
                     ((int)UNRECOVERED_JUMPTABLE + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
        *(byte *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] + bVar238;
switchD_14009313c_caseD_8e:
        uVar69 = (uint)UNRECOVERED_JUMPTABLE & ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)uVar69;
        cVar89 = (char)uVar69;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x377a8))->fd_array + 0x39)
        ;
        *pcVar83 = *pcVar83 + cVar89;
        goto code_r0x000140096b2c;
      case 0xb3:
code_r0x00014009693f:
        iRam0000000132f1eb54 = iRam0000000132f1eb54 + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xb4:
code_r0x000140096903:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar42;
        piVar80 = (int *)((longlong)((fd_set *)((longlong)puVar223 + -0x208))->fd_array + 0x18d);
        *piVar80 = *piVar80 + -1;
switchD_14009313c_caseD_a9:
        bVar238 = (byte)puVar97;
        puVar91 = (undefined1 *)pfVar168;
        goto code_r0x000140096909;
      case 0xb5:
code_r0x0001400968d6:
        pfVar168 = (fd_set *)puVar29;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_ab:
        bVar90 = (byte)UNRECOVERED_JUMPTABLE;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)_Src + -0x3f7bfdd8))->fd_array + 0x16);
        *pbVar2 = *pbVar2 + (char)puVar97;
        bVar238 = *pbVar2;
        goto code_r0x0001400968de;
      case 0xb6:
code_r0x0001400968e5:
        if ((bool)bVar238) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
switchD_14009313c_caseD_b5:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xb7:
code_r0x0001400968a8:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xb9:
        goto code_r0x000140096b51;
      case 0xba:
code_r0x0001400969ac:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xbb:
switchD_14007fde0_caseD_b0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xbc:
        goto code_r0x000140096b6f;
      case 0xbd:
code_r0x000140096889:
        cVar88 = (char)((ulonglong)_Dst >> 8);
        cVar89 = (char)UNRECOVERED_JUMPTABLE + cVar88;
        if (cVar89 == '\0' || SCARRY1((char)UNRECOVERED_JUMPTABLE,cVar88) != cVar89 < '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xbe:
code_r0x000140096921:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar28;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        goto switchD_14007f6e5_caseD_b3;
      case 0xbf:
code_r0x000140096b23:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        puVar97 = (uint *)(ulonglong)(byte)((char)_Dst + 0x89);
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)
                     ((int)UNRECOVERED_JUMPTABLE + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
code_r0x000140096b2c:
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] +
             (char)puVar97;
switchD_14009313c_caseD_a4:
        piVar80 = (int *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff00);
        *(char *)piVar80 = (char)*piVar80;
        *(char *)piVar80 = (char)*piVar80;
        *(undefined1 *)((longlong)piVar80 + 0x368e9) = *(undefined1 *)((longlong)piVar80 + 0x368e9);
        pbVar2 = (byte *)(piVar80 + -0x12);
        bVar238 = *pbVar2;
        *pbVar2 = *pbVar2 + (byte)puVar97;
        uVar69 = ((int)piVar80 - *piVar80) - (uint)CARRY1(bVar238,(byte)puVar97);
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)uVar69;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)uVar69;
code_r0x000140096b42:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_a6:
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x35930))->fd_array + 0xb1)
        ;
        *pcVar83 = *pcVar83 + (byte)UNRECOVERED_JUMPTABLE;
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] +
             (char)puVar97;
        bVar238 = (byte)UNRECOVERED_JUMPTABLE & (byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
        UNRECOVERED_JUMPTABLE =
             (code *)CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),bVar238);
        *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
code_r0x000140096b51:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_b3:
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x348f0))->fd_array + 0x1f1
                          );
        cVar89 = (char)UNRECOVERED_JUMPTABLE;
        *pcVar83 = *pcVar83 + cVar89;
        pSVar163 = ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37;
        SVar82 = *pSVar163;
        *(byte *)pSVar163 = (char)*pSVar163 + (byte)puVar97;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89 +
             CARRY1((byte)SVar82,(byte)puVar97);
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        _Dst = puVar97;
code_r0x000140096b60:
        cVar89 = (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x33ab8))->fd_array + 0x129
                          );
        *pcVar83 = *pcVar83 + cVar89;
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] +
             (char)_Dst;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
code_r0x000140096b6f:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x32c80))->fd_array + 0x61)
        ;
        *pcVar83 = *pcVar83 + (char)UNRECOVERED_JUMPTABLE;
        *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x37) =
             (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array[0x37] +
             (char)_Dst;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xc1:
code_r0x0001400968b7:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xc2:
code_r0x00014009694e:
        UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffffd8);
        goto code_r0x000140096946;
      case 0xc3:
        goto code_r0x00014009696c;
      case 0xc4:
code_r0x000140096ffd:
        goto code_r0x000140096ffc;
      case 0xc5:
code_r0x0001400970df:
        piVar80 = (int *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x189);
        *piVar80 = *piVar80 + -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xc6:
        goto code_r0x000140097024;
      case 199:
switchD_14007f7e4_caseD_de:
        pfVar107 = (fd_set *)puVar41;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x189)
        ;
        *pcVar83 = *pcVar83 - (char)param_4;
        _Src = (uint *)pcVar103;
code_r0x00014009707f:
        puVar197 = (undefined1 *)pfVar107;
        goto code_r0x00014009705b;
      case 200:
code_r0x0001400971b9:
        ((fd_set *)_Dst)->fd_count = ((fd_set *)_Dst)->fd_count + 1;
LAB_1400971b7:
        if (param_3 != (fd_set *)((longlong)&uRam0000000000000000 + 1)) goto LAB_140097217;
        goto LAB_14009720d;
      case 0xc9:
        goto code_r0x00014009750e;
      case 0xca:
code_r0x000140097408:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xcb:
        goto code_r0x00014009743c;
      case 0xcc:
code_r0x00014009735d:
        out((short)pcVar103,(int)UNRECOVERED_JUMPTABLE);
                    /* WARNING: Could not emulate address calculation at 0x000140097360 */
                    /* WARNING: Treating indirect jump as call */
        pfVar84 = (fd_set *)
                  (*(code *)(ulonglong)
                            *(uint *)((longlong)
                                      ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x417af238))->
                                      fd_array + 0x131))();
        return pfVar84;
      case 0xcd:
switchD_14007f6e5_caseD_fa:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_e5:
        UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
        goto code_r0x0001400975a0;
      case 0xce:
code_r0x000140097641:
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        bVar90 = (byte)_Dst;
        *pbVar2 = *pbVar2 | bVar90;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18d);
        bVar238 = *pbVar2;
        *pbVar2 = *pbVar2 - bVar90;
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x7394e + (uint)(bVar238 < bVar90));
        goto LAB_140097b64;
      case 0xcf:
code_r0x0001400974a5:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xd0:
code_r0x000140097692:
        pfVar168 = (fd_set *)puVar40;
        UNRECOVERED_JUMPTABLE = (code *)0x4010af19;
        goto code_r0x00014009767b;
      case 0xd1:
code_r0x0001400973bd:
        puVar225 = (uint *)pcVar83;
        goto code_r0x0001400973b8;
      case 0xd2:
code_r0x000140097675:
        pfVar168 = (fd_set *)puVar27;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        if (SCARRY1((char)_Dst,(char)((ulonglong)_Dst >> 8))) {
          UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff60);
        }
code_r0x00014009767b:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        param_4 = (fd_set *)((longlong)pfVar168 + 0x60);
        *(code **)param_4 = UNRECOVERED_JUMPTABLE;
        *(code **)((longlong)pfVar168 + 0x20) = FUN_14009801d;
        pcVar83 = &DAT_14010af19;
        writefds = (uint *)&DAT_00000013;
        goto LAB_140097aed;
      case 0xd3:
        goto code_r0x00014009731c;
      case 0xd4:
        goto code_r0x0001400973a0;
      case 0xd5:
code_r0x000140097624:
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        bVar90 = (byte)_Dst;
        *pbVar2 = *pbVar2 | bVar90;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18d);
        bVar238 = *pbVar2;
        *pbVar2 = *pbVar2 - bVar90;
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x73d3f + (uint)(bVar238 < bVar90));
switchD_14009313c_caseD_d1:
        goto LAB_140097b64;
      case 0xd6:
        goto code_r0x0001400972d1;
      case 0xd7:
code_r0x00014009741f:
        bVar237 = CARRY1((byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count,
                         (byte)UNRECOVERED_JUMPTABLE);
        *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (byte)UNRECOVERED_JUMPTABLE;
        goto code_r0x000140097421;
      case 0xd8:
code_r0x0001400972a3:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)((longlong)puVar201 + -8);
        *(undefined8 **)((longlong)puVar201 + -8) = puVar201;
        UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff70);
        goto code_r0x00014009729c;
      case 0xd9:
code_r0x000140097548:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pfVar168 = (fd_set *)puVar215;
code_r0x00014009754a:
        *(code **)((longlong)pfVar168 + 0x20) = UNRECOVERED_JUMPTABLE;
        pcVar83 = &DAT_14010b33d;
        writefds = (uint *)0x33;
        goto LAB_140097aed;
      case 0xda:
code_r0x00014009765e:
        piVar80 = (int *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18d);
        *piVar80 = *piVar80 + (int)_Dst;
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x505);
        _Src = (uint *)pcVar103;
        pfVar168 = (fd_set *)puVar216;
code_r0x000140097666:
        *(code **)((longlong)pfVar168 + 0x20) = UNRECOVERED_JUMPTABLE;
        pcVar83 = "UnsupportedSignatureAlgorithmForPublicKeyContext";
        writefds = (uint *)&DAT_00000030;
        goto LAB_140097aed;
      case 0xdb:
        goto code_r0x000140097751;
      case 0xdc:
code_r0x00014009757c:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
        goto LAB_140097b64;
      case 0xdd:
code_r0x000140097607:
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18b)
        ;
        *pcVar83 = *pcVar83 + (byte)_Dst;
        bVar238 = (byte)_Dst |
                  *(byte *)((longlong)
                            ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18b
                           );
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        *pbVar2 = *pbVar2 | bVar238;
        goto switchD_14007f7e4_caseD_eb;
      case 0xde:
code_r0x000140097720:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_e9:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
        goto LAB_140097b64;
      case 0xdf:
code_r0x00014009778b:
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE - 0x650b7);
        puVar97 = _Dst;
        pfVar168 = (fd_set *)puVar218;
        goto code_r0x000140097773;
      case 0xe0:
code_r0x0001400973eb:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar26;
        _Src = (uint *)(ulonglong)((uint)pcVar103 | (uint)_Dst);
        goto switchD_14009313c_caseD_c5;
      case 0xe1:
        goto code_r0x0001400973d4;
      case 0xe2:
code_r0x000140097812:
        pfVar168 = (fd_set *)puVar25;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18d)
        ;
        *pcVar83 = *pcVar83 + (char)_Dst;
        goto code_r0x000140097815;
      case 0xe3:
        goto code_r0x000140097275;
      case 0xe4:
code_r0x0001400977a8:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pfVar168 = (fd_set *)puVar219;
        goto code_r0x0001400977ac;
      case 0xe5:
code_r0x0001400977de:
        *(uint **)((longlong)pfVar77 + 0x48) = writefds;
        *(undefined **)((longlong)pfVar77 + 0x38) = &DAT_14010af5a;
        *(code **)((longlong)pfVar77 + 0x30) = FUN_1400326d9;
        _Dst = puVar97;
        pfVar168 = pfVar77;
        goto code_r0x0001400977fe;
      case 0xe6:
code_r0x0001400976af:
        goto LAB_140097b64;
      case 0xe7:
code_r0x00014009752b:
        goto LAB_140097b64;
      case 0xe8:
code_r0x0001400976d9:
        LOCK();
        uVar244 = *(undefined4 *)((longlong)UNRECOVERED_JUMPTABLE * 2);
        *(undefined4 *)((longlong)UNRECOVERED_JUMPTABLE * 2) = (int)UNRECOVERED_JUMPTABLE;
        UNRECOVERED_JUMPTABLE =
             (code *)CONCAT44((int)((ulonglong)UNRECOVERED_JUMPTABLE >> 0x20),uVar244);
        UNLOCK();
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18b)
        ;
        *pcVar83 = *pcVar83 + (char)_Dst;
        puVar97 = _Dst;
switchD_14009313c_caseD_da:
        bVar90 = (byte)puVar97 |
                 *(byte *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18b)
        ;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        *pbVar2 = *pbVar2 | bVar90;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18d);
        bVar238 = *pbVar2;
        *pbVar2 = *pbVar2 - bVar90;
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x73887 + (uint)(bVar238 < bVar90));
        goto LAB_140097b64;
      case 0xe9:
code_r0x0001400972e8:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar39;
        if (bVar237) {
          *(char *)&param_3->fd_count = (char)param_3->fd_count + (char)_Dst;
          _Src = (uint *)((ulonglong)_Src & 0xff);
          pcVar83 = (char *)puVar225;
        }
        else {
switchD_14009313c_caseD_e8:
          *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
          pcVar83 = (char *)puVar225;
        }
        goto LAB_1400972ec;
      case 0xea:
code_r0x00014009728c:
        *(byte *)&param_3->fd_count = (byte)param_3->fd_count >> 4 | (char)param_3->fd_count << 4;
        pfVar84 = (fd_set *)((ulonglong)puVar199 & 0xffffffff);
        puVar200 = (undefined1 *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
        pfVar84->fd_count = pfVar84->fd_count + (int)puVar199;
        pcVar103 = (char *)((longlong)pfVar84[-0x3c8665].fd_array + 0x11b);
        *pcVar103 = *pcVar103 + (char)pfVar84;
        UNRECOVERED_JUMPTABLE = (code *)pfVar84;
        puVar52 = puVar200;
        puVar225 = (uint *)pcVar83;
        goto code_r0x000140097298;
      case 0xeb:
code_r0x000140097241:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar24;
        pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x18d);
        *pcVar83 = *pcVar83 + (char)_Dst;
        UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff1e);
        goto switchD_14009313c_caseD_eb;
      case 0xec:
        goto code_r0x00014009725e;
      case 0xed:
code_r0x000140097200:
        *(int *)(((fd_set *)pcVar83)->fd_array + 1) = (int)param_3;
        return (fd_set *)UNRECOVERED_JUMPTABLE;
      case 0xee:
code_r0x0001400977f8:
        piVar80 = (int *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x189);
        *piVar80 = *piVar80 + -1;
        _Src = (uint *)pcVar103;
        pfVar168 = (fd_set *)puVar220;
code_r0x0001400977fe:
        *(uint **)((longlong)pfVar168 + 0x28) = _Dst;
        *(undefined8 *)((longlong)pfVar168 + 0x40) = 0xb;
        *(undefined8 *)((longlong)pfVar168 + 0x20) = 4;
code_r0x000140097815:
        puVar102 = &DAT_14010af50;
        uVar241 = 10;
        goto switchD_1400944c0_caseD_7c;
      case 0xef:
code_r0x00014009773d:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)pcVar103)->fd_array[0] + 0x18);
code_r0x000140097751:
        goto LAB_140097b64;
      case 0xf0:
        goto code_r0x000140097383;
      case 0xf1:
code_r0x000140097565:
        UNRECOVERED_JUMPTABLE = *(code **)((ulonglong)(uint)((fd_set *)_Src)->fd_array[0] + 0x18);
        goto LAB_140097b64;
      case 0xf2:
code_r0x00014009776e:
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x9a7);
        puVar97 = _Dst;
        pfVar168 = (fd_set *)puVar217;
code_r0x000140097773:
        *(code **)((longlong)pfVar168 + 0x50) = UNRECOVERED_JUMPTABLE;
        *(uint **)((longlong)pfVar168 + 0x48) = writefds;
        *(undefined **)((longlong)pfVar168 + 0x38) = &DAT_14010af10;
        *(code **)((longlong)pfVar168 + 0x30) = FUN_1400326d9;
        *(uint **)((longlong)pfVar168 + 0x28) = puVar97;
        *(undefined8 *)((longlong)pfVar168 + 0x40) = 9;
        *(undefined8 *)((longlong)pfVar168 + 0x20) = 4;
code_r0x0001400977ac:
        puVar102 = &DAT_14010af01;
        uVar241 = 0xb;
switchD_1400944c0_caseD_7c:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140097922;
        pfVar84 = (fd_set *)
                  FUN_140008ba0((undefined8 *)_Src,puVar102,uVar241,0x14010af0c,
                                *(ulonglong *)((longlong)pfVar168 + 0x20),
                                *(undefined8 *)((longlong)pfVar168 + 0x28),
                                *(undefined **)((longlong)pfVar168 + 0x30),
                                *(longlong *)((longlong)pfVar168 + 0x38),
                                *(ulonglong *)((longlong)pfVar168 + 0x40),
                                *(undefined8 *)((longlong)pfVar168 + 0x48),
                                *(undefined **)((longlong)pfVar168 + 0x50));
        return pfVar84;
      case 0xf3:
code_r0x0001400971d6:
        puVar225 = &pfVar62->fd_count;
        pfVar168 = (fd_set *)puVar38;
        uVar69 = (int)param_3 - 1;
        param_3 = (fd_set *)(ulonglong)uVar69;
        pcVar83 = (char *)puVar225;
        if (uVar69 != 0) {
          param_1 = (fd_set *)((longlong)&param_1->fd_count + 1);
          pfVar84 = (fd_set *)param_2;
          if (-1 < (char)param_1->fd_count) {
LAB_1400971e3:
            UNRECOVERED_JUMPTABLE = (code *)pfVar84;
            SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x20);
            SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x28);
            SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x38);
            ((fd_set *)puVar225)->fd_array[4] = *(SOCKET *)((longlong)pfVar168 + 0x30);
            ((fd_set *)puVar225)->fd_array[5] = SVar236;
            ((fd_set *)puVar225)->fd_array[2] = SVar82;
            ((fd_set *)puVar225)->fd_array[3] = SVar76;
            *(code **)puVar225 = UNRECOVERED_JUMPTABLE;
            ((fd_set *)puVar225)->fd_array[0] = (SOCKET)param_1;
code_r0x0001400971ff:
            ((fd_set *)puVar225)->fd_array[1] = (SOCKET)param_3;
            return (fd_set *)UNRECOVERED_JUMPTABLE;
          }
          goto LAB_1400971b7;
        }
LAB_14009720d:
        bVar238 = (byte)param_1->fd_count;
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)bVar238;
        *(byte *)((fd_set *)pcVar83)->fd_array = bVar238;
        param_2 = (undefined **)((longlong)((fd_set *)param_2)->fd_array + 0x2a);
LAB_140097217:
        *(undefined ***)pcVar83 = param_2;
        return (fd_set *)UNRECOVERED_JUMPTABLE;
      case 0xf4:
code_r0x0001400972ba:
        puVar202 = (undefined1 *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
        UNRECOVERED_JUMPTABLE = (code *)((ulonglong)puVar203 & 0xffffffa0);
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pcVar78 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x185)
        ;
        *pcVar78 = *pcVar78 + (byte)_Dst;
        pcVar78 = (char *)((longlong)(((fd_set *)puVar223)->fd_array + 8) + (longlong)pcVar103);
        *pcVar78 = *pcVar78 << ((byte)_Dst & 0x1f);
        *(undefined4 *)(puVar202 + 0xa8) = 1;
        puVar204 = (undefined8 *)puVar202;
        goto code_r0x0001400972d1;
      case 0xf5:
code_r0x0001400976f6:
        bVar90 = (byte)_Dst |
                 *(byte *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18b)
        ;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18b);
        *pbVar2 = *pbVar2 | bVar90;
        pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                         + 0x18d);
        bVar238 = *pbVar2;
        *pbVar2 = *pbVar2 - bVar90;
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x739f0 + (uint)(bVar238 < bVar90));
        goto LAB_140097b64;
      case 0xf6:
code_r0x00014009782c:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
        goto LAB_140097b64;
      case 0xf7:
        goto LAB_140097217;
      case 0xf8:
code_r0x0001400972ff:
        pfVar168 = (fd_set *)puVar23;
        UNRECOVERED_JUMPTABLE = (code *)(ulonglong)((uint)UNRECOVERED_JUMPTABLE | 0x78d70);
        goto code_r0x0001400972fd;
      case 0xf9:
code_r0x000140097333:
        pcVar78 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x189)
        ;
        *pcVar78 = *pcVar78 + (char)_Dst;
        _Src = (uint *)pcVar103;
        pfVar168 = (fd_set *)puVar206;
        puVar225 = (uint *)pcVar83;
        goto switchD_14009730b_caseD_83;
      case 0xfa:
code_r0x000140098fc3:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        pbVar2 = (byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array + 0x31);
        *pbVar2 = *pbVar2 | 0x84;
        pcVar103 = (char *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffffa0);
        *pcVar103 = *pcVar103 + (char)pcVar103;
        *(char *)&param_3->fd_count = (char)param_3->fd_count + (char)_Dst;
        LOCK();
        param_3->fd_count = (u_int)pcVar83;
        UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 0xfb:
      case 0xfd:
        goto code_r0x000140098f85;
      case 0xfc:
code_r0x000140098ff6:
        pfVar168 = (fd_set *)puVar21;
        uVar15 = param_3->fd_count;
        *(byte *)&param_3->fd_count = (char)param_3->fd_count + (byte)puVar97;
        *(char *)((longlong)pfVar168 + 0xc0) =
             *(char *)((longlong)pfVar168 + 0xc0) + (char)pcVar103 +
             CARRY1((byte)uVar15,(byte)puVar97);
        goto code_r0x000140098ff7;
      case 0xfe:
code_r0x000140098f73:
        *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
        bVar238 = (byte)((ulonglong)_Dst >> 8);
        bVar90 = (byte)param_2;
        param_2 = (undefined **)CONCAT71((int7)((ulonglong)param_2 >> 8),bVar90 + bVar238);
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)
                     ((int)UNRECOVERED_JUMPTABLE + 0x24b48948 + (uint)CARRY1(bVar90,bVar238));
        *(char *)&((fd_set *)_Dst)->fd_count = (char)((fd_set *)_Dst)->fd_count;
        pcVar83 = (char *)((longlong)
                           ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x18d)
        ;
        *pcVar83 = *pcVar83 + (char)_Dst;
        *(undefined2 *)((longlong)UNRECOVERED_JUMPTABLE * 9) = in_FS;
        puVar22 = puVar221;
code_r0x000140098f85:
        pfVar168 = (fd_set *)puVar22;
        ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
             ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
        puVar225 = (uint *)0xc6fffff4;
        uVar81 = CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),
                          (char)UNRECOVERED_JUMPTABLE + (char)((ulonglong)_Dst >> 8));
        piVar80 = (int *)((uVar81 & 0xffffffffffffff50) - 0x75);
        *piVar80 = *piVar80 + (int)_Dst;
        uVar81 = uVar81 & 0xffffffffffffff40;
        goto code_r0x000140098f97;
      case 0xff:
code_r0x000140099405:
        puVar225 = &pfVar62->fd_count;
        pfVar107 = (fd_set *)puVar222;
        if ((int)param_3 != 8) {
          if (param_3 != (fd_set *)&DAT_00000020) goto LAB_140099556;
          goto LAB_140099414;
        }
code_r0x000140099437:
        *(undefined8 *)((longlong)pfVar107 + 0x98) = 0x8000000000000000;
        *(fd_set **)((longlong)pfVar107 + 0x130) = pfVar227;
        *(fd_set **)((longlong)pfVar107 + 0x138) = param_3;
        *(undefined8 *)((longlong)pfVar107 + 0x140) = 0;
        _Src = (uint *)((ulonglong)param_3 >> 1);
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140099470;
        pfVar227 = (fd_set *)_Src;
        pfVar233 = (fd_set *)FUN_140019a0b((longlong *)puVar223,(ulonglong)_Src);
        if (pfVar233 == (fd_set *)0x0) {
          ppuVar231 = &PTR_s_C__Users_flare__cargo_registry_s_14010b6f0;
          goto LAB_140099726;
        }
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009948a;
        pfVar234 = (fd_set *)FUN_140019a0b((longlong *)puVar223,(ulonglong)_Src);
        if (pfVar234 == (fd_set *)0x0) {
          ppuVar231 = &PTR_s_C__Users_flare__cargo_registry_s_14010b708;
          goto LAB_140099726;
        }
code_r0x000140099493:
        if (*(longlong *)((longlong)pfVar107 + 0x140) != *(longlong *)((longlong)pfVar107 + 0x138))
        {
          lVar96 = -0x8000000000000000;
          *(undefined8 *)((longlong)pfVar107 + 0x50) = 0x8000000000000000;
          *(fd_set **)((longlong)pfVar107 + 0x58) = pfVar233;
          *(fd_set **)((longlong)pfVar107 + 0x68) = pfVar234;
          pfVar168 = pfVar107;
          goto LAB_140099565;
        }
        *(uint **)((longlong)pfVar107 + 0xe8) = _Src;
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400994bc;
        FUN_14009350d((ulonglong *)param_1);
        in_R10 = *(fd_set **)((longlong)pfVar107 + 0xe8);
        UNRECOVERED_JUMPTABLE = (code *)0x0;
        puVar97 = (uint *)0x0;
        param_3 = pfVar234;
        goto LAB_1400994c8;
      }
      if (cVar89 != '#') {
        bVar239 = true;
        pcVar83 = (char *)puVar225;
LAB_140086a30:
        *(fd_set **)((longlong)pfVar107 + 0x90) = pfVar84;
code_r0x000140086a38:
        param_3 = *(fd_set **)((longlong)pfVar107 + 0x60);
        _Dst = *(uint **)((longlong)pfVar107 + 0x218);
        cVar88 = *(char *)((longlong)pfVar107 + 0x220);
        param_1 = (fd_set *)
                  ((longlong)param_1->fd_array +
                  (longlong)(((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x3f));
        *(fd_set **)((longlong)pfVar107 + 0x48) = param_1;
        pfVar72 = *(fd_set **)((longlong)pfVar107 + 0xa8);
        if (bVar239) goto LAB_140087062;
        goto code_r0x000140086a64;
      }
      *(fd_set **)((longlong)pfVar107 + 0xf0) = pfVar227;
      *(undefined **)((longlong)pfVar107 + -8) = &UNK_140086a1f;
      FUN_1400759ea((ulonglong *)param_2);
    } while( true );
  case 0x22:
    goto code_r0x000140086980;
  case 0x23:
  case 0x24:
code_r0x000140086973:
    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    cVar89 = (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
    pfVar107 = (fd_set *)auStackY_88;
    goto code_r0x000140086977;
  case 0x25:
    goto code_r0x000140089986;
  case 0x26:
code_r0x0001400898fa:
  case 0x27:
  case 0x28:
code_r0x0001400898f0:
    (&UNK_14010fc69)[uVar71] = (&UNK_14010fc69)[uVar71] + (byte)_Dst;
    puVar223 = (uint *)(&UNK_14010fc69 + uVar71);
    bVar238 = (byte)_Dst & 0x1f;
    *puVar223 = *puVar223 >> bVar238 | *puVar223 << 0x20 - bVar238;
    local_60._0_8_ = (fd_set *)0x0;
    local_60._8_8_ = (longlong)&uRam0000000000000000 + 1;
    local_50 = (fd_set *)0x0;
    param_3 = (fd_set *)0x19001;
    uVar81 = 0;
    pfVar84 = (fd_set *)&stack0xffffffffffffffe0;
    puVar223 = &UINT_14010fd74;
    puVar225 = (uint *)0x8000000000000000;
    pfVar107 = (fd_set *)auStackY_88;
    goto LAB_14008993b;
  case 0x29:
    goto code_r0x00014008a981;
  case 0x2a:
switchD_14007f7e4_caseD_23:
    iVar66 = (int)writefds;
    SVar82 = (SOCKET)(uVar69 + 0x3d85e + (uint)bVar237);
    goto code_r0x00014008a9ab;
  case 0x2b:
code_r0x00014008a9a5:
    iVar66 = (int)writefds;
    SVar82 = (SOCKET)(uint)DAT_140110580;
    puVar112 = auStackY_88;
    goto code_r0x00014008a9ab;
  case 0x2c:
code_r0x00014008a9b3:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count | bVar238;
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Dst + 0x1efa0))->fd_array + 0xdd);
    *pcVar83 = *pcVar83 + (char)_Dst;
    (&UNK_14010fc69)[uVar71] = (&UNK_14010fc69)[uVar71] + (char)_Dst;
    UNRECOVERED_JUMPTABLE = (code *)swi(1);
    pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
    return pfVar84;
  case 0x2d:
code_r0x00014009308a:
    _Src = (uint *)((ulonglong)param_4 & 0xffffffff);
    pfVar72 = (fd_set *)((ulonglong)writefds & 0xffffffff);
    writefds = (uint *)&PTR_s_C__Users_flare__cargo_registry_s_14010aae8;
    in_R10 = (fd_set *)_Dst;
    break;
  case 0x2e:
code_r0x0001400930a7:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x2f:
code_r0x00014009308f:
    puVar223 = (uint *)((longlong)_Dst * 5 + -0x36);
    *puVar223 = *puVar223 << 0xc | *puVar223 >> 0x14;
    UNRECOVERED_JUMPTABLE = (code *)0x4010aae8;
    pfVar72 = (fd_set *)_Dst;
    break;
  case 0x30:
    break;
  case 0x31:
code_r0x0001400931ea:
    *(int *)(&UNK_14010fc6b + uVar71) = *(int *)(&UNK_14010fc6b + uVar71) + -1;
    uVar69 = (uint)_Dst | 0x4010fce0;
    pfVar93 = (fd_set *)(ulonglong)uVar69;
    if (-1 < (int)uVar69) {
      pfVar84 = (fd_set *)
                FUN_14000abf0(*(undefined4 **)pfVar93,
                              (undefined8 *)
                              ((longlong)
                               ((longlong)_Src << 0x20 |
                               (ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff) %
                               (longlong)(int)param_3 & 0xffffffff));
      return pfVar84;
    }
    pfStackY_90 = (fd_set *)0x1400931f5;
    (*(code *)((fd_set *)pcVar83)->fd_array[8])();
    puVar117 = (undefined1 *)(ulonglong)((int)auStackY_88 - 0x20);
    *(undefined8 *)(puVar117 + -8) = 0x140093200;
    cVar89 = FUN_1400930f1((longlong)pfVar93);
    if (cVar89 == '\0') {
      return (fd_set *)0x0;
    }
  case 0x3a:
code_r0x000140093203:
    uVar69 = (uint)pfVar93->fd_array[5];
    pfVar84 = (fd_set *)(ulonglong)uVar69;
    _Src = (uint *)pfVar93->fd_array[1];
    if (uVar69 != (uint)_Src) {
      puVar119 = puVar117;
      _Dst = (uint *)pfVar84;
      if (_Src <= pfVar84) {
switchD_14007fde0_caseD_25:
        ppuVar231 = &PTR_s_C__Users_flare__cargo_registry_s_14010a198;
        puVar120 = puVar119;
code_r0x000140093247:
        *(undefined8 *)(puVar120 + -8) = 0x14009324c;
        FUN_1400c3d29(_Dst,_Src,ppuVar231);
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
        (*UNRECOVERED_JUMPTABLE)();
      }
      _Dst = (uint *)pfVar93->fd_array[0];
      if (*(char *)((longlong)((fd_set *)_Dst)->fd_array + (longlong)(pfVar84[-1].fd_array + 0x3f))
          == ':') {
        writefds = (uint *)(ulonglong)(uVar69 + 1);
        param_4 = (fd_set *)(ulonglong)*(uint *)((longlong)pfVar93->fd_array + 0x2c);
        puVar118 = puVar117;
code_r0x000140093228:
        *(undefined8 *)(puVar118 + -8) = 0x140093230;
        pfVar84 = (fd_set *)
                  FUN_140093083((longlong)_Dst,(ulonglong)_Src,(ulonglong)writefds,
                                (ulonglong)((int)param_4 - 1));
        return pfVar84;
      }
    }
    return (fd_set *)0x0;
  case 0x32:
switchD_14007f6e5_caseD_34:
    puVar1 = (undefined4 *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x189);
    *puVar1 = *puVar1;
    ppuVar231 = (undefined **)writefds;
    goto code_r0x000140093247;
  case 0x33:
switchD_14007f6e5_caseD_36:
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x34:
switchD_14007f6e5_caseD_2f:
    pbVar2 = (byte *)((longlong)((fd_set *)param_2)->fd_array + (longlong)_Dst * 4 + 0x46);
    *pbVar2 = *pbVar2 << 4 | *pbVar2 >> 4;
    goto code_r0x000140093228;
  case 0x35:
switchD_14007f6e5_caseD_2d:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x36:
switchD_14007f6e5_caseD_2e:
    pfStackY_90 = (fd_set *)0x14009325b;
    cVar89 = FUN_1400930f1((longlong)_Dst);
    UNRECOVERED_JUMPTABLE = (code *)((longlong)&uRam0000000000000000 + 1);
    bVar239 = cVar89 == '\0';
    pcVar83 = (char *)_Dst;
    goto code_r0x000140093264;
  case 0x37:
switchD_14007f6e5_caseD_32:
    puVar121 = &UNK_14010fce8;
code_r0x000140093264:
    if (!bVar239) {
      param_4 = (fd_set *)(ulonglong)(uint)((fd_set *)pcVar83)->fd_array[5];
      puVar122 = (undefined8 *)puVar121;
      pfVar72 = (fd_set *)(ulonglong)*(uint *)((longlong)((fd_set *)pcVar83)->fd_array + 0x24);
code_r0x00014009326e:
      uVar69 = (int)pfVar72 + 3;
      writefds = (uint *)(ulonglong)uVar69;
      bVar239 = (uint)param_4 < uVar69;
      bVar237 = (uint)param_4 == uVar69;
code_r0x000140093275:
      if (!bVar239 && !bVar237) {
        SVar82 = ((fd_set *)pcVar83)->fd_array[0];
        uVar81 = ((fd_set *)pcVar83)->fd_array[1];
        *(undefined8 *)((longlong)puVar122 + -8) = 0x140093284;
        UNRECOVERED_JUMPTABLE =
             (code *)FUN_140093083(SVar82,uVar81,(ulonglong)writefds,(ulonglong)param_4);
      }
    }
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x38:
switchD_14007f6e5_caseD_30:
    pbVar2 = &UNK_14010fc63 + uVar71;
    *pbVar2 = *pbVar2 >> 4 | *pbVar2 << 4;
    pbVar2 = (byte *)((longlong)((fd_set *)((longlong)pcVar83 + -0x208))->fd_array + 0x1c3);
    *pbVar2 = *pbVar2 & (byte)param_2;
    _Dst = writefds;
    goto switchD_14007fde0_caseD_25;
  case 0x39:
switchD_14007f6e5_caseD_33:
    bVar239 = (uint)_Dst < uVar69;
    bVar237 = (uint)_Dst == uVar69;
    goto code_r0x000140093275;
  default:
    goto code_r0x000140093458;
  case 0x3f:
code_r0x000140093499:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x57:
code_r0x000140093486:
    if (!bVar237) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x66:
  case 0x68:
code_r0x000140093460:
    uVar69 = uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
    *(char *)(ulonglong)uVar69 = *(char *)(ulonglong)uVar69 + (char)uVar69;
code_r0x000140093458:
    pfStackY_90 = (fd_set *)0x140093469;
    lVar96 = FUN_14000ff76(3,(longlong)_Src,(ulonglong)writefds,
                           &PTR_s_C__Users_flare__cargo_registry_s_14010ad80);
    *(longlong *)pcVar83 = lVar96;
    ((fd_set *)pcVar83)->fd_array[0] = (SOCKET)_Src;
    param_3 = (fd_set *)0x0;
LAB_1400933fd:
    return (fd_set *)(ulonglong)((uVar70 & 0x3f) << 6 | (uint)param_3 & 0xffff | 0x20);
  case 0x6a:
    goto LAB_1400933fd;
  case 0x6c:
code_r0x0001400935b8:
    param_3 = (fd_set *)((ulonglong)param_3 & 0xffffffff);
code_r0x0001400935ba:
    pfVar84 = (fd_set *)FUN_1400381db((longlong)param_3,param_2);
    return pfVar84;
  case 0x6d:
code_r0x0001400938fd:
    pfVar168 = (fd_set *)auStackY_88;
    goto code_r0x0001400938fc;
  case 0x6e:
code_r0x000140093832:
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1b9);
    *pcVar83 = *pcVar83 + bVar238 + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x6f:
code_r0x000140093889:
    pcVar103 = (char *)(CONCAT71(uVar87,bVar238 + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count)
                       + -0x73);
    *pcVar103 = *pcVar103 + (char)_Dst;
    pfVar107 = (fd_set *)auStackY_88._0_8_;
    goto code_r0x00014009388e;
  case 0x70:
code_r0x000140093ac9:
    in((short)_Src);
    pfVar234 = (fd_set *)auStackY_88;
    goto code_r0x000140093ac7;
  case 0x71:
code_r0x0001400937bd:
    goto code_r0x0001400937ab;
  case 0x72:
code_r0x000140093a94:
    bVar238 = (byte)_Src;
    goto switchD_14007f6e5_caseD_77;
  case 0x73:
code_r0x000140093a9a:
    _Dst = (uint *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1ff);
    if ((fd_set *)_Dst != (fd_set *)0x0 && bVar239) goto code_r0x000140093aae;
    goto switchD_14007f6e5_caseD_75;
  case 0x74:
    goto code_r0x000140093a86;
  case 0x75:
    goto code_r0x000140093aa8;
  case 0x76:
code_r0x000140093aae:
    pfVar94 = (fd_set *)((ulonglong)param_3 & 0xffffffff);
    pfVar234 = (fd_set *)auStackY_88;
    _Dst = &param_3->fd_count;
switchD_14007f6e5_caseD_73:
    *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093ab5;
    uVar81 = FUN_140019e50((longlong)pfVar94);
    if ((uVar81 & 1) == 0) {
code_r0x000140093ab9:
      puVar223 = (uint *)((ulonglong)_Src & 0xffffffff);
      puVar61 = (undefined1 *)pfVar234;
      param_3 = (fd_set *)_Dst;
switchD_14007f6e5_caseD_72:
      pfVar234 = (fd_set *)puVar61;
      *(undefined8 *)((longlong)pfVar234 + -8) = 0x140093ac3;
      uVar81 = FUN_140019e50((longlong)_Dst);
      pfVar94 = param_3;
      if ((uVar81 & 1) != 0) goto switchD_140093766_default;
code_r0x000140093ac7:
      cVar89 = (char)pfVar227;
      cVar88 = (char)pfVar84;
      cVar104 = (char)param_2;
      if ((char)puVar223 == '\0') goto switchD_140093766_default;
      uVar71 = (ulonglong)_Src & 0xff;
      uVar81 = (ulonglong)(((uint)puVar223 & 0xff) << 8);
switchD_14007f7e4_caseD_72:
      uVar81 = uVar81 | uVar71;
switchD_14007f6e5_caseD_6c:
      if (0xfffe < (uint)uVar81) goto switchD_140093766_default;
LAB_1400936bb:
      *(undefined8 *)((longlong)pfVar234 + -8) = 0x1400936c3;
      lVar96 = FUN_140019a0b((longlong *)pfVar94,uVar81);
      if (lVar96 == 0) goto switchD_140093766_default;
      if (cVar88 == cVar104) {
        *(longlong *)((longlong)pfVar234 + 0x108) = lVar96;
        *(ulonglong *)((longlong)pfVar234 + 0x110) = uVar81;
        *(fd_set **)((longlong)pfVar234 + 0x100) = pfVar233;
        *(longlong *)((longlong)pfVar234 + 0x58) = lVar96;
        *(ulonglong *)((longlong)pfVar234 + 0x60) = uVar81;
        *(undefined8 *)((longlong)pfVar234 + 0x68) = 0;
        plVar100 = (longlong *)((longlong)pfVar234 + 0x70);
        puVar225 = (uint *)pcVar83;
        if (cVar89 == '\0') {
          *(undefined8 *)((longlong)pfVar234 + -8) = 0x14009379b;
          FUN_140094284(plVar100,(longlong)pfVar234 + 0x58,0,99);
          UNRECOVERED_JUMPTABLE = (code *)*plVar100;
          pfVar227 = *(fd_set **)((longlong)pfVar234 + 0x78);
          puVar91 = (undefined1 *)pfVar234;
          if ((fd_set *)UNRECOVERED_JUMPTABLE != pfVar233) goto LAB_140093987;
code_r0x0001400937ab:
          *(undefined8 *)(puVar91 + -8) = 0x1400937c6;
          FUN_140094284((longlong *)(puVar91 + 0x70),(longlong)(puVar91 + 0x58),0,99);
          UNRECOVERED_JUMPTABLE = *(code **)(puVar91 + 0x70);
          pfVar168 = (fd_set *)puVar91;
          param_1 = *(fd_set **)(puVar91 + 0x78);
          if ((fd_set *)UNRECOVERED_JUMPTABLE == pfVar233) {
            lVar96 = (longlong)pfVar227 * 100;
            pfVar234 = (fd_set *)puVar91;
            pfVar84 = *(fd_set **)(puVar91 + 0x78);
            goto LAB_1400937da;
          }
LAB_140093b63:
          pfVar227 = param_1;
          *(undefined8 *)((longlong)pfVar168 + 0x50) = *(undefined8 *)((longlong)pfVar168 + 0xa0);
          *(undefined8 *)((longlong)pfVar168 + 0x40) = *(undefined8 *)((longlong)pfVar168 + 0x90);
          *(undefined8 *)((longlong)pfVar168 + 0x48) = *(undefined8 *)((longlong)pfVar168 + 0x98);
          *(undefined8 *)((longlong)pfVar168 + 0x30) = *(undefined8 *)((longlong)pfVar168 + 0x80);
          *(undefined8 *)((longlong)pfVar168 + 0x38) = *(undefined8 *)((longlong)pfVar168 + 0x88);
        }
        else {
          *(undefined8 *)((longlong)pfVar234 + -8) = 0x14009371d;
          FUN_140094284(plVar100,(longlong)((longlong)pfVar234 + 0x58),0,99);
          UNRECOVERED_JUMPTABLE = (code *)*plVar100;
          pfVar227 = *(fd_set **)((longlong)pfVar234 + 0x78);
          if ((fd_set *)UNRECOVERED_JUMPTABLE == pfVar233) {
            lVar96 = 2000;
            pfVar84 = pfVar227;
            if ((fd_set *)0x31 < pfVar227) {
              lVar96 = 0x76c;
            }
LAB_1400937da:
            *(undefined8 *)((longlong)pfVar234 + -8) = 0x1400937f8;
            FUN_140094284((longlong *)((longlong)pfVar234 + 0x70),
                          (longlong)((longlong)pfVar234 + 0x58),1,0xc);
            UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar234 + 0x70);
            pfVar227 = *(fd_set **)((longlong)pfVar234 + 0x78);
            pcVar83 = (char *)puVar225;
            if ((fd_set *)UNRECOVERED_JUMPTABLE == pfVar233) {
              pfVar107 = pfVar234;
              if ((fd_set *)0xc < pfVar227) {
LAB_140093cfc:
                pcVar83 = "internal error: entered unreachable codeBitStringBool";
                _Src = (uint *)&DAT_00000028;
code_r0x000140093d0f:
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093d14;
                FUN_1400c3d10(pcVar83,(longlong)_Src);
                    /* WARNING: Does not return */
                UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
                (*UNRECOVERED_JUMPTABLE)();
              }
              param_3 = (fd_set *)((longlong)pfVar84->fd_array + lVar96 + -8);
              param_4 = (fd_set *)0x1f;
              pfVar168 = pfVar234;
              pfVar235 = pfVar227;
              if ((0x15aaUL >> ((ulonglong)pfVar227 & 0x3f) & 1) == 0) {
                if ((0xa50UL >> ((ulonglong)pfVar227 & 0x3f) & 1) == 0) {
                  if (pfVar227 != (fd_set *)((longlong)&uRam0000000000000000 + 2))
                  goto LAB_140093cfc;
code_r0x000140093bfa:
                  *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093c02;
                  param_4 = (fd_set *)FUN_14009435a((ulonglong)param_3);
                  pfVar168 = pfVar107;
                  pfVar235 = pfVar227;
                }
                else {
                  param_4 = (fd_set *)&DAT_0000001e;
                }
              }
LAB_14009383b:
              *(undefined8 *)((longlong)pfVar168 + -8) = 0x140093853;
              FUN_140094284((longlong *)((longlong)pfVar168 + 0x70),
                            (longlong)((longlong)pfVar168 + 0x58),1,(ulonglong)param_4);
              UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0x70);
              pfVar227 = *(fd_set **)((longlong)pfVar168 + 0x78);
              if ((fd_set *)UNRECOVERED_JUMPTABLE == pfVar233) {
code_r0x000140093863:
                *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009387e;
                FUN_140094284((longlong *)((longlong)pfVar168 + 0x70),
                              (longlong)((longlong)pfVar168 + 0x58),0,0x17);
                UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0x70);
                pfVar107 = pfVar168;
                pcVar83 = (char *)puVar225;
                pfVar227 = pfVar235;
                param_1 = *(fd_set **)((longlong)pfVar168 + 0x78);
                if ((fd_set *)UNRECOVERED_JUMPTABLE != pfVar233) goto LAB_140093b63;
code_r0x00014009388e:
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400938a9;
                FUN_140094284((longlong *)((longlong)pfVar107 + 0x70),
                              (longlong)((longlong)pfVar107 + 0x58),0,0x3b);
                UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar107 + 0x70);
                pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x78);
                pfVar168 = pfVar107;
                puVar225 = (uint *)pcVar83;
                if ((fd_set *)UNRECOVERED_JUMPTABLE == pfVar233) {
code_r0x0001400938b9:
                  *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400938d4;
                  FUN_140094284((longlong *)((longlong)pfVar168 + 0x70),
                                (longlong)((longlong)pfVar168 + 0x58),0,0x3b);
                  UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0x70);
                  _Src = *(uint **)((longlong)pfVar168 + 0x78);
                  if ((fd_set *)UNRECOVERED_JUMPTABLE == pfVar233) {
code_r0x0001400938e4:
                    writefds = *(uint **)((longlong)pfVar168 + 0x60);
                    param_2 = *(undefined ***)((longlong)pfVar168 + 0x68);
                    UNRECOVERED_JUMPTABLE = (code *)((longlong)pfVar233[-1].fd_array + 0x1cf);
                    if (param_2 < writefds) {
code_r0x0001400938fc:
                      if (*(char *)((longlong)((fd_set *)param_2)->fd_array +
                                   *(longlong *)((longlong)pfVar168 + 0x58) + -8) == 'Z') {
                        *(uint **)((longlong)pfVar168 + 0xa8) = writefds;
                        *(uint **)((longlong)pfVar168 + 0xc0) = _Src;
                        if ((fd_set *)0x7b1 < param_3) {
                          writefds = (uint *)((longlong)param_3[-1].fd_array + 0x1ff);
                          *(undefined8 *)((longlong)pfVar168 + 0x28) = 0;
                          puVar97 = (uint *)0x64;
switchD_14009313c_caseD_42:
                          *(ulonglong *)((longlong)pfVar168 + 0xb8) =
                               (ulonglong)writefds / (ulonglong)puVar97;
                          *(ulonglong *)((longlong)pfVar168 + 0xb0) = (ulonglong)writefds / 400;
                          *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009396a;
                          FUN_14009435a((ulonglong)param_3);
                    /* WARNING: Could not recover jumptable at 0x00014009397b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                          pfVar84 = (fd_set *)
                                    (*(code *)((longlong)&UINT_14010fea0 +
                                              (longlong)
                                              (int)(&UINT_14010fea0)
                                                   [(longlong)
                                                    ((longlong)pfVar227[-1].fd_array + 0x1ff)]))
                                              (&UINT_14010fea0,
                                               (code *)((longlong)&UINT_14010fea0 +
                                                       (longlong)
                                                       (int)(&UINT_14010fea0)
                                                            [(longlong)
                                                             ((longlong)pfVar227[-1].fd_array +
                                                             0x1ff)]));
                          return pfVar84;
                        }
                      }
                    }
                  }
                  else {
                    *(undefined8 *)((longlong)pfVar168 + 0x50) =
                         *(undefined8 *)((longlong)pfVar168 + 0xa0);
                    *(undefined8 *)((longlong)pfVar168 + 0x40) =
                         *(undefined8 *)((longlong)pfVar168 + 0x90);
                    *(undefined8 *)((longlong)pfVar168 + 0x48) =
                         *(undefined8 *)((longlong)pfVar168 + 0x98);
                    *(undefined8 *)((longlong)pfVar168 + 0x30) =
                         *(undefined8 *)((longlong)pfVar168 + 0x80);
                    *(undefined8 *)((longlong)pfVar168 + 0x38) =
                         *(undefined8 *)((longlong)pfVar168 + 0x88);
                    pfVar227 = (fd_set *)_Src;
                  }
                }
                else {
                  *(undefined8 *)((longlong)pfVar107 + 0x50) =
                       *(undefined8 *)((longlong)pfVar107 + 0xa0);
code_r0x000140093bce:
                  uVar241 = *(undefined8 *)((longlong)pfVar107 + 0x80);
                  uVar243 = *(undefined8 *)((longlong)pfVar107 + 0x88);
                  *(undefined8 *)((longlong)pfVar107 + 0x40) =
                       *(undefined8 *)((longlong)pfVar107 + 0x90);
                  *(undefined8 *)((longlong)pfVar107 + 0x48) =
                       *(undefined8 *)((longlong)pfVar107 + 0x98);
                  puVar142 = (undefined1 *)pfVar107;
                  puVar225 = (uint *)pcVar83;
code_r0x000140093be3:
                  *(undefined8 *)(puVar142 + 0x30) = uVar241;
                  *(undefined8 *)(puVar142 + 0x38) = uVar243;
                  pfVar168 = (fd_set *)puVar142;
                  pfVar227 = pfVar84;
                }
              }
              else {
                *(undefined8 *)((longlong)pfVar168 + 0x50) =
                     *(undefined8 *)((longlong)pfVar168 + 0xa0);
                *(undefined8 *)((longlong)pfVar168 + 0x40) =
                     *(undefined8 *)((longlong)pfVar168 + 0x90);
                *(undefined8 *)((longlong)pfVar168 + 0x48) =
                     *(undefined8 *)((longlong)pfVar168 + 0x98);
                *(undefined8 *)((longlong)pfVar168 + 0x30) =
                     *(undefined8 *)((longlong)pfVar168 + 0x80);
                *(undefined8 *)((longlong)pfVar168 + 0x38) =
                     *(undefined8 *)((longlong)pfVar168 + 0x88);
              }
              goto LAB_1400939ae;
            }
          }
LAB_140093987:
          _Dst = *(uint **)((longlong)pfVar234 + 0xa0);
          pfVar107 = pfVar234;
code_r0x00014009398f:
          *(uint **)((longlong)pfVar107 + 0x50) = _Dst;
          *(undefined8 *)((longlong)pfVar107 + 0x40) = *(undefined8 *)((longlong)pfVar107 + 0x90);
          *(undefined8 *)((longlong)pfVar107 + 0x48) = *(undefined8 *)((longlong)pfVar107 + 0x98);
          *(undefined8 *)((longlong)pfVar107 + 0x30) = *(undefined8 *)((longlong)pfVar107 + 0x80);
          *(undefined8 *)((longlong)pfVar107 + 0x38) = *(undefined8 *)((longlong)pfVar107 + 0x88);
          pfVar168 = pfVar107;
          puVar225 = (uint *)pcVar83;
        }
LAB_1400939ae:
        *(code **)puVar225 = UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_40:
        ((fd_set *)puVar225)->fd_array[0] = (SOCKET)pfVar227;
        SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x38);
        SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x40);
        SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x48);
        ((fd_set *)puVar225)->fd_array[1] = *(SOCKET *)((longlong)pfVar168 + 0x30);
        ((fd_set *)puVar225)->fd_array[2] = SVar82;
        ((fd_set *)puVar225)->fd_array[3] = SVar76;
        ((fd_set *)puVar225)->fd_array[4] = SVar236;
        ((fd_set *)puVar225)->fd_array[5] = *(SOCKET *)((longlong)pfVar168 + 0x50);
LAB_1400939d0:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400939dd;
        FUN_14009350d((ulonglong *)((longlong)pfVar168 + 200));
        pfVar107 = pfVar168;
        goto LAB_140093b41;
      }
      *(undefined1 **)((longlong)pfVar234 + 0x100) =
           (undefined1 *)((longlong)pfVar233[-1].fd_array + 0x1ce);
      puVar137 = (undefined8 *)pfVar234;
    }
    else {
switchD_140093766_default:
      *(undefined1 **)((longlong)pfVar234 + 0x100) =
           (undefined1 *)((longlong)pfVar233[-1].fd_array + 0x1ce);
      *(undefined1 *)((longlong)pfVar234 + 0x108) = 0;
      *(undefined2 *)((longlong)pfVar234 + 0x10d) = 0;
      *(undefined1 *)((longlong)pfVar234 + 0x10f) = 0;
      puVar135 = (undefined8 *)pfVar234;
code_r0x000140093b0a:
      *(undefined4 *)((longlong)puVar135 + 0x109) = 0;
      puVar137 = puVar135;
    }
LAB_140093b12:
    ((fd_set *)pcVar83)->fd_array[5] = *(SOCKET *)((longlong)puVar137 + 0xf8);
    puVar138 = puVar137;
code_r0x000140093b1e:
    SVar82 = *(SOCKET *)((longlong)puVar138 + 200);
    SVar76 = *(SOCKET *)((longlong)puVar138 + 0xd0);
    pfVar107 = (fd_set *)puVar138;
code_r0x000140093b26:
    uVar244 = *(undefined4 *)((longlong)pfVar107 + 0xd8);
    uVar245 = *(undefined4 *)((longlong)pfVar107 + 0xdc);
    in_XMM1_Dc = *(undefined4 *)((longlong)pfVar107 + 0xe0);
    in_XMM1_Dd = *(undefined4 *)((longlong)pfVar107 + 0xe4);
    SVar236 = *(SOCKET *)((longlong)pfVar107 + 0xf0);
    ((fd_set *)pcVar83)->fd_array[3] = *(SOCKET *)((longlong)pfVar107 + 0xe8);
    ((fd_set *)pcVar83)->fd_array[4] = SVar236;
    pfVar234 = pfVar107;
switchD_14009313c_caseD_47:
    *(undefined4 *)(((fd_set *)pcVar83)->fd_array + 1) = uVar244;
    *(undefined4 *)((longlong)((fd_set *)pcVar83)->fd_array + 0xc) = uVar245;
    *(undefined4 *)(((fd_set *)pcVar83)->fd_array + 2) = in_XMM1_Dc;
    *(undefined4 *)((longlong)((fd_set *)pcVar83)->fd_array + 0x14) = in_XMM1_Dd;
    *(SOCKET *)pcVar83 = SVar82;
    ((fd_set *)pcVar83)->fd_array[0] = SVar76;
    pfVar107 = pfVar234;
LAB_140093b41:
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140093b4e;
    UNRECOVERED_JUMPTABLE = (code *)FUN_14009487a((ulonglong *)((longlong)pfVar107 + 0x100));
code_r0x000140093b4f:
switchD_14009313c_caseD_48:
switchD_14009313c_caseD_49:
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x77:
code_r0x000140093aa0:
    puVar133 = auStackY_88;
    goto switchD_14007f6e5_caseD_75;
  case 0x78:
    goto switchD_14007f6e5_caseD_72;
  case 0x79:
    goto code_r0x000140093a8c;
  case 0x7a:
code_r0x000140093ab6:
    UINT_14010fd0c = UINT_14010fd0c + (int)pcVar83;
    pfVar234 = (fd_set *)auStackY_88;
    _Dst = &param_3->fd_count;
    goto code_r0x000140093ab9;
  case 0x7b:
code_r0x000140093a7e:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    *(char *)(uVar71 + 0x1807171e1) = *(char *)(uVar71 + 0x1807171e1) + (char)((ulonglong)_Dst >> 8)
    ;
    pfVar101 = (fd_set *)_Src;
code_r0x000140093a86:
    _Src = (uint *)((ulonglong)_Dst >> 8);
code_r0x000140093a89:
    UNRECOVERED_JUMPTABLE = (code *)((ulonglong)_Src & 0xff);
    bVar239 = (fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0;
    _Src = &pfVar101->fd_count;
    puVar58 = (undefined1 *)pfVar234;
    param_3 = pfVar94;
code_r0x000140093a8c:
    pfVar234 = (fd_set *)puVar58;
    bVar238 = (byte)_Src;
    puVar132 = (undefined1 *)pfVar234;
    if (bVar239) goto switchD_140093766_default;
switchD_14007f6e5_caseD_77:
    writefds = (uint *)(ulonglong)bVar238;
    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uint)((int)UNRECOVERED_JUMPTABLE << 0x18);
    _Dst = (uint *)(ulonglong)(((uint)param_1 & 0xff) << 0x10);
    puVar133 = puVar132;
switchD_14007f6e5_caseD_75:
    _Dst = (uint *)(ulonglong)((uint)_Dst | (uint)UNRECOVERED_JUMPTABLE);
    _Src = (uint *)((ulonglong)(((uint)param_4 & 0xff) << 8) | (ulonglong)writefds);
    puVar59 = puVar133;
    pfVar94 = param_3;
code_r0x000140093aa8:
    pfVar234 = (fd_set *)puVar59;
    cVar89 = (char)pfVar227;
    cVar88 = (char)pfVar84;
    cVar104 = (char)param_2;
    uVar81 = (ulonglong)_Src | (ulonglong)_Dst;
    goto switchD_14007f6e5_caseD_6c;
  case 0x7c:
code_r0x000140093bca:
    pfVar107 = (fd_set *)auStackY_88;
    goto code_r0x000140093bce;
  case 0x7d:
code_r0x000140093c9e:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x7e:
    goto code_r0x000140093be3;
  case 0x7f:
code_r0x000140093c3a:
    pfVar168 = (fd_set *)auStackY_88;
    if (!bVar240) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    goto LAB_1400939ae;
  case 0x80:
code_r0x000140093eee:
    puStackY_b0 = &DAT_14010fce0;
    pfVar168 = (fd_set *)auStackY_118;
    param_1 = (fd_set *)0x8000000000000032;
    pfVar234 = (fd_set *)&pfStackY_f0;
    uStackY_120 = 0x140093f19;
    pfStackY_b8 = (fd_set *)param_2;
    pfStackY_a8 = param_3;
    pfStackY_a0 = (fd_set *)pcVar83;
    auStackY_98 = (undefined1  [8])pfVar233;
    pfStackY_90 = (fd_set *)pcVar83;
    FUN_140093d16((undefined8 *)pfVar234,(longlong *)_Src,6);
    UNRECOVERED_JUMPTABLE = (code *)pfStackY_f0;
    puVar225 = _Dst;
    pfVar84 = apfStackY_e8[0];
    goto code_r0x000140093f20;
  case 0x81:
code_r0x000140093fd8:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x82:
code_r0x000140093f1d:
    _Src = (uint *)(ulonglong)(uint)((fd_set *)param_2)->fd_array[0];
    pfVar234 = (fd_set *)param_2;
    pfVar168 = (fd_set *)auStackY_88;
    puVar225 = &((fd_set *)pcVar83)->fd_count;
code_r0x000140093f20:
    SVar82 = pfVar234->fd_array[1];
    if ((fd_set *)UNRECOVERED_JUMPTABLE == param_1) {
      *(undefined8 *)((longlong)pfVar168 + -8) = 0x140093f39;
      FUN_140093ff0((ulonglong *)((longlong)pfVar168 + 0x28),(longlong *)_Src);
      UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0x28);
      puVar223 = (uint *)(ulonglong)*(byte *)((longlong)pfVar168 + 0x30);
      if ((fd_set *)UNRECOVERED_JUMPTABLE == param_1) {
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140093f58;
        FUN_140093d16((undefined8 *)((longlong)pfVar168 + 0x28),(longlong *)_Src,4);
        _Src = *(uint **)((longlong)pfVar168 + 0x28);
        UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0x30);
        puVar97 = *(uint **)((longlong)pfVar168 + 0x38);
        if ((fd_set *)_Src == param_1) {
          ((fd_set *)puVar225)->fd_array[0] = (SOCKET)pfVar84;
          ((fd_set *)puVar225)->fd_array[1] = SVar82;
          ((fd_set *)puVar225)->fd_array[2] = (SOCKET)UNRECOVERED_JUMPTABLE;
          _Dst = puVar97;
          pcVar83 = (char *)puVar225;
code_r0x000140093f74:
          ((fd_set *)pcVar83)->fd_array[3] = (SOCKET)_Dst;
          *(char *)(((fd_set *)pcVar83)->fd_array + 4) = (char)puVar223;
          *(fd_set **)pcVar83 = param_1;
        }
        else {
LAB_140093fc4:
          SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x40);
          SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x48);
          SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x58);
          ((fd_set *)puVar225)->fd_array[4] = *(SOCKET *)((longlong)pfVar168 + 0x50);
          ((fd_set *)puVar225)->fd_array[5] = SVar236;
          ((fd_set *)puVar225)->fd_array[2] = SVar82;
          ((fd_set *)puVar225)->fd_array[3] = SVar76;
          *(uint **)puVar225 = _Src;
          ((fd_set *)puVar225)->fd_array[0] = (SOCKET)UNRECOVERED_JUMPTABLE;
          ((fd_set *)puVar225)->fd_array[1] = (SOCKET)puVar97;
        }
      }
      else {
LAB_140093fa0:
        uVar241 = *(undefined8 *)((longlong)pfVar168 + 0x31);
        uVar243 = *(undefined8 *)((longlong)pfVar168 + 0x39);
        uVar9 = *(undefined8 *)((longlong)pfVar168 + 0x41);
        uVar10 = *(undefined8 *)((longlong)pfVar168 + 0x49);
        SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x58);
        ((fd_set *)puVar225)->fd_array[4] = *(SOCKET *)((longlong)pfVar168 + 0x50);
        ((fd_set *)puVar225)->fd_array[5] = SVar82;
        *(undefined8 *)((longlong)((fd_set *)puVar225)->fd_array + 0x11) = uVar9;
        *(undefined8 *)((longlong)((fd_set *)puVar225)->fd_array + 0x19) = uVar10;
        *(undefined8 *)((longlong)((fd_set *)puVar225)->fd_array + 1) = uVar241;
        *(undefined8 *)((longlong)((fd_set *)puVar225)->fd_array + 9) = uVar243;
        *(code **)puVar225 = UNRECOVERED_JUMPTABLE;
        *(char *)((fd_set *)puVar225)->fd_array = (char)puVar223;
      }
    }
    else {
      SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x40);
      SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x48);
      SVar8 = *(SOCKET *)((longlong)pfVar168 + 0x58);
      ((fd_set *)puVar225)->fd_array[4] = *(SOCKET *)((longlong)pfVar168 + 0x50);
      ((fd_set *)puVar225)->fd_array[5] = SVar8;
      ((fd_set *)puVar225)->fd_array[2] = SVar76;
      ((fd_set *)puVar225)->fd_array[3] = SVar236;
      *(code **)puVar225 = UNRECOVERED_JUMPTABLE;
      ((fd_set *)puVar225)->fd_array[0] = (SOCKET)pfVar84;
      ((fd_set *)puVar225)->fd_array[1] = SVar82;
    }
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x83:
    goto code_r0x000140093f74;
  case 0x84:
code_r0x0001400942b2:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    if (local_48 != pfVar233) {
      ((fd_set *)pcVar83)->fd_array[5] = (SOCKET)unaff_RDI;
      ((fd_set *)pcVar83)->fd_array[3] = unaff_RBX;
      ((fd_set *)pcVar83)->fd_array[4] = unaff_RBP;
      ((fd_set *)pcVar83)->fd_array[1] = (SOCKET)local_50;
      ((fd_set *)pcVar83)->fd_array[2] = (SOCKET)local_48;
      *(fd_set **)pcVar83 = local_48;
      ((fd_set *)pcVar83)->fd_array[0] = unaff_RBX;
      return local_48;
    }
    pfStackY_90 = (fd_set *)0x1400942d2;
    FUN_140094393((undefined8 *)local_60,(longlong)param_1);
    UNRECOVERED_JUMPTABLE = (code *)local_60._8_8_;
    _Dst = (uint *)local_60._0_8_;
    if ((fd_set *)local_60._0_8_ == pfVar233) {
      UNRECOVERED_JUMPTABLE = (code *)((longlong)(local_60._8_8_ + 8) + unaff_RBX * 10 + -8);
      bVar238 = param_2 <= UNRECOVERED_JUMPTABLE;
      bVar237 = UNRECOVERED_JUMPTABLE < param_3;
      bVar239 = (fd_set *)UNRECOVERED_JUMPTABLE == param_3;
      goto code_r0x0001400942ee;
    }
    goto code_r0x000140094324;
  case 0x85:
code_r0x0001400943a4:
    *(char *)(uVar71 + 0x128e28628) = *(char *)(uVar71 + 0x128e28628) + bVar238;
    bRam80137501a8fff85a = bVar238;
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x86:
code_r0x00014009431b:
    unaff_RDI = (fd_set *)_Src;
    out((char)((fd_set *)pcVar83)->fd_count,(short)unaff_RDI);
    ppfVar148 = &pfStackY_90;
    pfStackY_90 = (fd_set *)auStackY_88;
    UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff58);
    _Dst = (uint *)(ulonglong)(uint)((int)_Dst - *(int *)(&UNK_14010fc6b + uVar71));
    pcVar83 = (char *)((longlong)&((fd_set *)pcVar83)->fd_count + 1);
code_r0x000140094324:
    ((fd_set *)pcVar83)->fd_array[5] = (SOCKET)unaff_RDI;
    SVar82 = *(SOCKET *)((longlong)ppfVar148 + 0x38);
    SVar76 = *(SOCKET *)((longlong)ppfVar148 + 0x40);
    SVar236 = *(SOCKET *)((longlong)ppfVar148 + 0x50);
    ((fd_set *)pcVar83)->fd_array[3] = *(SOCKET *)((longlong)ppfVar148 + 0x48);
    ((fd_set *)pcVar83)->fd_array[4] = SVar236;
code_r0x000140094336:
    ((fd_set *)pcVar83)->fd_array[1] = SVar82;
    ((fd_set *)pcVar83)->fd_array[2] = SVar76;
    *(uint **)pcVar83 = _Dst;
    ((fd_set *)pcVar83)->fd_array[0] = (SOCKET)UNRECOVERED_JUMPTABLE;
code_r0x000140094351:
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x87:
    goto code_r0x000140094351;
  case 0x88:
code_r0x0001400942ed:
    bVar238 = (byte)_Dst;
    bVar237 = false;
code_r0x0001400942ee:
    if ((bVar238 & (bVar237 || bVar239)) == 0) {
      pfVar233 = (fd_set *)(auStackY_98 + 7);
    }
    else {
      ((fd_set *)pcVar83)->fd_array[0] = (SOCKET)UNRECOVERED_JUMPTABLE;
    }
    *(fd_set **)pcVar83 = pfVar233;
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x89:
code_r0x00014009470c:
    while( true ) {
      writefds = (uint *)&DAT_14010b399;
      _Dst = (uint *)pcVar83;
      _Src = &param_3->fd_count;
      param_4 = param_1;
      local_60._0_8_ = pfVar84;
switchD_14007fde0_caseD_7e:
      pfStackY_90 = (fd_set *)0x140094719;
      uVar241 = thunk_FUN_140006460(_Dst,(longlong)_Src,(ushort *)writefds,(ulonglong)param_4);
      if ((char)uVar241 != '\0') break;
      while( true ) {
        while( true ) {
          pfVar233 = (fd_set *)((longlong)&pfVar233->fd_count + 2);
          pfVar227 = (fd_set *)((longlong)&pfVar227->fd_count + 2);
          if (pfVar227 == (fd_set *)0x0) goto LAB_140094846;
          if ((short)pfVar233->fd_count != 0) break;
          param_2 = (undefined **)((longlong)&uRam0000000000000000 + 1);
        }
        if (((ulonglong)param_2 & 1) == 0) {
          uVar241 = 1;
          puVar102 = &DAT_14010bbb1;
        }
        else {
          uVar241 = 2;
          puVar102 = &DAT_14010bbb2;
        }
        pfStackY_90 = (fd_set *)0x14009468c;
        cVar89 = (*(code *)param_3->fd_array[2])(pcVar83,puVar102,uVar241);
        if (cVar89 != '\0') goto LAB_140094841;
        param_2 = (undefined **)0x0;
        if ((char)pfVar233->fd_count == '\0') break;
        pfStackY_90 = (fd_set *)0x1400946bc;
        local_60._0_8_ = pfVar84;
        uVar241 = thunk_FUN_140006460(pcVar83,(longlong)param_3,(ushort *)&DAT_14010b399,
                                      (ulonglong)param_1);
        puVar223 = (uint *)0x1;
        if ((char)uVar241 != '\0') goto LAB_14009485f;
code_r0x0001400946c7:
        pfStackY_90 = (fd_set *)0x1400946eb;
        local_60._0_8_ = pfVar84;
        uVar241 = thunk_FUN_140006460(pcVar83,(longlong)param_3,(ushort *)&DAT_14010bbb4,
                                      (ulonglong)param_1);
        if ((char)uVar241 != '\0') goto LAB_14009485f;
      }
    }
    goto LAB_140094841;
  case 0x8a:
code_r0x000140094809:
    if (!bVar237) {
      puVar91 = local_60 + 8;
      pfVar168 = (fd_set *)auStackY_88;
      goto code_r0x000140094818;
    }
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1ff);
    *pcVar83 = *pcVar83 + bVar238;
    cVar89 = *(char *)((longlong)((fd_set *)param_2)->fd_array +
                      (((ulonglong)UNRECOVERED_JUMPTABLE & 0xff) - 8));
    pfVar168 = (fd_set *)auStackY_88;
    goto code_r0x00014009480f;
  case 0x8b:
code_r0x00014009474e:
    *(char *)(&UINT_14010fd54 + (longlong)_Dst) =
         (char)(&UINT_14010fd54)[(longlong)_Dst] + (char)_Dst;
    UNRECOVERED_JUMPTABLE = (code *)0x0;
    goto switchD_14007fde0_caseD_85;
  case 0x8c:
code_r0x0001400947a5:
    *(char *)(ulonglong)(uint)(int)(short)UNRECOVERED_JUMPTABLE =
         *(char *)(ulonglong)(uint)(int)(short)UNRECOVERED_JUMPTABLE + bVar238;
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1ff);
    *pcVar83 = *pcVar83 + (char)_Dst;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x8d:
  case 0x94:
switchD_14007f7e4_caseD_8d:
    param_3 = (fd_set *)(ulonglong)(uint)((fd_set *)_Src)->fd_array[0];
    UNRECOVERED_JUMPTABLE = (code *)((longlong)&uRam0000000000000000 + 1);
    pfVar227 = (fd_set *)0x0;
    puVar223 = (uint *)(local_60 + 8);
    pfVar84 = (fd_set *)&DAT_140094872;
    param_2 = (undefined **)&DAT_14010b399;
    param_1 = (fd_set *)&stack0xffffffffffffff98;
    puVar151 = (undefined8 *)auStackY_88;
    goto switchD_14007fde0_caseD_85;
  case 0x8e:
code_r0x0001400946d4:
    goto code_r0x0001400946c7;
  case 0x8f:
  case 0x90:
  case 0x91:
switchD_14007f7e4_caseD_8e:
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  case 0x92:
code_r0x00014009485c:
    pfVar168 = (fd_set *)auStackY_88;
    goto code_r0x000140094857;
  case 0x93:
switchD_14007f6e5_caseD_95:
    pfStackY_90 = (fd_set *)0x140094865;
    pfVar84 = (fd_set *)func_0x000178cdcbad();
    return pfVar84;
  case 0x95:
  case 0x98:
  case 0x9a:
    goto switchD_14007fde0_caseD_7e;
  case 0x96:
  case 0x97:
    goto code_r0x000140094844;
  case 0x99:
code_r0x000140094850:
    *(byte *)(((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x37) =
         (char)((fd_set *)((longlong)_Dst + -0x208))->fd_array[0x37] + bVar238;
    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    pfVar168 = (fd_set *)auStackY_88;
    goto code_r0x000140094857;
  case 0x9b:
    goto code_r0x0001400951d1;
  case 0x9c:
    goto code_r0x000140095492;
  case 0x9d:
code_r0x0001400953a5:
    cVar89 = bVar238 + (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
    pcVar103 = (char *)CONCAT71(uVar87,cVar89);
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)param_2 + 0x2eb2290))->fd_array + 500);
    *pcVar83 = *pcVar83 + (char)_Dst;
    *pcVar103 = *pcVar103 + cVar89;
    pSVar163 = (SOCKET *)auStackY_88;
    goto LAB_1400953a1;
  case 0x9e:
    goto code_r0x00014009540f;
  case 0x9f:
    goto code_r0x000140095809;
  case 0xa0:
    goto code_r0x000140095bb4;
  case 0xa1:
    goto code_r0x000140095acf;
  case 0xa2:
code_r0x000140095b34:
    UNRECOVERED_JUMPTABLE = (code *)CONCAT71(uVar87,uRam1e658d4d03000003);
    pSVar163 = (SOCKET *)auStackY_88;
    goto code_r0x000140095b3d;
  case 0xa3:
code_r0x000140095362:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xa4:
code_r0x000140095753:
    piVar80 = (int *)((longlong)_Dst * 5 + -0x54);
    *piVar80 = *piVar80 + -1;
    pcVar83 = (char *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffffe8);
    *pcVar83 = *pcVar83 + (char)pcVar83;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xa5:
code_r0x000140095681:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xa6:
code_r0x0001400956df:
    uVar70 = (uint)_Dst;
    bVar239 = uVar69 == 0;
    pfVar168 = (fd_set *)auStackY_88;
code_r0x0001400956e1:
    _Dst = _Src;
    if (bVar239) {
switchD_14009543b_default:
      *(fd_set **)((longlong)pfVar168 + 0x440) = pfVar227;
      *(undefined1 *)((longlong)pfVar168 + 0x448) = 0;
      *(undefined2 *)((longlong)pfVar168 + 0x44d) = 0;
      *(undefined1 *)((longlong)pfVar168 + 0x44f) = 0;
      *(undefined4 *)((longlong)pfVar168 + 0x449) = 0;
      pfVar107 = pfVar168;
LAB_140094eda:
      puVar223 = *(uint **)((longlong)pfVar107 + 0x538);
      pfVar234 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
      param_3 = (fd_set *)0x0;
    }
    else {
      writefds = (uint *)(ulonglong)(byte)pfVar84->field_0x5;
      _Dst = (uint *)((ulonglong)
                      ((int)_Src << 8 | uVar70 << 0x10 | (int)UNRECOVERED_JUMPTABLE << 0x18) |
                     (ulonglong)writefds);
LAB_140095743:
      if (0xfffe < (uint)_Dst) goto switchD_14009543b_default;
LAB_1400952eb:
      *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400952f8;
      UNRECOVERED_JUMPTABLE =
           (code *)FUN_140019a0b((longlong *)((longlong)pfVar168 + 0x170),(ulonglong)_Dst);
      if ((fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0) goto switchD_14009543b_default;
      if ((char)pcVar83 != '0') {
        *(fd_set **)((longlong)pfVar168 + 0x440) = pfVar227;
        pfVar107 = pfVar168;
        goto LAB_140094eda;
      }
      *(code **)((longlong)pfVar168 + 0x448) = UNRECOVERED_JUMPTABLE;
      *(uint **)((longlong)pfVar168 + 0x450) = _Dst;
      pcVar103 = (char *)((longlong)pfVar227->fd_array + 0x2a);
      *(char **)((longlong)pfVar168 + 0x440) = pcVar103;
      *(code **)((longlong)pfVar168 + 0x120) = UNRECOVERED_JUMPTABLE;
      *(uint **)((longlong)pfVar168 + 0x128) = _Dst;
      *(undefined8 *)((longlong)pfVar168 + 0x130) = 0;
      *(fd_set **)((longlong)pfVar168 + 0x58) = pfVar84;
      if ((fd_set *)_Dst == (fd_set *)0x0) {
LAB_14009536f:
        _Dst = &((fd_set *)pcVar103)->fd_count;
        puVar223 = &((fd_set *)0x0)->fd_count;
        pfVar234 = pfVar227;
LAB_140095374:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140095381;
        FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x530));
        param_3 = (fd_set *)0x0;
        *(undefined8 *)((longlong)pfVar168 + 0x70) = *(undefined8 *)((longlong)pfVar168 + 0x48);
        *(fd_set **)((longlong)pfVar168 + 0x48) = pfVar84;
        *(char **)((longlong)pfVar168 + 0x60) = pcVar83;
        pfVar84 = *(fd_set **)((longlong)pfVar168 + 0x58);
        pfVar107 = pfVar168;
      }
      else {
        *(undefined8 *)((longlong)pfVar168 + 0x130) = 1;
        puVar223 = (uint *)CONCAT71((int7)((ulonglong)puVar223 >> 8),
                                    (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
        bVar238 = ~(byte)((ulonglong)puVar223 & 0xffffffff);
        pcVar103 = (char *)CONCAT71((int7)(((ulonglong)puVar223 & 0xffffffff) >> 8),bVar238);
        if (((bVar238 & 0x1f) == 0) ||
           ((fd_set *)_Dst == (fd_set *)((longlong)&uRam0000000000000000 + 1))) goto LAB_14009536f;
        *(undefined8 *)((longlong)pfVar168 + 0x130) = 2;
        bVar238 = *(byte *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 1);
        pcVar103 = (char *)(longlong)(char)bVar238;
        if ((longlong)pcVar103 < 0) {
          uVar69 = bVar238 - 0x81;
          pfVar234 = (fd_set *)(ulonglong)uVar69;
          pcVar103 = (char *)pfVar234;
          if (uVar69 < 4) {
            writefds = &switchD_140095a83::switchdataD_14010ff5c;
            pcVar103 = (char *)((longlong)&switchD_140095a83::switchdataD_14010ff5c +
                               (longlong)
                               (int)(&switchD_140095a83::switchdataD_14010ff5c)[(longlong)pfVar234])
            ;
            switch(pfVar234) {
            case (fd_set *)0x0:
              if ((fd_set *)((longlong)&uRam0000000000000000 + 2) < _Dst) {
                *(undefined8 *)((longlong)pfVar168 + 0x130) = 3;
                bVar238 = *(byte *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2);
                pcVar103 = (char *)(ulonglong)bVar238;
                if ((char)bVar238 < '\0') goto LAB_14009577b;
              }
              break;
            case (fd_set *)0x1:
              if (((fd_set *)((longlong)&uRam0000000000000000 + 2) < _Dst) &&
                 (*(undefined8 *)((longlong)pfVar168 + 0x130) = 3,
                 (fd_set *)_Dst != (fd_set *)((longlong)&uRam0000000000000000 + 3))) {
                bVar238 = *(byte *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2);
                *(undefined8 *)((longlong)pfVar168 + 0x130) = 4;
                pcVar103 = (char *)0x0;
                if (bVar238 != 0) {
                  uVar81 = (ulonglong)
                           *(byte *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3);
                  uVar71 = (ulonglong)bVar238 << 8;
LAB_140095e70:
                  pcVar103 = (char *)(uVar71 | uVar81);
                  if ((uint)pcVar103 < 0xffff) goto LAB_14009577b;
                }
              }
              break;
            case (fd_set *)0x2:
              if ((fd_set *)((longlong)&uRam0000000000000000 + 2) < _Dst) {
                *(undefined8 *)((longlong)pfVar168 + 0x130) = 3;
                bVar239 = (fd_set *)_Dst == (fd_set *)((longlong)&uRam0000000000000000 + 3);
                puVar165 = (undefined8 *)pfVar168;
code_r0x000140095d65:
                puVar225 = (uint *)pcVar83;
                pfVar168 = (fd_set *)puVar165;
                pcVar83 = (char *)puVar225;
                if (!bVar239) {
                  pcVar103 = (char *)(ulonglong)
                                     *(byte *)((longlong)
                                               &((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2);
code_r0x000140095d6f:
                  *(undefined8 *)((longlong)pfVar168 + 0x130) = 4;
                  pcVar83 = (char *)puVar225;
                  if ((fd_set *)&DAT_00000004 < _Dst) {
                    puVar97 = (uint *)(ulonglong)
                                      *(byte *)((longlong)
                                                &((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3);
                    *(undefined8 *)((longlong)pfVar168 + 0x130) = 5;
                    _Src = (uint *)pcVar103;
switchD_14009313c_caseD_7d:
                    pcVar103 = (char *)0x0;
                    pcVar83 = (char *)puVar225;
                    if ((fd_set *)_Src != (fd_set *)0x0) {
                      uVar81 = (ulonglong)(byte)((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4 |
                               (ulonglong)(uint)((int)puVar97 << 8);
                      uVar71 = (ulonglong)(uint)((int)_Src << 0x10);
                      goto LAB_140095e70;
                    }
                  }
                }
              }
              break;
            case (fd_set *)0x3:
              if (((fd_set *)((longlong)&uRam0000000000000000 + 2) < _Dst) &&
                 (*(undefined8 *)((longlong)pfVar168 + 0x130) = 3, puVar166 = (undefined8 *)pfVar168
                 , (fd_set *)_Dst != (fd_set *)((longlong)&uRam0000000000000000 + 3))) {
code_r0x000140095dd0:
                bVar238 = *(byte *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2);
                pcVar103 = (char *)(ulonglong)bVar238;
                *(undefined8 *)((longlong)puVar166 + 0x130) = 4;
                pfVar168 = (fd_set *)puVar166;
                if ((fd_set *)&DAT_00000004 < _Dst) {
                  bVar90 = *(byte *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3);
                  *(undefined8 *)((longlong)puVar166 + 0x130) = 5;
                  if ((fd_set *)_Dst != (fd_set *)&DAT_00000005) {
                    bVar64 = ((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4;
                    writefds = (uint *)(ulonglong)bVar64;
                    *(undefined8 *)((longlong)puVar166 + 0x130) = 6;
                    if ((fd_set *)pcVar103 != (fd_set *)0x0) {
                      writefds = (uint *)((ulonglong)bVar64 << 8);
                      uVar81 = (ulonglong)
                               CONCAT11(bVar64,((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x5);
                      uVar71 = (ulonglong)bVar238 << 0x18 | (ulonglong)bVar90 << 0x10;
                      goto LAB_140095e70;
                    }
                  }
                }
              }
            }
          }
          goto LAB_14009536f;
        }
LAB_14009577b:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140095788;
        param_3 = (fd_set *)
                  FUN_140019a0b((longlong *)((longlong)pfVar168 + 0x120),(ulonglong)pcVar103);
        pfVar234 = pfVar227;
        if (param_3 == (fd_set *)0x0) {
          puVar223 = (uint *)0x0;
          _Dst = (uint *)pcVar103;
          goto LAB_140095374;
        }
        cVar89 = (char)puVar223;
        _Dst = &((fd_set *)pcVar103)->fd_count;
        puVar223 = &((fd_set *)0x0)->fd_count;
        if (cVar89 != '0') goto LAB_140095374;
        *(char **)((longlong)pfVar168 + 0x50) = pcVar103;
        pcVar83 = *(char **)((longlong)pfVar168 + 0x130);
        if (*(fd_set **)((longlong)pfVar168 + 0x128) < pcVar83) goto LAB_1400968f0;
        puVar223 = *(uint **)((longlong)pfVar168 + 0x120);
        _Dst = (uint *)((longlong)pfVar168 + 0x1f0);
        _Src = (uint *)((longlong)pfVar168 + 0x120);
        pfVar107 = pfVar168;
        pfVar72 = (fd_set *)writefds;
        pfVar84 = (fd_set *)_Dst;
code_r0x0001400957d7:
        writefds = (uint *)CONCAT71((int7)((ulonglong)pfVar72 >> 8),0x30);
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400957df;
        FUN_140093d16((undefined8 *)_Dst,(longlong *)_Src,0x30);
        pfVar234 = *(fd_set **)pfVar84;
        *(SOCKET *)((longlong)pfVar107 + 0x60) = pfVar84->fd_array[0];
        *(SOCKET *)((longlong)pfVar107 + 0x48) = pfVar84->fd_array[1];
        UNRECOVERED_JUMPTABLE = (code *)((longlong)pfVar227->fd_array + 0x2a);
        if (pfVar234 != (fd_set *)UNRECOVERED_JUMPTABLE) {
          pcVar83 = *(char **)((longlong)pfVar107 + 0x208);
          pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x210);
          *(undefined8 *)((longlong)pfVar107 + 0xe0) = *(undefined8 *)((longlong)pfVar107 + 0x218);
          *(undefined8 *)((longlong)pfVar107 + 0x98) = *(undefined8 *)((longlong)pfVar107 + 0x220);
          puVar223 = *(uint **)((longlong)pfVar107 + 0x60);
          _Dst = _Src;
          pfVar168 = pfVar107;
          goto LAB_140095374;
        }
        param_1 = (fd_set *)((longlong)pfVar107 + 0x1f0);
        pfVar159 = pfVar107;
code_r0x000140095809:
        *(undefined8 *)((longlong)pfVar159 + -8) = 0x14009581c;
        FUN_14009721c((ulonglong *)param_1,(longlong *)((longlong)pfVar159 + 0x120));
        pfVar234 = *(fd_set **)param_1;
        _Dst = (uint *)param_1->fd_array[0];
        SVar82 = param_1->fd_array[1];
        if (pfVar234 != (fd_set *)UNRECOVERED_JUMPTABLE) {
          pcVar83 = *(char **)((longlong)pfVar159 + 0x208);
          pfVar84 = *(fd_set **)((longlong)pfVar159 + 0x210);
          *(SOCKET *)((longlong)pfVar159 + 0x48) = SVar82;
          *(undefined8 *)((longlong)pfVar159 + 0x98) = *(undefined8 *)((longlong)pfVar159 + 0x220);
          *(undefined8 *)((longlong)pfVar159 + 0xe0) = *(undefined8 *)((longlong)pfVar159 + 0x218);
          pfVar168 = pfVar159;
          puVar223 = _Dst;
          goto LAB_140095374;
        }
        pfVar84 = *(fd_set **)((longlong)pfVar159 + 0x58);
        pfVar107 = pfVar159;
        if (*(longlong *)((longlong)pfVar159 + 0x130) != *(longlong *)((longlong)pfVar159 + 0x128))
        goto LAB_140094eda;
        *(char **)((longlong)pfVar159 + 0x70) = pcVar83;
        *(uint **)((longlong)pfVar159 + 0xe0) = _Dst;
        *(SOCKET *)((longlong)pfVar159 + 0x98) = SVar82;
        *(undefined8 *)((longlong)pfVar159 + -8) = 0x140095870;
        FUN_14009350d((ulonglong *)((longlong)pfVar159 + 0x530));
        pfVar234 = *(fd_set **)((longlong)pfVar159 + 0x50);
      }
    }
    puVar95 = (ulonglong *)((longlong)pfVar107 + 0x440);
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094ef5;
    FUN_14009487a(puVar95);
    if (param_3 == (fd_set *)0x0) {
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009527c;
      FUN_14009350d((ulonglong *)((longlong)pfVar107 + 0xe8));
      pfVar77 = *(fd_set **)((longlong)pfVar107 + 0x60);
      puVar95 = *(ulonglong **)((longlong)pfVar107 + 0x48);
      _Dst = *(uint **)((longlong)pfVar107 + 0x98);
      writefds = *(uint **)((longlong)pfVar107 + 0xe0);
      param_4 = *(fd_set **)((longlong)pfVar107 + 0x70);
LAB_1400952a9:
      ((fd_set *)param_2)->fd_array[1] = (SOCKET)puVar223;
      ((fd_set *)param_2)->fd_array[2] = (SOCKET)param_4;
      ((fd_set *)param_2)->fd_array[3] = (SOCKET)pfVar77;
      ((fd_set *)param_2)->fd_array[4] = (SOCKET)puVar95;
      ((fd_set *)param_2)->fd_array[5] = (SOCKET)writefds;
      ((fd_set *)param_2)->fd_array[6] = (SOCKET)_Dst;
      ((fd_set *)param_2)->fd_array[0] = (SOCKET)pfVar234;
      *param_2 = (undefined1 *)((longlong)&pfVar227->fd_count + 1);
      return pfVar77;
    }
    pfVar77 = *(fd_set **)((longlong)pfVar107 + 0x180);
    if (pfVar77 != *(fd_set **)((longlong)pfVar107 + 0x178)) {
      puVar223 = *(uint **)((longlong)pfVar107 + 0xf0);
      pfVar234 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
      goto LAB_1400952a9;
    }
    *(fd_set **)((longlong)pfVar107 + 0x58) = pfVar84;
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094f26;
    FUN_14009350d((ulonglong *)((longlong)pfVar107 + 0xe8));
    bVar238 = (byte)writefds;
    *(undefined1 *)((longlong)pfVar107 + 0x410) = 4;
    *(fd_set **)((longlong)pfVar107 + 0x30) = param_3;
    *(fd_set **)((longlong)pfVar107 + 0x38) = pfVar234;
    *(undefined8 *)((longlong)pfVar107 + 0x40) = 0;
    *(undefined1 **)((longlong)pfVar107 + 0x408) =
         (undefined1 *)((longlong)pfVar227->fd_array + 0x16);
    puVar225 = (uint *)((longlong)pfVar227->fd_array + 0x19);
    *(uint **)((longlong)pfVar107 + 0x120) = puVar225;
    if (pfVar234 == (fd_set *)0x0) {
switchD_1400955ec_default:
      *(fd_set **)((longlong)pfVar107 + 0xe8) = pfVar227;
      *(undefined1 *)((longlong)pfVar107 + 0xf0) = 0;
      *(undefined2 *)((longlong)pfVar107 + 0xf5) = 0;
      *(undefined1 *)((longlong)pfVar107 + 0xf7) = 0;
      *(undefined4 *)((longlong)pfVar107 + 0xf1) = 0;
LAB_140094fa3:
      *(undefined4 *)((longlong)pfVar107 + 0x2eb) = *(undefined4 *)((longlong)pfVar107 + 0x14c);
      *(undefined4 *)((longlong)pfVar107 + 0x2e8) = *(undefined4 *)((longlong)pfVar107 + 0x149);
      param_1 = (fd_set *)((longlong)pfVar227->fd_array + 0x19);
    }
    else {
      *(undefined8 *)((longlong)pfVar107 + 0x40) = 1;
      bVar90 = (byte)param_3->fd_count;
      pfVar84 = (fd_set *)(ulonglong)bVar90;
      if (((~bVar90 & 0x1f) == 0) || (pfVar234 == (fd_set *)((longlong)&uRam0000000000000000 + 1)))
      goto switchD_1400955ec_default;
      *(undefined8 *)((longlong)pfVar107 + 0x40) = 2;
      bVar90 = *(byte *)((longlong)&param_3->fd_count + 1);
      UNRECOVERED_JUMPTABLE = (code *)(ulonglong)bVar90;
      if ((char)bVar90 < '\0') {
        switch(bVar90) {
        case 0x81:
          if ((fd_set *)((longlong)&uRam0000000000000000 + 2) < pfVar234) {
            *(undefined8 *)((longlong)pfVar107 + 0x40) = 3;
            bVar90 = *(byte *)((longlong)&param_3->fd_count + 2);
            UNRECOVERED_JUMPTABLE = (code *)(ulonglong)bVar90;
            if ((char)bVar90 < '\0') goto LAB_1400954b6;
          }
          break;
        case 0x82:
          if (((fd_set *)((longlong)&uRam0000000000000000 + 2) < pfVar234) &&
             (*(undefined8 *)((longlong)pfVar107 + 0x40) = 3,
             pfVar234 != (fd_set *)((longlong)&uRam0000000000000000 + 3))) {
            cVar89 = *(char *)((longlong)&param_3->fd_count + 2);
            *(undefined8 *)((longlong)pfVar107 + 0x40) = 4;
            if (cVar89 != '\0') {
              _Src = (uint *)(ulonglong)
                             CONCAT11(cVar89,*(undefined1 *)((longlong)&param_3->fd_count + 3));
LAB_140095a1c:
              bVar238 = (byte)writefds;
              pfVar168 = pfVar107;
              if ((uint)_Src < 0xffff) goto LAB_1400954b9;
            }
          }
          break;
        case 0x83:
          if (((fd_set *)((longlong)&uRam0000000000000000 + 2) < pfVar234) &&
             (*(undefined8 *)((longlong)pfVar107 + 0x40) = 3,
             pfVar234 != (fd_set *)((longlong)&uRam0000000000000000 + 3))) {
            bVar90 = *(byte *)((longlong)&param_3->fd_count + 2);
            *(undefined8 *)((longlong)pfVar107 + 0x40) = 4;
            if ((fd_set *)&DAT_00000004 < pfVar234) {
              bVar64 = *(byte *)((longlong)&param_3->fd_count + 3);
              *(undefined8 *)((longlong)pfVar107 + 0x40) = 5;
              if (bVar90 != 0) {
                _Src = (uint *)((ulonglong)((uint)bVar64 << 8 | (uint)bVar90 << 0x10) |
                               (ulonglong)(byte)param_3->field_0x4);
                goto LAB_140095a1c;
              }
            }
          }
          break;
        case 0x84:
          if (((fd_set *)((longlong)&uRam0000000000000000 + 2) < pfVar234) &&
             (*(undefined8 *)((longlong)pfVar107 + 0x40) = 3,
             pfVar234 != (fd_set *)((longlong)&uRam0000000000000000 + 3))) {
            bVar90 = *(byte *)((longlong)&param_3->fd_count + 2);
            *(undefined8 *)((longlong)pfVar107 + 0x40) = 4;
            if ((fd_set *)&DAT_00000004 < pfVar234) {
              bVar64 = *(byte *)((longlong)&param_3->fd_count + 3);
              *(undefined8 *)((longlong)pfVar107 + 0x40) = 5;
              if (pfVar234 != (fd_set *)&DAT_00000005) {
                bVar4 = param_3->field_0x4;
                *(undefined8 *)((longlong)pfVar107 + 0x40) = 6;
                if (bVar90 != 0) {
                  writefds = (uint *)(ulonglong)(byte)param_3->field_0x5;
                  _Src = (uint *)((ulonglong)
                                  ((uint)bVar4 << 8 | (uint)bVar64 << 0x10 | (uint)bVar90 << 0x18) |
                                 (ulonglong)writefds);
                  goto LAB_140095a1c;
                }
              }
            }
          }
        }
        goto switchD_1400955ec_default;
      }
LAB_1400954b6:
      _Src = (uint *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xff);
      pfVar168 = pfVar107;
LAB_1400954b9:
      *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400954c3;
      UNRECOVERED_JUMPTABLE =
           (code *)FUN_140019a0b((longlong *)((longlong)pfVar168 + 0x30),(ulonglong)_Src);
switchD_14009313c_caseD_71:
      bVar238 = (byte)writefds;
      pfVar107 = pfVar168;
      if ((fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0) goto switchD_1400955ec_default;
      if ((char)pfVar84 != -0x60) {
        *(fd_set **)((longlong)pfVar168 + 0xe8) = pfVar227;
        goto LAB_140094fa3;
      }
      *(code **)((longlong)pfVar168 + 0xf0) = UNRECOVERED_JUMPTABLE;
      *(uint **)((longlong)pfVar168 + 0xf8) = _Src;
      param_1 = (fd_set *)((longlong)pfVar227->fd_array + 0x2a);
      *(fd_set **)((longlong)pfVar168 + 0xe8) = param_1;
      writefds = (uint *)((longlong)pfVar168 + 0x170);
      *(code **)writefds = UNRECOVERED_JUMPTABLE;
      *(uint **)((longlong)pfVar168 + 0x178) = _Src;
      *(undefined8 *)((longlong)pfVar168 + 0x180) = 0;
      param_3 = (fd_set *)((longlong)pfVar168 + 0x1f0);
      *(undefined8 *)((longlong)pfVar168 + -8) = 0x140095519;
      FUN_140097163((ulonglong *)param_3,(longlong *)writefds);
      pfVar84 = *(fd_set **)param_3;
code_r0x00014009551c:
      bVar238 = (byte)writefds;
      bVar90 = (byte)param_3->fd_array[0];
      UNRECOVERED_JUMPTABLE = (code *)(ulonglong)bVar90;
      if (pfVar84 == param_1) {
        if (bVar90 != 2) {
          param_3 = (fd_set *)0x0;
          param_1 = (fd_set *)puVar225;
          goto LAB_140095a32;
        }
        if (*(longlong *)((longlong)pfVar107 + 0x180) != *(longlong *)((longlong)pfVar107 + 0x178))
        goto LAB_140094fa3;
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140095555;
        FUN_14009350d((ulonglong *)((longlong)pfVar107 + 0x120));
      }
      else {
        puVar97 = (uint *)((ulonglong)*(byte *)((longlong)pfVar107 + 0x1ff) << 0x10);
        _Src = (uint *)(ulonglong)*(ushort *)((longlong)pfVar107 + 0x1fd);
        pfVar160 = pfVar107;
code_r0x00014009588d:
        param_1 = pfVar84;
        bVar238 = (byte)writefds;
        *(undefined8 *)((longlong)pfVar160 + 0x50) = *(undefined8 *)((longlong)pfVar160 + 0x200);
        *(undefined8 *)((longlong)pfVar160 + 0x1b0) = *(undefined8 *)((longlong)pfVar160 + 0x208);
        *(undefined8 *)((longlong)pfVar160 + 0x1a8) = *(undefined8 *)((longlong)pfVar160 + 0x210);
        *(undefined1 *)((longlong)pfVar160 + 0x90) = *(undefined1 *)((longlong)pfVar160 + 0x218);
        *(undefined4 *)((longlong)pfVar160 + 0x1b8) = *(undefined4 *)((longlong)pfVar160 + 0x219);
        *(undefined4 *)((longlong)pfVar160 + 0x1bb) = *(undefined4 *)((longlong)pfVar160 + 0x21c);
        *(undefined8 *)((longlong)pfVar160 + 0x68) = *(undefined8 *)((longlong)pfVar160 + 0x220);
        param_3 = (fd_set *)
                  ((ulonglong)*(uint *)((longlong)pfVar160 + 0x1f9) << 8 |
                   (ulonglong)((uint)_Src | (uint)puVar97) << 0x28 |
                  (ulonglong)UNRECOVERED_JUMPTABLE);
        pfVar107 = pfVar160;
LAB_140095a32:
        *(undefined4 *)((longlong)pfVar107 + 0x2eb) = *(undefined4 *)((longlong)pfVar107 + 0x1bb);
        *(undefined4 *)((longlong)pfVar107 + 0x2e8) = *(undefined4 *)((longlong)pfVar107 + 0x1b8);
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140095a5b;
        FUN_14009350d((ulonglong *)((longlong)pfVar107 + 0x120));
      }
    }
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094fd0;
    FUN_14009487a((ulonglong *)((longlong)pfVar107 + 0xe8));
    pfVar84 = (fd_set *)((longlong)pfVar227->fd_array + 0x2a);
    pSVar163 = (SOCKET *)pfVar107;
    if (param_1 != pfVar84) {
LAB_1400953a1:
      puVar223 = &param_3->fd_count;
      *(undefined4 *)((longlong)pSVar163 + 0x2b) = *(undefined4 *)((longlong)pSVar163 + 0x2eb);
      *(undefined4 *)((longlong)pSVar163 + 0x28) = *(undefined4 *)((longlong)pSVar163 + 0x2e8);
      _Src = *(uint **)((longlong)pSVar163 + 0x50);
      pfVar84 = *(fd_set **)((longlong)pSVar163 + 0x1b0);
      param_3 = *(fd_set **)((longlong)pSVar163 + 0x1a8);
      goto LAB_1400953cf;
    }
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140094ff2;
    thunk_FUN_140093d16((undefined8 *)((longlong)pfVar107 + 0x1f0),
                        (longlong *)((longlong)pfVar107 + 0x30),bVar238);
    param_1 = *(fd_set **)((longlong)pfVar107 + 0x1f0);
    pcVar83 = *(char **)((longlong)pfVar107 + 0x1f8);
    pcVar103 = *(char **)((longlong)pfVar107 + 0x200);
    if (param_1 != pfVar84) {
switchD_1400944c0_caseD_17:
      pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x208);
      param_3 = *(fd_set **)((longlong)pfVar107 + 0x210);
      param_4 = (fd_set *)(ulonglong)*(byte *)((longlong)pfVar107 + 0x218);
      *(undefined4 *)((longlong)pfVar107 + 0x28) = *(undefined4 *)((longlong)pfVar107 + 0x219);
      *(undefined4 *)((longlong)pfVar107 + 0x2b) = *(undefined4 *)((longlong)pfVar107 + 0x21c);
      _Src = (uint *)pcVar103;
      puVar54 = (undefined1 *)pfVar107;
      pfVar93 = (fd_set *)pcVar83;
code_r0x00014009540f:
      _Dst = &pfVar93->fd_count;
      pfVar107 = (fd_set *)puVar54;
      uVar63 = SUB81(param_4,0);
      pvVar74 = *(void **)((longlong)pfVar107 + 0x220);
      goto LAB_14009556b;
    }
    *(char **)((longlong)pfVar107 + 0x50) = pcVar103;
    param_3 = (fd_set *)((longlong)pfVar107 + 0x1f0);
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140095023;
    FUN_140093d16((undefined8 *)param_3,(longlong *)((longlong)pfVar107 + 0x30),0x30);
    param_1 = *(fd_set **)param_3;
    _Dst = *(uint **)((longlong)pfVar107 + 0x1f8);
    _Src = *(uint **)((longlong)pfVar107 + 0x200);
    if (param_1 != pfVar84) goto LAB_140095464;
    pvVar74 = *(void **)((longlong)pfVar107 + 0x60);
    sVar232 = *(size_t *)((longlong)pfVar107 + 0x48);
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140095046;
    uVar241 = FUN_140075b91(_Dst,(size_t)_Src,pvVar74,sVar232);
    uVar63 = (undefined1)sVar232;
    if ((char)uVar241 == '\0') {
      param_1 = (fd_set *)((longlong)pfVar227->fd_array + 0x15);
      _Dst = (uint *)pcVar83;
      goto LAB_14009556b;
    }
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140095066;
    FUN_140093d16((undefined8 *)((longlong)pfVar107 + 0x1f0),(longlong *)((longlong)pfVar107 + 0x30)
                  ,0x30);
    param_1 = *(fd_set **)((longlong)pfVar107 + 0x1f0);
    _Dst = *(uint **)((longlong)pfVar107 + 0x1f8);
    _Src = *(uint **)((longlong)pfVar107 + 0x200);
    if (param_1 != pfVar84) {
LAB_140095464:
      pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x208);
      param_3 = *(fd_set **)((longlong)pfVar107 + 0x210);
      param_4 = (fd_set *)(ulonglong)*(byte *)((longlong)pfVar107 + 0x218);
      *(undefined4 *)((longlong)pfVar107 + 0x28) = *(undefined4 *)((longlong)pfVar107 + 0x219);
      *(undefined4 *)((longlong)pfVar107 + 0x2b) = *(undefined4 *)((longlong)pfVar107 + 0x21c);
code_r0x000140095492:
      uVar63 = SUB81(param_4,0);
      pvVar74 = *(void **)((longlong)pfVar107 + 0x220);
      goto LAB_14009556b;
    }
    *(uint **)((longlong)pfVar107 + 0x68) = _Src;
    *(uint **)((longlong)pfVar107 + 0x90) = _Dst;
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009509f;
    FUN_140093d16((undefined8 *)((longlong)pfVar107 + 0x1f0),(longlong *)((longlong)pfVar107 + 0x30)
                  ,0x30);
    param_1 = *(fd_set **)((longlong)pfVar107 + 0x1f0);
    _Dst = *(uint **)((longlong)pfVar107 + 0x1f8);
    _Src = *(uint **)((longlong)pfVar107 + 0x200);
    if (param_1 != pfVar84) goto LAB_140095464;
    *(uint **)((longlong)pfVar107 + 0x1a8) = _Src;
    *(uint **)((longlong)pfVar107 + 0x1b0) = _Dst;
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400950db;
    FUN_140093d16((undefined8 *)((longlong)pfVar107 + 0x1f0),(longlong *)((longlong)pfVar107 + 0x30)
                  ,0x30);
    param_1 = *(fd_set **)((longlong)pfVar107 + 0x1f0);
    _Dst = *(uint **)((longlong)pfVar107 + 0x1f8);
    _Src = *(uint **)((longlong)pfVar107 + 0x200);
    if (param_1 != pfVar84) goto LAB_140095464;
    *(uint **)((longlong)pfVar107 + 0x338) = _Src;
    *(uint **)((longlong)pfVar107 + 0x340) = _Dst;
    param_3 = (fd_set *)((longlong)pfVar107 + 0x1f0);
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140095117;
    FUN_140093d16((undefined8 *)param_3,(longlong *)((longlong)pfVar107 + 0x30),0x30);
    param_1 = *(fd_set **)param_3;
    UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar107 + 0x1f8);
    _Dst = *(uint **)((longlong)pfVar107 + 0x200);
    if (param_1 != pfVar84) {
      pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x208);
      param_3 = *(fd_set **)((longlong)pfVar107 + 0x210);
      param_4 = (fd_set *)(ulonglong)*(byte *)((longlong)pfVar107 + 0x218);
      *(undefined4 *)((longlong)pfVar107 + 0x28) = *(undefined4 *)((longlong)pfVar107 + 0x219);
      puVar161 = (undefined1 *)pfVar107;
code_r0x000140095acf:
      uVar63 = SUB81(param_4,0);
      *(undefined4 *)(puVar161 + 0x2b) = *(undefined4 *)(puVar161 + 0x21c);
      pvVar74 = *(void **)(puVar161 + 0x220);
      _Src = _Dst;
      pfVar107 = (fd_set *)puVar161;
      _Dst = (uint *)UNRECOVERED_JUMPTABLE;
      goto LAB_14009556b;
    }
    *(fd_set **)((longlong)pfVar107 + 0x1f0) = pfVar227;
    *(undefined8 *)((longlong)pfVar107 + 0x1f8) = *(undefined8 *)((longlong)pfVar107 + 0x58);
    *(fd_set **)((longlong)pfVar107 + 0x200) = pfVar233;
    *(char **)((longlong)pfVar107 + 0x208) = pcVar83;
    param_4 = *(fd_set **)((longlong)pfVar107 + 0x50);
    *(fd_set **)((longlong)pfVar107 + 0x210) = param_4;
    *(uint **)((longlong)pfVar107 + 0x218) = puVar223;
    *(undefined8 *)((longlong)pfVar107 + 0x220) = *(undefined8 *)((longlong)pfVar107 + 0x70);
    in_R10 = *(fd_set **)((longlong)pfVar107 + 0x60);
    *(fd_set **)((longlong)pfVar107 + 0x228) = in_R10;
    *(undefined8 *)((longlong)pfVar107 + 0x230) = *(undefined8 *)((longlong)pfVar107 + 0x48);
    *(undefined8 *)((longlong)pfVar107 + 0x238) = *(undefined8 *)((longlong)pfVar107 + 0xe0);
    *(undefined8 *)((longlong)pfVar107 + 0x240) = *(undefined8 *)((longlong)pfVar107 + 0x98);
    *(undefined8 *)((longlong)pfVar107 + 0x248) = *(undefined8 *)((longlong)pfVar107 + 0x90);
    *(undefined8 *)((longlong)pfVar107 + 0x250) = *(undefined8 *)((longlong)pfVar107 + 0x68);
    _Src = *(uint **)((longlong)pfVar107 + 0x1b0);
    puVar156 = (undefined8 *)pfVar107;
code_r0x0001400951d1:
    *(uint **)((longlong)puVar156 + 600) = _Src;
    *(undefined8 *)((longlong)puVar156 + 0x260) = *(undefined8 *)((longlong)puVar156 + 0x1a8);
    *(undefined8 *)((longlong)puVar156 + 0x268) = *(undefined8 *)((longlong)puVar156 + 0x340);
    *(undefined8 *)((longlong)puVar156 + 0x270) = *(undefined8 *)((longlong)puVar156 + 0x338);
    *(code **)((longlong)puVar156 + 0x278) = UNRECOVERED_JUMPTABLE;
    *(uint **)((longlong)puVar156 + 0x280) = _Dst;
    *(undefined8 *)((longlong)puVar156 + 0x288) = 0;
    *(undefined8 *)((longlong)puVar156 + 0x298) = 0;
    *(undefined8 *)((longlong)puVar156 + 0x2a8) = 0;
    *(undefined8 *)((longlong)puVar156 + 0x2b8) = 0;
    *(undefined8 *)((longlong)puVar156 + 0x2c8) = 0;
    *(undefined8 *)((longlong)puVar156 + 0x2d8) = 0;
    _Src = *(uint **)((longlong)puVar156 + 0x38);
    UNRECOVERED_JUMPTABLE = *(code **)((longlong)puVar156 + 0x40);
    bVar237 = UNRECOVERED_JUMPTABLE < _Src;
    if (UNRECOVERED_JUMPTABLE == (code *)_Src) {
      SVar82 = *(SOCKET *)((longlong)puVar156 + 0x58);
      goto LAB_1400960d8;
    }
    *(undefined1 *)((longlong)puVar156 + 0x3a0) = 3;
    pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
    pSVar163 = puVar156;
code_r0x000140095b3d:
    *(fd_set **)((longlong)pSVar163 + 0x398) = pfVar233;
    if (!bVar237) {
switchD_140095ea7_default:
      *(fd_set **)((longlong)pSVar163 + 0x3d0) = pfVar227;
      *(undefined1 *)((longlong)pSVar163 + 0x3d8) = 0;
      *(undefined2 *)((longlong)pSVar163 + 0x3dd) = 0;
      *(undefined1 *)((longlong)pSVar163 + 0x3df) = 0;
      *(undefined4 *)((longlong)pSVar163 + 0x3d9) = 0;
      SVar82 = *(SOCKET *)((longlong)pSVar163 + 0x58);
LAB_14009606a:
      puVar223 = *(uint **)((longlong)pSVar163 + 0x3a0);
      *(undefined4 *)((longlong)pSVar163 + 0x80) = *(undefined4 *)((longlong)pSVar163 + 0x3c1);
      *(undefined4 *)((longlong)pSVar163 + 0x83) = *(undefined4 *)((longlong)pSVar163 + 0x3c4);
      goto LAB_14009608e;
    }
code_r0x000140095b4b:
    puVar97 = *(uint **)((longlong)pSVar163 + 0x30);
    pfVar234 = (fd_set *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 1);
    *(fd_set **)((longlong)pSVar163 + 0x40) = pfVar234;
    bVar238 = *(byte *)((longlong)(puVar97 + 2) +
                       (longlong)
                       (((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x3f));
    pfVar224 = (fd_set *)CONCAT71((int7)((ulonglong)puVar223 >> 8),bVar238);
    if (((~bVar238 & 0x1f) == 0) || (_Src <= pfVar234)) goto switchD_140095ea7_default;
code_r0x000140095b76:
    pfVar234 = (fd_set *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2);
    *(fd_set **)((longlong)pSVar163 + 0x40) = pfVar234;
    bVar238 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                       (longlong)puVar97 + -7);
    if ((char)bVar238 < '\0') {
      switch(bVar238) {
      case 0x81:
        pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
        if (pfVar234 < _Src) {
          *(undefined1 **)((longlong)pSVar163 + 0x40) =
               (undefined1 *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3);
          bVar238 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                             (longlong)puVar97 + -6);
          if ((char)bVar238 < '\0') goto LAB_140095b8d;
        }
        break;
      case 0x82:
        pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
        if ((pfVar234 < _Src) &&
           (pfVar234 = (fd_set *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3),
           *(fd_set **)((longlong)pSVar163 + 0x40) = pfVar234, pfVar234 < _Src)) {
          bVar238 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                             (longlong)puVar97 + -6);
          *(undefined1 **)((longlong)pSVar163 + 0x40) =
               &((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4;
          if (bVar238 != 0) {
            uVar81 = (ulonglong)
                     *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                              (longlong)puVar97 + -5);
            uVar71 = (ulonglong)bVar238 << 8;
LAB_140096025:
            _Src = (uint *)(uVar71 | uVar81);
            pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
            if ((uint)_Src < 0xffff) goto LAB_140095b91;
          }
        }
        break;
      case 0x83:
        pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
        if ((pfVar234 < _Src) &&
           (pfVar234 = (fd_set *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3),
           *(fd_set **)((longlong)pSVar163 + 0x40) = pfVar234, pfVar234 < _Src)) {
          bVar238 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                             (longlong)puVar97 + -6);
          *(undefined1 **)((longlong)pSVar163 + 0x40) =
               &((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4;
          if (&((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4 < _Src) {
            bVar90 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                              (longlong)puVar97 + -5);
            *(undefined1 **)((longlong)pSVar163 + 0x40) =
                 &((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x5;
            if (bVar238 != 0) {
              uVar81 = (ulonglong)
                       *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                                (longlong)(puVar97 + -1));
              uVar71 = (ulonglong)((uint)bVar90 << 8 | (uint)bVar238 << 0x10);
              goto LAB_140096025;
            }
          }
        }
        break;
      case 0x84:
        pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
        if ((pfVar234 < _Src) &&
           (pfVar234 = (fd_set *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3),
           *(fd_set **)((longlong)pSVar163 + 0x40) = pfVar234, pfVar234 < _Src)) {
          bVar238 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                             (longlong)puVar97 + -6);
          *(undefined1 **)((longlong)pSVar163 + 0x40) =
               &((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4;
          if (&((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4 < _Src) {
            bVar90 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                              (longlong)puVar97 + -5);
            *(undefined1 **)((longlong)pSVar163 + 0x40) =
                 &((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x5;
            if (&((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x5 < _Src) {
              bVar64 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                                (longlong)(puVar97 + -1));
              *(undefined1 **)((longlong)pSVar163 + 0x40) =
                   &((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x6;
              if (bVar238 != 0) {
                uVar81 = (ulonglong)
                         *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                                  (longlong)puVar97 + -3);
                uVar71 = (ulonglong)
                         ((uint)bVar64 << 8 | (uint)bVar90 << 0x10 | (uint)bVar238 << 0x18);
                goto LAB_140096025;
              }
            }
          }
        }
      }
      goto switchD_140095ea7_default;
    }
LAB_140095b8d:
    _Src = (uint *)(ulonglong)bVar238;
LAB_140095b91:
    *(undefined8 *)((longlong)pSVar163 + -8) = 0x140095b9b;
    pfVar168 = (fd_set *)FUN_140019a0b((longlong *)((longlong)pSVar163 + 0x30),(ulonglong)_Src);
    if (pfVar168 == (fd_set *)0x0) goto switchD_140095ea7_default;
    pcVar83 = (char *)pfVar168;
    pfVar94 = (fd_set *)_Src;
    if ((char)pfVar224 != -0x5d) {
      *(fd_set **)((longlong)pSVar163 + 0x3d0) = pfVar227;
      SVar82 = *(SOCKET *)((longlong)pSVar163 + 0x58);
      pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
      goto LAB_14009606a;
    }
code_r0x000140095bb4:
    *(fd_set **)((longlong)pSVar163 + 0x3d8) = pfVar168;
    *(uint **)((longlong)pSVar163 + 0x3e0) = _Src;
    *(undefined1 **)((longlong)pSVar163 + 0x3d0) =
         (undefined1 *)((longlong)pfVar227->fd_array + 0x2a);
    *(char **)((longlong)pSVar163 + 200) = pcVar83;
    *(uint **)((longlong)pSVar163 + 0xd0) = _Src;
    *(undefined8 *)((longlong)pSVar163 + 0xd8) = 0;
    *(undefined1 *)((longlong)pSVar163 + 0x500) = 0xb;
    *(longlong *)((longlong)pSVar163 + 0x4f8) = (longlong)((longlong)pfVar227->fd_array + 0x16);
    *(undefined8 *)((longlong)pSVar163 + -8) = 0x140095c09;
    switchD_14009313c::caseD_a5
              ((undefined1 *)((longlong)pSVar163 + 0x360),(longlong *)((longlong)pSVar163 + 0x4f8));
    pfVar233 = (fd_set *)pSVar163;
    puVar60 = (undefined1 *)pSVar163;
    puVar223 = &pfVar224->fd_count;
    param_3 = pfVar94;
    if (pfVar94 == (fd_set *)0x0) goto switchD_1400968c1_default;
code_r0x000140095c0e:
    pfVar168 = (fd_set *)puVar60;
    *(undefined8 *)((longlong)pfVar168 + 0xd8) = 1;
    bVar238 = (byte)((fd_set *)pcVar83)->fd_count;
    puVar223 = (uint *)CONCAT71((int7)((ulonglong)puVar223 >> 8),bVar238);
    pfVar233 = pfVar168;
    if (((~bVar238 & 0x1f) != 0) && (param_3 != (fd_set *)((longlong)&uRam0000000000000000 + 1))) {
      *(undefined8 *)((longlong)pfVar168 + 0xd8) = 2;
      bVar90 = *(byte *)((longlong)&((fd_set *)pcVar83)->fd_count + 1);
      if (-1 < (char)bVar90) goto LAB_14009625b;
      UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(bVar90 - 0x81);
switchD_14009313c_caseD_86:
      pfVar233 = pfVar168;
      if ((uint)UNRECOVERED_JUMPTABLE < 4) {
        puVar97 = &switchD_1400968c1::switchdataD_14010ff8c;
code_r0x0001400968ba:
        uVar81 = (ulonglong)
                 *(int *)((longlong)((fd_set *)puVar97)->fd_array +
                         (longlong)UNRECOVERED_JUMPTABLE * 4 + -8);
code_r0x0001400968be:
                    /* WARNING: Could not recover jumptable at 0x0001400968c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pfVar84 = (fd_set *)(*(code *)((longlong)((fd_set *)puVar97)->fd_array + (uVar81 - 8)))();
        return pfVar84;
      }
    }
    goto switchD_1400968c1_default;
  case 0xa7:
    goto code_r0x000140095c0e;
  case 0xa8:
code_r0x000140095d57:
    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
    *(byte *)&((fd_set *)param_2)->fd_count = (char)((fd_set *)param_2)->fd_count + bVar238;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    (&UNK_14010fc63)[uVar71] = (&UNK_14010fc63)[uVar71] + (char)_Dst;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xa9:
code_r0x000140095c7f:
    pfVar168 = (fd_set *)0x38024;
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Src + 0x38822e8))->fd_array + 0x194);
    *pcVar83 = *pcVar83 + (char)_Dst;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    goto switchD_14009313c_caseD_73;
  case 0xaa:
code_r0x000140095ce1:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    goto code_r0x000140095ce3;
  case 0xab:
    goto switchD_140096440_default;
  case 0xac:
code_r0x000140096748:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xad:
code_r0x000140096661:
    *(char *)&((fd_set *)_Dst)->fd_count =
         (char)((fd_set *)_Dst)->fd_count << 1 | (char)((fd_set *)_Dst)->fd_count < '\0';
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    goto LAB_140096640;
  case 0xae:
code_r0x0001400966c8:
    pcVar83 = (char *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffffc0);
    *pcVar83 = *pcVar83 + (char)pcVar83;
    pcVar83 = (undefined1 *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1f6) +
              (longlong)param_3;
    *pcVar83 = *pcVar83 + (char)_Dst;
    bVar239 = *pcVar83 == '\0';
    goto code_r0x0001400966d0;
  case 0xaf:
code_r0x000140096186:
    *(char *)(((fd_set *)_Dst)->fd_array + 0x16) =
         (char)((fd_set *)_Dst)->fd_array[0x16] + (char)((ulonglong)param_2 >> 8);
    pfVar107 = (fd_set *)auStackY_88;
    goto code_r0x00014009618f;
  case 0xb0:
code_r0x000140096318:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    goto code_r0x00014009630e;
  case 0xb1:
code_r0x000140096238:
    pcVar103 = (char *)_Src;
    pfVar168 = (fd_set *)auStackY_88;
    pfVar107 = (fd_set *)auStackY_88;
    if (bVar239) goto LAB_14009625e;
switchD_14009313c_caseD_82:
    pfVar168 = (fd_set *)((longlong)pfVar168 + 8);
    goto LAB_140096236;
  case 0xb2:
code_r0x00014009629c:
    cVar89 = (char)_Dst;
    (&UNK_14010fc69)[uVar71] = (&UNK_14010fc69)[uVar71] + cVar89;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    (&UNK_14010fc69)[uVar71] = (&UNK_14010fc69)[uVar71] + cVar89;
    pfVar168 = (fd_set *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
    pcVar103 = (char *)((ulonglong)auStackY_88 & 0xffffffb8);
    *pcVar103 = *pcVar103 + (char)pcVar103;
    pcVar103[-0x7d] = pcVar103[-0x7d] + cVar89;
    *(char *)&param_3->fd_count = (char)((fd_set *)pcVar83)->fd_count;
    pcVar83 = (char *)((ulonglong)auStackY_88 & 0xffffff80);
    *pcVar83 = *pcVar83 + (char)pcVar83;
    *pcVar83 = *pcVar83 + (char)pcVar83;
    pcVar103 = (char *)_Src;
    param_3 = (fd_set *)((longlong)&param_3->fd_count + 1);
    goto code_r0x00014009627e;
  case 0xb3:
code_r0x0001400967f6:
    piVar80 = (int *)((longlong)_Dst * 5 + 0x36);
    *piVar80 = *piVar80 + -1;
    pfVar168 = (fd_set *)auStackY_88;
    goto code_r0x0001400967fa;
  case 0xb4:
code_r0x0001400969bf:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xb5:
code_r0x000140096973:
    pbVar2 = &UNK_14010fc63 + uVar71;
    bVar238 = *pbVar2;
    *pbVar2 = *pbVar2 + (byte)_Dst;
    ((fd_set *)_Src)->fd_count = ((fd_set *)_Src)->fd_count + 1;
    pfVar168 = (fd_set *)auStackY_88;
    pfVar233 = (fd_set *)auStackY_88;
    if (CARRY1(bVar238,(byte)_Dst) || ((fd_set *)_Src)->fd_count == 0)
    goto switchD_1400968c1_default;
switchD_14009313c_caseD_b6:
    *(undefined8 *)((longlong)pfVar168 + 0xd8) = 3;
    puVar183 = (undefined8 *)pfVar168;
code_r0x00014009698a:
    pfVar233 = (fd_set *)puVar183;
    pfVar168 = (fd_set *)puVar183;
    if (param_3 != (fd_set *)((longlong)&uRam0000000000000000 + 3)) {
code_r0x000140096994:
      UNRECOVERED_JUMPTABLE =
           (code *)(ulonglong)*(byte *)((longlong)&((fd_set *)pcVar83)->fd_count + 2);
      *(undefined8 *)((longlong)pfVar168 + 0xd8) = 4;
      bVar237 = param_3 < (fd_set *)&DAT_00000005;
      bVar239 = param_3 == (fd_set *)&DAT_00000005;
      puVar184 = (undefined1 *)pfVar168;
code_r0x0001400969a8:
      pfVar233 = (fd_set *)puVar184;
      if (!bVar237) {
        _Dst = (uint *)(ulonglong)*(byte *)((longlong)&((fd_set *)pcVar83)->fd_count + 3);
        *(undefined8 *)(puVar184 + 0xd8) = 5;
        if (!bVar239) {
          _Src = (uint *)(ulonglong)(byte)((fd_set *)pcVar83)->field_0x4;
          *(undefined8 *)(puVar184 + 0xd8) = 6;
          puVar187 = puVar184;
          if ((fd_set *)UNRECOVERED_JUMPTABLE != (fd_set *)0x0) {
code_r0x0001400969dd:
            writefds = (uint *)(ulonglong)(byte)((fd_set *)pcVar83)->field_0x5;
            UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uint)((int)UNRECOVERED_JUMPTABLE << 0x18);
            _Dst = (uint *)(ulonglong)(uint)((int)_Dst << 0x10);
            pfVar94 = (fd_set *)puVar187;
switchD_14007fde0_caseD_aa:
            pcVar103 = (char *)((ulonglong)
                                ((int)_Src << 8 | (uint)_Dst | (uint)UNRECOVERED_JUMPTABLE) |
                               (ulonglong)writefds);
            pfVar168 = pfVar94;
            goto LAB_140096a37;
          }
        }
      }
    }
    goto switchD_1400968c1_default;
  case 0xb6:
code_r0x000140096991:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xb7:
code_r0x000140096907:
    bVar238 = (byte)_Dst;
    puVar91 = auStackY_88;
code_r0x000140096909:
    pfVar168 = (fd_set *)(puVar91 + -8);
    *(fd_set **)(puVar91 + -8) = param_3;
    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
    pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                     0x183);
    bVar90 = *pbVar2;
    *pbVar2 = *pbVar2 + bVar238;
    ((fd_set *)_Src)->fd_count = ((fd_set *)_Src)->fd_count + 1;
    pfVar233 = (fd_set *)(puVar91 + -8);
    if (!CARRY1(bVar90,bVar238) && ((fd_set *)_Src)->fd_count != 0) {
switchD_14007f6e5_caseD_b3:
      *(undefined8 *)((longlong)pfVar168 + 0xd8) = 3;
      pfVar233 = pfVar168;
      if (param_3 != (fd_set *)((longlong)&uRam0000000000000000 + 3)) {
        UNRECOVERED_JUMPTABLE =
             (code *)(ulonglong)*(byte *)((longlong)&((fd_set *)puVar225)->fd_count + 2);
        *(undefined8 *)((longlong)pfVar168 + 0xd8) = 4;
        pfVar107 = pfVar168;
        goto code_r0x00014009693d;
      }
    }
    goto switchD_1400968c1_default;
  case 0xb8:
    goto code_r0x000140096a0a;
  case 0xb9:
code_r0x000140096a3f:
    in((short)_Src);
    UNRECOVERED_JUMPTABLE = (code *)swi(1);
    pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
    return pfVar84;
  case 0xba:
    goto code_r0x0001400969a8;
  case 0xbb:
    goto code_r0x000140096a6c;
  case 0xbc:
    goto code_r0x000140096946;
  case 0xbd:
    goto code_r0x000140096a5d;
  case 0xbe:
code_r0x0001400968d9:
    bVar238 = *(byte *)((longlong)&((fd_set *)pcVar83)->fd_count + 2);
    pfVar168 = (fd_set *)auStackY_88;
    bVar90 = bVar238;
code_r0x0001400968de:
    pfVar233 = pfVar168;
    if (-1 < (char)bVar238) goto switchD_1400968c1_default;
LAB_14009625b:
    pcVar103 = (char *)(ulonglong)bVar90;
    pfVar107 = pfVar168;
    goto LAB_14009625e;
  case 0xbf:
code_r0x000140096937:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    pfVar168 = (fd_set *)auStackY_88;
code_r0x00014009693b:
    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
    pfVar107 = pfVar168;
code_r0x00014009693d:
    pfVar233 = pfVar107;
    if (param_3 < (fd_set *)&DAT_00000005) goto switchD_1400968c1_default;
    _Src = (uint *)(ulonglong)*(byte *)((longlong)&((fd_set *)puVar225)->fd_count + 3);
    *(undefined8 *)((longlong)pfVar107 + 0xd8) = 5;
    pfVar168 = pfVar107;
    goto switchD_14007f7e4_caseD_b7;
  case 0xc0:
    goto code_r0x000140096a30;
  case 0xc1:
code_r0x0001400968ac:
    puVar97 = (uint *)(ulonglong)((int)_Dst + param_3->fd_count);
    LOCK();
    *(int *)((longlong)((fd_set *)param_2)->fd_array + (longlong)pcVar83 * 8 + -9) = (int)param_3;
    UNLOCK();
    *(int *)(&UNK_14010fc6d + uVar71) = *(int *)(&UNK_14010fc6d + uVar71) + -1;
    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 | 0x796d2);
    goto code_r0x0001400968ba;
  case 0xc2:
code_r0x000140096982:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    uVar69 = uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
    *(char *)(ulonglong)uVar69 = *(char *)(ulonglong)uVar69 + (char)uVar69;
    puVar183 = (undefined8 *)auStackY_88;
    goto code_r0x00014009698a;
  case 0xc3:
code_r0x00014009688e:
    piVar80 = (int *)((longlong)((fd_set *)((longlong)param_2 + 0x1682468))->fd_array + 0x14);
    *piVar80 = *piVar80 + -1;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    goto switchD_14007f6e5_caseD_d1;
  case 0xc4:
    goto code_r0x0001400969dd;
  case 0xc5:
    goto code_r0x000140096a4e;
  case 0xc6:
    goto code_r0x000140096adc;
  case 199:
code_r0x0001400969fb:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 200:
code_r0x000140096a21:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    (&UNK_14010fc65)[uVar71] = (&UNK_14010fc65)[uVar71] + (byte)_Dst;
    bVar238 = (byte)_Dst & 7;
    *(byte *)&param_3->fd_count =
         (byte)param_3->fd_count >> bVar238 | (char)param_3->fd_count << 8 - bVar238;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xc9:
    goto switchD_14009313c_caseD_8b;
  case 0xca:
    goto code_r0x000140096afa;
  case 0xcb:
    goto code_r0x000140096964;
  case 0xcc:
code_r0x000140096955:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    pfVar168 = (fd_set *)auStackY_88;
    goto switchD_14007f7e4_caseD_b7;
  case 0xcd:
code_r0x000140096bc2:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
code_r0x000140096bc4:
    UNRECOVERED_JUMPTABLE = (code *)0x8000000000000031;
    puVar225 = (uint *)pcVar83;
code_r0x000140096bce:
    goto LAB_140096ea4;
  case 0xce:
code_r0x000140096870:
    UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff6b);
    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                      0x18b);
    *pcVar83 = *pcVar83 + (char)_Dst;
    puVar177 = (undefined8 *)auStackY_88;
code_r0x00014009687a:
    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (int)UNRECOVERED_JUMPTABLE;
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                      0x189);
    *pcVar83 = *pcVar83 + (char)_Dst;
    puVar56 = (undefined1 *)puVar177;
code_r0x00014009687f:
    pfVar107 = (fd_set *)puVar56;
    UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff68);
    goto code_r0x00014009687d;
  case 0xcf:
    goto code_r0x000140096b09;
  case 0xd0:
code_r0x000140096baa:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
switchD_14009313c_caseD_9d:
    cVar89 = (char)puVar97 + '\x10';
    pcVar83 = (char *)CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),
                               (char)UNRECOVERED_JUMPTABLE +
                               (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
code_r0x000140096bb3:
    pcVar83[-0x7d] = pcVar83[-0x7d] + cVar89;
code_r0x000140096bb6:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xd1:
code_r0x000140096a7b:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xd2:
    goto code_r0x0001400969ce;
  case 0xd3:
code_r0x000140096a90:
    uVar63 = in((short)_Src);
    UNRECOVERED_JUMPTABLE = (code *)CONCAT71(uVar87,uVar63);
switchD_14009313c_caseD_97:
    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count = (char)UNRECOVERED_JUMPTABLE;
    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
code_r0x000140096a95:
    UNRECOVERED_JUMPTABLE = *(code **)_Src;
    pfVar84 = (fd_set *)UNRECOVERED_JUMPTABLE;
code_r0x000140096aa3:
    bVar239 = (longlong)UNRECOVERED_JUMPTABLE < 0;
    UNRECOVERED_JUMPTABLE = (code *)&DAT_00000004;
    if (bVar239) {
      UNRECOVERED_JUMPTABLE = (code *)pfVar84;
    }
switchD_14009313c_caseD_9a:
    UNRECOVERED_JUMPTABLE =
         (code *)(longlong)(int)(&UINT_14010ffac)[(longlong)UNRECOVERED_JUMPTABLE];
    _Dst = &UINT_14010ffac;
    goto code_r0x000140096abd;
  case 0xd4:
code_r0x0001400968bb:
    uVar81 = (ulonglong)
             *(uint *)((longlong)((fd_set *)puVar97)->fd_array +
                      (longlong)UNRECOVERED_JUMPTABLE * 4 + -8);
    goto code_r0x0001400968be;
  case 0xd5:
    goto code_r0x00014009687f;
  case 0xd6:
code_r0x000140096852:
    *(byte *)&((fd_set *)_Dst)->fd_count = (char)((fd_set *)_Dst)->fd_count + bVar238 + bVar237;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    goto code_r0x00014009683a;
  case 0xd7:
code_r0x000140096861:
    uVar244 = SUB84(_Dst,0);
    pcVar83 = (char *)((longlong)((fd_set *)((longlong)param_2 + 0x3498a60))->fd_array + 0x99);
    *pcVar83 = *pcVar83 + (char)_Dst;
    pfVar107 = (fd_set *)auStackY_88;
    goto code_r0x000140096867;
  case 0xd8:
code_r0x000140096824:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xd9:
    goto code_r0x000140096bb6;
  case 0xda:
code_r0x000140096acd:
    bVar90 = (byte)_Dst & 0x1f;
    ((fd_set *)param_2)->fd_count =
         ((fd_set *)param_2)->fd_count << bVar90 | ((fd_set *)param_2)->fd_count >> 0x20 - bVar90;
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    pfVar168 = (fd_set *)auStackY_88;
    param_3 = (fd_set *)param_3->fd_array;
switchD_14009313c_caseD_9b:
    _Src = &param_3->fd_count;
    _Dst = (uint *)((fd_set *)pcVar83)->fd_array;
    puVar194 = (undefined1 *)pfVar168;
code_r0x000140096adc:
    *(undefined8 *)(puVar194 + -8) = 0x140096ae1;
    FUN_140097058((undefined8 *)_Dst,(longlong)_Src);
    pfVar62 = (fd_set *)pcVar83;
code_r0x000140096ae1:
    puVar225 = &pfVar62->fd_count;
    UNRECOVERED_JUMPTABLE = (code *)0x800000000000002b;
code_r0x000140096aeb:
    goto LAB_140096ea4;
  case 0xdb:
switchD_14007fde0_caseD_d4:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xdc:
    goto code_r0x0001400969ec;
  case 0xdd:
    goto code_r0x000140096aeb;
  case 0xde:
code_r0x000140096805:
    pcVar83 = (char *)((ulonglong)(uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count) + 0x3b);
    *pcVar83 = *pcVar83 + (char)_Dst;
    *(char *)&param_3->fd_count = (char)param_3->fd_count + (char)_Dst;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xdf:
    goto code_r0x00014009689d;
  case 0xe0:
code_r0x000140096a9f:
    pfVar84 = (fd_set *)(ulonglong)((uint)_Src ^ 0x80000000);
    goto code_r0x000140096aa3;
  case 0xe1:
    goto code_r0x000140096bce;
  case 0xe2:
code_r0x000140096833:
    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)in_stack_00000078;
    puVar92 = (undefined8 *)auStackY_88;
    goto code_r0x00014009683a;
  case 0xe3:
code_r0x0001400968ca:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xe4:
code_r0x0001400968e8:
    *(int *)(&UNK_14010fc6d + uVar71) = *(int *)(&UNK_14010fc6d + uVar71) + -1;
    pfVar168 = (fd_set *)auStackY_88;
    goto LAB_1400968f0;
  case 0xe5:
code_r0x000140096f79:
    *(int *)(&UNK_14010fc65 + uVar71) = *(int *)(&UNK_14010fc65 + uVar71) + -1;
    *(char *)(uVar71 + 0x28021fa08) = *(char *)(uVar71 + 0x28021fa08) << 3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xe6:
    goto code_r0x00014009705b;
  case 0xe7:
code_r0x000140096fa0:
    pfStackY_90 = (fd_set *)0x140096fad;
    FUN_1400c3e10(_Dst,0x2b,writefds,param_4,in_stack_ffffffffffffff98);
                    /* WARNING: Does not return */
    UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
    (*UNRECOVERED_JUMPTABLE)();
  case 0xe8:
code_r0x000140096ff7:
    bVar239 = uVar70 == 0;
    param_2 = (undefined **)(ulonglong)(uVar70 - 1);
    pSVar196 = (SOCKET *)auStackY_88;
    goto code_r0x000140096ffa;
  case 0xe9:
code_r0x000140097135:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xea:
code_r0x00014009748a:
    pcVar103 = (char *)_Src;
    pfVar168 = (fd_set *)auStackY_88;
    goto LAB_140097481;
  case 0xeb:
code_r0x000140097384:
    uVar81 = (ulonglong)((uint)_Src | (uint)_Dst);
    pfVar168 = (fd_set *)auStackY_88;
    goto switchD_1400944c0_caseD_87;
  case 0xec:
    goto code_r0x0001400973b8;
  case 0xed:
    goto code_r0x0001400972d9;
  case 0xee:
switchD_1400944c0_caseD_8d:
    puVar214 = (undefined8 *)auStackY_88;
    goto code_r0x00014009750e;
  case 0xef:
code_r0x0001400975bd:
    bVar90 = (char)_Dst + (char)((ulonglong)_Dst >> 8);
    uVar70 = uVar70 + *(int *)((ulonglong)param_2 & 0xffffffff);
    uVar81 = (ulonglong)uVar70;
    *(char *)(uVar81 - 0x75) = *(char *)(uVar81 - 0x75) + bVar90;
    bVar90 = bVar90 | *(byte *)(uVar81 - 0x75);
    *(byte *)(uVar81 - 0x75) = *(byte *)(uVar81 - 0x75) | bVar90;
    pbVar2 = (byte *)(uVar81 - 0x73);
    bVar238 = *pbVar2;
    *pbVar2 = *pbVar2 - bVar90;
    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar70 + 0x73a38 + (uint)(bVar238 < bVar90));
    goto LAB_140097b64;
  case 0xf0:
    goto code_r0x000140097421;
  case 0xf1:
code_r0x00014009760e:
    bVar238 = (byte)_Dst;
    (&UNK_14010fc6b)[uVar71] = (&UNK_14010fc6b)[uVar71] | bVar238;
switchD_14007f7e4_caseD_eb:
    pbVar2 = (byte *)((longlong)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                     0x18d);
    bVar90 = *pbVar2;
    *pbVar2 = *pbVar2 - bVar238;
    UNRECOVERED_JUMPTABLE =
         (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x73b83 + (uint)(bVar90 < bVar238));
    goto LAB_140097b64;
  case 0xf2:
code_r0x000140097339:
                    /* WARNING: Could not emulate address calculation at 0x00014009733b */
                    /* WARNING: Treating indirect jump as call */
    pfVar84 = (fd_set *)(*(code *)(ulonglong)*(uint *)(uVar71 + 0x123960be1))();
    return pfVar84;
  case 0xf3:
    goto code_r0x0001400975f1;
  case 0xf4:
    goto code_r0x000140097298;
  case 0xf5:
    goto code_r0x00014009731c;
  case 0xf6:
    goto code_r0x0001400975a0;
  case 0xf7:
code_r0x00014009724d:
    pfVar168 = (fd_set *)auStackY_88;
    goto switchD_14009313c_caseD_eb;
  case 0xf8:
    goto code_r0x00014009739b;
  case 0xf9:
code_r0x00014009721f:
    puStackY_b0 = &DAT_14010fce0;
    pfVar168 = (fd_set *)auStackY_168;
    pfVar77 = (fd_set *)_Src;
    pfStackY_b8 = (fd_set *)param_2;
    pfStackY_a8 = param_3;
    pfStackY_a0 = (fd_set *)pcVar83;
    auStackY_98 = (undefined1  [8])pfVar233;
    pfStackY_90 = (fd_set *)pcVar83;
switchD_14009313c_caseD_e1:
    param_3 = pfVar77;
    pfVar233 = (fd_set *)0x8000000000000000;
    *(undefined1 *)((longlong)pfVar168 + 0x30) = 0;
    UNRECOVERED_JUMPTABLE = (code *)0x800000000000001e;
    puVar225 = puVar97;
switchD_14009313c_caseD_eb:
    *(code **)((longlong)pfVar168 + 0x28) = UNRECOVERED_JUMPTABLE;
    *(undefined8 *)((longlong)pfVar168 + -8) = 0x140097254;
    UNRECOVERED_JUMPTABLE = (code *)FUN_140019e50((longlong)_Src);
    _Dst = (uint *)(ulonglong)((~(byte)_Src & 0x1f) == 0);
    puVar17 = (undefined8 *)pfVar168;
    pfVar62 = (fd_set *)puVar225;
code_r0x00014009725e:
    puVar225 = &pfVar62->fd_count;
    pfVar168 = (fd_set *)puVar17;
    bVar239 = (((byte)_Dst | (byte)UNRECOVERED_JUMPTABLE) & 1) == 0;
code_r0x000140097263:
    pfVar107 = pfVar168;
    if (bVar239) {
code_r0x000140097269:
      param_2 = (undefined **)((ulonglong)_Src & 0xffffffff);
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140097273;
      uVar81 = FUN_140019e50((longlong)param_3);
      bVar239 = (uVar81 & 1) == 0;
      puVar198 = (undefined8 *)pfVar107;
      pcVar83 = (char *)puVar225;
code_r0x000140097275:
      pfVar168 = (fd_set *)puVar198;
      puVar225 = (uint *)pcVar83;
      if (!bVar239) goto switchD_14009730b_default;
      pfVar107 = (fd_set *)puVar198;
      if (-1 < (char)_Src) {
LAB_14009727f:
        cVar89 = (char)param_2;
        _Src = (uint *)((ulonglong)_Src & 0xff);
        pfVar168 = pfVar107;
        puVar225 = (uint *)pcVar83;
LAB_140097282:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009728a;
        UNRECOVERED_JUMPTABLE = (code *)FUN_140019a0b((longlong *)param_3,(ulonglong)_Src);
        if ((fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0) goto switchD_14009730b_default;
        if (cVar89 != '\x03') {
          *(fd_set **)((longlong)pfVar168 + 0x60) = pfVar233;
switchD_14009313c_caseD_ec:
          goto switchD_14007f7e4_caseD_e8;
        }
        goto code_r0x00014009729c;
      }
LAB_1400972ec:
      uVar69 = ((uint)_Src & 0xff) - 0x81;
      UNRECOVERED_JUMPTABLE = (code *)(ulonglong)uVar69;
      bVar238 = uVar69 < 3;
      bVar239 = uVar69 == 3;
code_r0x0001400972f7:
      puVar225 = (uint *)pcVar83;
      if (!(bool)bVar238 && !bVar239) goto switchD_14009730b_default;
code_r0x0001400972fd:
      puVar225 = (uint *)pcVar83;
      switch((longlong)&switchD_14009730b::switchdataD_140110074 +
             (longlong)
             (int)(&switchD_14009730b::switchdataD_140110074)[(longlong)UNRECOVERED_JUMPTABLE]) {
      case 0x14009730d:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140097315;
        uVar241 = FUN_140019e50((longlong)param_3);
        puVar97 = (uint *)(ulonglong)(byte)(-1 < (char)_Src | (byte)uVar241);
        pcVar103 = (char *)_Src;
        pfVar205 = pfVar168;
code_r0x00014009731c:
        _Src = (uint *)pcVar103;
        pfVar107 = pfVar205;
        pfVar168 = pfVar205;
        puVar225 = (uint *)pcVar83;
        if (((ulonglong)puVar97 & 1) == 0) goto LAB_14009727f;
        break;
      case 0x140097334:
switchD_14009730b_caseD_83:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009733c;
        uVar81 = FUN_140019e50((longlong)param_3);
        if ((uVar81 & 1) == 0) {
          param_1 = (fd_set *)((ulonglong)_Src & 0xffffffff);
          *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009734f;
          uVar81 = FUN_140019e50((longlong)param_3);
          if ((uVar81 & 1) == 0) {
            puVar223 = (uint *)((ulonglong)_Src & 0xffffffff);
            *(undefined8 *)((longlong)pfVar168 + -8) = 0x140097361;
            uVar81 = FUN_140019e50((longlong)param_3);
            bVar239 = (uVar81 & 1) == 0;
switchD_14009313c_caseD_ed:
            if ((bVar239) && (((ulonglong)param_1 & 0xff) != 0)) {
              _Dst = (uint *)((ulonglong)_Src & 0xff);
              UNRECOVERED_JUMPTABLE =
                   (code *)(ulonglong)(uint)((int)((ulonglong)param_1 & 0xff) << 0x10);
              pcVar103 = (char *)(ulonglong)(((uint)puVar223 & 0xff) << 8);
              puVar207 = (undefined8 *)pfVar168;
              pcVar83 = (char *)puVar225;
code_r0x000140097383:
              uVar81 = (ulonglong)pcVar103 | (ulonglong)_Dst;
              pfVar168 = (fd_set *)puVar207;
              puVar225 = (uint *)pcVar83;
              goto switchD_1400944c0_caseD_87;
            }
          }
        }
        break;
      case 0x14009738b:
switchD_14009730b_caseD_84:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140097393;
        uVar81 = FUN_140019e50((longlong)param_3);
        pcVar103 = (char *)_Src;
        puVar208 = (undefined1 *)pfVar168;
        puVar225 = (uint *)pcVar83;
        if ((uVar81 & 1) == 0) {
code_r0x00014009739b:
          _Dst = &param_3->fd_count;
          puVar223 = (uint *)((ulonglong)pcVar103 & 0xffffffff);
          puVar209 = (undefined8 *)puVar208;
          param_3 = (fd_set *)_Dst;
code_r0x0001400973a0:
          *(undefined8 *)((longlong)puVar209 + -8) = 0x1400973a5;
          uVar81 = FUN_140019e50((longlong)_Dst);
          pfVar168 = (fd_set *)puVar209;
          puVar225 = (uint *)pcVar83;
          if ((uVar81 & 1) == 0) {
            pfVar84 = (fd_set *)((ulonglong)pcVar103 & 0xffffffff);
            *(undefined8 *)((longlong)puVar209 + -8) = 0x1400973b4;
            uVar81 = FUN_140019e50((longlong)param_3);
            puVar210 = puVar209;
            if ((uVar81 & 1) == 0) {
code_r0x0001400973b8:
              param_1 = (fd_set *)((ulonglong)pcVar103 & 0xffffffff);
              *(undefined8 *)((longlong)puVar210 + -8) = 0x1400973c3;
              uVar81 = FUN_140019e50((longlong)param_3);
              pfVar168 = (fd_set *)puVar210;
              if ((uVar81 & 1) == 0) {
                UNRECOVERED_JUMPTABLE = (code *)((ulonglong)puVar223 & 0xff);
                _Src = (uint *)pcVar103;
code_r0x0001400973cb:
                if ((fd_set *)UNRECOVERED_JUMPTABLE != (fd_set *)0x0) {
switchD_14009313c_caseD_c8:
                  _Dst = (uint *)((ulonglong)pfVar84 & 0xff);
                  pcVar103 = (char *)_Src;
                  puVar18 = (undefined8 *)pfVar168;
                  pfVar62 = (fd_set *)puVar225;
code_r0x0001400973d4:
                  puVar225 = &pfVar62->fd_count;
                  pfVar168 = (fd_set *)puVar18;
                  _Src = (uint *)((ulonglong)(((uint)param_1 & 0xff) << 8) |
                                  (ulonglong)pcVar103 & 0xff |
                                 (ulonglong)
                                 (uint)((int)_Dst << 0x10 | (int)UNRECOVERED_JUMPTABLE << 0x18));
switchD_14009313c_caseD_c5:
                  goto switchD_14009313c_caseD_d4;
                }
              }
            }
          }
        }
        break;
      case 0x1400973ef:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400973f7;
        uVar81 = FUN_140019e50((longlong)param_3);
        if ((uVar81 & 1) == 0) {
          puVar223 = (uint *)((ulonglong)_Src & 0xffffffff);
          pfVar107 = pfVar168;
code_r0x0001400973fd:
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140097405;
          uVar81 = FUN_140019e50((longlong)param_3);
          pfVar168 = pfVar107;
          puVar225 = (uint *)pcVar83;
          if (((uVar81 & 1) == 0) && ((char)puVar223 != '\0')) {
            UNRECOVERED_JUMPTABLE = (code *)((ulonglong)_Src & 0xff);
            uVar81 = (ulonglong)(((uint)puVar223 & 0xff) << 8);
switchD_1400944c0_caseD_87:
            _Src = (uint *)(uVar81 | (ulonglong)UNRECOVERED_JUMPTABLE);
switchD_14009313c_caseD_d4:
            bVar237 = (uint)_Src < 0xffff;
            pcVar103 = (char *)_Src;
            puVar211 = (undefined8 *)pfVar168;
            pcVar83 = (char *)puVar225;
code_r0x000140097421:
            cVar89 = (char)param_2;
            _Src = (uint *)pcVar103;
            pfVar168 = (fd_set *)puVar211;
            puVar225 = (uint *)pcVar83;
            if (bVar237) goto LAB_140097282;
          }
        }
      }
    }
switchD_14009730b_default:
    *(fd_set **)((longlong)pfVar168 + 0x60) = pfVar233;
    UNRECOVERED_JUMPTABLE = (code *)0x0;
    *(undefined1 *)((longlong)pfVar168 + 0x68) = 0;
    *(undefined2 *)((longlong)pfVar168 + 0x6d) = 0;
switchD_14009313c_caseD_be:
    *(char *)((longlong)pfVar168 + 0x6f) = (char)UNRECOVERED_JUMPTABLE;
    puVar212 = (undefined8 *)pfVar168;
    pcVar83 = (char *)puVar225;
code_r0x00014009743c:
    *(undefined4 *)((longlong)puVar212 + 0x69) = 0;
    pfVar168 = (fd_set *)puVar212;
    puVar225 = (uint *)pcVar83;
    goto switchD_14007f7e4_caseD_e8;
  case 0xfa:
code_r0x0001400974c4:
    pcVar83 = (char *)((longlong)((fd_set *)_Dst)->fd_array + 7);
    *pcVar83 = *pcVar83 + (char)_Dst;
    ppfVar213 = &pfStackY_90;
    puVar92 = (undefined8 *)&DAT_14010fce0;
    cVar89 = '\x04';
    do {
      puVar92 = puVar92 + -1;
      ppfVar213 = ppfVar213 + -1;
      *ppfVar213 = (fd_set *)*puVar92;
      cVar89 = cVar89 + -1;
    } while ('\0' < cVar89);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xfb:
code_r0x0001400975da:
    UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
    goto LAB_140097b64;
  case 0xfc:
    goto code_r0x0001400976cd;
  case 0xfd:
code_r0x0001400974f8:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count >> 4 |
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count << 4;
    *(code **)param_4 = UNRECOVERED_JUMPTABLE;
    puVar214 = (undefined8 *)auStackY_88;
code_r0x00014009750e:
    pcVar83 = &DAT_14010b2a9;
    writefds = (uint *)0x27;
    _Src = (uint *)pcVar103;
    pfVar168 = (fd_set *)puVar214;
LAB_140097aed:
    *(undefined8 *)((longlong)pfVar168 + -8) = 0x140097af8;
    pfVar84 = (fd_set *)
              FUN_140008830((undefined8 *)_Src,pcVar83,writefds,param_4,
                            *(undefined **)((longlong)pfVar168 + 0x20));
    return pfVar84;
  case 0xfe:
code_r0x000140097583:
    bVar90 = (byte)_Dst;
    (&UNK_14010fc6b)[uVar71] = (&UNK_14010fc6b)[uVar71] | bVar90;
    pbVar2 = &UNK_14010fc6d + uVar71;
    bVar238 = *pbVar2;
    *pbVar2 = *pbVar2 - bVar90;
    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 + 0x73c65 + (uint)(bVar238 < bVar90));
    goto LAB_140097b64;
  case 0xff:
code_r0x00014009769c:
    *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar238;
    pcVar83 = (char *)UNRECOVERED_JUMPTABLE;
    pfVar168 = (fd_set *)auStackY_88;
    goto LAB_140097aed;
  }
  pfStackY_90 = (fd_set *)0x1400930aa;
  pfVar84 = (fd_set *)
            FUN_140090fad((ulonglong)pfVar72,(ulonglong)_Src,(longlong)in_R10,
                          (ulonglong)UNRECOVERED_JUMPTABLE,writefds);
  return pfVar84;
LAB_14007f60a:
  if (pfVar227 == (fd_set *)0x0) {
    return (fd_set *)&PTR_s_failed_to_write_whole_buffer_1400f7e78;
  }
  if (pcVar83 < pfVar227) {
    pfStackY_90 = (fd_set *)0x14007f666;
    FUN_1400c3c30((ulonglong)pfVar227,(ulonglong)pcVar83,(ulonglong)pcVar83,
                  &PTR_s__rustc_ac68faa20c58cbccd01ee7208_1400f8118);
                    /* WARNING: Does not return */
    UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
    (*UNRECOVERED_JUMPTABLE)();
  }
  param_3 = (fd_set *)((longlong)param_3->fd_array + (longlong)(pfVar227[-1].fd_array + 0x3f));
  pcVar83 = (char *)((longlong)pcVar83 - (longlong)pfVar227);
  goto LAB_14007f5c4;
code_r0x000140086818:
  puVar225 = *(uint **)((longlong)pfVar107 + 0x38);
  param_1 = *(fd_set **)((longlong)pfVar107 + 0x48);
LAB_140086822:
  *(fd_set **)((longlong)pfVar107 + 0x60) = param_3;
  pfVar84 = (fd_set *)0x2000;
  goto LAB_14008682d;
code_r0x0001400976cd:
  UNRECOVERED_JUMPTABLE = (code *)(ulonglong)((int)UNRECOVERED_JUMPTABLE + 0x738dd + (uint)bVar237);
  goto LAB_140097b64;
switchD_14009313c_caseD_5:
  do {
    puVar145 = (undefined8 *)pfVar101;
    pcVar103 = (char *)&DAT_14010aa63;
    writefds = (uint *)0x29;
    pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
    puVar97 = _Dst;
    puVar225 = _Dst;
    _Src = (uint *)pcVar103;
    puVar126 = puVar145;
    pfVar234 = (fd_set *)puVar145;
    pfVar101 = (fd_set *)puVar145;
    pfVar16 = (fd_set *)puVar145;
    pfVar159 = (fd_set *)puVar145;
    pfVar93 = (fd_set *)puVar145;
    pfVar123 = (fd_set *)puVar145;
    pfVar141 = (fd_set *)puVar145;
    pfVar205 = (fd_set *)puVar145;
    pfVar77 = (fd_set *)puVar145;
    pfVar94 = (fd_set *)puVar145;
    pfVar160 = (fd_set *)puVar145;
    puVar17 = puVar145;
    puVar18 = puVar145;
    puVar204 = puVar145;
    puVar19 = puVar145;
    pfVar107 = (fd_set *)puVar145;
    puVar20 = puVar145;
    puVar92 = puVar145;
    puVar115 = puVar145;
    puVar125 = puVar145;
    puVar221 = puVar145;
    puVar21 = puVar145;
    puVar22 = puVar145;
    puVar206 = puVar145;
    puVar23 = puVar145;
    puVar24 = puVar145;
    puVar25 = puVar145;
    puVar26 = puVar145;
    puVar215 = puVar145;
    puVar211 = puVar145;
    puVar27 = puVar145;
    pSVar196 = puVar145;
    puVar28 = puVar145;
    puVar29 = puVar145;
    pfVar195 = (fd_set *)puVar145;
    puVar180 = puVar145;
    puVar193 = puVar145;
    puVar183 = puVar145;
    puVar174 = puVar145;
    puVar166 = puVar145;
    puVar30 = puVar145;
    puVar162 = puVar145;
    puVar31 = puVar145;
    puVar149 = puVar145;
    puVar32 = puVar145;
    puVar134 = puVar145;
    puVar136 = puVar145;
    puVar139 = puVar145;
    puVar140 = puVar145;
    puVar137 = puVar145;
    puVar131 = puVar145;
    puVar114 = puVar145;
    puVar110 = puVar145;
    puVar199 = puVar145;
    puVar34 = puVar145;
    puVar122 = puVar145;
    puVar198 = puVar145;
    puVar207 = puVar145;
    puVar209 = puVar145;
    puVar212 = puVar145;
    puVar214 = puVar145;
    puVar35 = puVar145;
    puVar191 = puVar145;
    puVar177 = puVar145;
    puVar165 = puVar145;
    puVar36 = puVar145;
    puVar151 = puVar145;
    puVar150 = puVar145;
    puVar135 = puVar145;
    puVar138 = puVar145;
    puVar37 = puVar145;
    puVar116 = puVar145;
    puVar124 = puVar145;
    puVar222 = puVar145;
    puVar203 = puVar145;
    puVar38 = puVar145;
    puVar217 = puVar145;
    puVar220 = puVar145;
    puVar39 = puVar145;
    puVar219 = puVar145;
    puVar218 = puVar145;
    puVar216 = puVar145;
    puVar201 = puVar145;
    puVar210 = puVar145;
    puVar40 = puVar145;
    puVar41 = puVar145;
    puVar181 = puVar145;
    puVar42 = puVar145;
    puVar192 = puVar145;
    puVar43 = puVar145;
    puVar188 = puVar145;
    puVar44 = puVar145;
    puVar185 = puVar145;
    puVar186 = puVar145;
    puVar190 = puVar145;
    puVar189 = puVar145;
    puVar171 = puVar145;
    puVar167 = puVar145;
    puVar176 = puVar145;
    puVar158 = puVar145;
    puVar45 = puVar145;
    pSVar163 = puVar145;
    puVar164 = puVar145;
    puVar46 = puVar145;
    puVar157 = puVar145;
    puVar156 = puVar145;
    puVar155 = puVar145;
    puVar154 = puVar145;
    puVar152 = puVar145;
    puVar153 = puVar145;
    puVar146 = puVar145;
    puVar47 = puVar145;
    puVar147 = puVar145;
    puVar144 = puVar145;
    puVar143 = puVar145;
    puVar48 = puVar145;
    puVar128 = puVar145;
    puVar130 = puVar145;
    puVar129 = puVar145;
    puVar127 = puVar145;
    puVar113 = puVar145;
    puVar109 = puVar145;
    puVar49 = puVar145;
    puVar50 = puVar145;
    puVar106 = puVar145;
    puVar108 = puVar145;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pcVar83 = (char *)(fd_set *)pcVar83;
    pcVar83 = (char *)(fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pcVar83 = (char *)(fd_set *)pcVar83;
    pcVar83 = (char *)(fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar62 = (fd_set *)pcVar83;
    pfVar229 = param_3;
    pfVar72 = (fd_set *)writefds;
    switch(UNRECOVERED_JUMPTABLE) {
    case (code *)0x1400869f7:
      goto code_r0x0001400869f7;
    case (code *)0x140086a04:
      goto code_r0x000140086a04;
    case (code *)0x140086ab1:
      goto code_r0x000140086ab1;
    case (code *)0x140089974:
      goto code_r0x000140089974;
    case (code *)0x14008997e:
      goto code_r0x00014008997e;
    case (code *)0x140089a0a:
      goto code_r0x000140089a0a;
    case (code *)0x14008aa05:
      goto switchD_14007fde0_caseD_1a;
    case (code *)0x14008aa29:
      goto code_r0x00014008aa29;
    case (code *)0x14008aa37:
      goto code_r0x00014008aa37;
    case (code *)0x14008aa49:
      goto code_r0x00014008aa49;
    case (code *)0x14009310e:
      goto code_r0x00014009310e;
    case (code *)0x140093113:
      goto code_r0x000140093113;
    case (code *)0x14009311e:
      goto code_r0x00014009311e;
    case (code *)0x14009312b:
      goto code_r0x00014009312b;
    case (code *)0x14009326e:
      goto code_r0x00014009326e;
    case (code *)0x14009327e:
      goto code_r0x00014009327e;
    case (code *)0x140093287:
      goto code_r0x000140093287;
    case (code *)0x140093297:
      goto code_r0x000140093297;
    case (code *)0x1400932a7:
      goto code_r0x0001400932a7;
    case (code *)0x1400932b7:
      goto switchD_14009313c_caseD_d;
    case (code *)0x1400932c7:
switchD_14009313c_caseD_6:
      do {
        puVar145 = (undefined8 *)pfVar16;
        pcVar103 = "URLs mor";
        writefds = (uint *)0x25;
        pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
        puVar97 = _Dst;
        puVar225 = _Dst;
        _Src = (uint *)pcVar103;
        puVar126 = puVar145;
        pfVar234 = (fd_set *)puVar145;
        pfVar101 = (fd_set *)puVar145;
        pfVar16 = (fd_set *)puVar145;
        pfVar159 = (fd_set *)puVar145;
        pfVar93 = (fd_set *)puVar145;
        pfVar123 = (fd_set *)puVar145;
        pfVar141 = (fd_set *)puVar145;
        pfVar205 = (fd_set *)puVar145;
        pfVar77 = (fd_set *)puVar145;
        pfVar94 = (fd_set *)puVar145;
        pfVar160 = (fd_set *)puVar145;
        puVar17 = puVar145;
        puVar18 = puVar145;
        puVar204 = puVar145;
        puVar19 = puVar145;
        pfVar107 = (fd_set *)puVar145;
        puVar20 = puVar145;
        puVar92 = puVar145;
        puVar115 = puVar145;
        puVar125 = puVar145;
        puVar221 = puVar145;
        puVar21 = puVar145;
        puVar22 = puVar145;
        puVar206 = puVar145;
        puVar23 = puVar145;
        puVar24 = puVar145;
        puVar25 = puVar145;
        puVar26 = puVar145;
        puVar215 = puVar145;
        puVar211 = puVar145;
        puVar27 = puVar145;
        pSVar196 = puVar145;
        puVar28 = puVar145;
        puVar29 = puVar145;
        pfVar195 = (fd_set *)puVar145;
        puVar180 = puVar145;
        puVar193 = puVar145;
        puVar183 = puVar145;
        puVar174 = puVar145;
        puVar166 = puVar145;
        puVar30 = puVar145;
        puVar162 = puVar145;
        puVar31 = puVar145;
        puVar149 = puVar145;
        puVar32 = puVar145;
        puVar134 = puVar145;
        puVar136 = puVar145;
        puVar139 = puVar145;
        puVar140 = puVar145;
        puVar137 = puVar145;
        puVar131 = puVar145;
        puVar114 = puVar145;
        puVar110 = puVar145;
        puVar199 = puVar145;
        puVar34 = puVar145;
        puVar122 = puVar145;
        puVar198 = puVar145;
        puVar207 = puVar145;
        puVar209 = puVar145;
        puVar212 = puVar145;
        puVar214 = puVar145;
        puVar35 = puVar145;
        puVar191 = puVar145;
        puVar177 = puVar145;
        puVar165 = puVar145;
        puVar36 = puVar145;
        puVar151 = puVar145;
        puVar150 = puVar145;
        puVar135 = puVar145;
        puVar138 = puVar145;
        puVar37 = puVar145;
        puVar116 = puVar145;
        puVar124 = puVar145;
        puVar222 = puVar145;
        puVar203 = puVar145;
        puVar38 = puVar145;
        puVar217 = puVar145;
        puVar220 = puVar145;
        puVar39 = puVar145;
        puVar219 = puVar145;
        puVar218 = puVar145;
        puVar216 = puVar145;
        puVar201 = puVar145;
        puVar210 = puVar145;
        puVar40 = puVar145;
        puVar41 = puVar145;
        puVar181 = puVar145;
        puVar42 = puVar145;
        puVar192 = puVar145;
        puVar43 = puVar145;
        puVar188 = puVar145;
        puVar44 = puVar145;
        puVar185 = puVar145;
        puVar186 = puVar145;
        puVar190 = puVar145;
        puVar189 = puVar145;
        puVar171 = puVar145;
        puVar167 = puVar145;
        puVar176 = puVar145;
        puVar158 = puVar145;
        puVar45 = puVar145;
        pSVar163 = puVar145;
        puVar164 = puVar145;
        puVar46 = puVar145;
        puVar157 = puVar145;
        puVar156 = puVar145;
        puVar155 = puVar145;
        puVar154 = puVar145;
        puVar152 = puVar145;
        puVar153 = puVar145;
        puVar146 = puVar145;
        puVar47 = puVar145;
        puVar147 = puVar145;
        puVar144 = puVar145;
        puVar143 = puVar145;
        puVar48 = puVar145;
        puVar128 = puVar145;
        puVar130 = puVar145;
        puVar129 = puVar145;
        puVar127 = puVar145;
        puVar113 = puVar145;
        puVar109 = puVar145;
        puVar49 = puVar145;
        puVar50 = puVar145;
        puVar106 = puVar145;
        puVar108 = puVar145;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pcVar83 = (char *)(fd_set *)pcVar83;
        pcVar83 = (char *)(fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar62 = (fd_set *)pcVar83;
        pfVar229 = param_3;
        pfVar72 = (fd_set *)writefds;
        switch(UNRECOVERED_JUMPTABLE) {
        case (code *)0x1400869f7:
          goto code_r0x0001400869f7;
        case (code *)0x140086a04:
          goto code_r0x000140086a04;
        case (code *)0x140086ab1:
          goto code_r0x000140086ab1;
        case (code *)0x140089974:
          goto code_r0x000140089974;
        case (code *)0x14008997e:
          goto code_r0x00014008997e;
        case (code *)0x140089a0a:
          goto code_r0x000140089a0a;
        case (code *)0x14008aa05:
          goto switchD_14007fde0_caseD_1a;
        case (code *)0x14008aa29:
          goto code_r0x00014008aa29;
        case (code *)0x14008aa37:
          goto code_r0x00014008aa37;
        case (code *)0x14008aa49:
          goto code_r0x00014008aa49;
        case (code *)0x14009310e:
          goto code_r0x00014009310e;
        case (code *)0x140093113:
          goto code_r0x000140093113;
        case (code *)0x14009311e:
          goto code_r0x00014009311e;
        case (code *)0x14009312b:
          goto code_r0x00014009312b;
        case (code *)0x14009326e:
          goto code_r0x00014009326e;
        case (code *)0x14009327e:
          goto code_r0x00014009327e;
        case (code *)0x140093287:
          goto code_r0x000140093287;
        case (code *)0x140093297:
          goto code_r0x000140093297;
        case (code *)0x1400932a7:
          goto code_r0x0001400932a7;
        case (code *)0x1400932b7:
          goto switchD_14009313c_caseD_d;
        case (code *)0x1400932d7:
switchD_14009313c_caseD_7:
          do {
            puVar145 = (undefined8 *)pfVar159;
            pcVar103 = (char *)&DAT_14010a9f5;
            writefds = (uint *)&DAT_00000013;
            pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
            puVar97 = _Dst;
            puVar225 = _Dst;
            _Src = (uint *)pcVar103;
            puVar126 = puVar145;
            pfVar234 = (fd_set *)puVar145;
            pfVar101 = (fd_set *)puVar145;
            pfVar16 = (fd_set *)puVar145;
            pfVar159 = (fd_set *)puVar145;
            pfVar93 = (fd_set *)puVar145;
            pfVar123 = (fd_set *)puVar145;
            pfVar141 = (fd_set *)puVar145;
            pfVar205 = (fd_set *)puVar145;
            pfVar77 = (fd_set *)puVar145;
            pfVar94 = (fd_set *)puVar145;
            pfVar160 = (fd_set *)puVar145;
            puVar17 = puVar145;
            puVar18 = puVar145;
            puVar204 = puVar145;
            puVar19 = puVar145;
            pfVar107 = (fd_set *)puVar145;
            puVar20 = puVar145;
            puVar92 = puVar145;
            puVar115 = puVar145;
            puVar125 = puVar145;
            puVar221 = puVar145;
            puVar21 = puVar145;
            puVar22 = puVar145;
            puVar206 = puVar145;
            puVar23 = puVar145;
            puVar24 = puVar145;
            puVar25 = puVar145;
            puVar26 = puVar145;
            puVar215 = puVar145;
            puVar211 = puVar145;
            puVar27 = puVar145;
            pSVar196 = puVar145;
            puVar28 = puVar145;
            puVar29 = puVar145;
            pfVar195 = (fd_set *)puVar145;
            puVar180 = puVar145;
            puVar193 = puVar145;
            puVar183 = puVar145;
            puVar174 = puVar145;
            puVar166 = puVar145;
            puVar30 = puVar145;
            puVar162 = puVar145;
            puVar31 = puVar145;
            puVar149 = puVar145;
            puVar32 = puVar145;
            puVar134 = puVar145;
            puVar136 = puVar145;
            puVar139 = puVar145;
            puVar140 = puVar145;
            puVar137 = puVar145;
            puVar131 = puVar145;
            puVar114 = puVar145;
            puVar110 = puVar145;
            puVar199 = puVar145;
            puVar34 = puVar145;
            puVar122 = puVar145;
            puVar198 = puVar145;
            puVar207 = puVar145;
            puVar209 = puVar145;
            puVar212 = puVar145;
            puVar214 = puVar145;
            puVar35 = puVar145;
            puVar191 = puVar145;
            puVar177 = puVar145;
            puVar165 = puVar145;
            puVar36 = puVar145;
            puVar151 = puVar145;
            puVar150 = puVar145;
            puVar135 = puVar145;
            puVar138 = puVar145;
            puVar37 = puVar145;
            puVar116 = puVar145;
            puVar124 = puVar145;
            puVar222 = puVar145;
            puVar203 = puVar145;
            puVar38 = puVar145;
            puVar217 = puVar145;
            puVar220 = puVar145;
            puVar39 = puVar145;
            puVar219 = puVar145;
            puVar218 = puVar145;
            puVar216 = puVar145;
            puVar201 = puVar145;
            puVar210 = puVar145;
            puVar40 = puVar145;
            puVar41 = puVar145;
            puVar181 = puVar145;
            puVar42 = puVar145;
            puVar192 = puVar145;
            puVar43 = puVar145;
            puVar188 = puVar145;
            puVar44 = puVar145;
            puVar185 = puVar145;
            puVar186 = puVar145;
            puVar190 = puVar145;
            puVar189 = puVar145;
            puVar171 = puVar145;
            puVar167 = puVar145;
            puVar176 = puVar145;
            puVar158 = puVar145;
            puVar45 = puVar145;
            pSVar163 = puVar145;
            puVar164 = puVar145;
            puVar46 = puVar145;
            puVar157 = puVar145;
            puVar156 = puVar145;
            puVar155 = puVar145;
            puVar154 = puVar145;
            puVar152 = puVar145;
            puVar153 = puVar145;
            puVar146 = puVar145;
            puVar47 = puVar145;
            puVar147 = puVar145;
            puVar144 = puVar145;
            puVar143 = puVar145;
            puVar48 = puVar145;
            puVar128 = puVar145;
            puVar130 = puVar145;
            puVar129 = puVar145;
            puVar127 = puVar145;
            puVar113 = puVar145;
            puVar109 = puVar145;
            puVar49 = puVar145;
            puVar50 = puVar145;
            puVar106 = puVar145;
            puVar108 = puVar145;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pcVar83 = (char *)(fd_set *)pcVar83;
            pcVar83 = (char *)(fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar62 = (fd_set *)pcVar83;
            pfVar229 = param_3;
            pfVar72 = (fd_set *)writefds;
            switch(UNRECOVERED_JUMPTABLE) {
            case (code *)0x1400869f7:
              goto code_r0x0001400869f7;
            case (code *)0x140086a04:
              goto code_r0x000140086a04;
            case (code *)0x140086ab1:
              goto code_r0x000140086ab1;
            case (code *)0x140089974:
              goto code_r0x000140089974;
            case (code *)0x14008997e:
              goto code_r0x00014008997e;
            case (code *)0x140089a0a:
              goto code_r0x000140089a0a;
            case (code *)0x14008aa05:
              goto switchD_14007fde0_caseD_1a;
            case (code *)0x14008aa29:
              goto code_r0x00014008aa29;
            case (code *)0x14008aa37:
              goto code_r0x00014008aa37;
            case (code *)0x14008aa49:
              goto code_r0x00014008aa49;
            case (code *)0x14009310e:
              goto code_r0x00014009310e;
            case (code *)0x140093113:
              goto code_r0x000140093113;
            case (code *)0x14009311e:
              goto code_r0x00014009311e;
            case (code *)0x14009312b:
              goto code_r0x00014009312b;
            case (code *)0x14009326e:
              goto code_r0x00014009326e;
            case (code *)0x14009327e:
              goto code_r0x00014009327e;
            case (code *)0x140093287:
              goto code_r0x000140093287;
            case (code *)0x140093297:
              goto code_r0x000140093297;
            case (code *)0x1400932a7:
              goto code_r0x0001400932a7;
            case (code *)0x1400932b7:
              goto switchD_14009313c_caseD_d;
            case (code *)0x1400932c7:
              goto switchD_14009313c_caseD_6;
            case (code *)0x1400932e7:
switchD_14009313c_caseD_b:
              do {
                _Dst = puVar97;
                pcVar103 = (char *)&DAT_14010aa08;
                puVar145 = (undefined8 *)pfVar93;
code_r0x0001400932ee:
                writefds = (uint *)&DAT_00000014;
                pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
                puVar97 = _Dst;
                puVar225 = _Dst;
                _Src = (uint *)pcVar103;
                puVar126 = puVar145;
                pfVar234 = (fd_set *)puVar145;
                pfVar101 = (fd_set *)puVar145;
                pfVar16 = (fd_set *)puVar145;
                pfVar159 = (fd_set *)puVar145;
                pfVar93 = (fd_set *)puVar145;
                pfVar123 = (fd_set *)puVar145;
                pfVar141 = (fd_set *)puVar145;
                pfVar205 = (fd_set *)puVar145;
                pfVar77 = (fd_set *)puVar145;
                pfVar94 = (fd_set *)puVar145;
                pfVar160 = (fd_set *)puVar145;
                puVar17 = puVar145;
                puVar18 = puVar145;
                puVar204 = puVar145;
                puVar19 = puVar145;
                pfVar107 = (fd_set *)puVar145;
                puVar20 = puVar145;
                puVar92 = puVar145;
                puVar115 = puVar145;
                puVar125 = puVar145;
                puVar221 = puVar145;
                puVar21 = puVar145;
                puVar22 = puVar145;
                puVar206 = puVar145;
                puVar23 = puVar145;
                puVar24 = puVar145;
                puVar25 = puVar145;
                puVar26 = puVar145;
                puVar215 = puVar145;
                puVar211 = puVar145;
                puVar27 = puVar145;
                pSVar196 = puVar145;
                puVar28 = puVar145;
                puVar29 = puVar145;
                pfVar195 = (fd_set *)puVar145;
                puVar180 = puVar145;
                puVar193 = puVar145;
                puVar183 = puVar145;
                puVar174 = puVar145;
                puVar166 = puVar145;
                puVar30 = puVar145;
                puVar162 = puVar145;
                puVar31 = puVar145;
                puVar149 = puVar145;
                puVar32 = puVar145;
                puVar134 = puVar145;
                puVar136 = puVar145;
                puVar139 = puVar145;
                puVar140 = puVar145;
                puVar137 = puVar145;
                puVar131 = puVar145;
                puVar114 = puVar145;
                puVar110 = puVar145;
                puVar199 = puVar145;
                puVar34 = puVar145;
                puVar122 = puVar145;
                puVar198 = puVar145;
                puVar207 = puVar145;
                puVar209 = puVar145;
                puVar212 = puVar145;
                puVar214 = puVar145;
                puVar35 = puVar145;
                puVar191 = puVar145;
                puVar177 = puVar145;
                puVar165 = puVar145;
                puVar36 = puVar145;
                puVar151 = puVar145;
                puVar150 = puVar145;
                puVar135 = puVar145;
                puVar138 = puVar145;
                puVar37 = puVar145;
                puVar116 = puVar145;
                puVar124 = puVar145;
                puVar222 = puVar145;
                puVar203 = puVar145;
                puVar38 = puVar145;
                puVar217 = puVar145;
                puVar220 = puVar145;
                puVar39 = puVar145;
                puVar219 = puVar145;
                puVar218 = puVar145;
                puVar216 = puVar145;
                puVar201 = puVar145;
                puVar210 = puVar145;
                puVar40 = puVar145;
                puVar41 = puVar145;
                puVar181 = puVar145;
                puVar42 = puVar145;
                puVar192 = puVar145;
                puVar43 = puVar145;
                puVar188 = puVar145;
                puVar44 = puVar145;
                puVar185 = puVar145;
                puVar186 = puVar145;
                puVar190 = puVar145;
                puVar189 = puVar145;
                puVar171 = puVar145;
                puVar167 = puVar145;
                puVar176 = puVar145;
                puVar158 = puVar145;
                puVar45 = puVar145;
                pSVar163 = puVar145;
                puVar164 = puVar145;
                puVar46 = puVar145;
                puVar157 = puVar145;
                puVar156 = puVar145;
                puVar155 = puVar145;
                puVar154 = puVar145;
                puVar152 = puVar145;
                puVar153 = puVar145;
                puVar146 = puVar145;
                puVar47 = puVar145;
                puVar147 = puVar145;
                puVar144 = puVar145;
                puVar143 = puVar145;
                puVar48 = puVar145;
                puVar128 = puVar145;
                puVar130 = puVar145;
                puVar129 = puVar145;
                puVar127 = puVar145;
                puVar113 = puVar145;
                puVar109 = puVar145;
                puVar49 = puVar145;
                puVar50 = puVar145;
                puVar106 = puVar145;
                puVar108 = puVar145;
                pfVar62 = (fd_set *)pcVar83;
                pcVar83 = (char *)(fd_set *)pcVar83;
                pfVar229 = param_3;
                pfVar72 = (fd_set *)writefds;
                switch(UNRECOVERED_JUMPTABLE) {
                case (code *)0x1400869f7:
                  goto code_r0x0001400869f7;
                case (code *)0x140086a04:
                  goto code_r0x000140086a04;
                case (code *)0x140086ab1:
                  goto code_r0x000140086ab1;
                case (code *)0x140089974:
                  goto code_r0x000140089974;
                case (code *)0x14008997e:
                  goto code_r0x00014008997e;
                case (code *)0x140089a0a:
                  goto code_r0x000140089a0a;
                case (code *)0x14008aa05:
                  goto switchD_14007fde0_caseD_1a;
                case (code *)0x14008aa29:
                  goto code_r0x00014008aa29;
                case (code *)0x14008aa37:
                  goto code_r0x00014008aa37;
                case (code *)0x14008aa49:
                  goto code_r0x00014008aa49;
                case (code *)0x14009310e:
                  goto code_r0x00014009310e;
                case (code *)0x140093113:
                  goto code_r0x000140093113;
                case (code *)0x14009311e:
                  goto code_r0x00014009311e;
                case (code *)0x14009312b:
                  goto code_r0x00014009312b;
                case (code *)0x14009326e:
                  goto code_r0x00014009326e;
                case (code *)0x14009327e:
                  goto code_r0x00014009327e;
                case (code *)0x140093287:
                  goto code_r0x000140093287;
                case (code *)0x140093297:
                  goto code_r0x000140093297;
                case (code *)0x1400932a7:
                  goto code_r0x0001400932a7;
                case (code *)0x1400932b7:
switchD_14009313c_caseD_d:
                  bVar90 = (byte)UNRECOVERED_JUMPTABLE |
                           (byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
                  UNRECOVERED_JUMPTABLE =
                       (code *)CONCAT71((int7)((ulonglong)UNRECOVERED_JUMPTABLE >> 8),bVar90);
                  bVar238 = CARRY1((byte)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count,bVar90);
                  bVar240 = SCARRY1((char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count,bVar90);
                  *(byte *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                       (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + bVar90;
                  bVar237 = (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count < '\0';
                  bVar239 = (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count == '\0';
                  _Dst = puVar97;
                  pfVar107 = pfVar123;
                  puVar225 = (uint *)pcVar83;
                  pfVar72 = (fd_set *)writefds;
code_r0x0001400932bb:
                  uVar69 = (uint)UNRECOVERED_JUMPTABLE;
                  cVar89 = (char)UNRECOVERED_JUMPTABLE;
                  uVar70 = (uint)_Dst;
                  bVar90 = (byte)_Dst;
                  cVar88 = (char)((ulonglong)_Src >> 8);
                  iVar66 = (int)puVar225;
                  puVar97 = _Dst;
                  pcVar103 = (char *)_Src;
                  pfVar159 = pfVar107;
                  pfVar77 = pfVar107;
                  pfVar168 = pfVar107;
                  pfVar160 = pfVar107;
                  puVar17 = (undefined8 *)pfVar107;
                  puVar18 = (undefined8 *)pfVar107;
                  puVar204 = (undefined8 *)pfVar107;
                  puVar19 = (undefined8 *)pfVar107;
                  puVar20 = (undefined8 *)pfVar107;
                  puVar92 = (undefined8 *)pfVar107;
                  puVar115 = (undefined8 *)pfVar107;
                  puVar125 = (undefined8 *)pfVar107;
                  puVar221 = (undefined8 *)pfVar107;
                  puVar21 = (undefined8 *)pfVar107;
                  puVar22 = (undefined8 *)pfVar107;
                  puVar206 = (undefined8 *)pfVar107;
                  puVar23 = (undefined8 *)pfVar107;
                  puVar24 = (undefined8 *)pfVar107;
                  puVar25 = (undefined8 *)pfVar107;
                  puVar26 = (undefined8 *)pfVar107;
                  puVar215 = (undefined8 *)pfVar107;
                  puVar211 = (undefined8 *)pfVar107;
                  puVar27 = (undefined8 *)pfVar107;
                  pSVar196 = (SOCKET *)pfVar107;
                  puVar28 = (undefined8 *)pfVar107;
                  puVar29 = (undefined8 *)pfVar107;
                  pfVar195 = pfVar107;
                  puVar180 = (undefined8 *)pfVar107;
                  puVar193 = (undefined8 *)pfVar107;
                  puVar183 = (undefined8 *)pfVar107;
                  puVar174 = (undefined8 *)pfVar107;
                  puVar166 = (undefined8 *)pfVar107;
                  puVar30 = (undefined8 *)pfVar107;
                  puVar162 = (undefined8 *)pfVar107;
                  puVar31 = (undefined8 *)pfVar107;
                  puVar149 = (undefined8 *)pfVar107;
                  puVar32 = (undefined8 *)pfVar107;
                  puVar134 = (undefined8 *)pfVar107;
                  puVar136 = (undefined8 *)pfVar107;
                  puVar139 = (undefined8 *)pfVar107;
                  puVar140 = (undefined8 *)pfVar107;
                  puVar137 = (undefined8 *)pfVar107;
                  puVar131 = (undefined8 *)pfVar107;
                  puVar114 = (undefined8 *)pfVar107;
                  puVar110 = (undefined8 *)pfVar107;
                  pfVar62 = (fd_set *)puVar225;
                  pcVar83 = (char *)puVar225;
                  writefds = &pfVar72->fd_count;
                  puVar145 = (undefined8 *)pfVar107;
                  switch(UNRECOVERED_JUMPTABLE) {
                  case (code *)0x1400869ff:
                    goto code_r0x0001400869ff;
                  case (code *)0x140086a8e:
                    pfVar84 = pfVar72;
                    goto LAB_14008682d;
                  case (code *)0x140086afd:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x14008997e:
                    goto code_r0x00014008997e;
                  case (code *)0x1400899ff:
                    UNRECOVERED_JUMPTABLE = (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count +
                         (char)UNRECOVERED_JUMPTABLE;
                    goto code_r0x0001400899fd;
                  case (code *)0x140089a0b:
                    if ((fd_set *)_Dst == (fd_set *)((longlong)&uRam0000000000000000 + 1) || bVar239
                       ) goto code_r0x0001400899fd;
                    LOCK();
                    *(uint *)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x7fffff8))->fd_array =
                         uVar69;
                    UNLOCK();
                    goto code_r0x000140089a1a;
                  case (code *)0x14008aa37:
                    goto code_r0x00014008aa37;
                  case (code *)0x14008aa49:
                    goto code_r0x00014008aa49;
                  case (code *)0x14008aa6b:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x14008aa75:
                    goto code_r0x00014008aa74;
                  case (code *)0x14009310f:
                    pcVar83 = (char *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array +
                                      0x1b9);
                    *pcVar83 = *pcVar83 + cVar89;
                    uVar69 = uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count;
                    pcVar83 = (char *)(ulonglong)uVar69;
                    *pcVar83 = *pcVar83 + (char)uVar69;
                    pfVar84 = (fd_set *)
                              FUN_140028b99(pcVar83,(ulonglong)_Src,pfVar72,(ulonglong)param_4);
                    return pfVar84;
                  case (code *)0x140093113:
                    goto code_r0x000140093113;
                  case (code *)0x14009317f:
                    goto code_r0x00014009317f;
                  case (code *)0x1400931bf:
                    return (fd_set *)UNRECOVERED_JUMPTABLE;
                  case (code *)0x14009326f:
                    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 + 3);
                    puVar122 = (undefined8 *)pfVar107;
                    goto code_r0x00014009326e;
                  case (code *)0x14009327e:
                    goto code_r0x00014009327e;
                  case (code *)0x1400932a7:
                    goto code_r0x0001400932a7;
                  case (code *)0x1400932bf:
                    pcVar103 = (char *)(fd_set *)0x4010aa1c;
                    break;
                  case (code *)0x1400932cf:
                    UNRECOVERED_JUMPTABLE = (code *)0x25;
                    pfVar16 = pfVar107;
                    goto switchD_14009313c_caseD_6;
                  case (code *)0x1400932d7:
                    goto switchD_14009313c_caseD_7;
                  case (code *)0x1400932df:
                    UNRECOVERED_JUMPTABLE = (code *)&DAT_00000013;
                    goto switchD_14009313c_caseD_7;
                  case (code *)0x1400932ef:
                    UNRECOVERED_JUMPTABLE = (code *)&DAT_00000014;
                    break;
                  case (code *)0x1400932ff:
                    UNRECOVERED_JUMPTABLE = (code *)0x29;
                    pfVar101 = pfVar107;
                    goto switchD_14009313c_caseD_5;
                  case (code *)0x1400934f5:
                    goto code_r0x0001400934f5;
                  case (code *)0x1400934f7:
                    goto code_r0x0001400934f7;
                  case (code *)0x1400934fc:
                    puVar92 = *(undefined8 **)_Dst;
                    _Dst = (uint *)*puVar92;
                    UNRECOVERED_JUMPTABLE = *(code **)(puVar92[1] + 0x18);
                    puVar34 = (undefined8 *)pfVar107;
code_r0x00014009350a:
                    do {
                      puVar145 = puVar34;
                      pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
                      puVar97 = _Dst;
                      puVar225 = _Dst;
                      _Src = (uint *)pcVar103;
                      puVar126 = puVar145;
                      pfVar234 = (fd_set *)puVar145;
                      pfVar101 = (fd_set *)puVar145;
                      pfVar16 = (fd_set *)puVar145;
                      pfVar159 = (fd_set *)puVar145;
                      pfVar93 = (fd_set *)puVar145;
                      pfVar123 = (fd_set *)puVar145;
                      pfVar141 = (fd_set *)puVar145;
                      pfVar205 = (fd_set *)puVar145;
                      pfVar77 = (fd_set *)puVar145;
                      pfVar94 = (fd_set *)puVar145;
                      pfVar160 = (fd_set *)puVar145;
                      puVar17 = puVar145;
                      puVar18 = puVar145;
                      puVar204 = puVar145;
                      puVar19 = puVar145;
                      pfVar107 = (fd_set *)puVar145;
                      puVar20 = puVar145;
                      puVar92 = puVar145;
                      puVar115 = puVar145;
                      puVar125 = puVar145;
                      puVar221 = puVar145;
                      puVar21 = puVar145;
                      puVar22 = puVar145;
                      puVar206 = puVar145;
                      puVar23 = puVar145;
                      puVar24 = puVar145;
                      puVar25 = puVar145;
                      puVar26 = puVar145;
                      puVar215 = puVar145;
                      puVar211 = puVar145;
                      puVar27 = puVar145;
                      pSVar196 = puVar145;
                      puVar28 = puVar145;
                      puVar29 = puVar145;
                      pfVar195 = (fd_set *)puVar145;
                      puVar180 = puVar145;
                      puVar193 = puVar145;
                      puVar183 = puVar145;
                      puVar174 = puVar145;
                      puVar166 = puVar145;
                      puVar30 = puVar145;
                      puVar162 = puVar145;
                      puVar31 = puVar145;
                      puVar149 = puVar145;
                      puVar32 = puVar145;
                      puVar134 = puVar145;
                      puVar136 = puVar145;
                      puVar139 = puVar145;
                      puVar140 = puVar145;
                      puVar137 = puVar145;
                      puVar131 = puVar145;
                      puVar114 = puVar145;
                      puVar110 = puVar145;
                      puVar199 = puVar145;
                      puVar34 = puVar145;
                      puVar122 = puVar145;
                      puVar198 = puVar145;
                      puVar207 = puVar145;
                      puVar209 = puVar145;
                      puVar212 = puVar145;
                      puVar214 = puVar145;
                      puVar35 = puVar145;
                      puVar191 = puVar145;
                      puVar177 = puVar145;
                      puVar165 = puVar145;
                      puVar36 = puVar145;
                      puVar151 = puVar145;
                      puVar150 = puVar145;
                      puVar135 = puVar145;
                      puVar138 = puVar145;
                      puVar37 = puVar145;
                      puVar116 = puVar145;
                      puVar124 = puVar145;
                      puVar222 = puVar145;
                      puVar203 = puVar145;
                      puVar38 = puVar145;
                      puVar217 = puVar145;
                      puVar220 = puVar145;
                      puVar39 = puVar145;
                      puVar219 = puVar145;
                      puVar218 = puVar145;
                      puVar216 = puVar145;
                      puVar201 = puVar145;
                      puVar210 = puVar145;
                      puVar40 = puVar145;
                      puVar41 = puVar145;
                      puVar181 = puVar145;
                      puVar42 = puVar145;
                      puVar192 = puVar145;
                      puVar43 = puVar145;
                      puVar188 = puVar145;
                      puVar44 = puVar145;
                      puVar185 = puVar145;
                      puVar186 = puVar145;
                      puVar190 = puVar145;
                      puVar189 = puVar145;
                      puVar171 = puVar145;
                      puVar167 = puVar145;
                      puVar176 = puVar145;
                      puVar158 = puVar145;
                      puVar45 = puVar145;
                      pSVar163 = puVar145;
                      puVar164 = puVar145;
                      puVar46 = puVar145;
                      puVar157 = puVar145;
                      puVar156 = puVar145;
                      puVar155 = puVar145;
                      puVar154 = puVar145;
                      puVar152 = puVar145;
                      puVar153 = puVar145;
                      puVar146 = puVar145;
                      puVar47 = puVar145;
                      puVar147 = puVar145;
                      puVar144 = puVar145;
                      puVar143 = puVar145;
                      puVar48 = puVar145;
                      puVar128 = puVar145;
                      puVar130 = puVar145;
                      puVar129 = puVar145;
                      puVar127 = puVar145;
                      puVar113 = puVar145;
                      puVar109 = puVar145;
                      puVar49 = puVar145;
                      puVar50 = puVar145;
                      puVar106 = puVar145;
                      puVar108 = puVar145;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pcVar83 = (char *)(fd_set *)pcVar83;
                      pcVar83 = (char *)(fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pcVar83 = (char *)(fd_set *)pcVar83;
                      pcVar83 = (char *)(fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar62 = (fd_set *)pcVar83;
                      pfVar229 = param_3;
                      pfVar72 = (fd_set *)writefds;
                      switch(UNRECOVERED_JUMPTABLE) {
                      case (code *)0x1400869f7:
                        goto code_r0x0001400869f7;
                      case (code *)0x140086a04:
                        goto code_r0x000140086a04;
                      case (code *)0x140086ab1:
                        goto code_r0x000140086ab1;
                      case (code *)0x140089974:
                        goto code_r0x000140089974;
                      case (code *)0x14008997e:
                        goto code_r0x00014008997e;
                      case (code *)0x140089a0a:
                        goto code_r0x000140089a0a;
                      case (code *)0x14008aa05:
                        goto switchD_14007fde0_caseD_1a;
                      case (code *)0x14008aa29:
                        goto code_r0x00014008aa29;
                      case (code *)0x14008aa37:
                        goto code_r0x00014008aa37;
                      case (code *)0x14008aa49:
                        goto code_r0x00014008aa49;
                      case (code *)0x14009310e:
                        goto code_r0x00014009310e;
                      case (code *)0x140093113:
                        goto code_r0x000140093113;
                      case (code *)0x14009311e:
                        goto code_r0x00014009311e;
                      case (code *)0x14009312b:
                        goto code_r0x00014009312b;
                      case (code *)0x14009326e:
                        goto code_r0x00014009326e;
                      case (code *)0x14009327e:
                        goto code_r0x00014009327e;
                      case (code *)0x140093287:
                        goto code_r0x000140093287;
                      case (code *)0x140093297:
                        goto code_r0x000140093297;
                      case (code *)0x1400932a7:
                        goto code_r0x0001400932a7;
                      case (code *)0x1400932b7:
                        goto switchD_14009313c_caseD_d;
                      case (code *)0x1400932c7:
                        goto switchD_14009313c_caseD_6;
                      case (code *)0x1400932d7:
                        goto switchD_14009313c_caseD_7;
                      case (code *)0x1400932e7:
                        goto switchD_14009313c_caseD_b;
                      case (code *)0x1400932f7:
                        goto switchD_14009313c_caseD_5;
                      case (code *)0x1400934dc:
code_r0x0001400934dc:
                        do {
                          _Src = (uint *)param_2;
                          piVar80 = (int *)((longlong)
                                            ((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x18b)
                          ;
                          *piVar80 = *piVar80 + -1;
                          pbVar2 = (byte *)((longlong)param_4 * 5 + -0xf);
                          *pbVar2 = *pbVar2 & (byte)param_4;
                          bVar238 = (undefined1 *)0xffffffffffffffdf < puVar124;
                          bVar240 = SCARRY8((longlong)puVar124,0x20);
                          bVar237 = (longlong)((longlong)puVar124 + 0x20) < 0;
                          bVar239 = puVar124 == (undefined8 *)0xffffffffffffffe0;
                          param_2 = *(undefined ***)((longlong)puVar124 + 0x20);
                          param_3 = *(fd_set **)((longlong)puVar124 + 0x28);
                          puVar225 = *(uint **)((longlong)puVar124 + 0x30);
                          pfVar107 = (fd_set *)((longlong)puVar124 + 0x38);
                          pfVar72 = pfVar229;
                          param_4 = (fd_set *)pcVar83;
code_r0x0001400934f5:
                          param_1 = *(fd_set **)pfVar107;
                          pcVar103 = (char *)_Src;
                          puVar125 = (undefined8 *)((longlong)pfVar107 + 8);
                          pcVar83 = (char *)puVar225;
                          writefds = &pfVar72->fd_count;
code_r0x0001400934f7:
                          pfVar84 = (fd_set *)*puVar125;
                          puVar145 = puVar125 + 1;
                          pfVar168 = (fd_set *)UNRECOVERED_JUMPTABLE;
                          puVar97 = _Dst;
                          puVar225 = _Dst;
                          _Src = (uint *)pcVar103;
                          puVar126 = puVar125 + 1;
                          pfVar234 = (fd_set *)(puVar125 + 1);
                          pfVar101 = (fd_set *)(puVar125 + 1);
                          pfVar16 = (fd_set *)(puVar125 + 1);
                          pfVar159 = (fd_set *)(puVar125 + 1);
                          pfVar93 = (fd_set *)(puVar125 + 1);
                          pfVar123 = (fd_set *)(puVar125 + 1);
                          pfVar141 = (fd_set *)(puVar125 + 1);
                          pfVar205 = (fd_set *)(puVar125 + 1);
                          pfVar77 = (fd_set *)(puVar125 + 1);
                          pfVar94 = (fd_set *)(puVar125 + 1);
                          pfVar160 = (fd_set *)(puVar125 + 1);
                          puVar17 = puVar125 + 1;
                          puVar18 = puVar125 + 1;
                          puVar204 = puVar125 + 1;
                          puVar19 = puVar125 + 1;
                          pfVar107 = (fd_set *)(puVar125 + 1);
                          puVar20 = puVar125 + 1;
                          puVar92 = puVar125 + 1;
                          puVar115 = puVar125 + 1;
                          puVar125 = puVar125 + 1;
                          puVar221 = puVar125 + 1;
                          puVar21 = puVar125 + 1;
                          puVar22 = puVar125 + 1;
                          puVar206 = puVar125 + 1;
                          puVar23 = puVar125 + 1;
                          puVar24 = puVar125 + 1;
                          puVar25 = puVar125 + 1;
                          puVar26 = puVar125 + 1;
                          puVar215 = puVar125 + 1;
                          puVar211 = puVar125 + 1;
                          puVar27 = puVar125 + 1;
                          pSVar196 = puVar125 + 1;
                          puVar28 = puVar125 + 1;
                          puVar29 = puVar125 + 1;
                          pfVar195 = (fd_set *)(puVar125 + 1);
                          puVar180 = puVar125 + 1;
                          puVar193 = puVar125 + 1;
                          puVar183 = puVar125 + 1;
                          puVar174 = puVar125 + 1;
                          puVar166 = puVar125 + 1;
                          puVar30 = puVar125 + 1;
                          puVar162 = puVar125 + 1;
                          puVar31 = puVar125 + 1;
                          puVar149 = puVar125 + 1;
                          puVar32 = puVar125 + 1;
                          puVar134 = puVar125 + 1;
                          puVar136 = puVar125 + 1;
                          puVar139 = puVar125 + 1;
                          puVar140 = puVar125 + 1;
                          puVar137 = puVar125 + 1;
                          puVar131 = puVar125 + 1;
                          puVar114 = puVar125 + 1;
                          puVar110 = puVar125 + 1;
                          puVar199 = puVar125 + 1;
                          puVar34 = puVar125 + 1;
                          puVar122 = puVar125 + 1;
                          puVar198 = puVar125 + 1;
                          puVar207 = puVar125 + 1;
                          puVar209 = puVar125 + 1;
                          puVar212 = puVar125 + 1;
                          puVar214 = puVar125 + 1;
                          puVar35 = puVar125 + 1;
                          puVar191 = puVar125 + 1;
                          puVar177 = puVar125 + 1;
                          puVar165 = puVar125 + 1;
                          puVar36 = puVar125 + 1;
                          puVar151 = puVar125 + 1;
                          puVar150 = puVar125 + 1;
                          puVar135 = puVar125 + 1;
                          puVar138 = puVar125 + 1;
                          puVar37 = puVar125 + 1;
                          puVar116 = puVar125 + 1;
                          puVar124 = puVar125 + 1;
                          puVar222 = puVar125 + 1;
                          puVar203 = puVar125 + 1;
                          puVar38 = puVar125 + 1;
                          puVar217 = puVar125 + 1;
                          puVar220 = puVar125 + 1;
                          puVar39 = puVar125 + 1;
                          puVar219 = puVar125 + 1;
                          puVar218 = puVar125 + 1;
                          puVar216 = puVar125 + 1;
                          puVar201 = puVar125 + 1;
                          puVar210 = puVar125 + 1;
                          puVar40 = puVar125 + 1;
                          puVar41 = puVar125 + 1;
                          puVar181 = puVar125 + 1;
                          puVar42 = puVar125 + 1;
                          puVar192 = puVar125 + 1;
                          puVar43 = puVar125 + 1;
                          puVar188 = puVar125 + 1;
                          puVar44 = puVar125 + 1;
                          puVar185 = puVar125 + 1;
                          puVar186 = puVar125 + 1;
                          puVar190 = puVar125 + 1;
                          puVar189 = puVar125 + 1;
                          puVar171 = puVar125 + 1;
                          puVar167 = puVar125 + 1;
                          puVar176 = puVar125 + 1;
                          puVar158 = puVar125 + 1;
                          puVar45 = puVar125 + 1;
                          pSVar163 = puVar125 + 1;
                          puVar164 = puVar125 + 1;
                          puVar46 = puVar125 + 1;
                          puVar157 = puVar125 + 1;
                          puVar156 = puVar125 + 1;
                          puVar155 = puVar125 + 1;
                          puVar154 = puVar125 + 1;
                          puVar152 = puVar125 + 1;
                          puVar153 = puVar125 + 1;
                          puVar146 = puVar125 + 1;
                          puVar47 = puVar125 + 1;
                          puVar147 = puVar125 + 1;
                          puVar144 = puVar125 + 1;
                          puVar143 = puVar125 + 1;
                          puVar48 = puVar125 + 1;
                          puVar128 = puVar125 + 1;
                          puVar130 = puVar125 + 1;
                          puVar129 = puVar125 + 1;
                          puVar127 = puVar125 + 1;
                          puVar113 = puVar125 + 1;
                          puVar109 = puVar125 + 1;
                          puVar49 = puVar125 + 1;
                          puVar50 = puVar125 + 1;
                          puVar106 = puVar125 + 1;
                          puVar108 = puVar125 + 1;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pcVar83 = (char *)(fd_set *)pcVar83;
                          pcVar83 = (char *)(fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pcVar83 = (char *)(fd_set *)pcVar83;
                          pcVar83 = (char *)(fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar62 = (fd_set *)pcVar83;
                          pfVar229 = param_3;
                          pfVar72 = (fd_set *)writefds;
                          switch(UNRECOVERED_JUMPTABLE) {
                          case (code *)0x1400869f7:
                            goto code_r0x0001400869f7;
                          case (code *)0x140086a04:
                            goto code_r0x000140086a04;
                          case (code *)0x140086ab1:
                            goto code_r0x000140086ab1;
                          case (code *)0x140089974:
                            goto code_r0x000140089974;
                          case (code *)0x14008997e:
                            goto code_r0x00014008997e;
                          case (code *)0x140089a0a:
                            goto code_r0x000140089a0a;
                          case (code *)0x14008aa05:
                            goto switchD_14007fde0_caseD_1a;
                          case (code *)0x14008aa29:
                            goto code_r0x00014008aa29;
                          case (code *)0x14008aa37:
                            goto code_r0x00014008aa37;
                          case (code *)0x14008aa49:
                            goto code_r0x00014008aa49;
                          case (code *)0x14009310e:
                            goto code_r0x00014009310e;
                          case (code *)0x140093113:
                            goto code_r0x000140093113;
                          case (code *)0x14009311e:
                            goto code_r0x00014009311e;
                          case (code *)0x14009312b:
                            goto code_r0x00014009312b;
                          case (code *)0x14009326e:
                            goto code_r0x00014009326e;
                          case (code *)0x14009327e:
                            goto code_r0x00014009327e;
                          case (code *)0x140093287:
                            goto code_r0x000140093287;
                          case (code *)0x140093297:
                            goto code_r0x000140093297;
                          case (code *)0x1400932a7:
                            goto code_r0x0001400932a7;
                          case (code *)0x1400932b7:
                            goto switchD_14009313c_caseD_d;
                          case (code *)0x1400932c7:
                            goto switchD_14009313c_caseD_6;
                          case (code *)0x1400932d7:
                            goto switchD_14009313c_caseD_7;
                          case (code *)0x1400932e7:
                            goto switchD_14009313c_caseD_b;
                          case (code *)0x1400932f7:
                            goto switchD_14009313c_caseD_5;
                          case (code *)0x1400934e4:
                            goto code_r0x0001400934e4;
                          case (code *)0x1400934f7:
                            goto code_r0x0001400934f7;
                          case (code *)0x14009350a:
                            goto code_r0x00014009350a;
                          case (code *)0x14009351d:
                            goto code_r0x00014009351d;
                          case (code *)0x14009363c:
                            goto code_r0x00014009363c;
                          case (code *)0x140093841:
                            goto code_r0x000140093841;
                          case (code *)0x1400938b6:
                            goto code_r0x0001400938b6;
                          case (code *)0x14009390d:
                            goto switchD_14007f6e5_caseD_69;
                          case (code *)0x140093981:
                            goto code_r0x000140093981;
                          case (code *)0x140093b02:
                            goto code_r0x000140093b02;
                          case (code *)0x140093b0a:
                            goto code_r0x000140093b0a;
                          case (code *)0x140093b10:
                            goto code_r0x000140093b10;
                          case (code *)0x140093b18:
                            goto code_r0x000140093b18;
                          case (code *)0x140093b1e:
                            goto code_r0x000140093b1e;
                          case (code *)0x140093b24:
                            goto code_r0x000140093b24;
                          case (code *)0x140093b2c:
                            goto code_r0x000140093b2c;
                          case (code *)0x140093b32:
                            goto switchD_14009313c_caseD_4e;
                          case (code *)0x140093b3a:
                            goto switchD_14009313c_caseD_47;
                          case (code *)0x140093b42:
                            goto code_r0x000140093b42;
                          case (code *)0x140093b4d:
                            goto code_r0x000140093b4d;
                          case (code *)0x140093c4e:
                            goto code_r0x000140093c4e;
                          case (code *)0x140093c67:
                            goto code_r0x000140093c67;
                          case (code *)0x140093cbe:
                            goto switchD_14007f7e4_caseD_75;
                          case (code *)0x140093d22:
                            goto code_r0x000140093d22;
                          case (code *)0x140093f72:
                            goto code_r0x000140093f72;
                          case (code *)0x140093fa1:
                            goto code_r0x000140093fa1;
                          case (code *)0x140093ff8:
                            goto switchD_14007f7e4_caseD_79;
                          case (code *)0x14009405c:
                            goto code_r0x00014009405c;
                          case (code *)0x140094336:
                            goto code_r0x000140094336;
                          case (code *)0x140094371:
                            goto switchD_14007f7e4_caseD_7f;
                          case (code *)0x14009439f:
                            goto code_r0x00014009439f;
                          case (code *)0x1400943d5:
                            goto code_r0x0001400943d5;
                          case (code *)0x140094428:
                            goto code_r0x000140094428;
                          case (code *)0x140094758:
                            goto code_r0x000140094758;
                          case (code *)0x140094790:
                            goto code_r0x000140094790;
                          case (code *)0x140094798:
                            goto code_r0x000140094798;
                          case (code *)0x1400947b8:
                            goto code_r0x0001400947b8;
                          case (code *)0x1400947d2:
                            goto code_r0x0001400947d2;
                          case (code *)0x140094829:
                            goto switchD_14007f7e4_caseD_82;
                          case (code *)0x14009488d:
                            goto code_r0x00014009488d;
                          case (code *)0x1400948c8:
                            goto code_r0x0001400948c8;
                          case (code *)0x1400948d4:
                            goto code_r0x0001400948d4;
                          case (code *)0x1400948e0:
                            goto code_r0x0001400948e0;
                          case (code *)0x1400948e4:
                            goto switchD_1400944c0_caseD_a;
                          case (code *)0x1400948e8:
                            goto code_r0x0001400948e8;
                          case (code *)0x140095255:
                            goto code_r0x000140095255;
                          case (code *)0x1400953e6:
                            goto code_r0x0001400953e6;
                          case (code *)0x140095429:
                            goto code_r0x000140095429;
                          case (code *)0x140095493:
                            goto code_r0x000140095493;
                          case (code *)0x140095516:
                            goto code_r0x000140095516;
                          case (code *)0x140095705:
                            goto code_r0x000140095705;
                          case (code *)0x140095763:
                            goto switchD_14007f6e5_caseD_a0;
                          case (code *)0x1400957d7:
                            goto code_r0x0001400957d7;
                          case (code *)0x14009588d:
                            goto code_r0x00014009588d;
                          case (code *)0x140095b53:
                            goto code_r0x000140095b53;
                          case (code *)0x140095bb8:
                            goto code_r0x000140095bb8;
                          case (code *)0x140095c38:
                            goto code_r0x000140095c38;
                          case (code *)0x140095c92:
                            goto code_r0x000140095c92;
                          case (code *)0x140095d03:
                            goto code_r0x000140095d03;
                          case (code *)0x140095d65:
                            goto code_r0x000140095d65;
                          case (code *)0x140095ddb:
                            goto code_r0x000140095ddb;
                          case (code *)0x14009620a:
                            goto code_r0x00014009620a;
                          case (code *)0x1400962bc:
                            goto switchD_14007f7e4_caseD_aa;
                          case (code *)0x140096320:
                            goto code_r0x000140096320;
                          case (code *)0x14009639c:
                            goto code_r0x00014009639c;
                          case (code *)0x14009669b:
                            goto code_r0x00014009669b;
                          case (code *)0x1400966e5:
                            goto code_r0x0001400966e5;
                          case (code *)0x14009674c:
                            goto code_r0x00014009674c;
                          case (code *)0x1400967cc:
                            goto code_r0x0001400967cc;
                          case (code *)0x14009687a:
                            goto code_r0x00014009687a;
                          case (code *)0x140096889:
                            goto code_r0x000140096889;
                          case (code *)0x1400968a8:
                            goto code_r0x0001400968a8;
                          case (code *)0x1400968b7:
                            goto code_r0x0001400968b7;
                          case (code *)0x1400968d6:
                            goto code_r0x0001400968d6;
                          case (code *)0x1400968e5:
                            goto code_r0x0001400968e5;
                          case (code *)0x1400968f4:
                            goto code_r0x0001400968f4;
                          case (code *)0x140096903:
                            goto code_r0x000140096903;
                          case (code *)0x140096912:
                            goto code_r0x000140096912;
                          case (code *)0x140096921:
                            goto code_r0x000140096921;
                          case (code *)0x140096930:
                            goto code_r0x000140096930;
                          case (code *)0x14009693f:
                            goto code_r0x00014009693f;
                          case (code *)0x14009694e:
                            goto code_r0x00014009694e;
                          case (code *)0x14009695d:
                            goto code_r0x00014009695d;
                          case (code *)0x14009696c:
                            goto code_r0x00014009696c;
                          case (code *)0x14009698b:
                            goto code_r0x00014009698b;
                          case (code *)0x1400969ac:
                            goto code_r0x0001400969ac;
                          case (code *)0x1400969bb:
                            goto switchD_14009313c_caseD_8a;
                          case (code *)0x1400969ca:
                            goto code_r0x0001400969ca;
                          case (code *)0x1400969d9:
                            goto code_r0x0001400969d9;
                          case (code *)0x1400969e8:
                            goto switchD_14007fde0_caseD_aa;
                          case (code *)0x1400969f7:
                            goto code_r0x0001400969f7;
                          case (code *)0x140096a06:
                            goto switchD_1400944c0_caseD_2f;
                          case (code *)0x140096a15:
                            goto switchD_1400944c0_caseD_5a;
                          case (code *)0x140096a2c:
                            goto switchD_14007fde0_caseD_cc;
                          case (code *)0x140096a43:
                            goto switchD_1400944c0_caseD_5e;
                          case (code *)0x140096a52:
                            goto code_r0x000140096a52;
                          case (code *)0x140096a61:
                            goto switchD_14007fde0_caseD_b8;
                          case (code *)0x140096a70:
                            goto switchD_14007fde0_caseD_b0;
                          case (code *)0x140096a7f:
                            goto switchD_14007fde0_caseD_a9;
                          case (code *)0x140096a8e:
                            goto switchD_14007fde0_caseD_b5;
                          case (code *)0x140096aa5:
                            goto code_r0x000140096aa5;
                          case (code *)0x140096ab4:
                            goto code_r0x000140096ab4;
                          case (code *)0x140096ac3:
                            goto code_r0x000140096ac3;
                          case (code *)0x140096ad2:
                            goto code_r0x000140096ad2;
                          case (code *)0x140096ae1:
                            goto code_r0x000140096ae1;
                          case (code *)0x140096af0:
                            goto code_r0x000140096af0;
                          case (code *)0x140096aff:
                            goto code_r0x000140096aff;
                          case (code *)0x140096b14:
                            goto code_r0x000140096b14;
                          case (code *)0x140096b23:
                            goto code_r0x000140096b23;
                          case (code *)0x140096b42:
                            goto code_r0x000140096b42;
                          case (code *)0x140096b51:
                            goto code_r0x000140096b51;
                          case (code *)0x140096b60:
                            goto code_r0x000140096b60;
                          case (code *)0x140096b6f:
                            goto code_r0x000140096b6f;
                          case (code *)0x140096b7e:
                            goto code_r0x000140096b7e;
                          case (code *)0x140096b8d:
                            goto code_r0x000140096b8d;
                          case (code *)0x140096c2e:
                            goto code_r0x000140096c2e;
                          case (code *)0x140096c3a:
                            goto code_r0x000140096c3a;
                          case (code *)0x140096c46:
                            goto code_r0x000140096c46;
                          case (code *)0x140096c52:
                            goto code_r0x000140096c52;
                          case (code *)0x140096ffd:
                            goto code_r0x000140096ffd;
                          case (code *)0x140097024:
                            goto code_r0x000140097024;
                          case (code *)0x14009707b:
                            goto switchD_14007f7e4_caseD_de;
                          case (code *)0x1400970df:
                            goto code_r0x0001400970df;
                          case (code *)0x1400971b9:
                            goto code_r0x0001400971b9;
                          case (code *)0x1400971d6:
                            goto code_r0x0001400971d6;
                          case (code *)0x140097200:
                            goto code_r0x000140097200;
                          case (code *)0x140097217:
                            goto LAB_140097217;
                          case (code *)0x140097241:
                            goto code_r0x000140097241;
                          case (code *)0x14009725e:
                            goto code_r0x00014009725e;
                          case (code *)0x140097275:
                            goto code_r0x000140097275;
                          case (code *)0x14009728c:
                            goto code_r0x00014009728c;
                          case (code *)0x1400972a3:
                            goto code_r0x0001400972a3;
                          case (code *)0x1400972ba:
                            goto code_r0x0001400972ba;
                          case (code *)0x1400972d1:
                            goto code_r0x0001400972d1;
                          case (code *)0x1400972e8:
                            goto code_r0x0001400972e8;
                          case (code *)0x1400972ff:
                            goto code_r0x0001400972ff;
                          case (code *)0x14009731c:
                            goto code_r0x00014009731c;
                          case (code *)0x140097333:
                            goto code_r0x000140097333;
                          case (code *)0x14009735d:
                            goto code_r0x00014009735d;
                          case (code *)0x140097383:
                            goto code_r0x000140097383;
                          case (code *)0x1400973a0:
                            goto code_r0x0001400973a0;
                          case (code *)0x1400973bd:
                            goto code_r0x0001400973bd;
                          case (code *)0x1400973d4:
                            goto code_r0x0001400973d4;
                          case (code *)0x1400973eb:
                            goto code_r0x0001400973eb;
                          case (code *)0x140097408:
                            goto code_r0x000140097408;
                          case (code *)0x14009741f:
                            goto code_r0x00014009741f;
                          case (code *)0x14009743c:
                            goto code_r0x00014009743c;
                          case (code *)0x1400974a5:
                            goto code_r0x0001400974a5;
                          case (code *)0x14009750e:
                            goto code_r0x00014009750e;
                          case (code *)0x14009752b:
                            goto code_r0x00014009752b;
                          case (code *)0x140097548:
                            goto code_r0x000140097548;
                          case (code *)0x140097565:
                            goto code_r0x000140097565;
                          case (code *)0x14009757c:
                            goto code_r0x00014009757c;
                          case (code *)0x140097593:
                            goto switchD_14007f6e5_caseD_fa;
                          case (code *)0x140097607:
                            goto code_r0x000140097607;
                          case (code *)0x140097624:
                            goto code_r0x000140097624;
                          case (code *)0x140097641:
                            goto code_r0x000140097641;
                          case (code *)0x14009765e:
                            goto code_r0x00014009765e;
                          case (code *)0x140097675:
                            goto code_r0x000140097675;
                          case (code *)0x140097692:
                            goto code_r0x000140097692;
                          case (code *)0x1400976af:
                            goto code_r0x0001400976af;
                          case (code *)0x1400976d9:
                            goto code_r0x0001400976d9;
                          case (code *)0x1400976f6:
                            goto code_r0x0001400976f6;
                          case (code *)0x140097720:
                            goto code_r0x000140097720;
                          case (code *)0x14009773d:
                            goto code_r0x00014009773d;
                          case (code *)0x140097751:
                            goto code_r0x000140097751;
                          case (code *)0x14009776e:
                            goto code_r0x00014009776e;
                          case (code *)0x14009778b:
                            goto code_r0x00014009778b;
                          case (code *)0x1400977a8:
                            goto code_r0x0001400977a8;
                          case (code *)0x1400977de:
                            goto code_r0x0001400977de;
                          case (code *)0x1400977f8:
                            goto code_r0x0001400977f8;
                          case (code *)0x140097812:
                            goto code_r0x000140097812;
                          case (code *)0x14009782c:
                            goto code_r0x00014009782c;
                          case (code *)0x140098f73:
                            goto code_r0x000140098f73;
                          case (code *)0x140098f85:
                            goto code_r0x000140098f85;
                          case (code *)0x140098fc3:
                            goto code_r0x000140098fc3;
                          case (code *)0x140098ff6:
                            goto code_r0x000140098ff6;
                          case (code *)0x140099405:
                            goto code_r0x000140099405;
                          }
                        } while( true );
                      case (code *)0x1400934e4:
                        goto code_r0x0001400934e4;
                      case (code *)0x1400934f7:
                        goto code_r0x0001400934f7;
                      case (code *)0x14009351d:
                        goto code_r0x00014009351d;
                      case (code *)0x14009363c:
                        goto code_r0x00014009363c;
                      case (code *)0x140093841:
                        goto code_r0x000140093841;
                      case (code *)0x1400938b6:
                        goto code_r0x0001400938b6;
                      case (code *)0x14009390d:
                        goto switchD_14007f6e5_caseD_69;
                      case (code *)0x140093981:
                        goto code_r0x000140093981;
                      case (code *)0x140093b02:
                        goto code_r0x000140093b02;
                      case (code *)0x140093b0a:
                        goto code_r0x000140093b0a;
                      case (code *)0x140093b10:
                        goto code_r0x000140093b10;
                      case (code *)0x140093b18:
                        goto code_r0x000140093b18;
                      case (code *)0x140093b1e:
                        goto code_r0x000140093b1e;
                      case (code *)0x140093b24:
                        goto code_r0x000140093b24;
                      case (code *)0x140093b2c:
                        goto code_r0x000140093b2c;
                      case (code *)0x140093b32:
                        goto switchD_14009313c_caseD_4e;
                      case (code *)0x140093b3a:
                        goto switchD_14009313c_caseD_47;
                      case (code *)0x140093b42:
                        goto code_r0x000140093b42;
                      case (code *)0x140093b4d:
                        goto code_r0x000140093b4d;
                      case (code *)0x140093c4e:
                        goto code_r0x000140093c4e;
                      case (code *)0x140093c67:
                        goto code_r0x000140093c67;
                      case (code *)0x140093cbe:
                        goto switchD_14007f7e4_caseD_75;
                      case (code *)0x140093d22:
                        goto code_r0x000140093d22;
                      case (code *)0x140093f72:
                        goto code_r0x000140093f72;
                      case (code *)0x140093fa1:
                        goto code_r0x000140093fa1;
                      case (code *)0x140093ff8:
                        goto switchD_14007f7e4_caseD_79;
                      case (code *)0x14009405c:
                        goto code_r0x00014009405c;
                      case (code *)0x140094336:
                        goto code_r0x000140094336;
                      case (code *)0x140094371:
                        goto switchD_14007f7e4_caseD_7f;
                      case (code *)0x14009439f:
                        goto code_r0x00014009439f;
                      case (code *)0x1400943d5:
                        goto code_r0x0001400943d5;
                      case (code *)0x140094428:
                        goto code_r0x000140094428;
                      case (code *)0x140094758:
                        goto code_r0x000140094758;
                      case (code *)0x140094790:
                        goto code_r0x000140094790;
                      case (code *)0x140094798:
                        goto code_r0x000140094798;
                      case (code *)0x1400947b8:
                        goto code_r0x0001400947b8;
                      case (code *)0x1400947d2:
                        goto code_r0x0001400947d2;
                      case (code *)0x140094829:
                        goto switchD_14007f7e4_caseD_82;
                      case (code *)0x14009488d:
                        goto code_r0x00014009488d;
                      case (code *)0x1400948c8:
                        goto code_r0x0001400948c8;
                      case (code *)0x1400948d4:
                        goto code_r0x0001400948d4;
                      case (code *)0x1400948e0:
                        goto code_r0x0001400948e0;
                      case (code *)0x1400948e4:
                        goto switchD_1400944c0_caseD_a;
                      case (code *)0x1400948e8:
                        goto code_r0x0001400948e8;
                      case (code *)0x140095255:
                        goto code_r0x000140095255;
                      case (code *)0x1400953e6:
                        goto code_r0x0001400953e6;
                      case (code *)0x140095429:
                        goto code_r0x000140095429;
                      case (code *)0x140095493:
                        goto code_r0x000140095493;
                      case (code *)0x140095516:
                        goto code_r0x000140095516;
                      case (code *)0x140095705:
                        goto code_r0x000140095705;
                      case (code *)0x140095763:
                        goto switchD_14007f6e5_caseD_a0;
                      case (code *)0x1400957d7:
                        goto code_r0x0001400957d7;
                      case (code *)0x14009588d:
                        goto code_r0x00014009588d;
                      case (code *)0x140095b53:
                        goto code_r0x000140095b53;
                      case (code *)0x140095bb8:
                        goto code_r0x000140095bb8;
                      case (code *)0x140095c38:
                        goto code_r0x000140095c38;
                      case (code *)0x140095c92:
                        goto code_r0x000140095c92;
                      case (code *)0x140095d03:
                        goto code_r0x000140095d03;
                      case (code *)0x140095d65:
                        goto code_r0x000140095d65;
                      case (code *)0x140095ddb:
                        goto code_r0x000140095ddb;
                      case (code *)0x14009620a:
                        goto code_r0x00014009620a;
                      case (code *)0x1400962bc:
                        goto switchD_14007f7e4_caseD_aa;
                      case (code *)0x140096320:
                        goto code_r0x000140096320;
                      case (code *)0x14009639c:
                        goto code_r0x00014009639c;
                      case (code *)0x14009669b:
                        goto code_r0x00014009669b;
                      case (code *)0x1400966e5:
                        goto code_r0x0001400966e5;
                      case (code *)0x14009674c:
                        goto code_r0x00014009674c;
                      case (code *)0x1400967cc:
                        goto code_r0x0001400967cc;
                      case (code *)0x14009687a:
                        goto code_r0x00014009687a;
                      case (code *)0x140096889:
                        goto code_r0x000140096889;
                      case (code *)0x1400968a8:
                        goto code_r0x0001400968a8;
                      case (code *)0x1400968b7:
                        goto code_r0x0001400968b7;
                      case (code *)0x1400968d6:
                        goto code_r0x0001400968d6;
                      case (code *)0x1400968e5:
                        goto code_r0x0001400968e5;
                      case (code *)0x1400968f4:
                        goto code_r0x0001400968f4;
                      case (code *)0x140096903:
                        goto code_r0x000140096903;
                      case (code *)0x140096912:
                        goto code_r0x000140096912;
                      case (code *)0x140096921:
                        goto code_r0x000140096921;
                      case (code *)0x140096930:
                        goto code_r0x000140096930;
                      case (code *)0x14009693f:
                        goto code_r0x00014009693f;
                      case (code *)0x14009694e:
                        goto code_r0x00014009694e;
                      case (code *)0x14009695d:
                        goto code_r0x00014009695d;
                      case (code *)0x14009696c:
                        goto code_r0x00014009696c;
                      case (code *)0x14009698b:
                        goto code_r0x00014009698b;
                      case (code *)0x1400969ac:
                        goto code_r0x0001400969ac;
                      case (code *)0x1400969bb:
                        goto switchD_14009313c_caseD_8a;
                      case (code *)0x1400969ca:
                        goto code_r0x0001400969ca;
                      case (code *)0x1400969d9:
                        goto code_r0x0001400969d9;
                      case (code *)0x1400969e8:
                        goto switchD_14007fde0_caseD_aa;
                      case (code *)0x1400969f7:
                        goto code_r0x0001400969f7;
                      case (code *)0x140096a06:
                        goto switchD_1400944c0_caseD_2f;
                      case (code *)0x140096a15:
                        goto switchD_1400944c0_caseD_5a;
                      case (code *)0x140096a2c:
                        goto switchD_14007fde0_caseD_cc;
                      case (code *)0x140096a43:
                        goto switchD_1400944c0_caseD_5e;
                      case (code *)0x140096a52:
                        goto code_r0x000140096a52;
                      case (code *)0x140096a61:
                        goto switchD_14007fde0_caseD_b8;
                      case (code *)0x140096a70:
                        goto switchD_14007fde0_caseD_b0;
                      case (code *)0x140096a7f:
                        goto switchD_14007fde0_caseD_a9;
                      case (code *)0x140096a8e:
                        goto switchD_14007fde0_caseD_b5;
                      case (code *)0x140096aa5:
                        goto code_r0x000140096aa5;
                      case (code *)0x140096ab4:
                        goto code_r0x000140096ab4;
                      case (code *)0x140096ac3:
                        goto code_r0x000140096ac3;
                      case (code *)0x140096ad2:
                        goto code_r0x000140096ad2;
                      case (code *)0x140096ae1:
                        goto code_r0x000140096ae1;
                      case (code *)0x140096af0:
                        goto code_r0x000140096af0;
                      case (code *)0x140096aff:
                        goto code_r0x000140096aff;
                      case (code *)0x140096b14:
                        goto code_r0x000140096b14;
                      case (code *)0x140096b23:
                        goto code_r0x000140096b23;
                      case (code *)0x140096b42:
                        goto code_r0x000140096b42;
                      case (code *)0x140096b51:
                        goto code_r0x000140096b51;
                      case (code *)0x140096b60:
                        goto code_r0x000140096b60;
                      case (code *)0x140096b6f:
                        goto code_r0x000140096b6f;
                      case (code *)0x140096b7e:
                        goto code_r0x000140096b7e;
                      case (code *)0x140096b8d:
                        goto code_r0x000140096b8d;
                      case (code *)0x140096c2e:
                        goto code_r0x000140096c2e;
                      case (code *)0x140096c3a:
                        goto code_r0x000140096c3a;
                      case (code *)0x140096c46:
                        goto code_r0x000140096c46;
                      case (code *)0x140096c52:
                        goto code_r0x000140096c52;
                      case (code *)0x140096ffd:
                        goto code_r0x000140096ffd;
                      case (code *)0x140097024:
                        goto code_r0x000140097024;
                      case (code *)0x14009707b:
                        goto switchD_14007f7e4_caseD_de;
                      case (code *)0x1400970df:
                        goto code_r0x0001400970df;
                      case (code *)0x1400971b9:
                        goto code_r0x0001400971b9;
                      case (code *)0x1400971d6:
                        goto code_r0x0001400971d6;
                      case (code *)0x140097200:
                        goto code_r0x000140097200;
                      case (code *)0x140097217:
                        goto LAB_140097217;
                      case (code *)0x140097241:
                        goto code_r0x000140097241;
                      case (code *)0x14009725e:
                        goto code_r0x00014009725e;
                      case (code *)0x140097275:
                        goto code_r0x000140097275;
                      case (code *)0x14009728c:
                        goto code_r0x00014009728c;
                      case (code *)0x1400972a3:
                        goto code_r0x0001400972a3;
                      case (code *)0x1400972ba:
                        goto code_r0x0001400972ba;
                      case (code *)0x1400972d1:
                        goto code_r0x0001400972d1;
                      case (code *)0x1400972e8:
                        goto code_r0x0001400972e8;
                      case (code *)0x1400972ff:
                        goto code_r0x0001400972ff;
                      case (code *)0x14009731c:
                        goto code_r0x00014009731c;
                      case (code *)0x140097333:
                        goto code_r0x000140097333;
                      case (code *)0x14009735d:
                        goto code_r0x00014009735d;
                      case (code *)0x140097383:
                        goto code_r0x000140097383;
                      case (code *)0x1400973a0:
                        goto code_r0x0001400973a0;
                      case (code *)0x1400973bd:
                        goto code_r0x0001400973bd;
                      case (code *)0x1400973d4:
                        goto code_r0x0001400973d4;
                      case (code *)0x1400973eb:
                        goto code_r0x0001400973eb;
                      case (code *)0x140097408:
                        goto code_r0x000140097408;
                      case (code *)0x14009741f:
                        goto code_r0x00014009741f;
                      case (code *)0x14009743c:
                        goto code_r0x00014009743c;
                      case (code *)0x1400974a5:
                        goto code_r0x0001400974a5;
                      case (code *)0x14009750e:
                        goto code_r0x00014009750e;
                      case (code *)0x14009752b:
                        goto code_r0x00014009752b;
                      case (code *)0x140097548:
                        goto code_r0x000140097548;
                      case (code *)0x140097565:
                        goto code_r0x000140097565;
                      case (code *)0x14009757c:
                        goto code_r0x00014009757c;
                      case (code *)0x140097593:
                        goto switchD_14007f6e5_caseD_fa;
                      case (code *)0x140097607:
                        goto code_r0x000140097607;
                      case (code *)0x140097624:
                        goto code_r0x000140097624;
                      case (code *)0x140097641:
                        goto code_r0x000140097641;
                      case (code *)0x14009765e:
                        goto code_r0x00014009765e;
                      case (code *)0x140097675:
                        goto code_r0x000140097675;
                      case (code *)0x140097692:
                        goto code_r0x000140097692;
                      case (code *)0x1400976af:
                        goto code_r0x0001400976af;
                      case (code *)0x1400976d9:
                        goto code_r0x0001400976d9;
                      case (code *)0x1400976f6:
                        goto code_r0x0001400976f6;
                      case (code *)0x140097720:
                        goto code_r0x000140097720;
                      case (code *)0x14009773d:
                        goto code_r0x00014009773d;
                      case (code *)0x140097751:
                        goto code_r0x000140097751;
                      case (code *)0x14009776e:
                        goto code_r0x00014009776e;
                      case (code *)0x14009778b:
                        goto code_r0x00014009778b;
                      case (code *)0x1400977a8:
                        goto code_r0x0001400977a8;
                      case (code *)0x1400977de:
                        goto code_r0x0001400977de;
                      case (code *)0x1400977f8:
                        goto code_r0x0001400977f8;
                      case (code *)0x140097812:
                        goto code_r0x000140097812;
                      case (code *)0x14009782c:
                        goto code_r0x00014009782c;
                      case (code *)0x140098f73:
                        goto code_r0x000140098f73;
                      case (code *)0x140098f85:
                        goto code_r0x000140098f85;
                      case (code *)0x140098fc3:
                        goto code_r0x000140098fc3;
                      case (code *)0x140098ff6:
                        goto code_r0x000140098ff6;
                      case (code *)0x140099405:
                        goto code_r0x000140099405;
                      }
                    } while( true );
                  case (code *)0x14009354a:
                    goto code_r0x00014009354a;
                  case (code *)0x14009355d:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto switchD_140093542_caseD_2f;
                  case (code *)0x14009367c:
                    pcVar83 = (char *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffffc8);
                    *pcVar83 = *pcVar83 + (char)pcVar83;
                    pcVar83[-0x77] = pcVar83[-0x77] + bVar90;
                    pfVar234 = pfVar107;
                    pfVar94 = param_3;
                    goto switchD_14009313c_caseD_3f;
                  case (code *)0x1400938b7:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto code_r0x0001400938b9;
                  case (code *)0x1400938cd:
                    goto code_r0x0001400938b9;
                  case (code *)0x140093981:
                    goto code_r0x000140093981;
                  case (code *)0x14009398d:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto code_r0x00014009398f;
                  case (code *)0x140093b02:
                    goto code_r0x000140093b02;
                  case (code *)0x140093b10:
                    goto code_r0x000140093b10;
                  case (code *)0x140093b18:
                    goto code_r0x000140093b18;
                  case (code *)0x140093b1f:
                    *(char *)((longlong)pfVar107 + 200) =
                         *(char *)((longlong)pfVar107 + 200) + cVar89 + bVar238;
                    goto code_r0x000140093b26;
                  case (code *)0x140093b24:
                    goto code_r0x000140093b24;
                  case (code *)0x140093b2c:
                    goto code_r0x000140093b2c;
                  case (code *)0x140093b3f:
                    ((fd_set *)puVar225)->fd_count =
                         ((fd_set *)puVar225)->fd_count + uVar69 + (uint)bVar238;
                    goto LAB_140093b41;
                  case (code *)0x140093b4d:
                    goto code_r0x000140093b4d;
                  case (code *)0x140093b8b:
                    goto LAB_140093b63;
                  case (code *)0x140093bcf:
                    *(char *)((longlong)pfVar107 + 0x80) =
                         *(char *)((longlong)pfVar107 + 0x80) + cVar89 + bVar238;
                    goto code_r0x000140093bce;
                  case (code *)0x140093bfa:
                    goto code_r0x000140093bfa;
                  case (code *)0x140093c7f:
                    uVar81 = (ulonglong)(uVar69 + 0xd7);
                    goto LAB_140093c84;
                  case (code *)0x140093cff:
                    if (!(bool)bVar238 && !bVar239) {
                      pcVar83 = (char *)((longlong)((fd_set *)puVar223)->fd_array +
                                        (longlong)_Dst * 4 + -3);
                      cVar88 = *pcVar83;
                      *pcVar83 = *pcVar83 + bVar90;
                      out((short)_Src,cVar89);
                      if (SCARRY1(cVar88,bVar90) == *pcVar83 < '\0') {
                        ((fd_set *)_Src)->fd_count = ((fd_set *)_Src)->fd_count + 1;
                        *(byte *)&param_3->fd_count = (char)param_3->fd_count + bVar90;
                        *(fd_set **)((longlong)pfVar107 + -8) = param_1;
                        *(fd_set **)((longlong)pfVar107 + -0x10) = pfVar227;
                        *(fd_set **)((longlong)pfVar107 + -0x18) = pfVar233;
                        *(uint **)((longlong)pfVar107 + -0x20) = puVar225;
                        *(fd_set **)((longlong)pfVar107 + -0x28) = param_3;
                        *(uint **)((longlong)pfVar107 + -0x30) = puVar223;
                        puVar145 = (undefined8 *)((longlong)pfVar107 + -0x38);
                        *(undefined ***)((longlong)pfVar107 + -0x38) = param_2;
                        goto code_r0x000140093d22;
                      }
                    }
                    *(char *)(((fd_set *)_Src)->fd_array + 4) =
                         (char)((fd_set *)_Src)->fd_array[4] + (char)((ulonglong)param_2 >> 8);
                    pcVar83 = (char *)_Dst;
                    goto code_r0x000140093d0f;
                  case (code *)0x140093d6a:
                    goto code_r0x000140093d6a;
                  case (code *)0x140093f76:
                    goto code_r0x000140093f76;
                  case (code *)0x140093fb1:
                    pfVar168 = (fd_set *)((longlong)pfVar107 + -8);
                    *(uint **)((longlong)pfVar107 + -8) = puVar225;
                    uVar15 = param_3->fd_count;
                    *(byte *)&param_3->fd_count = (char)param_3->fd_count - bVar90;
                    piVar80 = (int *)((longlong)((fd_set *)puVar225)->fd_array + 0x11);
                    *piVar80 = *piVar80 + uVar70 + (uint)((byte)uVar15 < bVar90);
                    goto LAB_140093fa0;
                  case (code *)0x140093ffe:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x189);
                    *pcVar83 = *pcVar83 + bVar90;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x1400940fd:
                    goto code_r0x0001400940fd;
                  case (code *)0x14009433f:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x14009439f:
                    goto code_r0x00014009439f;
                  case (code *)0x1400943d5:
                    goto code_r0x0001400943d5;
                  case (code *)0x1400943f9:
                    goto code_r0x0001400943f9;
                  case (code *)0x140094429:
                    goto code_r0x000140094429;
                  case (code *)0x14009475f:
                    pfVar234 = param_3;
                    goto switchD_14007f6e5_caseD_87;
                  case (code *)0x1400947bb:
                    goto code_r0x0001400947bb;
                  case (code *)0x1400947d2:
                    goto code_r0x0001400947d2;
                  case (code *)0x1400947d8:
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x2d8d4780))->
                                       fd_array + 0x79);
                    *pcVar83 = *pcVar83 + cVar88;
                    pfVar168 = (fd_set *)((longlong)pfVar107 + -8);
                    *(uint **)((longlong)pfVar107 + -8) = _Dst;
                    piVar80 = (int *)((longlong)
                                      ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                      fd_array + 0x18d);
                    *piVar80 = *piVar80 + -1;
                    goto code_r0x0001400947d9;
                  case (code *)0x1400948a9:
                    puVar225 = (uint *)(ulonglong)(uint)(iVar66 << 2);
                    param_3->fd_count =
                         (uint)(CONCAT14(iVar66 << 1 < 0,param_3->fd_count) >> 0xf) |
                         param_3->fd_count << 0x12;
                    puVar223 = (uint *)((ulonglong)pfVar107 & 0xffffffff);
                    pfVar168 = (fd_set *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
                    *puVar223 = *puVar223 >> 1 | *puVar223 << 0x1f;
                    if (((ulonglong)_Dst & 1) != 0) goto switchD_14009492e_default;
                    goto switchD_14009313c_caseD_5d;
                  case (code *)0x1400948c9:
                    goto code_r0x0001400948c9;
                  case (code *)0x1400948cf:
                    goto code_r0x0001400948cf;
                  case (code *)0x1400948e0:
                    goto code_r0x0001400948e0;
                  case (code *)0x1400948e5:
                    goto code_r0x0001400948e5;
                  case (code *)0x1400948f6:
                    *(uint **)((longlong)pfVar107 + -8) = _Src;
                    goto code_r0x0001400948f7;
                  case (code *)0x1400948fe:
                    goto code_r0x0001400948fe;
                  case (code *)0x1400952df:
                    piVar80 = (int *)((longlong)UNRECOVERED_JUMPTABLE * 9 + 0x134880f);
                    *piVar80 = *piVar80 + uVar69;
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto LAB_1400952e8;
                  case (code *)0x1400953e6:
                    goto code_r0x0001400953e6;
                  case (code *)0x14009549b:
                    goto code_r0x000140095492;
                  case (code *)0x1400954ad:
                    piVar80 = (int *)((longlong)UNRECOVERED_JUMPTABLE * 9 + 0x117880f);
                    *piVar80 = *piVar80 + uVar69;
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto LAB_1400954b6;
                  case (code *)0x14009551e:
                    pbVar2 = (byte *)((longlong)pfVar227->fd_array + 0x31);
                    *pbVar2 = *pbVar2 | (byte)param_4;
                    *(char *)(((fd_set *)((longlong)param_2 + -0x7af0fd28))->fd_array + 3) =
                         (char)((fd_set *)((longlong)param_2 + -0x7af0fd28))->fd_array[3] + cVar89;
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x18b);
                    *pcVar83 = *pcVar83 + bVar90;
                    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
                    pcVar83 = (char *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array + 0x33)
                    ;
                    *pcVar83 = *pcVar83 + bVar90;
                    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
                    *(byte *)&param_3->fd_count = (char)param_3->fd_count + bVar90;
                    halt_baddata();
                  case (code *)0x1400957d7:
                    goto code_r0x0001400957d7;
                  case (code *)0x1400957e7:
                    *(uint *)((longlong)pfVar107 + 0x60) = uVar69;
                    goto code_r0x0001400957d7;
                  case (code *)0x1400957f7:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x14009588d:
                    goto code_r0x00014009588d;
                  case (code *)0x140095b53:
                    goto code_r0x000140095b53;
                  case (code *)0x140095bf8:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x140095c92:
                    goto code_r0x000140095c92;
                  case (code *)0x140095cf8:
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x18d);
                    *pcVar83 = *pcVar83 + bVar90;
                    *(undefined2 *)
                     ((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                     (longlong)param_2 * 4 + -8) = in_FS;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x140095d6f:
                    goto code_r0x000140095d6f;
                  case (code *)0x140095ddb:
                    goto code_r0x000140095ddb;
                  case (code *)0x1400962be:
                    *(char *)&((fd_set *)_Dst)->fd_count = (char)((fd_set *)_Dst)->fd_count + cVar88
                    ;
                    piVar80 = (int *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffffb8);
                    *piVar80 = *piVar80 + (int)piVar80;
                    *(char *)((longlong)piVar80 + -0x73) =
                         *(char *)((longlong)piVar80 + -0x73) + bVar90;
                    halt_baddata();
                  case (code *)0x1400962cb:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x14009632f:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto LAB_140096329;
                  case (code *)0x14009639f:
                    LOCK();
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    UNLOCK();
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x18b);
                    *pcVar83 = *pcVar83 + bVar90;
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x189);
                    *pcVar83 = *pcVar83 + bVar90;
                    UNRECOVERED_JUMPTABLE =
                         (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff48);
                    goto code_r0x00014009635d;
                  case (code *)0x14009669b:
                    goto code_r0x00014009669b;
                  case (code *)0x1400966e5:
                    goto code_r0x0001400966e5;
                  case (code *)0x1400967cc:
                    goto code_r0x0001400967cc;
                  case (code *)0x1400967ec:
                    *(undefined2 *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count = in_FS;
                    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x14009687b:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto code_r0x00014009687d;
                  case (code *)0x140096889:
                    goto code_r0x000140096889;
                  case (code *)0x1400968b7:
                    goto code_r0x0001400968b7;
                  case (code *)0x1400968d6:
                    goto code_r0x0001400968d6;
                  case (code *)0x1400968f4:
                    goto code_r0x0001400968f4;
                  case (code *)0x1400968f7:
                    goto LAB_1400968f7;
                  case (code *)0x1400968ff:
                    goto code_r0x0001400968ff;
                  case (code *)0x140096921:
                    goto code_r0x000140096921;
                  case (code *)0x140096932:
                    *(undefined4 *)((longlong)pfVar107 + 0xd8) = 4;
                    goto code_r0x00014009693d;
                  case (code *)0x14009696c:
                    goto code_r0x00014009696c;
                  case (code *)0x14009696e:
                    return (fd_set *)UNRECOVERED_JUMPTABLE;
                  case (code *)0x14009698b:
                    goto code_r0x00014009698b;
                  case (code *)0x140096996:
                    goto code_r0x00014009699a;
                  case (code *)0x1400969bb:
                    goto switchD_14009313c_caseD_8a;
                  case (code *)0x1400969ce:
                    goto code_r0x0001400969ce;
                  case (code *)0x1400969db:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x1400969e9:
                    _Dst = (uint *)(ulonglong)(uVar70 << 2 | uVar70 >> 0x1e);
                    goto code_r0x0001400969ec;
                  case (code *)0x1400969f7:
                    goto code_r0x0001400969f7;
                  case (code *)0x1400969ff:
                    *(undefined4 *)((longlong)pfVar107 + 0xd8) = 3;
                    pfVar16 = pfVar107;
                    goto code_r0x000140096a0a;
                  case (code *)0x140096a07:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto switchD_14009313c_caseD_9f;
                  case (code *)0x140096a61:
                    goto switchD_14007fde0_caseD_b8;
                  case (code *)0x140096ab7:
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x140096abd:
                    goto code_r0x000140096abd;
                  case (code *)0x140096ace:
                    uVar81 = (ulonglong)(uVar69 + ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count);
                    goto switchD_14007fde0_caseD_c3;
                  case (code *)0x140096ad3:
                    goto code_r0x000140096ad3;
                  case (code *)0x140096adb:
                    puVar194 = (undefined1 *)pfVar107;
                    goto code_r0x000140096adc;
                  case (code *)0x140096ae5:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                  case (code *)0x140096ae9:
                    goto switchD_1400944c0_caseD_3a;
                  case (code *)0x140096aeb:
                    goto code_r0x000140096aeb;
                  case (code *)0x140096af8:
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + 0x3a458))->
                                       fd_array + 0x189);
                    *pcVar83 = *pcVar83 + cVar89;
                    goto switchD_14007fde0_caseD_b9;
                  case (code *)0x140096afb:
                    param_3->fd_count = ((fd_set *)puVar225)->fd_count;
                    goto switchD_1400944c0_caseD_3a;
                  case (code *)0x140096aff:
                    goto code_r0x000140096aff;
                  case (code *)0x140096b14:
                    goto code_r0x000140096b14;
                  case (code *)0x140096b23:
                    goto code_r0x000140096b23;
                  case (code *)0x140096b42:
                    goto code_r0x000140096b42;
                  case (code *)0x140096b51:
                    goto code_r0x000140096b51;
                  case (code *)0x140096b60:
                    goto code_r0x000140096b60;
                  case (code *)0x140096b6f:
                    goto code_r0x000140096b6f;
                  case (code *)0x140096b7e:
                    goto code_r0x000140096b7e;
                  case (code *)0x140096b8d:
                    goto code_r0x000140096b8d;
                  case (code *)0x140096c2e:
                    goto code_r0x000140096c2e;
                  case (code *)0x140096c46:
                    goto code_r0x000140096c46;
                  case (code *)0x140096c52:
                    goto code_r0x000140096c52;
                  case (code *)0x140096cfb:
                    *(byte *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array +
                             0x37) =
                         (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array
                               [0x37] + bVar90;
                    piVar80 = (int *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffff);
                    *(char *)piVar80 = (char)*piVar80 + (char)piVar80;
                    *piVar80 = *piVar80 + uVar69;
                    *(byte *)(piVar80 + -0x12) = (char)piVar80[-0x12] + bVar90 + 0x67;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x140096ffd:
                    goto code_r0x000140096ffd;
                  case (code *)0x140097065:
                    _Src = (uint *)(ulonglong)(uint)((fd_set *)_Src)->fd_array[0];
                    puVar197 = (undefined1 *)pfVar107;
                    goto code_r0x00014009705b;
                  case (code *)0x14009707f:
                    goto code_r0x00014009707f;
                  case (code *)0x1400970ff:
                    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140097104;
                    pfVar84 = memcpy(_Dst,_Src,(size_t)pfVar72);
                    param_3->fd_array[1] = (SOCKET)puVar225;
                    return pfVar84;
                  case (code *)0x1400971ff:
                    goto code_r0x0001400971ff;
                  case (code *)0x140097241:
                    goto code_r0x000140097241;
                  case (code *)0x14009725e:
                    goto code_r0x00014009725e;
                  case (code *)0x14009725f:
                    puVar225 = (uint *)(ulonglong)(uint)(iVar66 << 1);
                    param_3->fd_count = param_3->fd_count + uVar70;
                    puVar223 = (uint *)((longlong)
                                        ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                        fd_array + 0x189);
                    *puVar223 = *puVar223 >> (bVar90 & 0x1f) | *puVar223 << 0x20 - (bVar90 & 0x1f);
                    goto code_r0x000140097269;
                  case (code *)0x14009727f:
                    goto LAB_14009727f;
                  case (code *)0x140097289:
                    piVar80 = (int *)((longlong)
                                      ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                      fd_array + 0x185);
                    *piVar80 = *piVar80 + -1;
                    puVar199 = (undefined8 *)pfVar107;
                    goto code_r0x00014009728c;
                  case (code *)0x1400972be:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto code_r0x0001400972c0;
                  case (code *)0x1400972cc:
                    *(char *)&((fd_set *)_Dst)->fd_count = (char)((fd_set *)_Dst)->fd_count + cVar89
                    ;
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    *(char *)(((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x7bf10178))->fd_array
                             + 0x35) =
                         (char)((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x7bf10178))->fd_array
                               [0x35] + cVar89;
                    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
                    puVar33 = (undefined1 *)pfVar107;
                    goto code_r0x0001400972d9;
                  case (code *)0x1400972d1:
                    goto code_r0x0001400972d1;
                  case (code *)0x1400972f7:
                    goto code_r0x0001400972f7;
                  case (code *)0x1400972f8:
                    LOCK();
                    ((fd_set *)_Src)->fd_count = (u_int)puVar223;
                    UNLOCK();
                    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + uVar69;
                    pcVar103 = (char *)((longlong)
                                        ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                        fd_array + 0x18d);
                    *pcVar103 = *pcVar103 + bVar90;
                  case (code *)0x1400972ff:
                    goto code_r0x0001400972ff;
                  case (code *)0x140097333:
                    goto code_r0x000140097333;
                  case (code *)0x1400973cb:
                    goto code_r0x0001400973cb;
                  case (code *)0x1400973d4:
                    goto code_r0x0001400973d4;
                  case (code *)0x1400973e8:
                    pcVar103 = (char *)(ulonglong)((uint)_Src | uVar69);
                    goto code_r0x0001400973d4;
                  case (code *)0x1400973eb:
                    goto code_r0x0001400973eb;
                  case (code *)0x1400973fd:
                    goto code_r0x0001400973fd;
                  case (code *)0x1400973fe:
                    goto code_r0x0001400973fd;
                  case (code *)0x1400973ff:
                    goto code_r0x0001400973fd;
                  case (code *)0x14009741e:
                    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 1;
                    *(byte *)&param_3->fd_count = (char)param_3->fd_count + bVar90;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case (code *)0x14009741f:
                    goto code_r0x00014009741f;
                  case (code *)0x1400974bf:
                    pfVar84 = (fd_set *)&DAT_00000004;
                    if (bVar237) {
                      pfVar84 = pfVar72;
                    }
                    goto code_r0x0001400974c9;
                  case (code *)0x140097548:
                    goto code_r0x000140097548;
                  case (code *)0x14009754e:
                    pbVar2 = (byte *)((longlong)
                                      ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                      fd_array + 0x18d);
                    *pbVar2 = *pbVar2 & bVar90;
                    UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uVar69 + 0x73de7);
                    goto code_r0x00014009754a;
                  case (code *)0x14009756b:
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x18d);
                    *pcVar83 = (*pcVar83 - bVar90) - bVar238;
                    goto code_r0x000140097565;
                  case (code *)0x14009757c:
                    goto code_r0x00014009757c;
                  case (code *)0x140097593:
                    goto switchD_14007f6e5_caseD_fa;
                  case (code *)0x1400975ef:
                    *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + cVar89;
                    goto code_r0x0001400975f1;
                  case (code *)0x140097607:
                    goto code_r0x000140097607;
                  case (code *)0x140097643:
                    UNRECOVERED_JUMPTABLE = (code *)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array[2];
                    goto LAB_140097b64;
                  case (code *)0x14009765f:
                    goto code_r0x00014009765f;
                  case (code *)0x140097666:
                    goto code_r0x000140097666;
                  case (code *)0x140097675:
                    goto code_r0x000140097675;
                  case (code *)0x14009769f:
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x18b);
                    *pcVar83 = *pcVar83 + bVar90;
                    goto switchD_14009313c_caseD_c6;
                  case (code *)0x1400976af:
                    goto code_r0x0001400976af;
                  case (code *)0x1400976df:
                    goto switchD_14009313c_caseD_da;
                  case (code *)0x1400976fe:
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x18d);
                    *pcVar83 = (*pcVar83 - bVar90) - bVar238;
                    goto code_r0x0001400976f6;
                  case (code *)0x140097720:
                    goto code_r0x000140097720;
                  case (code *)0x14009773d:
                    goto code_r0x00014009773d;
                  case (code *)0x140097751:
                    goto code_r0x000140097751;
                  case (code *)0x14009776f:
                    ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
                         ((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count | uVar69;
                    pcVar83 = (char *)((longlong)
                                       ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                       fd_array + 0x189);
                    *pcVar83 = *pcVar83 + bVar90;
                    UNRECOVERED_JUMPTABLE =
                         (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff50);
                    goto code_r0x000140097773;
                  case (code *)0x14009778f:
                    piVar80 = (int *)((longlong)
                                      ((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->
                                      fd_array + 0x189);
                    *piVar80 = *piVar80 + -1;
                    UNRECOVERED_JUMPTABLE =
                         (code *)((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff30);
                    goto code_r0x000140097773;
                  case (code *)0x1400977ac:
                    goto code_r0x0001400977ac;
                  case (code *)0x1400977de:
                    goto code_r0x0001400977de;
                  case (code *)0x1400977ff:
                    *(uint *)((longlong)pfVar107 + 0x28) = uVar70;
                    goto code_r0x0001400977fe;
                  case (code *)0x140097812:
                    goto code_r0x000140097812;
                  case (code *)0x14009782c:
                    goto code_r0x00014009782c;
                  case (code *)0x140098f73:
                    goto code_r0x000140098f73;
                  case (code *)0x140098f85:
                    goto code_r0x000140098f85;
                  case (code *)0x140098fc3:
                    goto code_r0x000140098fc3;
                  case (code *)0x140098ff6:
                    goto code_r0x000140098ff6;
                  case (code *)0x140099487:
                    pfVar234 = (fd_set *)(ulonglong)(uVar69 + 0x8548fff8);
                    *(byte *)&param_3->fd_count =
                         (byte)param_3->fd_count >> 4 | (char)param_3->fd_count << 4;
                    *(undefined2 *)&((fd_set *)_Src)->fd_count = in_ES;
                    *(char *)&pfVar234->fd_count =
                         (char)pfVar234->fd_count + (char)(uVar69 + 0x8548fff8);
                    goto code_r0x000140099493;
                  }
                  goto code_r0x0001400932ee;
                case (code *)0x1400932c7:
                  goto switchD_14009313c_caseD_6;
                case (code *)0x1400932d7:
                  goto switchD_14009313c_caseD_7;
                case (code *)0x1400932f7:
                  goto switchD_14009313c_caseD_5;
                case (code *)0x1400934dc:
                  goto code_r0x0001400934dc;
                case (code *)0x1400934e4:
                  goto code_r0x0001400934e4;
                case (code *)0x1400934f7:
                  goto code_r0x0001400934f7;
                case (code *)0x14009350a:
                  goto code_r0x00014009350a;
                case (code *)0x14009351d:
                  goto code_r0x00014009351d;
                case (code *)0x14009363c:
                  goto code_r0x00014009363c;
                case (code *)0x140093841:
                  goto code_r0x000140093841;
                case (code *)0x1400938b6:
                  goto code_r0x0001400938b6;
                case (code *)0x14009390d:
                  goto switchD_14007f6e5_caseD_69;
                case (code *)0x140093981:
                  goto code_r0x000140093981;
                case (code *)0x140093b02:
                  goto code_r0x000140093b02;
                case (code *)0x140093b0a:
                  goto code_r0x000140093b0a;
                case (code *)0x140093b10:
                  goto code_r0x000140093b10;
                case (code *)0x140093b18:
                  goto code_r0x000140093b18;
                case (code *)0x140093b1e:
                  goto code_r0x000140093b1e;
                case (code *)0x140093b24:
                  goto code_r0x000140093b24;
                case (code *)0x140093b2c:
                  goto code_r0x000140093b2c;
                case (code *)0x140093b32:
                  goto switchD_14009313c_caseD_4e;
                case (code *)0x140093b3a:
                  goto switchD_14009313c_caseD_47;
                case (code *)0x140093b42:
                  goto code_r0x000140093b42;
                case (code *)0x140093b4d:
                  goto code_r0x000140093b4d;
                case (code *)0x140093c4e:
                  goto code_r0x000140093c4e;
                case (code *)0x140093c67:
                  goto code_r0x000140093c67;
                case (code *)0x140093cbe:
                  goto switchD_14007f7e4_caseD_75;
                case (code *)0x140093d22:
                  goto code_r0x000140093d22;
                case (code *)0x140093f72:
                  goto code_r0x000140093f72;
                case (code *)0x140093fa1:
                  goto code_r0x000140093fa1;
                case (code *)0x140093ff8:
                  goto switchD_14007f7e4_caseD_79;
                case (code *)0x14009405c:
                  goto code_r0x00014009405c;
                case (code *)0x140094336:
                  goto code_r0x000140094336;
                case (code *)0x140094371:
                  goto switchD_14007f7e4_caseD_7f;
                case (code *)0x14009439f:
                  goto code_r0x00014009439f;
                case (code *)0x1400943d5:
                  goto code_r0x0001400943d5;
                case (code *)0x140094428:
                  goto code_r0x000140094428;
                case (code *)0x140094758:
                  goto code_r0x000140094758;
                case (code *)0x140094790:
                  goto code_r0x000140094790;
                case (code *)0x140094798:
                  goto code_r0x000140094798;
                case (code *)0x1400947b8:
                  goto code_r0x0001400947b8;
                case (code *)0x1400947d2:
                  goto code_r0x0001400947d2;
                case (code *)0x140094829:
                  goto switchD_14007f7e4_caseD_82;
                case (code *)0x14009488d:
                  goto code_r0x00014009488d;
                case (code *)0x1400948c8:
                  goto code_r0x0001400948c8;
                case (code *)0x1400948d4:
                  goto code_r0x0001400948d4;
                case (code *)0x1400948e0:
                  goto code_r0x0001400948e0;
                case (code *)0x1400948e4:
                  goto switchD_1400944c0_caseD_a;
                case (code *)0x1400948e8:
                  goto code_r0x0001400948e8;
                case (code *)0x140095255:
                  goto code_r0x000140095255;
                case (code *)0x1400953e6:
                  goto code_r0x0001400953e6;
                case (code *)0x140095429:
                  goto code_r0x000140095429;
                case (code *)0x140095493:
                  goto code_r0x000140095493;
                case (code *)0x140095516:
                  goto code_r0x000140095516;
                case (code *)0x140095705:
                  goto code_r0x000140095705;
                case (code *)0x140095763:
                  goto switchD_14007f6e5_caseD_a0;
                case (code *)0x1400957d7:
                  goto code_r0x0001400957d7;
                case (code *)0x14009588d:
                  goto code_r0x00014009588d;
                case (code *)0x140095b53:
                  goto code_r0x000140095b53;
                case (code *)0x140095bb8:
                  goto code_r0x000140095bb8;
                case (code *)0x140095c38:
                  goto code_r0x000140095c38;
                case (code *)0x140095c92:
                  goto code_r0x000140095c92;
                case (code *)0x140095d03:
                  goto code_r0x000140095d03;
                case (code *)0x140095d65:
                  goto code_r0x000140095d65;
                case (code *)0x140095ddb:
                  goto code_r0x000140095ddb;
                case (code *)0x14009620a:
                  goto code_r0x00014009620a;
                case (code *)0x1400962bc:
                  goto switchD_14007f7e4_caseD_aa;
                case (code *)0x140096320:
                  goto code_r0x000140096320;
                case (code *)0x14009639c:
                  goto code_r0x00014009639c;
                case (code *)0x14009669b:
                  goto code_r0x00014009669b;
                case (code *)0x1400966e5:
                  goto code_r0x0001400966e5;
                case (code *)0x14009674c:
                  goto code_r0x00014009674c;
                case (code *)0x1400967cc:
                  goto code_r0x0001400967cc;
                case (code *)0x14009687a:
                  goto code_r0x00014009687a;
                case (code *)0x140096889:
                  goto code_r0x000140096889;
                case (code *)0x1400968a8:
                  goto code_r0x0001400968a8;
                case (code *)0x1400968b7:
                  goto code_r0x0001400968b7;
                case (code *)0x1400968d6:
                  goto code_r0x0001400968d6;
                case (code *)0x1400968e5:
                  goto code_r0x0001400968e5;
                case (code *)0x1400968f4:
                  goto code_r0x0001400968f4;
                case (code *)0x140096903:
                  goto code_r0x000140096903;
                case (code *)0x140096912:
                  goto code_r0x000140096912;
                case (code *)0x140096921:
                  goto code_r0x000140096921;
                case (code *)0x140096930:
                  goto code_r0x000140096930;
                case (code *)0x14009693f:
                  goto code_r0x00014009693f;
                case (code *)0x14009694e:
                  goto code_r0x00014009694e;
                case (code *)0x14009695d:
                  goto code_r0x00014009695d;
                case (code *)0x14009696c:
                  goto code_r0x00014009696c;
                case (code *)0x14009698b:
                  goto code_r0x00014009698b;
                case (code *)0x1400969ac:
                  goto code_r0x0001400969ac;
                case (code *)0x1400969bb:
                  goto switchD_14009313c_caseD_8a;
                case (code *)0x1400969ca:
                  goto code_r0x0001400969ca;
                case (code *)0x1400969d9:
                  goto code_r0x0001400969d9;
                case (code *)0x1400969e8:
                  goto switchD_14007fde0_caseD_aa;
                case (code *)0x1400969f7:
                  goto code_r0x0001400969f7;
                case (code *)0x140096a06:
                  goto switchD_1400944c0_caseD_2f;
                case (code *)0x140096a15:
                  goto switchD_1400944c0_caseD_5a;
                case (code *)0x140096a2c:
                  goto switchD_14007fde0_caseD_cc;
                case (code *)0x140096a43:
                  goto switchD_1400944c0_caseD_5e;
                case (code *)0x140096a52:
                  goto code_r0x000140096a52;
                case (code *)0x140096a61:
                  goto switchD_14007fde0_caseD_b8;
                case (code *)0x140096a70:
                  goto switchD_14007fde0_caseD_b0;
                case (code *)0x140096a7f:
                  goto switchD_14007fde0_caseD_a9;
                case (code *)0x140096a8e:
                  goto switchD_14007fde0_caseD_b5;
                case (code *)0x140096aa5:
                  goto code_r0x000140096aa5;
                case (code *)0x140096ab4:
                  goto code_r0x000140096ab4;
                case (code *)0x140096ac3:
                  goto code_r0x000140096ac3;
                case (code *)0x140096ad2:
                  goto code_r0x000140096ad2;
                case (code *)0x140096ae1:
                  goto code_r0x000140096ae1;
                case (code *)0x140096af0:
                  goto code_r0x000140096af0;
                case (code *)0x140096aff:
                  goto code_r0x000140096aff;
                case (code *)0x140096b14:
                  goto code_r0x000140096b14;
                case (code *)0x140096b23:
                  goto code_r0x000140096b23;
                case (code *)0x140096b42:
                  goto code_r0x000140096b42;
                case (code *)0x140096b51:
                  goto code_r0x000140096b51;
                case (code *)0x140096b60:
                  goto code_r0x000140096b60;
                case (code *)0x140096b6f:
                  goto code_r0x000140096b6f;
                case (code *)0x140096b7e:
                  goto code_r0x000140096b7e;
                case (code *)0x140096b8d:
                  goto code_r0x000140096b8d;
                case (code *)0x140096c2e:
                  goto code_r0x000140096c2e;
                case (code *)0x140096c3a:
                  goto code_r0x000140096c3a;
                case (code *)0x140096c46:
                  goto code_r0x000140096c46;
                case (code *)0x140096c52:
                  goto code_r0x000140096c52;
                case (code *)0x140096ffd:
                  goto code_r0x000140096ffd;
                case (code *)0x140097024:
                  goto code_r0x000140097024;
                case (code *)0x14009707b:
                  goto switchD_14007f7e4_caseD_de;
                case (code *)0x1400970df:
                  goto code_r0x0001400970df;
                case (code *)0x1400971b9:
                  goto code_r0x0001400971b9;
                case (code *)0x1400971d6:
                  goto code_r0x0001400971d6;
                case (code *)0x140097200:
                  goto code_r0x000140097200;
                case (code *)0x140097217:
                  goto LAB_140097217;
                case (code *)0x140097241:
                  goto code_r0x000140097241;
                case (code *)0x14009725e:
                  goto code_r0x00014009725e;
                case (code *)0x140097275:
                  goto code_r0x000140097275;
                case (code *)0x14009728c:
                  goto code_r0x00014009728c;
                case (code *)0x1400972a3:
                  goto code_r0x0001400972a3;
                case (code *)0x1400972ba:
                  goto code_r0x0001400972ba;
                case (code *)0x1400972d1:
                  goto code_r0x0001400972d1;
                case (code *)0x1400972e8:
                  goto code_r0x0001400972e8;
                case (code *)0x1400972ff:
                  goto code_r0x0001400972ff;
                case (code *)0x14009731c:
                  goto code_r0x00014009731c;
                case (code *)0x140097333:
                  goto code_r0x000140097333;
                case (code *)0x14009735d:
                  goto code_r0x00014009735d;
                case (code *)0x140097383:
                  goto code_r0x000140097383;
                case (code *)0x1400973a0:
                  goto code_r0x0001400973a0;
                case (code *)0x1400973bd:
                  goto code_r0x0001400973bd;
                case (code *)0x1400973d4:
                  goto code_r0x0001400973d4;
                case (code *)0x1400973eb:
                  goto code_r0x0001400973eb;
                case (code *)0x140097408:
                  goto code_r0x000140097408;
                case (code *)0x14009741f:
                  goto code_r0x00014009741f;
                case (code *)0x14009743c:
                  goto code_r0x00014009743c;
                case (code *)0x1400974a5:
                  goto code_r0x0001400974a5;
                case (code *)0x14009750e:
                  goto code_r0x00014009750e;
                case (code *)0x14009752b:
                  goto code_r0x00014009752b;
                case (code *)0x140097548:
                  goto code_r0x000140097548;
                case (code *)0x140097565:
                  goto code_r0x000140097565;
                case (code *)0x14009757c:
                  goto code_r0x00014009757c;
                case (code *)0x140097593:
                  goto switchD_14007f6e5_caseD_fa;
                case (code *)0x140097607:
                  goto code_r0x000140097607;
                case (code *)0x140097624:
                  goto code_r0x000140097624;
                case (code *)0x140097641:
                  goto code_r0x000140097641;
                case (code *)0x14009765e:
                  goto code_r0x00014009765e;
                case (code *)0x140097675:
                  goto code_r0x000140097675;
                case (code *)0x140097692:
                  goto code_r0x000140097692;
                case (code *)0x1400976af:
                  goto code_r0x0001400976af;
                case (code *)0x1400976d9:
                  goto code_r0x0001400976d9;
                case (code *)0x1400976f6:
                  goto code_r0x0001400976f6;
                case (code *)0x140097720:
                  goto code_r0x000140097720;
                case (code *)0x14009773d:
                  goto code_r0x00014009773d;
                case (code *)0x140097751:
                  goto code_r0x000140097751;
                case (code *)0x14009776e:
                  goto code_r0x00014009776e;
                case (code *)0x14009778b:
                  goto code_r0x00014009778b;
                case (code *)0x1400977a8:
                  goto code_r0x0001400977a8;
                case (code *)0x1400977de:
                  goto code_r0x0001400977de;
                case (code *)0x1400977f8:
                  goto code_r0x0001400977f8;
                case (code *)0x140097812:
                  goto code_r0x000140097812;
                case (code *)0x14009782c:
                  goto code_r0x00014009782c;
                case (code *)0x140098f73:
                  goto code_r0x000140098f73;
                case (code *)0x140098f85:
                  goto code_r0x000140098f85;
                case (code *)0x140098fc3:
                  goto code_r0x000140098fc3;
                case (code *)0x140098ff6:
                  goto code_r0x000140098ff6;
                case (code *)0x140099405:
                  goto code_r0x000140099405;
                }
              } while( true );
            case (code *)0x1400932f7:
              goto switchD_14009313c_caseD_5;
            case (code *)0x1400934dc:
              goto code_r0x0001400934dc;
            case (code *)0x1400934e4:
              goto code_r0x0001400934e4;
            case (code *)0x1400934f7:
              goto code_r0x0001400934f7;
            case (code *)0x14009350a:
              goto code_r0x00014009350a;
            case (code *)0x14009351d:
              goto code_r0x00014009351d;
            case (code *)0x14009363c:
              goto code_r0x00014009363c;
            case (code *)0x140093841:
              goto code_r0x000140093841;
            case (code *)0x1400938b6:
              goto code_r0x0001400938b6;
            case (code *)0x14009390d:
              goto switchD_14007f6e5_caseD_69;
            case (code *)0x140093981:
              goto code_r0x000140093981;
            case (code *)0x140093b02:
              goto code_r0x000140093b02;
            case (code *)0x140093b0a:
              goto code_r0x000140093b0a;
            case (code *)0x140093b10:
              goto code_r0x000140093b10;
            case (code *)0x140093b18:
              goto code_r0x000140093b18;
            case (code *)0x140093b1e:
              goto code_r0x000140093b1e;
            case (code *)0x140093b24:
              goto code_r0x000140093b24;
            case (code *)0x140093b2c:
              goto code_r0x000140093b2c;
            case (code *)0x140093b32:
              goto switchD_14009313c_caseD_4e;
            case (code *)0x140093b3a:
              goto switchD_14009313c_caseD_47;
            case (code *)0x140093b42:
              goto code_r0x000140093b42;
            case (code *)0x140093b4d:
              goto code_r0x000140093b4d;
            case (code *)0x140093c4e:
              goto code_r0x000140093c4e;
            case (code *)0x140093c67:
              goto code_r0x000140093c67;
            case (code *)0x140093cbe:
              goto switchD_14007f7e4_caseD_75;
            case (code *)0x140093d22:
              goto code_r0x000140093d22;
            case (code *)0x140093f72:
              goto code_r0x000140093f72;
            case (code *)0x140093fa1:
              goto code_r0x000140093fa1;
            case (code *)0x140093ff8:
              goto switchD_14007f7e4_caseD_79;
            case (code *)0x14009405c:
              goto code_r0x00014009405c;
            case (code *)0x140094336:
              goto code_r0x000140094336;
            case (code *)0x140094371:
              goto switchD_14007f7e4_caseD_7f;
            case (code *)0x14009439f:
              goto code_r0x00014009439f;
            case (code *)0x1400943d5:
              goto code_r0x0001400943d5;
            case (code *)0x140094428:
              goto code_r0x000140094428;
            case (code *)0x140094758:
              goto code_r0x000140094758;
            case (code *)0x140094790:
              goto code_r0x000140094790;
            case (code *)0x140094798:
              goto code_r0x000140094798;
            case (code *)0x1400947b8:
              goto code_r0x0001400947b8;
            case (code *)0x1400947d2:
              goto code_r0x0001400947d2;
            case (code *)0x140094829:
              goto switchD_14007f7e4_caseD_82;
            case (code *)0x14009488d:
              goto code_r0x00014009488d;
            case (code *)0x1400948c8:
              goto code_r0x0001400948c8;
            case (code *)0x1400948d4:
              goto code_r0x0001400948d4;
            case (code *)0x1400948e0:
              goto code_r0x0001400948e0;
            case (code *)0x1400948e4:
              goto switchD_1400944c0_caseD_a;
            case (code *)0x1400948e8:
              goto code_r0x0001400948e8;
            case (code *)0x140095255:
              goto code_r0x000140095255;
            case (code *)0x1400953e6:
              goto code_r0x0001400953e6;
            case (code *)0x140095429:
              goto code_r0x000140095429;
            case (code *)0x140095493:
              goto code_r0x000140095493;
            case (code *)0x140095516:
              goto code_r0x000140095516;
            case (code *)0x140095705:
              goto code_r0x000140095705;
            case (code *)0x140095763:
              goto switchD_14007f6e5_caseD_a0;
            case (code *)0x1400957d7:
              goto code_r0x0001400957d7;
            case (code *)0x14009588d:
              goto code_r0x00014009588d;
            case (code *)0x140095b53:
              goto code_r0x000140095b53;
            case (code *)0x140095bb8:
              goto code_r0x000140095bb8;
            case (code *)0x140095c38:
              goto code_r0x000140095c38;
            case (code *)0x140095c92:
              goto code_r0x000140095c92;
            case (code *)0x140095d03:
              goto code_r0x000140095d03;
            case (code *)0x140095d65:
              goto code_r0x000140095d65;
            case (code *)0x140095ddb:
              goto code_r0x000140095ddb;
            case (code *)0x14009620a:
              goto code_r0x00014009620a;
            case (code *)0x1400962bc:
              goto switchD_14007f7e4_caseD_aa;
            case (code *)0x140096320:
              goto code_r0x000140096320;
            case (code *)0x14009639c:
              goto code_r0x00014009639c;
            case (code *)0x14009669b:
              goto code_r0x00014009669b;
            case (code *)0x1400966e5:
              goto code_r0x0001400966e5;
            case (code *)0x14009674c:
              goto code_r0x00014009674c;
            case (code *)0x1400967cc:
              goto code_r0x0001400967cc;
            case (code *)0x14009687a:
              goto code_r0x00014009687a;
            case (code *)0x140096889:
              goto code_r0x000140096889;
            case (code *)0x1400968a8:
              goto code_r0x0001400968a8;
            case (code *)0x1400968b7:
              goto code_r0x0001400968b7;
            case (code *)0x1400968d6:
              goto code_r0x0001400968d6;
            case (code *)0x1400968e5:
              goto code_r0x0001400968e5;
            case (code *)0x1400968f4:
              goto code_r0x0001400968f4;
            case (code *)0x140096903:
              goto code_r0x000140096903;
            case (code *)0x140096912:
              goto code_r0x000140096912;
            case (code *)0x140096921:
              goto code_r0x000140096921;
            case (code *)0x140096930:
              goto code_r0x000140096930;
            case (code *)0x14009693f:
              goto code_r0x00014009693f;
            case (code *)0x14009694e:
              goto code_r0x00014009694e;
            case (code *)0x14009695d:
              goto code_r0x00014009695d;
            case (code *)0x14009696c:
              goto code_r0x00014009696c;
            case (code *)0x14009698b:
              goto code_r0x00014009698b;
            case (code *)0x1400969ac:
              goto code_r0x0001400969ac;
            case (code *)0x1400969bb:
              goto switchD_14009313c_caseD_8a;
            case (code *)0x1400969ca:
              goto code_r0x0001400969ca;
            case (code *)0x1400969d9:
              goto code_r0x0001400969d9;
            case (code *)0x1400969e8:
              goto switchD_14007fde0_caseD_aa;
            case (code *)0x1400969f7:
              goto code_r0x0001400969f7;
            case (code *)0x140096a06:
              goto switchD_1400944c0_caseD_2f;
            case (code *)0x140096a15:
              goto switchD_1400944c0_caseD_5a;
            case (code *)0x140096a2c:
              goto switchD_14007fde0_caseD_cc;
            case (code *)0x140096a43:
              goto switchD_1400944c0_caseD_5e;
            case (code *)0x140096a52:
              goto code_r0x000140096a52;
            case (code *)0x140096a61:
              goto switchD_14007fde0_caseD_b8;
            case (code *)0x140096a70:
              goto switchD_14007fde0_caseD_b0;
            case (code *)0x140096a7f:
              goto switchD_14007fde0_caseD_a9;
            case (code *)0x140096a8e:
              goto switchD_14007fde0_caseD_b5;
            case (code *)0x140096aa5:
              goto code_r0x000140096aa5;
            case (code *)0x140096ab4:
              goto code_r0x000140096ab4;
            case (code *)0x140096ac3:
              goto code_r0x000140096ac3;
            case (code *)0x140096ad2:
              goto code_r0x000140096ad2;
            case (code *)0x140096ae1:
              goto code_r0x000140096ae1;
            case (code *)0x140096af0:
              goto code_r0x000140096af0;
            case (code *)0x140096aff:
              goto code_r0x000140096aff;
            case (code *)0x140096b14:
              goto code_r0x000140096b14;
            case (code *)0x140096b23:
              goto code_r0x000140096b23;
            case (code *)0x140096b42:
              goto code_r0x000140096b42;
            case (code *)0x140096b51:
              goto code_r0x000140096b51;
            case (code *)0x140096b60:
              goto code_r0x000140096b60;
            case (code *)0x140096b6f:
              goto code_r0x000140096b6f;
            case (code *)0x140096b7e:
              goto code_r0x000140096b7e;
            case (code *)0x140096b8d:
              goto code_r0x000140096b8d;
            case (code *)0x140096c2e:
              goto code_r0x000140096c2e;
            case (code *)0x140096c3a:
              goto code_r0x000140096c3a;
            case (code *)0x140096c46:
              goto code_r0x000140096c46;
            case (code *)0x140096c52:
              goto code_r0x000140096c52;
            case (code *)0x140096ffd:
              goto code_r0x000140096ffd;
            case (code *)0x140097024:
              goto code_r0x000140097024;
            case (code *)0x14009707b:
              goto switchD_14007f7e4_caseD_de;
            case (code *)0x1400970df:
              goto code_r0x0001400970df;
            case (code *)0x1400971b9:
              goto code_r0x0001400971b9;
            case (code *)0x1400971d6:
              goto code_r0x0001400971d6;
            case (code *)0x140097200:
              goto code_r0x000140097200;
            case (code *)0x140097217:
              goto LAB_140097217;
            case (code *)0x140097241:
              goto code_r0x000140097241;
            case (code *)0x14009725e:
              goto code_r0x00014009725e;
            case (code *)0x140097275:
              goto code_r0x000140097275;
            case (code *)0x14009728c:
              goto code_r0x00014009728c;
            case (code *)0x1400972a3:
              goto code_r0x0001400972a3;
            case (code *)0x1400972ba:
              goto code_r0x0001400972ba;
            case (code *)0x1400972d1:
              goto code_r0x0001400972d1;
            case (code *)0x1400972e8:
              goto code_r0x0001400972e8;
            case (code *)0x1400972ff:
              goto code_r0x0001400972ff;
            case (code *)0x14009731c:
              goto code_r0x00014009731c;
            case (code *)0x140097333:
              goto code_r0x000140097333;
            case (code *)0x14009735d:
              goto code_r0x00014009735d;
            case (code *)0x140097383:
              goto code_r0x000140097383;
            case (code *)0x1400973a0:
              goto code_r0x0001400973a0;
            case (code *)0x1400973bd:
              goto code_r0x0001400973bd;
            case (code *)0x1400973d4:
              goto code_r0x0001400973d4;
            case (code *)0x1400973eb:
              goto code_r0x0001400973eb;
            case (code *)0x140097408:
              goto code_r0x000140097408;
            case (code *)0x14009741f:
              goto code_r0x00014009741f;
            case (code *)0x14009743c:
              goto code_r0x00014009743c;
            case (code *)0x1400974a5:
              goto code_r0x0001400974a5;
            case (code *)0x14009750e:
              goto code_r0x00014009750e;
            case (code *)0x14009752b:
              goto code_r0x00014009752b;
            case (code *)0x140097548:
              goto code_r0x000140097548;
            case (code *)0x140097565:
              goto code_r0x000140097565;
            case (code *)0x14009757c:
              goto code_r0x00014009757c;
            case (code *)0x140097593:
              goto switchD_14007f6e5_caseD_fa;
            case (code *)0x140097607:
              goto code_r0x000140097607;
            case (code *)0x140097624:
              goto code_r0x000140097624;
            case (code *)0x140097641:
              goto code_r0x000140097641;
            case (code *)0x14009765e:
              goto code_r0x00014009765e;
            case (code *)0x140097675:
              goto code_r0x000140097675;
            case (code *)0x140097692:
              goto code_r0x000140097692;
            case (code *)0x1400976af:
              goto code_r0x0001400976af;
            case (code *)0x1400976d9:
              goto code_r0x0001400976d9;
            case (code *)0x1400976f6:
              goto code_r0x0001400976f6;
            case (code *)0x140097720:
              goto code_r0x000140097720;
            case (code *)0x14009773d:
              goto code_r0x00014009773d;
            case (code *)0x140097751:
              goto code_r0x000140097751;
            case (code *)0x14009776e:
              goto code_r0x00014009776e;
            case (code *)0x14009778b:
              goto code_r0x00014009778b;
            case (code *)0x1400977a8:
              goto code_r0x0001400977a8;
            case (code *)0x1400977de:
              goto code_r0x0001400977de;
            case (code *)0x1400977f8:
              goto code_r0x0001400977f8;
            case (code *)0x140097812:
              goto code_r0x000140097812;
            case (code *)0x14009782c:
              goto code_r0x00014009782c;
            case (code *)0x140098f73:
              goto code_r0x000140098f73;
            case (code *)0x140098f85:
              goto code_r0x000140098f85;
            case (code *)0x140098fc3:
              goto code_r0x000140098fc3;
            case (code *)0x140098ff6:
              goto code_r0x000140098ff6;
            case (code *)0x140099405:
              goto code_r0x000140099405;
            }
          } while( true );
        case (code *)0x1400932e7:
          goto switchD_14009313c_caseD_b;
        case (code *)0x1400932f7:
          goto switchD_14009313c_caseD_5;
        case (code *)0x1400934dc:
          goto code_r0x0001400934dc;
        case (code *)0x1400934e4:
          goto code_r0x0001400934e4;
        case (code *)0x1400934f7:
          goto code_r0x0001400934f7;
        case (code *)0x14009350a:
          goto code_r0x00014009350a;
        case (code *)0x14009351d:
          goto code_r0x00014009351d;
        case (code *)0x14009363c:
          goto code_r0x00014009363c;
        case (code *)0x140093841:
          goto code_r0x000140093841;
        case (code *)0x1400938b6:
          goto code_r0x0001400938b6;
        case (code *)0x14009390d:
          goto switchD_14007f6e5_caseD_69;
        case (code *)0x140093981:
          goto code_r0x000140093981;
        case (code *)0x140093b02:
          goto code_r0x000140093b02;
        case (code *)0x140093b0a:
          goto code_r0x000140093b0a;
        case (code *)0x140093b10:
          goto code_r0x000140093b10;
        case (code *)0x140093b18:
          goto code_r0x000140093b18;
        case (code *)0x140093b1e:
          goto code_r0x000140093b1e;
        case (code *)0x140093b24:
          goto code_r0x000140093b24;
        case (code *)0x140093b2c:
          goto code_r0x000140093b2c;
        case (code *)0x140093b32:
          goto switchD_14009313c_caseD_4e;
        case (code *)0x140093b3a:
          goto switchD_14009313c_caseD_47;
        case (code *)0x140093b42:
          goto code_r0x000140093b42;
        case (code *)0x140093b4d:
          goto code_r0x000140093b4d;
        case (code *)0x140093c4e:
          goto code_r0x000140093c4e;
        case (code *)0x140093c67:
          goto code_r0x000140093c67;
        case (code *)0x140093cbe:
          goto switchD_14007f7e4_caseD_75;
        case (code *)0x140093d22:
          goto code_r0x000140093d22;
        case (code *)0x140093f72:
          goto code_r0x000140093f72;
        case (code *)0x140093fa1:
          goto code_r0x000140093fa1;
        case (code *)0x140093ff8:
          goto switchD_14007f7e4_caseD_79;
        case (code *)0x14009405c:
          goto code_r0x00014009405c;
        case (code *)0x140094336:
          goto code_r0x000140094336;
        case (code *)0x140094371:
          goto switchD_14007f7e4_caseD_7f;
        case (code *)0x14009439f:
          goto code_r0x00014009439f;
        case (code *)0x1400943d5:
          goto code_r0x0001400943d5;
        case (code *)0x140094428:
          goto code_r0x000140094428;
        case (code *)0x140094758:
          goto code_r0x000140094758;
        case (code *)0x140094790:
          goto code_r0x000140094790;
        case (code *)0x140094798:
          goto code_r0x000140094798;
        case (code *)0x1400947b8:
          goto code_r0x0001400947b8;
        case (code *)0x1400947d2:
          goto code_r0x0001400947d2;
        case (code *)0x140094829:
          goto switchD_14007f7e4_caseD_82;
        case (code *)0x14009488d:
          goto code_r0x00014009488d;
        case (code *)0x1400948c8:
          goto code_r0x0001400948c8;
        case (code *)0x1400948d4:
          goto code_r0x0001400948d4;
        case (code *)0x1400948e0:
          goto code_r0x0001400948e0;
        case (code *)0x1400948e4:
          goto switchD_1400944c0_caseD_a;
        case (code *)0x1400948e8:
          goto code_r0x0001400948e8;
        case (code *)0x140095255:
          goto code_r0x000140095255;
        case (code *)0x1400953e6:
          goto code_r0x0001400953e6;
        case (code *)0x140095429:
          goto code_r0x000140095429;
        case (code *)0x140095493:
          goto code_r0x000140095493;
        case (code *)0x140095516:
          goto code_r0x000140095516;
        case (code *)0x140095705:
          goto code_r0x000140095705;
        case (code *)0x140095763:
          goto switchD_14007f6e5_caseD_a0;
        case (code *)0x1400957d7:
          goto code_r0x0001400957d7;
        case (code *)0x14009588d:
          goto code_r0x00014009588d;
        case (code *)0x140095b53:
          goto code_r0x000140095b53;
        case (code *)0x140095bb8:
          goto code_r0x000140095bb8;
        case (code *)0x140095c38:
          goto code_r0x000140095c38;
        case (code *)0x140095c92:
          goto code_r0x000140095c92;
        case (code *)0x140095d03:
          goto code_r0x000140095d03;
        case (code *)0x140095d65:
          goto code_r0x000140095d65;
        case (code *)0x140095ddb:
          goto code_r0x000140095ddb;
        case (code *)0x14009620a:
          goto code_r0x00014009620a;
        case (code *)0x1400962bc:
          goto switchD_14007f7e4_caseD_aa;
        case (code *)0x140096320:
          goto code_r0x000140096320;
        case (code *)0x14009639c:
          goto code_r0x00014009639c;
        case (code *)0x14009669b:
          goto code_r0x00014009669b;
        case (code *)0x1400966e5:
          goto code_r0x0001400966e5;
        case (code *)0x14009674c:
          goto code_r0x00014009674c;
        case (code *)0x1400967cc:
          goto code_r0x0001400967cc;
        case (code *)0x14009687a:
          goto code_r0x00014009687a;
        case (code *)0x140096889:
          goto code_r0x000140096889;
        case (code *)0x1400968a8:
          goto code_r0x0001400968a8;
        case (code *)0x1400968b7:
          goto code_r0x0001400968b7;
        case (code *)0x1400968d6:
          goto code_r0x0001400968d6;
        case (code *)0x1400968e5:
          goto code_r0x0001400968e5;
        case (code *)0x1400968f4:
          goto code_r0x0001400968f4;
        case (code *)0x140096903:
          goto code_r0x000140096903;
        case (code *)0x140096912:
          goto code_r0x000140096912;
        case (code *)0x140096921:
          goto code_r0x000140096921;
        case (code *)0x140096930:
          goto code_r0x000140096930;
        case (code *)0x14009693f:
          goto code_r0x00014009693f;
        case (code *)0x14009694e:
          goto code_r0x00014009694e;
        case (code *)0x14009695d:
          goto code_r0x00014009695d;
        case (code *)0x14009696c:
          goto code_r0x00014009696c;
        case (code *)0x14009698b:
          goto code_r0x00014009698b;
        case (code *)0x1400969ac:
          goto code_r0x0001400969ac;
        case (code *)0x1400969bb:
          goto switchD_14009313c_caseD_8a;
        case (code *)0x1400969ca:
          goto code_r0x0001400969ca;
        case (code *)0x1400969d9:
          goto code_r0x0001400969d9;
        case (code *)0x1400969e8:
          goto switchD_14007fde0_caseD_aa;
        case (code *)0x1400969f7:
          goto code_r0x0001400969f7;
        case (code *)0x140096a06:
          goto switchD_1400944c0_caseD_2f;
        case (code *)0x140096a15:
          goto switchD_1400944c0_caseD_5a;
        case (code *)0x140096a2c:
          goto switchD_14007fde0_caseD_cc;
        case (code *)0x140096a43:
          goto switchD_1400944c0_caseD_5e;
        case (code *)0x140096a52:
          goto code_r0x000140096a52;
        case (code *)0x140096a61:
          goto switchD_14007fde0_caseD_b8;
        case (code *)0x140096a70:
          goto switchD_14007fde0_caseD_b0;
        case (code *)0x140096a7f:
          goto switchD_14007fde0_caseD_a9;
        case (code *)0x140096a8e:
          goto switchD_14007fde0_caseD_b5;
        case (code *)0x140096aa5:
          goto code_r0x000140096aa5;
        case (code *)0x140096ab4:
          goto code_r0x000140096ab4;
        case (code *)0x140096ac3:
          goto code_r0x000140096ac3;
        case (code *)0x140096ad2:
          goto code_r0x000140096ad2;
        case (code *)0x140096ae1:
          goto code_r0x000140096ae1;
        case (code *)0x140096af0:
          goto code_r0x000140096af0;
        case (code *)0x140096aff:
          goto code_r0x000140096aff;
        case (code *)0x140096b14:
          goto code_r0x000140096b14;
        case (code *)0x140096b23:
          goto code_r0x000140096b23;
        case (code *)0x140096b42:
          goto code_r0x000140096b42;
        case (code *)0x140096b51:
          goto code_r0x000140096b51;
        case (code *)0x140096b60:
          goto code_r0x000140096b60;
        case (code *)0x140096b6f:
          goto code_r0x000140096b6f;
        case (code *)0x140096b7e:
          goto code_r0x000140096b7e;
        case (code *)0x140096b8d:
          goto code_r0x000140096b8d;
        case (code *)0x140096c2e:
          goto code_r0x000140096c2e;
        case (code *)0x140096c3a:
          goto code_r0x000140096c3a;
        case (code *)0x140096c46:
          goto code_r0x000140096c46;
        case (code *)0x140096c52:
          goto code_r0x000140096c52;
        case (code *)0x140096ffd:
          goto code_r0x000140096ffd;
        case (code *)0x140097024:
          goto code_r0x000140097024;
        case (code *)0x14009707b:
          goto switchD_14007f7e4_caseD_de;
        case (code *)0x1400970df:
          goto code_r0x0001400970df;
        case (code *)0x1400971b9:
          goto code_r0x0001400971b9;
        case (code *)0x1400971d6:
          goto code_r0x0001400971d6;
        case (code *)0x140097200:
          goto code_r0x000140097200;
        case (code *)0x140097217:
          goto LAB_140097217;
        case (code *)0x140097241:
          goto code_r0x000140097241;
        case (code *)0x14009725e:
          goto code_r0x00014009725e;
        case (code *)0x140097275:
          goto code_r0x000140097275;
        case (code *)0x14009728c:
          goto code_r0x00014009728c;
        case (code *)0x1400972a3:
          goto code_r0x0001400972a3;
        case (code *)0x1400972ba:
          goto code_r0x0001400972ba;
        case (code *)0x1400972d1:
          goto code_r0x0001400972d1;
        case (code *)0x1400972e8:
          goto code_r0x0001400972e8;
        case (code *)0x1400972ff:
          goto code_r0x0001400972ff;
        case (code *)0x14009731c:
          goto code_r0x00014009731c;
        case (code *)0x140097333:
          goto code_r0x000140097333;
        case (code *)0x14009735d:
          goto code_r0x00014009735d;
        case (code *)0x140097383:
          goto code_r0x000140097383;
        case (code *)0x1400973a0:
          goto code_r0x0001400973a0;
        case (code *)0x1400973bd:
          goto code_r0x0001400973bd;
        case (code *)0x1400973d4:
          goto code_r0x0001400973d4;
        case (code *)0x1400973eb:
          goto code_r0x0001400973eb;
        case (code *)0x140097408:
          goto code_r0x000140097408;
        case (code *)0x14009741f:
          goto code_r0x00014009741f;
        case (code *)0x14009743c:
          goto code_r0x00014009743c;
        case (code *)0x1400974a5:
          goto code_r0x0001400974a5;
        case (code *)0x14009750e:
          goto code_r0x00014009750e;
        case (code *)0x14009752b:
          goto code_r0x00014009752b;
        case (code *)0x140097548:
          goto code_r0x000140097548;
        case (code *)0x140097565:
          goto code_r0x000140097565;
        case (code *)0x14009757c:
          goto code_r0x00014009757c;
        case (code *)0x140097593:
          goto switchD_14007f6e5_caseD_fa;
        case (code *)0x140097607:
          goto code_r0x000140097607;
        case (code *)0x140097624:
          goto code_r0x000140097624;
        case (code *)0x140097641:
          goto code_r0x000140097641;
        case (code *)0x14009765e:
          goto code_r0x00014009765e;
        case (code *)0x140097675:
          goto code_r0x000140097675;
        case (code *)0x140097692:
          goto code_r0x000140097692;
        case (code *)0x1400976af:
          goto code_r0x0001400976af;
        case (code *)0x1400976d9:
          goto code_r0x0001400976d9;
        case (code *)0x1400976f6:
          goto code_r0x0001400976f6;
        case (code *)0x140097720:
          goto code_r0x000140097720;
        case (code *)0x14009773d:
          goto code_r0x00014009773d;
        case (code *)0x140097751:
          goto code_r0x000140097751;
        case (code *)0x14009776e:
          goto code_r0x00014009776e;
        case (code *)0x14009778b:
          goto code_r0x00014009778b;
        case (code *)0x1400977a8:
          goto code_r0x0001400977a8;
        case (code *)0x1400977de:
          goto code_r0x0001400977de;
        case (code *)0x1400977f8:
          goto code_r0x0001400977f8;
        case (code *)0x140097812:
          goto code_r0x000140097812;
        case (code *)0x14009782c:
          goto code_r0x00014009782c;
        case (code *)0x140098f73:
          goto code_r0x000140098f73;
        case (code *)0x140098f85:
          goto code_r0x000140098f85;
        case (code *)0x140098fc3:
          goto code_r0x000140098fc3;
        case (code *)0x140098ff6:
          goto code_r0x000140098ff6;
        case (code *)0x140099405:
          goto code_r0x000140099405;
        }
      } while( true );
    case (code *)0x1400932d7:
      goto switchD_14009313c_caseD_7;
    case (code *)0x1400932e7:
      goto switchD_14009313c_caseD_b;
    case (code *)0x1400934dc:
      goto code_r0x0001400934dc;
    case (code *)0x1400934e4:
      goto code_r0x0001400934e4;
    case (code *)0x1400934f7:
      goto code_r0x0001400934f7;
    case (code *)0x14009350a:
      goto code_r0x00014009350a;
    case (code *)0x14009351d:
      goto code_r0x00014009351d;
    case (code *)0x14009363c:
      goto code_r0x00014009363c;
    case (code *)0x140093841:
      goto code_r0x000140093841;
    case (code *)0x1400938b6:
      goto code_r0x0001400938b6;
    case (code *)0x14009390d:
      goto switchD_14007f6e5_caseD_69;
    case (code *)0x140093981:
      goto code_r0x000140093981;
    case (code *)0x140093b02:
      goto code_r0x000140093b02;
    case (code *)0x140093b0a:
      goto code_r0x000140093b0a;
    case (code *)0x140093b10:
      goto code_r0x000140093b10;
    case (code *)0x140093b18:
      goto code_r0x000140093b18;
    case (code *)0x140093b1e:
      goto code_r0x000140093b1e;
    case (code *)0x140093b24:
      goto code_r0x000140093b24;
    case (code *)0x140093b2c:
      goto code_r0x000140093b2c;
    case (code *)0x140093b32:
      goto switchD_14009313c_caseD_4e;
    case (code *)0x140093b3a:
      goto switchD_14009313c_caseD_47;
    case (code *)0x140093b42:
      goto code_r0x000140093b42;
    case (code *)0x140093b4d:
      goto code_r0x000140093b4d;
    case (code *)0x140093c4e:
      goto code_r0x000140093c4e;
    case (code *)0x140093c67:
      goto code_r0x000140093c67;
    case (code *)0x140093cbe:
      goto switchD_14007f7e4_caseD_75;
    case (code *)0x140093d22:
      goto code_r0x000140093d22;
    case (code *)0x140093f72:
      goto code_r0x000140093f72;
    case (code *)0x140093fa1:
      goto code_r0x000140093fa1;
    case (code *)0x140093ff8:
      goto switchD_14007f7e4_caseD_79;
    case (code *)0x14009405c:
      goto code_r0x00014009405c;
    case (code *)0x140094336:
      goto code_r0x000140094336;
    case (code *)0x140094371:
      goto switchD_14007f7e4_caseD_7f;
    case (code *)0x14009439f:
      goto code_r0x00014009439f;
    case (code *)0x1400943d5:
      goto code_r0x0001400943d5;
    case (code *)0x140094428:
      goto code_r0x000140094428;
    case (code *)0x140094758:
      goto code_r0x000140094758;
    case (code *)0x140094790:
      goto code_r0x000140094790;
    case (code *)0x140094798:
      goto code_r0x000140094798;
    case (code *)0x1400947b8:
      goto code_r0x0001400947b8;
    case (code *)0x1400947d2:
      goto code_r0x0001400947d2;
    case (code *)0x140094829:
      goto switchD_14007f7e4_caseD_82;
    case (code *)0x14009488d:
      goto code_r0x00014009488d;
    case (code *)0x1400948c8:
      goto code_r0x0001400948c8;
    case (code *)0x1400948d4:
      goto code_r0x0001400948d4;
    case (code *)0x1400948e0:
      goto code_r0x0001400948e0;
    case (code *)0x1400948e4:
      goto switchD_1400944c0_caseD_a;
    case (code *)0x1400948e8:
      goto code_r0x0001400948e8;
    case (code *)0x140095255:
      goto code_r0x000140095255;
    case (code *)0x1400953e6:
      goto code_r0x0001400953e6;
    case (code *)0x140095429:
      goto code_r0x000140095429;
    case (code *)0x140095493:
      goto code_r0x000140095493;
    case (code *)0x140095516:
      goto code_r0x000140095516;
    case (code *)0x140095705:
      goto code_r0x000140095705;
    case (code *)0x140095763:
      goto switchD_14007f6e5_caseD_a0;
    case (code *)0x1400957d7:
      goto code_r0x0001400957d7;
    case (code *)0x14009588d:
      goto code_r0x00014009588d;
    case (code *)0x140095b53:
      goto code_r0x000140095b53;
    case (code *)0x140095bb8:
      goto code_r0x000140095bb8;
    case (code *)0x140095c38:
      goto code_r0x000140095c38;
    case (code *)0x140095c92:
      goto code_r0x000140095c92;
    case (code *)0x140095d03:
      goto code_r0x000140095d03;
    case (code *)0x140095d65:
      goto code_r0x000140095d65;
    case (code *)0x140095ddb:
      goto code_r0x000140095ddb;
    case (code *)0x14009620a:
      goto code_r0x00014009620a;
    case (code *)0x1400962bc:
      goto switchD_14007f7e4_caseD_aa;
    case (code *)0x140096320:
      goto code_r0x000140096320;
    case (code *)0x14009639c:
      goto code_r0x00014009639c;
    case (code *)0x14009669b:
      goto code_r0x00014009669b;
    case (code *)0x1400966e5:
      goto code_r0x0001400966e5;
    case (code *)0x14009674c:
      goto code_r0x00014009674c;
    case (code *)0x1400967cc:
      goto code_r0x0001400967cc;
    case (code *)0x14009687a:
      goto code_r0x00014009687a;
    case (code *)0x140096889:
      goto code_r0x000140096889;
    case (code *)0x1400968a8:
      goto code_r0x0001400968a8;
    case (code *)0x1400968b7:
      goto code_r0x0001400968b7;
    case (code *)0x1400968d6:
      goto code_r0x0001400968d6;
    case (code *)0x1400968e5:
      goto code_r0x0001400968e5;
    case (code *)0x1400968f4:
      goto code_r0x0001400968f4;
    case (code *)0x140096903:
      goto code_r0x000140096903;
    case (code *)0x140096912:
      goto code_r0x000140096912;
    case (code *)0x140096921:
      goto code_r0x000140096921;
    case (code *)0x140096930:
      goto code_r0x000140096930;
    case (code *)0x14009693f:
      goto code_r0x00014009693f;
    case (code *)0x14009694e:
      goto code_r0x00014009694e;
    case (code *)0x14009695d:
      goto code_r0x00014009695d;
    case (code *)0x14009696c:
      goto code_r0x00014009696c;
    case (code *)0x14009698b:
      goto code_r0x00014009698b;
    case (code *)0x1400969ac:
      goto code_r0x0001400969ac;
    case (code *)0x1400969bb:
      goto switchD_14009313c_caseD_8a;
    case (code *)0x1400969ca:
      goto code_r0x0001400969ca;
    case (code *)0x1400969d9:
      goto code_r0x0001400969d9;
    case (code *)0x1400969e8:
      goto switchD_14007fde0_caseD_aa;
    case (code *)0x1400969f7:
      goto code_r0x0001400969f7;
    case (code *)0x140096a06:
      goto switchD_1400944c0_caseD_2f;
    case (code *)0x140096a15:
      goto switchD_1400944c0_caseD_5a;
    case (code *)0x140096a2c:
      goto switchD_14007fde0_caseD_cc;
    case (code *)0x140096a43:
      goto switchD_1400944c0_caseD_5e;
    case (code *)0x140096a52:
      goto code_r0x000140096a52;
    case (code *)0x140096a61:
      goto switchD_14007fde0_caseD_b8;
    case (code *)0x140096a70:
      goto switchD_14007fde0_caseD_b0;
    case (code *)0x140096a7f:
      goto switchD_14007fde0_caseD_a9;
    case (code *)0x140096a8e:
      goto switchD_14007fde0_caseD_b5;
    case (code *)0x140096aa5:
      goto code_r0x000140096aa5;
    case (code *)0x140096ab4:
      goto code_r0x000140096ab4;
    case (code *)0x140096ac3:
      goto code_r0x000140096ac3;
    case (code *)0x140096ad2:
      goto code_r0x000140096ad2;
    case (code *)0x140096ae1:
      goto code_r0x000140096ae1;
    case (code *)0x140096af0:
      goto code_r0x000140096af0;
    case (code *)0x140096aff:
      goto code_r0x000140096aff;
    case (code *)0x140096b14:
      goto code_r0x000140096b14;
    case (code *)0x140096b23:
      goto code_r0x000140096b23;
    case (code *)0x140096b42:
      goto code_r0x000140096b42;
    case (code *)0x140096b51:
      goto code_r0x000140096b51;
    case (code *)0x140096b60:
      goto code_r0x000140096b60;
    case (code *)0x140096b6f:
      goto code_r0x000140096b6f;
    case (code *)0x140096b7e:
      goto code_r0x000140096b7e;
    case (code *)0x140096b8d:
      goto code_r0x000140096b8d;
    case (code *)0x140096c2e:
      goto code_r0x000140096c2e;
    case (code *)0x140096c3a:
      goto code_r0x000140096c3a;
    case (code *)0x140096c46:
      goto code_r0x000140096c46;
    case (code *)0x140096c52:
      goto code_r0x000140096c52;
    case (code *)0x140096ffd:
      goto code_r0x000140096ffd;
    case (code *)0x140097024:
      goto code_r0x000140097024;
    case (code *)0x14009707b:
      goto switchD_14007f7e4_caseD_de;
    case (code *)0x1400970df:
      goto code_r0x0001400970df;
    case (code *)0x1400971b9:
      goto code_r0x0001400971b9;
    case (code *)0x1400971d6:
      goto code_r0x0001400971d6;
    case (code *)0x140097200:
      goto code_r0x000140097200;
    case (code *)0x140097217:
      goto LAB_140097217;
    case (code *)0x140097241:
      goto code_r0x000140097241;
    case (code *)0x14009725e:
      goto code_r0x00014009725e;
    case (code *)0x140097275:
      goto code_r0x000140097275;
    case (code *)0x14009728c:
      goto code_r0x00014009728c;
    case (code *)0x1400972a3:
      goto code_r0x0001400972a3;
    case (code *)0x1400972ba:
      goto code_r0x0001400972ba;
    case (code *)0x1400972d1:
      goto code_r0x0001400972d1;
    case (code *)0x1400972e8:
      goto code_r0x0001400972e8;
    case (code *)0x1400972ff:
      goto code_r0x0001400972ff;
    case (code *)0x14009731c:
      goto code_r0x00014009731c;
    case (code *)0x140097333:
      goto code_r0x000140097333;
    case (code *)0x14009735d:
      goto code_r0x00014009735d;
    case (code *)0x140097383:
      goto code_r0x000140097383;
    case (code *)0x1400973a0:
      goto code_r0x0001400973a0;
    case (code *)0x1400973bd:
      goto code_r0x0001400973bd;
    case (code *)0x1400973d4:
      goto code_r0x0001400973d4;
    case (code *)0x1400973eb:
      goto code_r0x0001400973eb;
    case (code *)0x140097408:
      goto code_r0x000140097408;
    case (code *)0x14009741f:
      goto code_r0x00014009741f;
    case (code *)0x14009743c:
      goto code_r0x00014009743c;
    case (code *)0x1400974a5:
      goto code_r0x0001400974a5;
    case (code *)0x14009750e:
      goto code_r0x00014009750e;
    case (code *)0x14009752b:
      goto code_r0x00014009752b;
    case (code *)0x140097548:
      goto code_r0x000140097548;
    case (code *)0x140097565:
      goto code_r0x000140097565;
    case (code *)0x14009757c:
      goto code_r0x00014009757c;
    case (code *)0x140097593:
      goto switchD_14007f6e5_caseD_fa;
    case (code *)0x140097607:
      goto code_r0x000140097607;
    case (code *)0x140097624:
      goto code_r0x000140097624;
    case (code *)0x140097641:
      goto code_r0x000140097641;
    case (code *)0x14009765e:
      goto code_r0x00014009765e;
    case (code *)0x140097675:
      goto code_r0x000140097675;
    case (code *)0x140097692:
      goto code_r0x000140097692;
    case (code *)0x1400976af:
      goto code_r0x0001400976af;
    case (code *)0x1400976d9:
      goto code_r0x0001400976d9;
    case (code *)0x1400976f6:
      goto code_r0x0001400976f6;
    case (code *)0x140097720:
      goto code_r0x000140097720;
    case (code *)0x14009773d:
      goto code_r0x00014009773d;
    case (code *)0x140097751:
      goto code_r0x000140097751;
    case (code *)0x14009776e:
      goto code_r0x00014009776e;
    case (code *)0x14009778b:
      goto code_r0x00014009778b;
    case (code *)0x1400977a8:
      goto code_r0x0001400977a8;
    case (code *)0x1400977de:
      goto code_r0x0001400977de;
    case (code *)0x1400977f8:
      goto code_r0x0001400977f8;
    case (code *)0x140097812:
      goto code_r0x000140097812;
    case (code *)0x14009782c:
      goto code_r0x00014009782c;
    case (code *)0x140098f73:
      goto code_r0x000140098f73;
    case (code *)0x140098f85:
      goto code_r0x000140098f85;
    case (code *)0x140098fc3:
      goto code_r0x000140098fc3;
    case (code *)0x140098ff6:
      goto code_r0x000140098ff6;
    case (code *)0x140099405:
      goto code_r0x000140099405;
    }
  } while( true );
code_r0x0001400975f1:
  UNRECOVERED_JUMPTABLE = *(code **)(((fd_set *)_Src)->fd_array[0] + 0x18);
  goto LAB_140097b64;
code_r0x0001400972d9:
  pfVar168 = (fd_set *)puVar33;
  pcVar83 = (char *)((longlong)_Dst * 5 + 0x26);
  *pcVar83 = *pcVar83 + (char)_Dst;
  goto LAB_1400972dd;
LAB_140099556:
  lVar96 = -0x7ffffffffffffff3;
  goto LAB_140099560;
LAB_140099414:
  *(undefined1 *)((longlong)pfVar107 + 0x58) = 0;
  goto LAB_140099419;
code_r0x000140098f97:
  *(ulonglong *)((longlong)pfVar168 + 0x30) = uVar81;
  *(fd_set **)((longlong)pfVar168 + 0x28) = pfVar84;
  *(fd_set **)((longlong)pfVar168 + 0x20) = pfVar233;
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x140098fbe;
  FUN_14009911f((ulonglong *)((longlong)pfVar168 + 0xa0),(byte *)((longlong)pfVar168 + 0x50),
                (longlong)param_2,param_1,*(undefined8 *)((longlong)pfVar168 + 0x20),
                *(undefined8 *)((longlong)pfVar168 + 0x28),*(longlong *)((longlong)pfVar168 + 0x30))
  ;
  if (*(ulonglong *)((longlong)pfVar168 + 0xa0) < 0x8000000000000032) {
    UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0xd0);
    puVar97 = *(uint **)((longlong)pfVar168 + 0x40);
    ((fd_set *)puVar97)->fd_array[5] = (SOCKET)UNRECOVERED_JUMPTABLE;
    SVar82 = *(SOCKET *)((longlong)pfVar168 + 0xa0);
    SVar76 = *(SOCKET *)((longlong)pfVar168 + 0xa8);
    uVar244 = *(undefined4 *)((longlong)pfVar168 + 0xb0);
    uVar245 = *(undefined4 *)((longlong)pfVar168 + 0xb4);
    in_XMM1_Dc = *(undefined4 *)((longlong)pfVar168 + 0xb8);
    in_XMM1_Dd = *(undefined4 *)((longlong)pfVar168 + 0xbc);
code_r0x000140098ff7:
    SVar236 = *(SOCKET *)((longlong)pfVar168 + 200);
    ((fd_set *)puVar97)->fd_array[3] = *(SOCKET *)((longlong)pfVar168 + 0xc0);
    ((fd_set *)puVar97)->fd_array[4] = SVar236;
    *(undefined4 *)(((fd_set *)puVar97)->fd_array + 1) = uVar244;
    *(undefined4 *)((longlong)((fd_set *)puVar97)->fd_array + 0xc) = uVar245;
    *(undefined4 *)(((fd_set *)puVar97)->fd_array + 2) = in_XMM1_Dc;
    *(undefined4 *)((longlong)((fd_set *)puVar97)->fd_array + 0x14) = in_XMM1_Dd;
    *(SOCKET *)puVar97 = SVar82;
    ((fd_set *)puVar97)->fd_array[0] = SVar76;
    return (fd_set *)UNRECOVERED_JUMPTABLE;
  }
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x140098e22;
  FUN_140098ce0((ulonglong *)((longlong)pfVar168 + 0x140),(ulonglong *)((longlong)pfVar168 + 0x1a8))
  ;
  if (*(longlong *)((longlong)pfVar168 + 0x140) == 0) {
    pfVar84 = *(fd_set **)((longlong)pfVar168 + 0x40);
    *(fd_set **)pfVar84 = param_3;
    return pfVar84;
  }
  uVar241 = *(undefined8 *)(*(longlong *)((longlong)pfVar168 + 0x148) + 0xe0);
  *(undefined8 *)((longlong)pfVar168 + 0x158) =
       *(undefined8 *)(*(longlong *)((longlong)pfVar168 + 0x148) + 0xd8);
  *(undefined8 *)((longlong)pfVar168 + 0x160) = uVar241;
  *(undefined8 *)((longlong)pfVar168 + 0x168) = 0;
  do {
    *(undefined8 *)((longlong)pfVar168 + -8) = 0x140098e5c;
    FUN_140094400((longlong *)puVar223,(longlong *)pfVar227);
    if (*(fd_set **)((longlong)pfVar168 + 0xd8) == (fd_set *)puVar225) {
      *(uint **)((longlong)pfVar168 + 0x1c0) = puVar225;
      *(undefined8 *)((longlong)pfVar168 + -8) = 0x140098f8d;
      FUN_14009844b((ulonglong *)((longlong)pfVar168 + 0x1c0));
      goto LAB_140098f8d;
    }
    *(undefined8 *)((longlong)pfVar168 + 0x1a0) = *(undefined8 *)((longlong)pfVar168 + 0x108);
    *(undefined8 *)((longlong)pfVar168 + 400) = *(undefined8 *)((longlong)pfVar168 + 0xf8);
    *(undefined8 *)((longlong)pfVar168 + 0x198) = *(undefined8 *)((longlong)pfVar168 + 0x100);
    *(undefined8 *)((longlong)pfVar168 + 0x180) = *(undefined8 *)((longlong)pfVar168 + 0xe8);
    *(undefined8 *)((longlong)pfVar168 + 0x188) = *(undefined8 *)((longlong)pfVar168 + 0xf0);
    *(undefined8 *)((longlong)pfVar168 + 0x170) = *(undefined8 *)((longlong)pfVar168 + 0xd8);
    *(undefined8 *)((longlong)pfVar168 + 0x178) = *(undefined8 *)((longlong)pfVar168 + 0xe0);
    if (*(fd_set **)((longlong)pfVar168 + 0x170) == param_3) {
      *(undefined8 *)((longlong)pfVar168 + 0x30) = *(undefined8 *)((longlong)pfVar168 + 0x48);
      *(fd_set **)((longlong)pfVar168 + 0x28) = pfVar84;
      *(fd_set **)((longlong)pfVar168 + 0x20) = pfVar233;
      *(undefined8 *)((longlong)pfVar168 + -8) = 0x140098ee0;
      FUN_14009911f((ulonglong *)((longlong)pfVar168 + 0x50),(byte *)((longlong)pfVar168 + 0x178),
                    (longlong)param_2,param_1,*(undefined8 *)((longlong)pfVar168 + 0x20),
                    *(undefined8 *)((longlong)pfVar168 + 0x28),
                    *(longlong *)((longlong)pfVar168 + 0x30));
    }
    else {
      *(undefined8 *)((longlong)pfVar168 + 0x80) = *(undefined8 *)((longlong)pfVar168 + 0x108);
      *(undefined8 *)((longlong)pfVar168 + 0x70) = *(undefined8 *)((longlong)pfVar168 + 0xf8);
      *(undefined8 *)((longlong)pfVar168 + 0x78) = *(undefined8 *)((longlong)pfVar168 + 0x100);
      *(undefined8 *)((longlong)pfVar168 + 0x60) = *(undefined8 *)((longlong)pfVar168 + 0xe8);
      *(undefined8 *)((longlong)pfVar168 + 0x68) = *(undefined8 *)((longlong)pfVar168 + 0xf0);
      *(undefined8 *)((longlong)pfVar168 + 0x50) = *(undefined8 *)((longlong)pfVar168 + 0xd8);
      *(undefined8 *)((longlong)pfVar168 + 0x58) = *(undefined8 *)((longlong)pfVar168 + 0xe0);
    }
    pfVar234 = *(fd_set **)((longlong)pfVar168 + 0x50);
  } while (pfVar234 == (fd_set *)puVar225);
  *(undefined8 *)((longlong)pfVar168 + 0x1e8) = *(undefined8 *)((longlong)pfVar168 + 0x78);
  *(undefined8 *)((longlong)pfVar168 + 0x1f0) = *(undefined8 *)((longlong)pfVar168 + 0x80);
  *(undefined8 *)((longlong)pfVar168 + 0x1d8) = *(undefined8 *)((longlong)pfVar168 + 0x68);
  *(undefined8 *)((longlong)pfVar168 + 0x1e0) = *(undefined8 *)((longlong)pfVar168 + 0x70);
  *(undefined8 *)((longlong)pfVar168 + 0x1c8) = *(undefined8 *)((longlong)pfVar168 + 0x58);
  *(undefined8 *)((longlong)pfVar168 + 0x1d0) = *(undefined8 *)((longlong)pfVar168 + 0x60);
  *(undefined8 *)((longlong)pfVar168 + 0x110) = *(undefined8 *)((longlong)pfVar168 + 0x1c8);
  *(undefined8 *)((longlong)pfVar168 + 0x118) = *(undefined8 *)((longlong)pfVar168 + 0x1d0);
  *(undefined8 *)((longlong)pfVar168 + 0x120) = *(undefined8 *)((longlong)pfVar168 + 0x1d8);
  *(undefined8 *)((longlong)pfVar168 + 0x128) = *(undefined8 *)((longlong)pfVar168 + 0x1e0);
  *(undefined8 *)((longlong)pfVar168 + 0x130) = *(undefined8 *)((longlong)pfVar168 + 0x1e8);
  *(undefined8 *)((longlong)pfVar168 + 0x138) = *(undefined8 *)((longlong)pfVar168 + 0x1f0);
  if (pfVar234 != param_3) {
    puVar92 = *(undefined8 **)((longlong)pfVar168 + 0x40);
    *puVar92 = pfVar234;
    uVar241 = *(undefined8 *)((longlong)pfVar168 + 0x118);
    uVar243 = *(undefined8 *)((longlong)pfVar168 + 0x120);
    uVar9 = *(undefined8 *)((longlong)pfVar168 + 0x128);
    uVar10 = *(undefined8 *)((longlong)pfVar168 + 0x130);
    uVar13 = *(undefined8 *)((longlong)pfVar168 + 0x138);
    puVar92[1] = *(undefined8 *)((longlong)pfVar168 + 0x110);
    puVar92[2] = uVar241;
    puVar92[3] = uVar243;
    puVar92[4] = uVar9;
    puVar92[5] = uVar10;
    puVar92[6] = uVar13;
    return pfVar234;
  }
LAB_140098f8d:
  *(undefined1 *)((longlong)pfVar168 + 0x50) = 1;
  uVar81 = *(ulonglong *)((longlong)pfVar168 + 0x48);
  goto code_r0x000140098f97;
code_r0x000140096a4e:
  pcVar83 = (char *)((longlong)((fd_set *)((longlong)param_2 + 0x8b2400))->fd_array + 0x84);
  *pcVar83 = *pcVar83 + (char)_Dst;
  *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
       (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
LAB_140096a48:
  UNRECOVERED_JUMPTABLE = (code *)(ulonglong)*(uint *)((longlong)puVar192 + 0x88);
  *(undefined4 *)((longlong)puVar192 + 0xa3) = *(undefined4 *)((longlong)puVar192 + 0x8b);
  puVar55 = (undefined1 *)puVar192;
code_r0x000140096a5d:
  pfVar168 = (fd_set *)puVar55;
  *(int *)((longlong)pfVar168 + 0xa0) = (int)UNRECOVERED_JUMPTABLE;
LAB_140096a64:
  _Dst = (uint *)((longlong)pfVar168 + 0x360);
  puVar57 = (undefined1 *)pfVar168;
code_r0x000140096a6c:
  pfVar168 = (fd_set *)puVar57;
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x140096a71;
  FUN_14009350d((ulonglong *)_Dst);
  goto LAB_140095cbc;
code_r0x000140096a0a:
  pfVar168 = pfVar16;
  pfVar233 = pfVar168;
  if (param_3 != (fd_set *)((longlong)&uRam0000000000000000 + 3)) {
    _Src = (uint *)(ulonglong)*(byte *)((longlong)&((fd_set *)puVar225)->fd_count + 2);
switchD_14009313c_caseD_9e:
    *(undefined8 *)((longlong)pfVar168 + 0xd8) = 4;
code_r0x000140096a24:
    bVar239 = (fd_set *)_Src == (fd_set *)0x0;
switchD_14009313c_caseD_88:
    pfVar233 = pfVar168;
    if (!bVar239) {
      uVar81 = (ulonglong)*(byte *)((longlong)&((fd_set *)puVar225)->fd_count + 3);
      _Src = (uint *)(ulonglong)(uint)((int)_Src << 8);
      goto switchD_1400944c0_caseD_54;
    }
  }
  goto switchD_1400968c1_default;
code_r0x000140096afa:
  goto LAB_140096ea4;
code_r0x000140096a30:
  uVar81 = (ulonglong)(uint)((int)UNRECOVERED_JUMPTABLE + (int)_Dst);
  puVar91 = (undefined1 *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1ff);
  pfVar168 = (fd_set *)puVar190;
  if (puVar91 != (undefined1 *)0x0) {
    *(char *)&param_3->fd_count = (char)param_3->fd_count + (char)puVar91;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
switchD_1400944c0_caseD_54:
  pcVar103 = (char *)((ulonglong)_Src | uVar81);
LAB_140096a37:
  pfVar233 = pfVar168;
  puVar191 = (undefined8 *)pfVar168;
  if (0xfffe < (uint)pcVar103) goto switchD_1400968c1_default;
switchD_1400944c0_caseD_5e:
  pfVar107 = (fd_set *)puVar191;
LAB_14009625e:
  *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009626b;
  pcVar83 = (char *)FUN_140019a0b((longlong *)((longlong)pfVar107 + 200),(ulonglong)pcVar103);
  pfVar233 = pfVar107;
  if (pcVar83 == (char *)0x0) goto switchD_1400968c1_default;
  pfVar168 = pfVar107;
  if ((char)puVar223 == '0') {
code_r0x00014009627e:
    *(char **)((longlong)pfVar168 + 0x2f0) = pcVar83;
    *(char **)((longlong)pfVar168 + 0x2f8) = pcVar103;
    *(undefined1 **)((longlong)pfVar168 + 0x2e8) =
         (undefined1 *)((longlong)pfVar227->fd_array + 0x2a);
    *(char **)((longlong)pfVar168 + 0xb0) = pcVar83;
    *(char **)((longlong)pfVar168 + 0xb8) = pcVar103;
    *(undefined8 *)((longlong)pfVar168 + 0xc0) = 0;
    if ((fd_set *)pcVar103 != (fd_set *)0x0) {
      puVar225 = (uint *)0x0;
      param_1 = (fd_set *)pcVar103;
      do {
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400962d6;
        switchD_14009313c::caseD_a5
                  ((undefined1 *)((longlong)pfVar168 + 0x1b8),
                   (longlong *)((longlong)pfVar168 + 0x4f8));
        puVar172 = (undefined1 *)pfVar168;
        if (puVar225 < param_1) {
code_r0x0001400962df:
          UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0xb0);
          pfVar234 = (fd_set *)((longlong)&((fd_set *)puVar225)->fd_count + 1);
          *(fd_set **)((longlong)pfVar168 + 0xc0) = pfVar234;
          bVar238 = *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                             (longlong)(((fd_set *)((longlong)puVar225 + -0x208))->fd_array + 0x3f))
          ;
          pfVar233 = (fd_set *)(ulonglong)bVar238;
          puVar172 = (undefined1 *)pfVar168;
          if (((~bVar238 & 0x1f) == 0) ||
             (puVar169 = (undefined1 *)pfVar168, pcVar83 = (char *)puVar225, param_1 <= pfVar234))
          goto switchD_140096440_default;
code_r0x00014009630e:
          _Dst = (uint *)((longlong)&((fd_set *)pcVar83)->fd_count + 2);
          *(uint **)(puVar169 + 0xc0) = _Dst;
          bVar238 = ((undefined1 *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 1))
                    [(longlong)pcVar83];
          pcVar103 = (char *)(ulonglong)bVar238;
          bVar237 = (char)bVar238 < '\0';
          puVar36 = (undefined8 *)puVar169;
code_r0x000140096320:
          pfVar107 = (fd_set *)puVar36;
          bVar238 = (byte)pcVar103;
          if (bVar237) {
            puVar172 = (undefined1 *)pfVar107;
            switch((uint)pcVar103 & 0xff) {
            case 0x81:
              if (_Dst < param_1) {
                *(undefined1 **)((longlong)pfVar107 + 0xc0) =
                     (undefined1 *)((longlong)&((fd_set *)pcVar83)->fd_count + 3);
                bVar238 = ((undefined1 *)
                          ((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2))
                          [(longlong)pcVar83];
                if ((char)bVar238 < '\0') goto LAB_140096326;
              }
              break;
            case 0x82:
              if ((_Dst < param_1) &&
                 (pfVar234 = (fd_set *)((longlong)&((fd_set *)pcVar83)->fd_count + 3),
                 *(fd_set **)((longlong)pfVar107 + 0xc0) = pfVar234, pfVar234 < param_1)) {
                bVar238 = ((undefined1 *)
                          ((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2))
                          [(longlong)pcVar83];
                *(undefined1 **)((longlong)pfVar107 + 0xc0) = &((fd_set *)pcVar83)->field_0x4;
                if (bVar238 != 0) {
                  uVar81 = (ulonglong)
                           (byte)((undefined1 *)
                                 ((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3))
                                 [(longlong)pcVar83];
                  uVar71 = (ulonglong)bVar238 << 8;
LAB_140096608:
                  _Src = (uint *)(uVar71 | uVar81);
                  if ((uint)_Src < 0xffff) goto LAB_140096329;
                }
              }
              break;
            case 0x83:
              if ((_Dst < param_1) &&
                 (pfVar234 = (fd_set *)((longlong)&((fd_set *)pcVar83)->fd_count + 3),
                 *(fd_set **)((longlong)pfVar107 + 0xc0) = pfVar234, pfVar234 < param_1)) {
                bVar238 = ((undefined1 *)
                          ((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2))
                          [(longlong)pcVar83];
                *(undefined1 **)((longlong)pfVar107 + 0xc0) = &((fd_set *)pcVar83)->field_0x4;
                if (&((fd_set *)pcVar83)->field_0x4 < param_1) {
                  bVar90 = ((undefined1 *)
                           ((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3))
                           [(longlong)pcVar83];
                  *(undefined1 **)((longlong)pfVar107 + 0xc0) = &((fd_set *)pcVar83)->field_0x5;
                  if (bVar238 != 0) {
                    uVar81 = (ulonglong)
                             (byte)(&((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4)
                                   [(longlong)pcVar83];
                    uVar71 = (ulonglong)((uint)bVar90 << 8 | (uint)bVar238 << 0x10);
                    goto LAB_140096608;
                  }
                }
              }
              break;
            case 0x84:
              if ((_Dst < param_1) &&
                 (pfVar234 = (fd_set *)((longlong)&((fd_set *)pcVar83)->fd_count + 3),
                 *(fd_set **)((longlong)pfVar107 + 0xc0) = pfVar234, pfVar234 < param_1)) {
                bVar238 = ((undefined1 *)
                          ((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 2))
                          [(longlong)pcVar83];
                *(undefined1 **)((longlong)pfVar107 + 0xc0) = &((fd_set *)pcVar83)->field_0x4;
                if (&((fd_set *)pcVar83)->field_0x4 < param_1) {
                  bVar90 = ((undefined1 *)
                           ((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 3))
                           [(longlong)pcVar83];
                  *(undefined1 **)((longlong)pfVar107 + 0xc0) = &((fd_set *)pcVar83)->field_0x5;
                  if (&((fd_set *)pcVar83)->field_0x5 < param_1) {
                    bVar64 = (&((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x4)[(longlong)pcVar83];
                    *(undefined1 **)((longlong)pfVar107 + 0xc0) = &((fd_set *)pcVar83)->field_0x6;
                    if (bVar238 != 0) {
                      uVar81 = (ulonglong)
                               (byte)(&((fd_set *)UNRECOVERED_JUMPTABLE)->field_0x5)
                                     [(longlong)pcVar83];
                      uVar71 = (ulonglong)
                               ((uint)bVar64 << 8 | (uint)bVar90 << 0x10 | (uint)bVar238 << 0x18);
                      goto LAB_140096608;
                    }
                  }
                }
              }
            }
            goto switchD_140096440_default;
          }
LAB_140096326:
          _Src = (uint *)(ulonglong)bVar238;
LAB_140096329:
          *(undefined8 *)((longlong)pfVar107 + -8) = 0x140096336;
          UNRECOVERED_JUMPTABLE =
               (code *)FUN_140019a0b((longlong *)((longlong)pfVar107 + 0xb0),(ulonglong)_Src);
          puVar172 = (undefined1 *)pfVar107;
          if ((fd_set *)UNRECOVERED_JUMPTABLE == (fd_set *)0x0) goto switchD_140096440_default;
          if ((char)pfVar233 != '0') {
            *(fd_set **)((longlong)pfVar107 + 0x170) = pfVar227;
            puVar173 = (undefined1 *)pfVar107;
            goto LAB_140096640;
          }
          *(code **)((longlong)pfVar107 + 0x178) = UNRECOVERED_JUMPTABLE;
          *(uint **)((longlong)pfVar107 + 0x180) = _Src;
          puVar225 = (uint *)((longlong)pfVar227->fd_array + 0x2a);
          pfVar168 = pfVar107;
code_r0x00014009635d:
          *(uint **)((longlong)pfVar168 + 0x170) = puVar225;
          *(code **)((longlong)pfVar168 + 0x348) = UNRECOVERED_JUMPTABLE;
          *(uint **)((longlong)pfVar168 + 0x350) = _Src;
          *(undefined8 *)((longlong)pfVar168 + 0x358) = 0;
          *(undefined8 *)((longlong)pfVar168 + -8) = 0x140096393;
          FUN_140093eeb((ulonglong *)((longlong)pfVar168 + 0xe8),
                        (longlong *)((longlong)pfVar168 + 0x348));
          pfVar233 = *(fd_set **)((longlong)pfVar168 + 0xe8);
          param_1 = *(fd_set **)((longlong)pfVar168 + 0xf0);
          *(undefined8 *)((longlong)pfVar168 + 0x48) = *(undefined8 *)((longlong)pfVar168 + 0xf8);
          *(undefined8 *)((longlong)pfVar168 + 0x70) = *(undefined8 *)((longlong)pfVar168 + 0x100);
          *(undefined8 *)((longlong)pfVar168 + 0x98) = *(undefined8 *)((longlong)pfVar168 + 0x108);
          *(undefined1 *)((longlong)pfVar168 + 0x60) = *(undefined1 *)((longlong)pfVar168 + 0x110);
          *(undefined4 *)((longlong)pfVar168 + 0x160) = *(undefined4 *)((longlong)pfVar168 + 0x111);
          *(undefined4 *)((longlong)pfVar168 + 0x163) = *(undefined4 *)((longlong)pfVar168 + 0x114);
          if (pfVar233 == (fd_set *)puVar225) {
            if ((*(longlong *)((longlong)pfVar168 + 0x48) == 3) &&
               ((short)param_1->fd_count == 0x1d55)) {
              param_1 = (fd_set *)((longlong)&param_1->fd_count + 2);
              _Src = &pfVar233->fd_count;
              puVar20 = (undefined8 *)pfVar168;
              if (param_1 == (fd_set *)0x0) {
LAB_1400968f0:
                *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400968f5;
                FUN_1400c3cf0();
                    /* WARNING: Does not return */
                UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
                (*UNRECOVERED_JUMPTABLE)();
              }
code_r0x0001400966e5:
              pfVar168 = (fd_set *)puVar20;
              bVar238 = (byte)param_1->fd_count;
              uVar81 = (ulonglong)bVar238;
              puVar225 = (uint *)((longlong)pfVar168 + 0x298);
              if ((((bVar238 != 0xf) &&
                   (puVar225 = (uint *)((longlong)pfVar168 + 0x2c8), bVar238 != 0x11)) &&
                  (puVar225 = (uint *)((longlong)pfVar168 + 0x288), bVar238 != 0x13)) &&
                 (puVar225 = (uint *)((longlong)pfVar168 + 0x2b8), bVar238 != 0x1e)) {
code_r0x00014009671d:
                puVar225 = (uint *)((longlong)pfVar168 + 0x2d8);
                if ((int)uVar81 != 0x1f) {
                  if ((int)uVar81 != 0x25) goto LAB_14009640c;
                  puVar225 = (uint *)((longlong)pfVar168 + 0x2a8);
                }
              }
              bVar238 = (byte)uVar81;
              if (*(longlong *)puVar225 != 0) {
                pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 2);
                puVar223 = &param_1->fd_count;
                goto LAB_1400964a1;
              }
LAB_14009674a:
              *(fd_set **)((longlong)pfVar168 + 0x120) = pfVar227;
              *(undefined8 *)((longlong)pfVar168 + 800) = *(undefined8 *)((longlong)pfVar168 + 0x70)
              ;
              *(undefined8 *)((longlong)pfVar168 + 0x328) =
                   *(undefined8 *)((longlong)pfVar168 + 0x98);
              *(undefined8 *)((longlong)pfVar168 + 0x330) = 0;
              if (bVar238 == 0xf) {
switchD_14009313c_caseD_81:
                *(undefined8 *)((longlong)pfVar168 + -8) = 0x140096789;
                param_1 = (fd_set *)FUN_140096f69((longlong *)((longlong)pfVar168 + 800));
                *(uint **)((longlong)pfVar168 + 0x48) = _Src;
                puVar92 = (undefined8 *)pfVar168;
                pcVar83 = (char *)puVar225;
                pfVar233 = pfVar227;
LAB_1400967d1:
                puVar178 = (undefined1 *)puVar92;
                pfVar227 = pfVar233;
                if (*(longlong *)((longlong)puVar92 + 0x330) ==
                    *(longlong *)((longlong)puVar92 + 0x328)) {
                  *(undefined8 *)((longlong)puVar92 + -8) = 0x1400967f7;
                  FUN_14009350d((ulonglong *)((longlong)puVar92 + 0x120));
                  *(fd_set **)pcVar83 = param_1;
                  pfVar168 = (fd_set *)puVar92;
code_r0x0001400967fa:
                  ((fd_set *)pcVar83)->fd_array[0] = *(SOCKET *)((longlong)pfVar168 + 0x48);
                  goto LAB_140096803;
                }
              }
              else {
                *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400967ab;
                FUN_140093d16((undefined8 *)((longlong)pfVar168 + 0xe8),
                              (longlong *)((longlong)pfVar168 + 800),0x30);
                _Dst = *(uint **)((longlong)pfVar168 + 0xe8);
                param_1 = *(fd_set **)((longlong)pfVar168 + 0xf0);
                UNRECOVERED_JUMPTABLE = (code *)((longlong)pfVar227->fd_array + 0x2a);
                *(undefined8 *)((longlong)pfVar168 + 0x48) =
                     *(undefined8 *)((longlong)pfVar168 + 0xf8);
                puVar92 = (undefined8 *)pfVar168;
                pcVar83 = (char *)puVar225;
code_r0x0001400967cc:
                pfVar233 = pfVar227;
                if ((code *)_Dst == UNRECOVERED_JUMPTABLE) goto LAB_1400967d1;
                UNRECOVERED_JUMPTABLE = *(code **)((longlong)puVar92 + 0x100);
                pfVar233 = (fd_set *)_Dst;
code_r0x00014009683a:
                *(code **)((longlong)puVar92 + 0x70) = UNRECOVERED_JUMPTABLE;
                *(undefined8 *)((longlong)puVar92 + 0x98) =
                     *(undefined8 *)((longlong)puVar92 + 0x108);
                *(undefined1 *)((longlong)puVar92 + 0x60) =
                     *(undefined1 *)((longlong)puVar92 + 0x110);
                UNRECOVERED_JUMPTABLE = (code *)(ulonglong)*(uint *)((longlong)puVar92 + 0x111);
                uVar244 = *(undefined4 *)((longlong)puVar92 + 0x114);
                pfVar107 = (fd_set *)puVar92;
code_r0x000140096867:
                *(int *)((longlong)pfVar107 + 0x168) = (int)UNRECOVERED_JUMPTABLE;
                *(undefined4 *)((longlong)pfVar107 + 0x16b) = uVar244;
                UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar107 + 0x118);
code_r0x00014009687d:
                *(code **)((longlong)pfVar107 + 0x68) = UNRECOVERED_JUMPTABLE;
                *(undefined8 *)((longlong)pfVar107 + -8) = 0x14009688f;
                FUN_14009350d((ulonglong *)((longlong)pfVar107 + 0x120));
                puVar178 = (undefined1 *)pfVar107;
              }
switchD_14007f6e5_caseD_d1:
              UNRECOVERED_JUMPTABLE = (code *)(ulonglong)*(uint *)(puVar178 + 0x168);
              _Dst = (uint *)(ulonglong)*(uint *)(puVar178 + 0x16b);
              puVar179 = puVar178;
code_r0x00014009689d:
              uVar245 = SUB84(_Dst,0);
              uVar244 = SUB84(UNRECOVERED_JUMPTABLE,0);
              pfVar168 = (fd_set *)puVar179;
              goto LAB_140096493;
            }
LAB_14009640c:
            if ((*(byte *)((longlong)pfVar168 + 0x60) & 1) != 0) {
              pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x1a);
              puVar223 = &param_1->fd_count;
              goto LAB_1400964a1;
            }
LAB_140096803:
            puVar173 = (undefined1 *)pfVar168;
            if (*(longlong *)((longlong)pfVar168 + 0x358) !=
                *(longlong *)((longlong)pfVar168 + 0x350)) goto LAB_140096640;
            *(undefined8 *)((longlong)pfVar168 + -8) = 0x140096826;
            FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x1b8));
            pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x2a);
          }
          else {
            *(undefined8 *)((longlong)pfVar168 + 0x68) = *(undefined8 *)((longlong)pfVar168 + 0x118)
            ;
            uVar244 = *(undefined4 *)((longlong)pfVar168 + 0x160);
            uVar245 = *(undefined4 *)((longlong)pfVar168 + 0x163);
LAB_140096493:
            *(undefined4 *)((longlong)pfVar168 + 0xa8) = uVar244;
            *(undefined4 *)((longlong)pfVar168 + 0xab) = uVar245;
            puVar223 = &param_1->fd_count;
LAB_1400964a1:
            *(undefined4 *)((longlong)pfVar168 + 0x88) = *(undefined4 *)((longlong)pfVar168 + 0xa8);
            *(undefined4 *)((longlong)pfVar168 + 0x8b) = *(undefined4 *)((longlong)pfVar168 + 0xab);
            *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400964ca;
            FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x1b8));
            *(undefined8 *)((longlong)pfVar168 + 0x50) = *(undefined8 *)((longlong)pfVar168 + 0x48);
            pfVar84 = *(fd_set **)((longlong)pfVar168 + 0x70);
            param_3 = *(fd_set **)((longlong)pfVar168 + 0x98);
            *(undefined1 *)((longlong)pfVar168 + 0x90) = *(undefined1 *)((longlong)pfVar168 + 0x60);
          }
        }
        else {
switchD_140096440_default:
          *(fd_set **)(puVar172 + 0x170) = pfVar227;
          puVar172[0x178] = 0;
          *(undefined2 *)(puVar172 + 0x17d) = 0;
          puVar172[0x17f] = 0;
          *(undefined4 *)(puVar172 + 0x179) = 0;
          puVar173 = puVar172;
LAB_140096640:
          pfVar233 = *(fd_set **)(puVar173 + 0x1b8);
          puVar223 = *(uint **)(puVar173 + 0x1c0);
          *(undefined8 *)(puVar173 + 0x50) = *(undefined8 *)(puVar173 + 0x1c8);
          pfVar84 = *(fd_set **)(puVar173 + 0x1d0);
          param_3 = *(fd_set **)(puVar173 + 0x1d8);
          puVar173[0x90] = puVar173[0x1e0];
          *(undefined4 *)(puVar173 + 0x88) = *(undefined4 *)(puVar173 + 0x1e1);
          *(undefined4 *)(puVar173 + 0x8b) = *(undefined4 *)(puVar173 + 0x1e4);
          *(undefined8 *)(puVar173 + 0x68) = *(undefined8 *)(puVar173 + 0x1e8);
          pfVar168 = (fd_set *)puVar173;
        }
LAB_1400966a3:
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400966b0;
        FUN_14009487a((ulonglong *)((longlong)pfVar168 + 0x170));
        puVar192 = (undefined8 *)pfVar168;
        if (pfVar233 != (fd_set *)((longlong)pfVar227->fd_array + 0x2a)) goto LAB_140096a48;
        param_1 = *(fd_set **)((longlong)pfVar168 + 0xb8);
        puVar225 = *(uint **)((longlong)pfVar168 + 0xc0);
code_r0x0001400966cd:
        bVar239 = (fd_set *)puVar225 == param_1;
        puVar175 = (undefined1 *)pfVar168;
code_r0x0001400966d0:
        pfVar168 = (fd_set *)puVar175;
      } while (!bVar239);
    }
    pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x2a);
    goto LAB_140096a64;
  }
LAB_1400968f7:
  *(fd_set **)((longlong)pfVar107 + 0x2e8) = pfVar227;
code_r0x0001400968ff:
  pfVar168 = pfVar107;
  goto LAB_140095c58;
LAB_1400947ee:
  pcVar83 = (char *)puVar225;
  if (pfVar227 == (fd_set *)0x0) goto code_r0x000140094857;
  *(fd_set **)((longlong)pfVar168 + 0x30) = pfVar233;
  if (!bVar239) {
switchD_14009313c_caseD_5e:
    *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009480f;
    cVar89 = (*(code *)pfVar84)(puVar225,", ");
code_r0x00014009480f:
    if (cVar89 != '\0') goto LAB_140094841;
  }
  puVar91 = (undefined1 *)((longlong)pfVar168 + 0x30);
code_r0x000140094818:
  *(undefined1 **)((longlong)pfVar168 + 0x20) = puVar91;
  *(uint **)((longlong)pfVar168 + 0x28) = puVar223;
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x140094833;
  uVar241 = thunk_FUN_140006460(puVar225,(longlong)param_3,(ushort *)param_2,(ulonglong)param_1);
  if ((char)uVar241 != '\0') goto LAB_140094841;
  pfVar233 = (fd_set *)((longlong)&pfVar233->fd_count + 1);
  pfVar227 = (fd_set *)((longlong)pfVar227[-1].fd_array + 0x1ff);
  bVar239 = false;
  goto LAB_1400947ee;
code_r0x000140094857:
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009485d;
  uVar69 = (*(code *)pfVar84)(pcVar83);
  puVar223 = (uint *)(ulonglong)uVar69;
  goto LAB_14009485f;
code_r0x000140094790:
  *(undefined8 *)((longlong)puVar151 + -8) = 0x1400947a1;
  uVar241 = thunk_FUN_140006460(pcVar83,(longlong)param_3,(ushort *)param_2,(ulonglong)param_1);
  if ((char)uVar241 != '\0') goto LAB_140094841;
  pfVar227 = (fd_set *)((longlong)&pfVar227->fd_count + 1);
  UNRECOVERED_JUMPTABLE = (code *)0x0;
switchD_14007fde0_caseD_85:
  bVar239 = pfVar227 == (fd_set *)&DAT_00000004;
  puVar150 = puVar151;
code_r0x000140094758:
  puVar225 = (uint *)pcVar83;
  pfVar168 = (fd_set *)puVar150;
  pfVar234 = param_3;
  if (bVar239) goto LAB_140094846;
switchD_14007f6e5_caseD_87:
  *(longlong *)((longlong)pfVar168 + 0x30) =
       (longlong)pfVar233->fd_array + (longlong)(pfVar227[-1].fd_array + 0x3f);
  if (((ulonglong)UNRECOVERED_JUMPTABLE & 1) == 0) {
    UNRECOVERED_JUMPTABLE = (code *)pfVar234->fd_array[2];
    *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009477e;
    cVar89 = (*UNRECOVERED_JUMPTABLE)(puVar225,&DAT_14010bbb0,1);
    if (cVar89 != '\0') goto LAB_140094841;
  }
LAB_140094786:
  *(uint **)((longlong)pfVar168 + 0x20) = puVar223;
  *(fd_set **)((longlong)pfVar168 + 0x28) = pfVar84;
  puVar151 = (undefined8 *)pfVar168;
  pcVar83 = (char *)puVar225;
  param_3 = pfVar234;
  goto code_r0x000140094790;
LAB_140094846:
  puVar223 = (uint *)0x0;
  goto LAB_14009485f;
switchD_14007fde0_caseD_1a:
  puVar114 = puVar37;
  uVar65 = (ushort)pfVar84;
  if (bVar239) {
    *(undefined8 *)((longlong)puVar114 + -8) = 0x14008aa30;
    uVar69 = WSAGetLastError();
    pfVar84 = (fd_set *)param_2;
code_r0x00014008aa30:
    param_2 = (undefined **)((ulonglong)uVar69 << 0x20 | 2);
    if (pfVar84 != (fd_set *)0x0) {
LAB_14008ab52:
      ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3d] = (SOCKET)pcVar83;
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ab65;
      FUN_14006a7d0(((fd_set *)puVar223)->fd_array + 0x24);
    }
LAB_14008ab66:
    do {
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ab6f;
      closesocket((SOCKET)pcVar83);
      pcVar83 = pcVar103;
      pfVar233 = (fd_set *)param_2;
      pfVar234 = pfVar227;
      do {
        while( true ) {
          param_2 = (undefined **)pfVar233;
          pfVar227 = (fd_set *)(pfVar234->fd_array + 3);
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ab82;
          FUN_14007d9e5(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xe);
          ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xe] = (SOCKET)param_2;
          uVar69 = *(uint *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0x8c);
          pfVar77 = (fd_set *)(ulonglong)uVar69;
          uVar65 = 2;
          pfVar233 = (fd_set *)param_2;
          if (pfVar227 == (fd_set *)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x36])
          goto LAB_14008ac90;
          uVar5 = (ushort)pfVar227->fd_count;
          pfVar84 = (fd_set *)(ulonglong)uVar5;
          if (uVar5 == 2) goto LAB_14008ac90;
          *(undefined2 *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0x15) =
               *(undefined2 *)((longlong)pfVar234->fd_array + 0x22);
          ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x14] =
               *(SOCKET *)((longlong)pfVar234->fd_array + 0x1a);
          ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xf] =
               *(SOCKET *)((longlong)pfVar234->fd_array + 0x24);
          *(undefined4 *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0x16) =
               *(undefined4 *)((longlong)pfVar234->fd_array + 0x2c);
          *(int *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xac) =
               (int)pfVar234->fd_array[6];
          *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc4) =
               *(undefined2 *)((longlong)pfVar234->fd_array + 0x34);
          *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc2) =
               *(undefined2 *)((longlong)pfVar234->fd_array + 0x36);
          pfVar234 = pfVar227;
          if (uVar69 != 1000000000) break;
          if (*(char *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 199) == '\0')
          {
LAB_14008a8cc:
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a8db;
            FUN_140078763((undefined8 *)param_1,
                          (longlong *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x2a));
            if (SBORROW8(0,((fd_set *)puVar223)->fd_array[0x3a])) {
              *(undefined8 *)((longlong)puVar114 + -8) = 0x14008aff3;
              FUN_1400c3cf0();
                    /* WARNING: Does not return */
              UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
              (*UNRECOVERED_JUMPTABLE)();
            }
            *(undefined8 *)((longlong)puVar114 + -8) = 0x50;
            pfVar84 = param_1;
            pSVar163 = ((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7;
            for (lVar96 = *(longlong *)((longlong)puVar114 + -8); lVar96 != 0; lVar96 = lVar96 + -1)
            {
              *(char *)pSVar163 = (char)pfVar84->fd_count;
              pfVar84 = (fd_set *)((longlong)&pfVar84->fd_count + 1);
              pSVar163 = (SOCKET *)((longlong)pSVar163 + 1);
            }
            pcVar83 = "SOCKS feature disabled.";
            *(undefined8 *)((longlong)puVar114 + -8) = 0x17;
            writefds = *(uint **)((longlong)puVar114 + -8);
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a90e;
            pfVar233 = (fd_set *)FUN_14006ff40(0x28,"SOCKS feature disabled.",(ulonglong)writefds);
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a919;
            FUN_1400761ab((longlong *)(((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7));
          }
          else {
            *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x44) =
                 *(undefined2 *)
                  ((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xa4);
            *(int *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8) =
                 (int)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x14];
            uVar69 = *(uint *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xa6);
            if (DAT_140144240 == '\0') {
              *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ac23;
              FUN_1400c68a0();
            }
            SVar82 = ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xf];
            ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] = 0;
            pfVar227 = (fd_set *)(SVar82 << 0x20 | (ulonglong)uVar69);
            pfVar233 = pfVar227;
            if (uVar5 == 3) {
LAB_14008a934:
              *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a940;
              FUN_14007d9e5(((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7);
              uVar65 = uVar5;
              if (uVar5 != 3) goto LAB_14008afa3;
            }
            else {
              pfVar77 = (fd_set *)pcVar83;
              pfVar233 = (fd_set *)0x0;
              while (pcVar83 = (char *)pfVar77, (short)pfVar84 != 2) {
                *(short *)(((fd_set *)puVar223)->fd_array + 0x3a) = (short)pfVar84;
                *(undefined2 *)((longlong)((fd_set *)puVar223)->fd_array + 0x1d6) =
                     *(undefined2 *)
                      ((longlong)((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x44);
                *(int *)((longlong)((fd_set *)puVar223)->fd_array + 0x1d2) =
                     (int)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[8];
                ((fd_set *)puVar223)->fd_array[0x3b] = (SOCKET)pfVar227;
                *(int *)(((fd_set *)puVar223)->fd_array + 0x3c) = (int)(SVar82 >> 0x20);
                *(int *)((longlong)((fd_set *)puVar223)->fd_array + 0x1e4) =
                     (int)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x16];
                *(undefined4 *)(((fd_set *)puVar223)->fd_array + 0x3d) =
                     *(undefined4 *)
                      ((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xac);
                *(undefined2 *)((longlong)((fd_set *)puVar223)->fd_array + 0x1ec) =
                     *(undefined2 *)
                      ((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc4);
                *(undefined2 *)((longlong)((fd_set *)puVar223)->fd_array + 0x1ee) =
                     *(undefined2 *)
                      ((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc2);
                *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a7cc;
                bVar239 = FUN_140074760((short *)param_1,(SOCKET)pcVar83,writefds,(int)param_4);
                pfVar233 = (fd_set *)pcVar83;
                if (!bVar239) goto LAB_14008a934;
                *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a7e3;
                pfVar77 = (fd_set *)pcVar83;
                FUN_14007d9e5(((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7);
                ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] = (SOCKET)pcVar83;
                pfVar84 = (fd_set *)((longlong)&uRam0000000000000000 + 2);
              }
              if (pfVar233 == (fd_set *)0x0) {
                pfVar233 = (fd_set *)&PTR_s_could_not_resolve_to_any_address_1400f81c0;
              }
            }
          }
        }
        pcVar83 = (char *)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3e];
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a805;
        FUN_1400764a2((ulonglong *)param_1,(ulonglong)pcVar83,uVar69);
        uVar81 = ((fd_set *)puVar223)->fd_array[0x3a];
        if ((int)((fd_set *)puVar223)->fd_array[0x3b] == 1000000000) {
          puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008adbf;
          FUN_1400884b6(puVar92,uVar81);
          pvVar7 = (LPVOID)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x10];
          SVar82 = ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3f];
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008add2;
          FUN_1400807e2(pvVar7,SVar82);
          goto LAB_14008ae57;
        }
        if (*(char *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 199) == '\0')
        goto LAB_14008a8cc;
        writefds = &pfVar77->fd_count;
        if (DAT_140144240 == '\0') {
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ac2d;
          FUN_1400c68a0();
          writefds = &pfVar77->fd_count;
        }
        *(undefined8 *)((longlong)puVar114 + -8) = 2;
        uVar81 = *(ulonglong *)((longlong)puVar114 + -8);
        *(undefined8 *)((longlong)puVar114 + -8) = 0x17;
        if ((uVar5 & 1) != 0) {
          uVar81 = *(ulonglong *)((longlong)puVar114 + -8);
        }
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a86f;
        uVar81 = FUN_140072160(uVar81 & 0xffffffff);
        pfVar233 = (fd_set *)pcVar83;
      } while ((uVar81 & 1) != 0);
      *(undefined4 *)(((fd_set *)puVar223)->fd_array + 0x3a) = 1;
      pcVar103 = (char *)0x8004667e;
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a895;
      writefds = &param_1->fd_count;
      iVar66 = ioctlsocket((SOCKET)pcVar83,-0x7ffb9982,&param_1->fd_count);
      if (iVar66 != -1) goto code_r0x00014008a89e;
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008a956;
      uVar69 = WSAGetLastError();
      param_2 = (undefined **)((ulonglong)uVar69 << 0x20 | 2);
    } while( true );
  }
  goto code_r0x00014008aa07;
code_r0x00014008a89e:
  if ((uVar5 & 1) == 0) {
    uVar65 = *(ushort *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xa4);
    uVar65 = uVar65 << 8 | uVar65 >> 8;
    _Dst = (uint *)((longlong)&uRam0000000000000000 + 2);
    uVar69 = (uint)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x14];
    _Src = (uint *)0x0;
    *(undefined8 *)((longlong)puVar114 + -8) = 0x10;
  }
  else {
    uVar65 = *(ushort *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc4);
    uVar65 = uVar65 << 8 | uVar65 >> 8;
    _Dst = (uint *)0x17;
    _Src = *(uint **)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xa2);
    uVar69 = (uint)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x16];
    *(undefined8 *)((longlong)puVar114 + -8) = 0x1c;
  }
  param_4 = (fd_set *)(ulonglong)uVar69;
  UNRECOVERED_JUMPTABLE = (code *)(ulonglong)uVar65;
  writefds = *(uint **)((longlong)puVar114 + -8);
  puVar111 = (undefined1 *)puVar114;
code_r0x00014008a981:
  iVar66 = (int)writefds;
  ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x12] = (SOCKET)param_2;
  *(short *)(((fd_set *)puVar223)->fd_array + 0x3a) = (short)_Dst;
  *(short *)((longlong)((fd_set *)puVar223)->fd_array + 0x1d2) = (short)UNRECOVERED_JUMPTABLE;
  *(int *)((longlong)((fd_set *)puVar223)->fd_array + 0x1d4) = (int)param_4;
  ((fd_set *)puVar223)->fd_array[0x3b] = (SOCKET)_Src;
  SVar82 = ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xf];
  puVar112 = puVar111;
code_r0x00014008a9ab:
  ((fd_set *)puVar223)->fd_array[0x3c] = SVar82;
  *(undefined4 *)(((fd_set *)puVar223)->fd_array + 0x3d) =
       *(undefined4 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xac);
  *(undefined8 *)(puVar112 + -8) = 0x14008a9ca;
  iVar66 = connect((SOCKET)pcVar83,(sockaddr *)param_1,iVar66);
  if (iVar66 == -1) {
    *(undefined8 *)(puVar112 + -8) = 0x14008a9d9;
    uVar69 = WSAGetLastError();
    param_2 = (undefined **)((ulonglong)uVar69 << 0x20 | 2);
  }
  else {
    param_2 = (undefined **)0x0;
  }
  ((fd_set *)puVar223)->fd_array[0x24] = (SOCKET)param_2;
  *(undefined4 *)(((fd_set *)puVar223)->fd_array + 0x3a) = 0;
  pcVar103 = (char *)0x8004667e;
  *(undefined8 *)(puVar112 + -8) = 0x14008aa02;
  writefds = &param_1->fd_count;
  iVar66 = ioctlsocket((SOCKET)pcVar83,-0x7ffb9982,&param_1->fd_count);
  bVar239 = iVar66 == -1;
  puVar37 = (undefined8 *)puVar112;
  goto switchD_14007fde0_caseD_1a;
code_r0x000140089986:
  pfVar107 = (fd_set *)puVar51;
  if (*(char *)(((ulonglong)UNRECOVERED_JUMPTABLE & 0xffffffffffffff70) + 0x10) == '#') {
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400899a2;
    FUN_1400759ea((ulonglong *)param_1);
    goto LAB_140089940;
  }
code_r0x000140089a1a:
  *(undefined8 *)((longlong)pfVar107 + 0x48) = (undefined1 *)((longlong)pfVar107 + 0x58);
  *(undefined1 **)((longlong)pfVar107 + 0x50) = &LAB_1400298e7;
  *(undefined **)((longlong)pfVar107 + -8) = &UNK_140089a46;
  FUN_1400811fe((ulonglong *)((longlong)pfVar107 + 0x70),(ushort *)&UNK_140108c8b,
                (ulonglong)((longlong)pfVar107 + 0x48));
  *(undefined **)((longlong)pfVar107 + -8) = &UNK_140089a4e;
  uVar63 = FUN_140076505(pfVar233);
  *(uint **)((longlong)pfVar107 + 0x88) = puVar225;
  *(undefined8 *)((longlong)pfVar107 + 0xe0) = 0;
  *(undefined1 *)((longlong)pfVar107 + 0xf0) = 8;
  *(uint **)((longlong)pfVar107 + 0x68) = puVar225;
  *(undefined **)((longlong)pfVar107 + -8) = &UNK_140089a7c;
  FUN_1400849c1((undefined8 *)((longlong)pfVar107 + 0x178),(longlong *)((longlong)pfVar107 + 0x68),
                (ulonglong)pfVar233);
  *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089a86;
  lVar96 = FUN_14007fa6e(uVar63,(undefined1 *)((longlong)pfVar107 + 0x178));
  goto LAB_140089a86;
code_r0x0001400899fd:
  ((fd_set *)param_2)->fd_array[0x17] = (SOCKET)UNRECOVERED_JUMPTABLE;
  uVar81 = (longlong)pfVar233->fd_array + *(longlong *)((longlong)pfVar107 + 0x40) + -8;
  if (pfVar233 != (fd_set *)0x0) {
LAB_14008993b:
    *(ulonglong *)((longlong)pfVar107 + 0x40) = uVar81;
LAB_140089940:
    if (param_3 == (fd_set *)0x0) {
      pfVar234 = (fd_set *)((longlong)&uRam0000000000000000 + 1);
      pfVar233 = (fd_set *)0x0;
    }
    else {
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089950;
      FUN_14007630d((longlong *)pfVar84,(longlong)param_2);
      pfVar234 = *(fd_set **)((longlong)pfVar107 + 0x68);
      puVar109 = (undefined8 *)pfVar107;
      if (pfVar234 == (fd_set *)0x0) {
code_r0x00014008995a:
        *(longlong *)((longlong)puVar109 + 0x50) = *(longlong *)((longlong)puVar109 + 0x70);
        *(undefined8 *)((longlong)puVar109 + 0x48) = 0;
        *(undefined8 *)((longlong)puVar109 + -8) = 0x140089975;
        FUN_1400762c3((undefined1 *)pfVar84,*(longlong *)((longlong)puVar109 + 0x70));
                    /* WARNING: Could not recover jumptable at 0x000140089982. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pfVar84 = (fd_set *)
                  (*(code *)((longlong)((fd_set *)puVar223)->fd_array +
                            (longlong)
                            *(int *)((longlong)((fd_set *)puVar223)->fd_array +
                                    (ulonglong)*(byte *)((longlong)puVar109 + 0x68) * 4 + -8) + -8))
                            ();
        return pfVar84;
      }
      pfVar233 = *(fd_set **)((longlong)pfVar107 + 0x70);
      if (param_3 < *(fd_set **)((longlong)pfVar107 + 0x70)) {
        pfVar233 = param_3;
      }
    }
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400899c8;
    pfVar227 = pfVar234;
    lVar96 = FUN_140075fa2(10,(longlong)pfVar234,(ulonglong)pfVar233);
    if (lVar96 == 1) {
      if (pfVar233 <= pfVar227) {
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089c23;
        FUN_1400c3c30(0,(ulonglong)pfVar227,(ulonglong)pfVar233,
                      &PTR_s__rustc_ac68faa20c58cbccd01ee7208_1400f7f80);
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
        (*UNRECOVERED_JUMPTABLE)();
      }
      pfVar84 = (fd_set *)((longlong)&pfVar227->fd_count + 1);
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089ad6;
      FUN_140011c6d((ulonglong *)((longlong)pfVar107 + 0x28),pfVar234,(ulonglong)pfVar84);
      if (param_3 < pfVar84) {
        pfVar84 = param_3;
      }
      uVar81 = (longlong)pfVar84->fd_array + (((fd_set *)param_2)->fd_array[0x17] - 8);
      if (((fd_set *)param_2)->fd_array[0x18] < uVar81) {
        uVar81 = ((fd_set *)param_2)->fd_array[0x18];
      }
      ((fd_set *)param_2)->fd_array[0x17] = uVar81;
      uVar81 = (longlong)pfVar227->fd_array + *(longlong *)((longlong)pfVar107 + 0x40) + -7;
      goto LAB_140089b04;
    }
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400899e2;
    FUN_140011c6d((ulonglong *)((longlong)pfVar107 + 0x28),pfVar234,(ulonglong)pfVar233);
    param_3 = (fd_set *)((longlong)param_3 - (longlong)pfVar233);
    UNRECOVERED_JUMPTABLE =
         (code *)((longlong)pfVar233->fd_array + (((fd_set *)param_2)->fd_array[0x17] - 8));
    if ((fd_set *)((fd_set *)param_2)->fd_array[0x18] < UNRECOVERED_JUMPTABLE) {
      UNRECOVERED_JUMPTABLE = (code *)((fd_set *)param_2)->fd_array[0x18];
    }
    goto code_r0x0001400899fd;
  }
LAB_140089b04:
  if (uVar81 == 0) {
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089b57;
    lVar96 = FUN_14006ff40(6,"Unexpected EOF",0xe);
  }
  else {
    if (uVar81 < 0x19001) {
      lVar96 = *(longlong *)((longlong)pfVar107 + 0x30);
      uVar81 = *(ulonglong *)((longlong)pfVar107 + 0x38);
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089b7e;
      uVar241 = FUN_140091232(lVar96,uVar81,&DAT_140108ca3,1);
      if ((char)uVar241 != '\0') {
        if (uVar81 == 0) {
          uVar81 = 0;
        }
        else {
          uVar81 = uVar81 - 1;
          *(ulonglong *)((longlong)pfVar107 + 0x38) = uVar81;
        }
        *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089be6;
        uVar241 = FUN_140091232(lVar96,uVar81,"\r",1);
        if ((uVar81 != 0) && ((char)uVar241 != '\0')) {
          *(ulonglong *)((longlong)pfVar107 + 0x38) = uVar81 - 1;
        }
        pfVar84 = *(fd_set **)((longlong)pfVar107 + 0x38);
        puVar92 = *(undefined8 **)((longlong)pfVar107 + 0x20);
        puVar92[2] = pfVar84;
        uVar241 = *(undefined8 *)((longlong)pfVar107 + 0x30);
        *puVar92 = *(undefined8 *)((longlong)pfVar107 + 0x28);
        puVar92[1] = uVar241;
        return pfVar84;
      }
      *(undefined8 *)((longlong)pfVar107 + 0x48) = (undefined1 *)((longlong)pfVar107 + 0x28);
      *(code **)((longlong)pfVar107 + 0x50) = FUN_1400699b3;
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089bbd;
      FUN_1400811fe((ulonglong *)((longlong)pfVar107 + 0x68),(ushort *)&DAT_140108ca4,
                    (ulonglong)((longlong)pfVar107 + 0x48));
      uVar63 = 0x14;
    }
    else {
      *(undefined8 *)((longlong)pfVar107 + 0x48) = &DAT_140108c60;
      *(code **)((longlong)pfVar107 + 0x50) = FUN_14000c3b0;
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089b3f;
      FUN_1400811fe((ulonglong *)((longlong)pfVar107 + 0x68),(ushort *)&DAT_140108c68,
                    (ulonglong)((longlong)pfVar107 + 0x48));
      uVar63 = 0x28;
    }
    *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089bc7;
    lVar96 = FUN_140063110(uVar63,(undefined8 *)((longlong)pfVar107 + 0x68));
  }
LAB_140089a86:
  puVar92 = *(undefined8 **)((longlong)pfVar107 + 0x20);
  puVar92[1] = lVar96;
  *puVar92 = puVar225;
  *(undefined8 *)((longlong)pfVar107 + -8) = 0x140089aa1;
  pfVar84 = (fd_set *)
            thunk_FUN_140016b3a(*(longlong *)((longlong)pfVar107 + 0x28),
                                *(LPVOID *)((longlong)pfVar107 + 0x30));
  return pfVar84;
switchD_14009313c_caseD_8b:
  UNRECOVERED_JUMPTABLE = (code *)(ulonglong)(uint)((int)UNRECOVERED_JUMPTABLE + (int)puVar97);
  _Dst = puVar97;
code_r0x000140096abd:
                    /* WARNING: Could not recover jumptable at 0x000140096ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pfVar84 = (fd_set *)
            (*(code *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                      (longlong)(((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x3f)))();
  return pfVar84;
code_r0x00014007f937:
  while( true ) {
    pfStackY_90 = (fd_set *)0x14007f93c;
    bVar239 = FUN_140074a00((undefined8 *)_Dst,_Src,(ulonglong)writefds);
    local_48 = (fd_set *)CONCAT71(extraout_var,bVar239);
    _Dst = &param_1->fd_count;
    if (bVar239) break;
    if ((fd_set *)_Src == (fd_set *)0x0) {
      return pfVar233;
    }
    pfStackY_90 = (fd_set *)0x14007f981;
    FUN_14007f82f((longlong *)param_3,(ulonglong)_Src);
    _Dst = (uint *)pcVar83;
    _Src = (uint *)local_60._8_8_;
    writefds = &local_50->fd_count;
    if (local_50 == (fd_set *)0x0) {
      return (fd_set *)0x0;
    }
  }
code_r0x00014007f953:
  pfStackY_90 = (fd_set *)0x14007f958;
  FUN_1400762c3((undefined1 *)_Dst,(longlong)_Src);
                    /* WARNING: Could not recover jumptable at 0x00014007f965. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pfVar84 = (fd_set *)
            (*(code *)((longlong)pfVar227->fd_array +
                      (longlong)
                      *(int *)((longlong)pfVar227->fd_array +
                              (in_stack_ffffffffffffff98 & 0xff) * 4 + -8) + -8))();
  return pfVar84;
LAB_1400994c8:
  do {
    if (param_2 == (undefined **)UNRECOVERED_JUMPTABLE) {
      ppuVar231 = &PTR_s_C__Users_flare__cargo_registry_s_14010b6a8;
      goto LAB_140099726;
    }
    if (pfVar227 == (fd_set *)UNRECOVERED_JUMPTABLE) {
      ppuVar231 = &PTR_s_C__Users_flare__cargo_registry_s_14010b6c0;
LAB_140099726:
      *(undefined ***)((longlong)pfVar107 + 0x20) = ppuVar231;
      *(undefined8 *)((longlong)pfVar107 + -8) = 0x140099748;
      FUN_1400c3e10("called `Result::unwrap()` on an `Err` value",0x2b,
                    (undefined1 *)((longlong)pfVar107 + 0x3c),&DAT_14010aec0,
                    *(undefined8 *)((longlong)pfVar107 + 0x20));
                    /* WARNING: Does not return */
      UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
      (*UNRECOVERED_JUMPTABLE)();
    }
    if (in_R10 == (fd_set *)UNRECOVERED_JUMPTABLE) {
      ppuVar231 = &PTR_s_C__Users_flare__cargo_registry_s_14010b6d8;
      goto LAB_140099726;
    }
    bVar238 = *(byte *)((longlong)param_3->fd_array +
                       (longlong)
                       (((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x3f));
    _Src = (uint *)(ulonglong)bVar238;
    iVar66 = 0x1f;
    if ((byte)~bVar238 != 0) {
      for (; (byte)~bVar238 >> iVar66 == 0; iVar66 = iVar66 + -1) {
      }
    }
    iVar98 = 0;
    if ((bVar238 | 0x100) != 0) {
      for (; ((bVar238 | 0x100) >> iVar98 & 1) == 0; iVar98 = iVar98 + 1) {
      }
    }
    if ((byte)((char)iVar98 + ((byte)iVar66 ^ 7)) != '\b') goto LAB_140099556;
    writefds = (uint *)(ulonglong)
                       *(byte *)((longlong)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_array +
                                *(longlong *)((longlong)pfVar107 + 0x90) + -8);
switchD_14009313c_caseD_f4:
    bVar238 = (byte)_Src;
    if (((ulonglong)puVar97 & 1) == 0) {
      if (bVar238 != 0xff) goto LAB_140099536;
      puVar97 = (uint *)0x0;
    }
    else {
      if (bVar238 != 0) goto LAB_140099556;
LAB_140099536:
      puVar97 = (uint *)((longlong)&uRam0000000000000000 + 1);
    }
    if ((bVar238 &
        (*(byte *)((longlong)pfVar233->fd_array +
                  (longlong)
                  (((fd_set *)((longlong)UNRECOVERED_JUMPTABLE + -0x208))->fd_array + 0x3f)) ^
        (byte)writefds)) != 0) goto LAB_140099414;
    UNRECOVERED_JUMPTABLE = (code *)((longlong)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + 1);
  } while (param_2 != (undefined **)UNRECOVERED_JUMPTABLE);
  *(undefined1 *)((longlong)pfVar107 + 0x58) = 1;
LAB_140099419:
  lVar96 = -0x7fffffffffffffce;
LAB_140099560:
  *(longlong *)((longlong)pfVar107 + 0x50) = lVar96;
  pfVar168 = pfVar107;
LAB_140099565:
  if (((ulonglong)puVar225 & 1) == 0) {
    if (lVar96 == -0x7fffffffffffffce) {
      *(uint *)((longlong)pfVar168 + 0x40) =
           CONCAT31((int3)((uint)*(undefined4 *)((longlong)pfVar168 + 0x40) >> 8),
                    (byte)*(undefined4 *)((longlong)pfVar168 + 0x40) |
                    *(byte *)((longlong)pfVar168 + 0x58));
      *(uint *)((longlong)pfVar168 + 0x44) =
           CONCAT31((int3)((uint)*(undefined4 *)((longlong)pfVar168 + 0x44) >> 8),
                    (byte)*(undefined4 *)((longlong)pfVar168 + 0x44) |
                    *(byte *)((longlong)pfVar168 + 0x58) ^ 1);
      goto LAB_140099219;
    }
  }
  else if (lVar96 == -0x7fffffffffffffce) {
    if (*(char *)((longlong)pfVar168 + 0x58) == '\x01') {
LAB_14009970a:
      pfVar84 = (fd_set *)0x8000000000000019;
LAB_1400996bb:
      **(undefined8 **)((longlong)pfVar168 + 0x48) = pfVar84;
      return pfVar84;
    }
LAB_140099219:
    do {
      while (*(longlong *)((longlong)pfVar168 + 0x110) != *(longlong *)((longlong)pfVar168 + 0x108))
      {
        *(undefined8 *)((longlong)pfVar168 + 0x98) = 0x8000000000000015;
        if (pfVar84 == (fd_set *)0x0) {
          pfVar84 = *(fd_set **)((longlong)pfVar168 + 0x48);
          *(undefined8 *)pfVar84 = 0x8000000000000015;
          return pfVar84;
        }
        pfVar84 = (fd_set *)((longlong)pfVar84[-1].fd_array + 0x1ff);
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140099258;
        FUN_14009350d((ulonglong *)param_1);
        *(fd_set **)(*(longlong *)((longlong)pfVar168 + 0x220) + 0x10) = pfVar84;
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140099277;
        FUN_140093d16((undefined8 *)param_1,(longlong *)((longlong)pfVar168 + 0x100),0x30);
        lVar96 = *(longlong *)((longlong)pfVar168 + 0x98);
        lVar105 = *(longlong *)((longlong)pfVar168 + 0xa0);
        lVar85 = *(longlong *)((longlong)pfVar168 + 0xa8);
        if (lVar96 != -0x7fffffffffffffce) {
          lVar230 = *(longlong *)((longlong)pfVar168 + 0xb0);
          *(undefined8 *)((longlong)pfVar168 + 0xd0) = *(undefined8 *)((longlong)pfVar168 + 0xb8);
          *(undefined8 *)((longlong)pfVar168 + 0xd8) = *(undefined8 *)((longlong)pfVar168 + 0xc0);
          *(undefined8 *)((longlong)pfVar168 + 0xe0) = *(undefined8 *)((longlong)pfVar168 + 200);
LAB_140099671:
          plVar100 = *(longlong **)((longlong)pfVar168 + 0x48);
          *plVar100 = lVar96;
          plVar100[1] = lVar105;
          plVar100[2] = lVar85;
          plVar100[3] = lVar230;
          lVar96 = *(longlong *)((longlong)pfVar168 + 0xd8);
          plVar100[4] = *(longlong *)((longlong)pfVar168 + 0xd0);
          plVar100[5] = lVar96;
          pfVar84 = *(fd_set **)((longlong)pfVar168 + 0xe0);
          plVar100[6] = (longlong)pfVar84;
          return pfVar84;
        }
        *(undefined1 *)((longlong)pfVar168 + 0x138) = 0xc;
        *(undefined8 *)((longlong)pfVar168 + 0x130) = 0x800000000000001e;
        *(longlong *)((longlong)pfVar168 + 0x118) = lVar105;
        *(longlong *)((longlong)pfVar168 + 0x120) = lVar85;
        *(undefined8 *)((longlong)pfVar168 + 0x128) = 0;
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400992e5;
        FUN_14009488e((undefined8 *)param_1,(longlong *)((longlong)pfVar168 + 0x118));
        lVar96 = *(longlong *)((longlong)pfVar168 + 0x98);
        lVar105 = *(longlong *)((longlong)pfVar168 + 0xa0);
        lVar85 = *(longlong *)((longlong)pfVar168 + 0xa8);
        lVar230 = *(longlong *)((longlong)pfVar168 + 0xb0);
        if (lVar96 != -0x7fffffffffffffce) {
          *(undefined8 *)((longlong)pfVar168 + 0xe0) = *(undefined8 *)((longlong)pfVar168 + 200);
          *(undefined8 *)((longlong)pfVar168 + 0xd0) = *(undefined8 *)((longlong)pfVar168 + 0xb8);
          *(undefined8 *)((longlong)pfVar168 + 0xd8) = *(undefined8 *)((longlong)pfVar168 + 0xc0);
          *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009965d;
          FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x130));
          goto LAB_140099671;
        }
        if (*(longlong *)((longlong)pfVar168 + 0x128) != *(longlong *)((longlong)pfVar168 + 0x120))
        {
          lVar105 = *(longlong *)((longlong)pfVar168 + 0x138);
          lVar96 = -0x7fffffffffffffe2;
          goto LAB_140099671;
        }
        *(undefined8 *)((longlong)pfVar168 + -8) = 0x140099339;
        FUN_14009350d((ulonglong *)puVar223);
        if (*(char *)((longlong)pfVar168 + 0x3f) == (char)lVar105) {
                    /* WARNING: Could not recover jumptable at 0x000140099359. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pfVar84 = (fd_set *)
                    (*(code *)((longlong)&UINT_14011014c +
                              (longlong)
                              (int)(&UINT_14011014c)[*(longlong *)((longlong)pfVar168 + 0xf8)]))();
          return pfVar84;
        }
      }
      lVar96 = *(longlong *)((longlong)pfVar168 + 0xf0);
      if (((~(byte)*(undefined4 *)((longlong)pfVar168 + 0x44) | *(byte *)((longlong)pfVar168 + 0x40)
           ) & 1) == 0) goto LAB_14009970a;
      do {
        lVar96 = lVar96 + 1;
        if (lVar96 == 2) {
LAB_1400996b1:
          pfVar84 = (fd_set *)0x8000000000000033;
          goto LAB_1400996bb;
        }
        lVar85 = lVar96 * 0x18;
        bVar238 = *(byte *)((longlong)pfVar168 + lVar85 + 0x178);
        if (bVar238 == 2) goto LAB_1400996b1;
        lVar105 = *(longlong *)((longlong)pfVar168 + lVar85 + 0x180);
      } while (lVar105 == 0);
      *(longlong *)((longlong)pfVar168 + 0xf0) = lVar96;
      uVar241 = *(undefined8 *)((longlong)pfVar168 + lVar85 + 0x188);
      *(longlong *)((longlong)pfVar168 + 0x100) = lVar105;
      *(undefined8 *)((longlong)pfVar168 + 0x108) = uVar241;
      *(undefined8 *)((longlong)pfVar168 + 0x110) = 0;
      *(byte *)((longlong)pfVar168 + 0x3d) = bVar238 & 1;
      *(undefined4 *)((longlong)pfVar168 + 0x44) = 0;
      *(undefined4 *)((longlong)pfVar168 + 0x40) = 0;
    } while( true );
  }
LAB_1400996d4:
  _Src = *(uint **)((longlong)pfVar168 + 0x48);
  ((fd_set *)_Src)->fd_array[5] = *(SOCKET *)((longlong)pfVar168 + 0x80);
  UNRECOVERED_JUMPTABLE = *(code **)((longlong)pfVar168 + 0x50);
  puVar97 = *(uint **)((longlong)pfVar168 + 0x58);
  SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x60);
  SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x68);
  SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x78);
  ((fd_set *)_Src)->fd_array[3] = *(SOCKET *)((longlong)pfVar168 + 0x70);
  ((fd_set *)_Src)->fd_array[4] = SVar236;
  ((fd_set *)_Src)->fd_array[1] = SVar82;
  ((fd_set *)_Src)->fd_array[2] = SVar76;
  *(code **)_Src = UNRECOVERED_JUMPTABLE;
switchD_14009313c_caseD_f8:
  ((fd_set *)_Src)->fd_array[0] = (SOCKET)puVar97;
  return (fd_set *)UNRECOVERED_JUMPTABLE;
  while( true ) {
    pvVar74 = (void *)pfVar84->fd_array[0];
    uVar81 = pfVar84->fd_array[1];
    *(undefined8 *)((longlong)pSVar196 + -8) = 0x140097015;
    FUN_140006370((ulonglong *)pfVar233,pvVar74,uVar81);
    *(undefined8 *)((longlong)(param_1->fd_array + 1) + (longlong)puVar223) =
         *(undefined8 *)((longlong)pSVar196 + 0x40);
    SVar82 = *(SOCKET *)((longlong)pSVar196 + 0x30);
    SVar76 = *(SOCKET *)((longlong)pSVar196 + 0x38);
    puVar35 = pSVar196;
    pfVar62 = (fd_set *)(pfVar84->fd_array + 2);
code_r0x000140097024:
    puVar225 = &pfVar62->fd_count;
    pfVar168 = (fd_set *)puVar35;
    pSVar163 = (SOCKET *)
               ((longlong)param_1->fd_array +
               (longlong)(((fd_set *)((longlong)puVar223 + -0x208))->fd_array + 0x3f));
    *pSVar163 = SVar82;
    pSVar163[1] = SVar76;
    puVar223 = (uint *)(((fd_set *)puVar223)->fd_array + 2);
LAB_140096ff6:
    bVar239 = (fd_set *)param_2 == (fd_set *)0x0;
    param_2 = (undefined **)((longlong)((fd_set *)((longlong)param_2 + -0x208))->fd_array + 0x1ff);
    pSVar196 = (SOCKET *)pfVar168;
    pfVar84 = (fd_set *)puVar225;
code_r0x000140096ffa:
    if (bVar239) break;
code_r0x000140096ffc:
    if (pfVar227 == (fd_set *)puVar223) break;
  }
LAB_140097032:
  *(undefined8 *)param_3 = *(undefined8 *)((longlong)pSVar196 + 0x20);
  param_3->fd_array[0] = (SOCKET)param_1;
  pfVar84 = *(fd_set **)((longlong)pSVar196 + 0x28);
  param_3->fd_array[1] = (SOCKET)pfVar84;
  return pfVar84;
code_r0x000140097298:
  pfVar168 = (fd_set *)puVar52;
  *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
       (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
code_r0x00014009729c:
  *(code **)((longlong)pfVar168 + 0x68) = UNRECOVERED_JUMPTABLE;
  *(uint **)((longlong)pfVar168 + 0x70) = _Src;
  param_2 = (undefined **)((longlong)pfVar233->fd_array + 0x2a);
  *(undefined ***)((longlong)pfVar168 + 0x60) = param_2;
  *(code **)((longlong)pfVar168 + 0x98) = UNRECOVERED_JUMPTABLE;
  *(uint **)((longlong)pfVar168 + 0xa0) = _Src;
code_r0x0001400972c0:
  pcVar83 = (char *)puVar225;
  if ((fd_set *)_Src != (fd_set *)0x0) {
code_r0x0001400972c5:
    *(undefined8 *)((longlong)pfVar168 + 0xa8) = 1;
    pcVar103 = (char *)_Src;
    puVar204 = (undefined8 *)pfVar168;
    pcVar83 = (char *)puVar225;
code_r0x0001400972d1:
    pfVar168 = (fd_set *)puVar204;
    if ((char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count == '\0') {
LAB_140097481:
      *(undefined8 *)((longlong)pfVar168 + -8) = 0x140097491;
      SVar82 = FUN_140096f69((longlong *)((longlong)pfVar168 + 0x98));
      puVar225 = (uint *)pcVar83;
      if (*(longlong *)((longlong)pfVar168 + 0xa8) != *(longlong *)((longlong)pfVar168 + 0xa0)) {
switchD_14007f7e4_caseD_e8:
        ((fd_set *)puVar225)->fd_array[5] = *(SOCKET *)((longlong)pfVar168 + 0x58);
        SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x28);
        SVar76 = *(SOCKET *)((longlong)pfVar168 + 0x30);
switchD_14009313c_caseD_cb:
        SVar236 = *(SOCKET *)((longlong)pfVar168 + 0x38);
        SVar8 = *(SOCKET *)((longlong)pfVar168 + 0x40);
        SVar11 = *(SOCKET *)((longlong)pfVar168 + 0x50);
        ((fd_set *)puVar225)->fd_array[3] = *(SOCKET *)((longlong)pfVar168 + 0x48);
        ((fd_set *)puVar225)->fd_array[4] = SVar11;
        ((fd_set *)puVar225)->fd_array[1] = SVar236;
        ((fd_set *)puVar225)->fd_array[2] = SVar8;
        *(SOCKET *)puVar225 = SVar82;
        ((fd_set *)puVar225)->fd_array[0] = SVar76;
        goto LAB_140097464;
      }
      ((fd_set *)pcVar83)->fd_array[0] = SVar82;
      ((fd_set *)pcVar83)->fd_array[1] = (SOCKET)pcVar103;
      *(undefined ***)pcVar83 = param_2;
      goto LAB_1400972dd;
    }
  }
  *(fd_set **)pcVar83 = pfVar233;
LAB_1400972dd:
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x1400972e7;
  FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x28));
LAB_140097464:
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x14009746e;
  pfVar84 = (fd_set *)FUN_14009487a((ulonglong *)((longlong)pfVar168 + 0x60));
  return pfVar84;
code_r0x00014008aa07:
  pfVar233 = (fd_set *)pcVar83;
  if ((fd_set *)param_2 != (fd_set *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00014008aa23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pfVar84 = (fd_set *)
              (*(code *)((longlong)&UINT_14010fd84 +
                        (longlong)(int)(&UINT_14010fd84)[(uint)param_2 & 3]))();
    return pfVar84;
  }
LAB_14008af9c:
  param_2 = (undefined **)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x12];
LAB_14008afa3:
  *(short *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 6) =
       (short)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x15];
  ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[5] =
       ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x14];
LAB_14008ac90:
  pvVar7 = (LPVOID)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x10];
  SVar82 = ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3f];
  *(undefined8 *)((longlong)puVar114 + -8) = 0x14008aca3;
  FUN_1400807e2(pvVar7,SVar82);
  if (uVar65 == 2) {
    if ((fd_set *)param_2 == (fd_set *)0x0) {
      *(undefined8 *)((longlong)puVar114 + -8) = 0x3c;
      uVar241 = *(undefined8 *)((longlong)puVar114 + -8);
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b57b;
      FUN_1400c6141("shouldn\'t happen: failed to connect to all IPs, but no error",uVar241,
                    &DAT_140108840,param_4);
                    /* WARNING: Does not return */
      UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
      (*UNRECOVERED_JUMPTABLE)();
    }
    *(undefined8 *)((longlong)puVar114 + -8) = 0xd;
    uVar81 = *(ulonglong *)((longlong)puVar114 + -8);
    *(undefined8 *)((longlong)puVar114 + -8) = 0x14008accf;
    FUN_140084984(((fd_set *)puVar223)->fd_array + 0x3a,4,"Connect error",uVar81);
    puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
    *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ace1;
    FUN_1400849c1(puVar92,(longlong *)(((fd_set *)puVar223)->fd_array + 0x3a),(ulonglong)param_2);
    goto LAB_14008ae68;
  }
  *(short *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc) =
       (short)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[6];
  ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xb] =
       ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[5];
  ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xd] = (SOCKET)pfVar233;
  *(uint *)(((fd_set *)puVar223)->fd_array + 0x3a) =
       (uint)*(byte *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array[7] + 0xcd);
  *(undefined4 *)((longlong)puVar114 + 0x20) = 4;
  *(undefined8 *)((longlong)puVar114 + -8) = 6;
  uVar241 = *(undefined8 *)((longlong)puVar114 + -8);
  *(undefined8 *)((longlong)puVar114 + -8) = 1;
  uVar243 = *(undefined8 *)((longlong)puVar114 + -8);
  *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ad39;
  iVar66 = setsockopt((SOCKET)pfVar233,(int)uVar241,(int)uVar243,
                      (char *)(((fd_set *)puVar223)->fd_array + 0x3a),
                      *(int *)((longlong)puVar114 + 0x20));
  if (iVar66 == -1) {
    *(undefined8 *)((longlong)puVar114 + -8) = 0x14008addd;
    uVar69 = WSAGetLastError();
    ppuVar231 = (undefined **)(((ulonglong)uVar69 << 0x20) + 2);
    puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
LAB_14008adec:
    *(undefined8 *)((longlong)puVar114 + -8) = 0x14008adf1;
    FUN_1400884b6(puVar92,(ulonglong)ppuVar231);
  }
  else {
    SVar82 = ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x39];
    iVar66 = *(int *)(SVar82 + 0x90);
    if (iVar66 == 1000000000) {
      SVar76 = ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[7];
      uVar81 = *(ulonglong *)(SVar76 + 0x88);
      uVar69 = *(uint *)(SVar76 + 0x90);
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ad79;
      ppuVar231 = FUN_140072280((SOCKET)pfVar233,uVar81,uVar69);
      SVar236 = *(SOCKET *)((longlong)puVar223 + 0x820);
      if (ppuVar231 != (undefined **)0x0) {
LAB_14008ada4:
        puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
        goto LAB_14008adec;
      }
      ppuVar73 = *(undefined ***)(SVar76 + 0x98);
      uVar69 = *(uint *)(SVar76 + 0xa0);
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ad9b;
      ppuVar231 = FUN_140072330((SOCKET)pfVar233,(ulonglong)ppuVar73,uVar69);
      if (ppuVar231 != (undefined **)0x0) goto LAB_14008ada4;
LAB_14008aed9:
      if (*(char *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc1) == '\0') {
LAB_14008b4ee:
        puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
        *(short *)((longlong)puVar92 + 0x1a) =
             (short)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xc];
        *(SOCKET *)((longlong)puVar92 + 0x12) =
             ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xb];
        *(SOCKET *)((longlong)puVar92 + 0x1c) =
             ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xf];
        *(int *)((longlong)puVar92 + 0x24) =
             (int)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x16];
        *(undefined4 *)(puVar92 + 5) =
             *(undefined4 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xac);
        *(undefined2 *)((longlong)puVar92 + 0x2c) =
             *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc4);
        *(undefined2 *)((longlong)puVar92 + 0x2e) =
             *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc2);
        puVar92[1] = pfVar233;
        *(ushort *)(puVar92 + 2) = uVar65;
        *puVar92 = 0x8000000000000001;
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b560;
        FUN_14007d9e5(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xe);
        goto LAB_14008ae68;
      }
      ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x12] = (SOCKET)param_2;
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008aef9;
      pvVar74 = (void *)FUN_140080372(SVar82 + 0x18);
      *(undefined8 *)((longlong)puVar114 + -8) = 5;
      sVar232 = *(size_t *)((longlong)puVar114 + -8);
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008af0c;
      uVar241 = FUN_140075b91(pvVar74,(size_t)ppuVar73,"https",sVar232);
      if (((char)uVar241 == '\0') ||
         (SBORROW8(0,((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x2a]))) goto LAB_14008b4ee;
      SVar76 = *(SOCKET *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array[7] + 0x18);
      SVar8 = *(SOCKET *)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array[7] + 0x20);
      *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0x9e) =
           *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xb6);
      ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3b] = SVar76;
      ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3c] = SVar8;
      if ((SBORROW8(0,((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x2d])) ||
         (SBORROW8(0,((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x30]))) {
        ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] = 0;
        ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[8] = 1;
        ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[9] = 0;
      }
      else {
        pSVar163 = ((fd_set *)puVar223)->fd_array + 0x3a;
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008af78;
        FUN_1400787e0(pSVar163,(longlong *)
                               (((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x2d));
        if (SBORROW8(0,*pSVar163)) {
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[8] = 0;
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[9] = 1;
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[10] = 0;
        }
        else {
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[10] =
               ((fd_set *)puVar223)->fd_array[0x3c];
          SVar76 = ((fd_set *)puVar223)->fd_array[0x3b];
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[8] =
               ((fd_set *)puVar223)->fd_array[0x3a];
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[9] = SVar76;
        }
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b01c;
        FUN_1400787e0(pSVar163,(longlong *)
                               (((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x30));
        if (SBORROW8(0,*pSVar163)) {
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] = 0;
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[8] = 1;
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[9] = 0;
        }
        else {
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[9] =
               ((fd_set *)puVar223)->fd_array[0x3c];
          SVar76 = ((fd_set *)puVar223)->fd_array[0x3b];
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] =
               ((fd_set *)puVar223)->fd_array[0x3a];
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[8] = SVar76;
        }
        ((fd_set *)puVar223)->fd_array[0x3a] =
             (SOCKET)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8);
        ((fd_set *)puVar223)->fd_array[0x3b] = (SOCKET)&LAB_140064a76;
        ((fd_set *)puVar223)->fd_array[0x3c] =
             (SOCKET)(((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7);
        ((fd_set *)puVar223)->fd_array[0x3d] = (SOCKET)&LAB_140064a76;
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b0a3;
        FUN_1400811fe(((fd_set *)puVar223)->fd_array + 0x24,(ushort *)&DAT_140108074,
                      (ulonglong)(((fd_set *)puVar223)->fd_array + 0x3a));
        SVar76 = ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7];
        pvVar7 = (LPVOID)((fd_set *)((longlong)puVar223 + 0x410))->fd_array[8];
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b0b6;
        thunk_FUN_140016b3a(SVar76,pvVar7);
        SVar76 = ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[8];
        pvVar7 = (LPVOID)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[9];
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b0c9;
        thunk_FUN_140016b3a(SVar76,pvVar7);
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b0db;
        FUN_14008b695(((fd_set *)puVar223)->fd_array + 0x3a,
                      (longlong *)(((fd_set *)puVar223)->fd_array + 0x24));
        if (*(char *)((longlong)((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x19c) == '\0')
        {
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[8] =
               (SOCKET)(((fd_set *)puVar223)->fd_array + 0x3a);
          ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[9] = (SOCKET)&LAB_140064a76;
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b122;
          FUN_1400811fe(((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7,
                        (ushort *)&DAT_140108640,
                        (ulonglong)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8));
        }
        else {
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] = 0;
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[8] = 1;
          ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[9] = 0;
        }
        SVar76 = ((fd_set *)puVar223)->fd_array[0x3a];
        pvVar7 = (LPVOID)((fd_set *)puVar223)->fd_array[0x3b];
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b138;
        thunk_FUN_140016b3a(SVar76,pvVar7);
      }
      SVar76 = ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0];
      ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[9] = SVar76;
      ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[10] = SVar236;
      ((fd_set *)puVar223)->fd_array[0x24] = SVar76;
      ((fd_set *)puVar223)->fd_array[0x25] = SVar236;
      pSVar163 = ((fd_set *)puVar223)->fd_array + 0x3a;
      *pSVar163 = (SOCKET)(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 9);
      ((fd_set *)puVar223)->fd_array[0x3b] = (SOCKET)&LAB_1400298e7;
      puVar91 = (undefined1 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0x9e);
      ((fd_set *)puVar223)->fd_array[0x3c] = (SOCKET)puVar91;
      ((fd_set *)puVar223)->fd_array[0x3d] = (SOCKET)switchD_14007fe5b::caseD_4000b3e0;
      ((fd_set *)puVar223)->fd_array[0x3e] = (SOCKET)(((fd_set *)puVar223)->fd_array + 0x24);
      ((fd_set *)puVar223)->fd_array[0x3f] = (SOCKET)&LAB_1400298e7;
      *(undefined1 **)((longlong)puVar223 + 0x208) = puVar91;
      ((fd_set *)((longlong)puVar223 + 0x208))->fd_array[0] =
           (SOCKET)switchD_14007fe5b::caseD_4000b3e0;
      ((fd_set *)((longlong)puVar223 + 0x208))->fd_array[1] =
           (SOCKET)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x3b);
      ((fd_set *)((longlong)puVar223 + 0x208))->fd_array[2] = (SOCKET)&LAB_1400298e7;
      ((fd_set *)((longlong)puVar223 + 0x208))->fd_array[3] =
           (SOCKET)(((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7);
      ((fd_set *)((longlong)puVar223 + 0x208))->fd_array[4] = (SOCKET)&LAB_140064a76;
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b1e5;
      FUN_1400811fe(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8,(ushort *)&DAT_140108661,
                    (ulonglong)pSVar163);
      SVar76 = ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7];
      pvVar7 = (LPVOID)((fd_set *)((longlong)puVar223 + 0x410))->fd_array[8];
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b1f8;
      thunk_FUN_140016b3a(SVar76,pvVar7);
      *pSVar163 = (SOCKET)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8);
      ((fd_set *)puVar223)->fd_array[0x3b] = (SOCKET)&LAB_140064a76;
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b219;
      uVar81 = FUN_14007f9b0(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xd,
                             (ushort *)&DAT_14010b399,
                             (ulonglong)(((fd_set *)puVar223)->fd_array + 0x3a));
      if (uVar81 != 0) {
        ((fd_set *)((longlong)puVar223 + 0x410))->fd_array[7] = uVar81;
        *(undefined **)((longlong)puVar114 + 0x20) = &DAT_1401087d8;
        *(undefined8 *)((longlong)puVar114 + -8) = 0x2b;
        uVar241 = *(undefined8 *)((longlong)puVar114 + -8);
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b5a9;
        FUN_1400c3e10("called `Result::unwrap()` on an `Err` value",uVar241,
                      ((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7,&PTR_FUN_1400f8460,
                      *(undefined8 *)((longlong)puVar114 + 0x20));
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)invalidInstructionException();
        (*UNRECOVERED_JUMPTABLE)();
      }
      SVar76 = ((fd_set *)((longlong)puVar223 + 0x618))->fd_array[8];
      pvVar7 = (LPVOID)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[9];
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b235;
      thunk_FUN_140016b3a(SVar76,pvVar7);
      SVar76 = ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xd];
      pSVar163 = ((fd_set *)puVar223)->fd_array + 0x3a;
      for (lVar96 = 0x274; lVar96 != 0; lVar96 = lVar96 + -1) {
        *(undefined1 *)pSVar163 = 0;
        pSVar163 = (SOCKET *)((longlong)pSVar163 + 1);
      }
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b255;
      DVar67 = GetCurrentProcessId();
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b263;
      iVar66 = WSADuplicateSocketW(SVar76,DVar67,((fd_set *)puVar223)->fd_array + 0x3a);
      if (iVar66 == -1) {
LAB_14008b492:
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b498;
        uVar69 = WSAGetLastError();
        uVar81 = (ulonglong)uVar69;
LAB_14008b49a:
        puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b4b1;
        FUN_1400884b6(puVar92,uVar81 << 0x20 | 2);
LAB_14008b4cf:
        param_2 = (undefined **)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x12];
      }
      else {
        uVar244 = *(undefined4 *)
                   ((longlong)((fd_set *)((longlong)puVar223 + 0x208))->fd_array + 0x14);
        uVar81 = (ulonglong)(uint)((fd_set *)((longlong)puVar223 + 0x208))->fd_array[4];
        uVar245 = *(undefined4 *)
                   ((longlong)((fd_set *)((longlong)puVar223 + 0x208))->fd_array + 0x24);
        *(undefined4 *)((longlong)puVar114 + 0x28) = 0x81;
        *(undefined4 *)((longlong)puVar114 + 0x20) = 0;
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b292;
        hObject = (HANDLE)WSASocketW(uVar244,uVar81,uVar245);
        if (hObject == (HANDLE)0xffffffffffffffff) {
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b429;
          uVar69 = WSAGetLastError();
          if ((uVar69 == 0x2739) || (uVar81 = (ulonglong)uVar69, uVar69 == 0x2726)) {
            uVar244 = *(undefined4 *)
                       ((longlong)((fd_set *)((longlong)puVar223 + 0x208))->fd_array + 0x14);
            SVar76 = ((fd_set *)((longlong)puVar223 + 0x208))->fd_array[4];
            *(undefined4 *)((longlong)puVar114 + 0x28) = 1;
            *(undefined4 *)((longlong)puVar114 + 0x20) = 0;
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b45f;
            hObject = (HANDLE)WSASocketW(uVar244,(int)SVar76);
            if (hObject == (HANDLE)0xffffffffffffffff) goto LAB_14008b492;
            *(undefined8 *)((longlong)puVar114 + -8) = 1;
            uVar81 = *(ulonglong *)((longlong)puVar114 + -8);
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b477;
            BVar68 = SetHandleInformation(hObject,(DWORD)uVar81,0);
            if (BVar68 != 0) goto LAB_14008b29f;
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b485;
            DVar67 = GetLastError();
            uVar81 = (ulonglong)DVar67;
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b490;
            closesocket((SOCKET)hObject);
          }
          goto LAB_14008b49a;
        }
LAB_14008b29f:
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b2a7;
        pvVar75 = (void *)FUN_140080372(SVar82 + 0x18);
        *(undefined2 *)((longlong)puVar114 + 0x28) =
             *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xb6);
        *(SOCKET *)((longlong)puVar114 + 0x20) = SVar236;
        pvVar74 = (void *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0];
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b2d4;
        FUN_14008a246(((fd_set *)puVar223)->fd_array + 0x13,pvVar75,uVar81,pvVar74,
                      *(ulonglong *)((longlong)puVar114 + 0x20),
                      *(undefined2 *)((longlong)puVar114 + 0x28));
        plVar100 = (longlong *)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x3a];
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b2e0;
        SVar76 = FUN_14008a299(plVar100);
        ((fd_set *)puVar223)->fd_array[0x12] = SVar76;
        *(ushort *)(((fd_set *)puVar223)->fd_array + 0x3a) = uVar65;
        *(SOCKET *)((longlong)((fd_set *)puVar223)->fd_array + 0x1d2) =
             ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xb];
        *(short *)((longlong)((fd_set *)puVar223)->fd_array + 0x1da) =
             (short)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xc];
        *(SOCKET *)((longlong)((fd_set *)puVar223)->fd_array + 0x1dc) =
             ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xf];
        *(int *)((longlong)((fd_set *)puVar223)->fd_array + 0x1e4) =
             (int)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x16];
        *(undefined4 *)(((fd_set *)puVar223)->fd_array + 0x3d) =
             *(undefined4 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xac);
        *(undefined2 *)((longlong)((fd_set *)puVar223)->fd_array + 0x1ec) =
             *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc4);
        *(undefined2 *)((longlong)((fd_set *)puVar223)->fd_array + 0x1ee) =
             *(undefined2 *)((longlong)((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xc2);
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b353;
        FUN_14008b5e6((undefined1 *)(((fd_set *)((longlong)puVar223 + -0x208))->fd_array + 0x36),
                      hObject,((fd_set *)puVar223)->fd_array + 0x3a,
                      (undefined1 *)(((fd_set *)puVar223)->fd_array + 0x12));
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b365;
        FUN_1400884f7(((fd_set *)puVar223)->fd_array + 0x24,SVar82);
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b37a;
        FUN_140088644((undefined1 (*) [16])(((fd_set *)puVar223)->fd_array + 0x3a),
                      ((fd_set *)((longlong)puVar223 + -0x208))->fd_array + 0x36,
                      (longlong *)(((fd_set *)puVar223)->fd_array + 0x24));
        SVar82 = ((fd_set *)puVar223)->fd_array[0x3a];
        pSVar163 = ((fd_set *)puVar223)->fd_array + 0x3b;
        pSVar196 = ((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7;
        for (lVar96 = 0x108; lVar96 != 0; lVar96 = lVar96 + -1) {
          *(char *)pSVar196 = (char)*pSVar163;
          pSVar163 = (SOCKET *)((longlong)pSVar163 + 1);
          pSVar196 = (SOCKET *)((longlong)pSVar196 + 1);
        }
        if (SVar82 != 0x8000000000000001) {
          pSVar163 = (SOCKET *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
          pSVar196 = ((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7;
          pSVar228 = pSVar163 + 1;
          for (lVar96 = 0x108; lVar96 != 0; lVar96 = lVar96 + -1) {
            *(char *)pSVar228 = (char)*pSVar196;
            pSVar196 = (SOCKET *)((longlong)pSVar196 + 1);
            pSVar228 = (SOCKET *)((longlong)pSVar228 + 1);
          }
          *pSVar163 = SVar82;
          goto LAB_14008b4cf;
        }
        pSVar163 = ((fd_set *)((longlong)puVar223 + 0x410))->fd_array + 7;
        pSVar196 = ((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8;
        for (lVar96 = 0x108; lVar96 != 0; lVar96 = lVar96 + -1) {
          *(char *)pSVar196 = (char)*pSVar163;
          pSVar163 = (SOCKET *)((longlong)pSVar163 + 1);
          pSVar196 = (SOCKET *)((longlong)pSVar196 + 1);
        }
        sVar6 = (short)((fd_set *)((longlong)puVar223 + 0x618))->fd_array[0x28];
        if (sVar6 == 200) {
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b4e7;
          FUN_1400805ef((longlong *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8));
          pfVar233 = (fd_set *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xd];
          goto LAB_14008b4ee;
        }
        param_2 = (undefined **)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x12];
        if ((sVar6 == 0x197) || (uVar63 = 10, sVar6 == 0x191)) {
          uVar63 = 0xb;
        }
        puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
        *puVar92 = 0x8000000000000000;
        puVar92[1] = 0x8000000000000000;
        puVar92[4] = 0x8000000000000000;
        puVar92[0xf] = 0;
        *(undefined1 *)(puVar92 + 0x11) = uVar63;
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008b41e;
        FUN_1400805ef((longlong *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 8));
      }
    }
    else {
      uVar81 = *(ulonglong *)(SVar82 + 0x88);
      pSVar163 = ((fd_set *)puVar223)->fd_array + 0x3a;
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ae12;
      FUN_1400764a2(pSVar163,uVar81,iVar66);
      uVar69 = (uint)((fd_set *)puVar223)->fd_array[0x3b];
      ppuVar73 = (undefined **)*pSVar163;
      if (uVar69 == 1000000000) {
LAB_14008ae22:
        puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
      }
      else {
        *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ae33;
        ppuVar73 = FUN_140072280((SOCKET)pfVar233,(ulonglong)ppuVar73,uVar69);
        if (ppuVar73 == (undefined **)0x0) {
          *(undefined8 *)((longlong)puVar114 + -8) = 0x14008aeaa;
          FUN_1400764a2(pSVar163,uVar81,iVar66);
          uVar69 = (uint)((fd_set *)puVar223)->fd_array[0x3b];
          ppuVar73 = (undefined **)*pSVar163;
          if (uVar69 != 1000000000) {
            *(undefined8 *)((longlong)puVar114 + -8) = 0x14008aec6;
            ppuVar231 = FUN_140072330((SOCKET)pfVar233,(ulonglong)ppuVar73,uVar69);
            SVar236 = *(SOCKET *)((longlong)puVar223 + 0x820);
            if (ppuVar231 == (undefined **)0x0) goto LAB_14008aed9;
            goto LAB_14008ada4;
          }
          goto LAB_14008ae22;
        }
        puVar92 = (undefined8 *)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0x17];
      }
      *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ae47;
      FUN_1400884b6(puVar92,(ulonglong)ppuVar73);
    }
  }
  SVar82 = ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[0xd];
  *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ae57;
  closesocket(SVar82);
LAB_14008ae57:
  if ((fd_set *)param_2 != (fd_set *)0x0) {
    *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ae68;
    FUN_1400759ea(((fd_set *)((longlong)puVar223 + 0x820))->fd_array + 0xe);
  }
LAB_14008ae68:
  SVar82 = ((fd_set *)((longlong)puVar223 + 0x820))->fd_array[1];
  pvVar7 = (LPVOID)((fd_set *)((longlong)puVar223 + 0x820))->fd_array[2];
  *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ae7b;
  thunk_FUN_140016b3a(SVar82,pvVar7);
  *(undefined8 *)((longlong)puVar114 + -8) = 0x14008ae87;
  pfVar84 = (fd_set *)
            FUN_14007619f((longlong *)(((fd_set *)((longlong)puVar223 + 0x618))->fd_array + 0x2a));
  return pfVar84;
code_r0x000140096946:
  param_3->fd_count = param_3->fd_count - 1;
  _Src = (uint *)CONCAT62((int6)((ulonglong)pcVar103 >> 0x10),CONCAT11(0x56,(char)pcVar103));
  *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
       (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
  cRam0000000188096958 = cRam0000000188096958 + (char)UNRECOVERED_JUMPTABLE;
  pfVar168 = (fd_set *)puVar181;
  puVar225 = (uint *)pcVar83;
switchD_14007f7e4_caseD_b7:
  pfVar233 = pfVar168;
  if ((fd_set *)UNRECOVERED_JUMPTABLE != (fd_set *)0x0) {
switchD_14009313c_caseD_94:
    _Dst = (uint *)(ulonglong)(byte)((fd_set *)puVar225)->field_0x4;
    puVar182 = (undefined1 *)pfVar168;
code_r0x000140096964:
    pcVar103 = (char *)(ulonglong)(uint)((int)_Src << 8 | (int)UNRECOVERED_JUMPTABLE << 0x10);
    puVar19 = (undefined8 *)puVar182;
code_r0x00014009696c:
    pfVar168 = (fd_set *)puVar19;
    _Src = (uint *)((ulonglong)pcVar103 | (ulonglong)_Dst);
switchD_14009313c_caseD_a7:
    pcVar103 = (char *)_Src;
    goto LAB_140096a37;
  }
switchD_1400968c1_default:
  *(fd_set **)((longlong)pfVar233 + 0x2e8) = pfVar227;
  *(undefined1 *)((longlong)pfVar233 + 0x2f0) = 0;
  *(undefined2 *)((longlong)pfVar233 + 0x2f5) = 0;
  *(undefined1 *)((longlong)pfVar233 + 0x2f7) = 0;
  *(undefined4 *)((longlong)pfVar233 + 0x2f1) = 0;
  pfVar168 = pfVar233;
LAB_140095c58:
  pfVar233 = *(fd_set **)((longlong)pfVar168 + 0x360);
  puVar223 = *(uint **)((longlong)pfVar168 + 0x368);
switchD_14009313c_caseD_73:
  *(undefined8 *)((longlong)pfVar168 + 0x50) = *(undefined8 *)((longlong)pfVar168 + 0x370);
  pfVar84 = *(fd_set **)((longlong)pfVar168 + 0x378);
  param_3 = *(fd_set **)((longlong)pfVar168 + 0x380);
  *(undefined1 *)((longlong)pfVar168 + 0x90) = *(undefined1 *)((longlong)pfVar168 + 0x388);
  *(undefined4 *)((longlong)pfVar168 + 0xa0) = *(undefined4 *)((longlong)pfVar168 + 0x389);
  *(undefined4 *)((longlong)pfVar168 + 0xa3) = *(undefined4 *)((longlong)pfVar168 + 0x38c);
  *(undefined8 *)((longlong)pfVar168 + 0x68) = *(undefined8 *)((longlong)pfVar168 + 0x390);
LAB_140095cbc:
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x140095cc9;
  FUN_14009487a((ulonglong *)((longlong)pfVar168 + 0x2e8));
  *(undefined8 *)((longlong)pfVar168 + -8) = 0x140095cd6;
  FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x4f8));
  pcVar83 = (char *)((longlong)pfVar227->fd_array + 0x2a);
  puVar167 = (undefined8 *)pfVar168;
  if (pfVar233 == (fd_set *)pcVar83) {
code_r0x000140095ce3:
    if (*(longlong *)((longlong)puVar167 + 0xd8) == *(longlong *)((longlong)puVar167 + 0xd0)) {
      *(undefined8 *)((longlong)puVar167 + -8) = 0x140095d06;
      FUN_14009350d((ulonglong *)((longlong)puVar167 + 0x398));
      pfVar168 = (fd_set *)puVar167;
      pfVar233 = (fd_set *)pcVar83;
    }
    else {
LAB_14009620e:
      puVar223 = *(uint **)((longlong)puVar167 + 0x3a0);
      *(undefined4 *)((longlong)puVar167 + 0x80) = *(undefined4 *)((longlong)puVar167 + 0x3c1);
      *(undefined4 *)((longlong)puVar167 + 0x83) = *(undefined4 *)((longlong)puVar167 + 0x3c4);
      pfVar233 = (fd_set *)((longlong)pfVar227->fd_array + 0x16);
      pfVar168 = (fd_set *)puVar167;
    }
  }
  else {
    *(undefined4 *)((longlong)pfVar168 + 0x83) = *(undefined4 *)((longlong)pfVar168 + 0xa3);
    *(undefined4 *)((longlong)pfVar168 + 0x80) = *(undefined4 *)((longlong)pfVar168 + 0xa0);
    *(undefined8 *)((longlong)pfVar168 + -8) = 0x140095f16;
    FUN_14009350d((ulonglong *)((longlong)pfVar168 + 0x398));
  }
LAB_140096236:
  SVar82 = *(SOCKET *)((longlong)pfVar168 + 0x58);
  pSVar163 = (SOCKET *)pfVar168;
LAB_14009608e:
  *(undefined8 *)((longlong)pSVar163 + -8) = 0x14009609b;
  uVar241 = FUN_14009487a((ulonglong *)((longlong)pSVar163 + 0x3d0));
  if (pfVar233 == (fd_set *)((longlong)pfVar227->fd_array + 0x2a)) {
    pfVar233 = *(fd_set **)((longlong)pSVar163 + 0x200);
    pcVar83 = *(char **)((longlong)pSVar163 + 0x208);
    param_4 = *(fd_set **)((longlong)pSVar163 + 0x210);
    puVar223 = *(uint **)((longlong)pSVar163 + 0x218);
    *(ulonglong *)((longlong)pSVar163 + 0x70) =
         CONCAT71((int7)((ulonglong)uVar241 >> 8),*(undefined1 *)((longlong)pSVar163 + 0x220));
    in_R10 = *(fd_set **)((longlong)pSVar163 + 0x228);
    puVar156 = pSVar163;
LAB_1400960d8:
    *(undefined4 *)((longlong)puVar156 + 0x2b) = *(undefined4 *)((longlong)puVar156 + 0x224);
    *(undefined4 *)((longlong)puVar156 + 0x28) = *(undefined4 *)((longlong)puVar156 + 0x221);
    puVar91 = (undefined1 *)((longlong)puVar156 + 0x230);
    puVar119 = (undefined1 *)((longlong)puVar156 + 0x440);
    for (lVar96 = 0xb8; lVar96 != 0; lVar96 = lVar96 + -1) {
      *puVar119 = *puVar91;
      puVar91 = puVar91 + 1;
      puVar119 = puVar119 + 1;
    }
    *(undefined4 *)((longlong)puVar156 + 0x78) = *(undefined4 *)((longlong)puVar156 + 0x28);
    *(undefined4 *)((longlong)puVar156 + 0x7b) = *(undefined4 *)((longlong)puVar156 + 0x2b);
    puVar91 = (undefined1 *)((longlong)puVar156 + 0x440);
    puVar119 = (undefined1 *)((longlong)puVar156 + 0x530);
    for (lVar96 = 0xb8; lVar96 != 0; lVar96 = lVar96 + -1) {
      *puVar119 = *puVar91;
      puVar91 = puVar91 + 1;
      puVar119 = puVar119 + 1;
    }
    *(undefined4 *)((longlong)puVar156 + 0x158) = *(undefined4 *)((longlong)puVar156 + 0x78);
    *(undefined4 *)((longlong)puVar156 + 0x15b) = *(undefined4 *)((longlong)puVar156 + 0x7b);
    if (*(longlong *)((longlong)puVar156 + 0x40) != *(longlong *)((longlong)puVar156 + 0x38)) {
      ((fd_set *)param_2)->fd_array[6] = *(SOCKET *)((longlong)puVar156 + 0x438);
      SVar76 = *(SOCKET *)((longlong)puVar156 + 0x408);
      SVar236 = *(SOCKET *)((longlong)puVar156 + 0x410);
      SVar8 = *(SOCKET *)((longlong)puVar156 + 0x418);
      SVar11 = *(SOCKET *)((longlong)puVar156 + 0x420);
      SVar12 = *(SOCKET *)((longlong)puVar156 + 0x430);
      ((fd_set *)param_2)->fd_array[4] = *(SOCKET *)((longlong)puVar156 + 0x428);
      ((fd_set *)param_2)->fd_array[5] = SVar12;
      ((fd_set *)param_2)->fd_array[2] = SVar8;
      ((fd_set *)param_2)->fd_array[3] = SVar11;
      ((fd_set *)param_2)->fd_array[0] = SVar76;
      ((fd_set *)param_2)->fd_array[1] = SVar236;
      *param_2 = (undefined1 *)((longlong)&pfVar227->fd_count + 1);
      *(undefined8 *)((longlong)puVar156 + -8) = 0x1400961d8;
      pfVar84 = (fd_set *)FUN_1400386fd((longlong)pfVar227,SVar82);
      return pfVar84;
    }
    *param_2 = (undefined *)pfVar227;
    ((fd_set *)param_2)->fd_array[0] = SVar82;
    ((fd_set *)param_2)->fd_array[1] = (SOCKET)pfVar233;
    ((fd_set *)param_2)->fd_array[2] = (SOCKET)pcVar83;
    ((fd_set *)param_2)->fd_array[3] = (SOCKET)param_4;
    ((fd_set *)param_2)->fd_array[4] = (SOCKET)puVar223;
    *(char *)(((fd_set *)param_2)->fd_array + 5) = (char)*(undefined8 *)((longlong)puVar156 + 0x70);
    uVar244 = *(undefined4 *)((longlong)puVar156 + 0x15b);
    *(undefined4 *)((longlong)((fd_set *)param_2)->fd_array + 0x29) =
         *(undefined4 *)((longlong)puVar156 + 0x158);
    *(undefined4 *)((longlong)((fd_set *)param_2)->fd_array + 0x2c) = uVar244;
    ((fd_set *)param_2)->fd_array[6] = (SOCKET)in_R10;
    param_2 = (undefined **)(((fd_set *)param_2)->fd_array + 7);
    pcVar83 = (char *)((longlong)puVar156 + 0x530);
    _Dst = (uint *)0xb8;
    pfVar107 = (fd_set *)puVar156;
code_r0x00014009618f:
    for (; (fd_set *)_Dst != (fd_set *)0x0;
        _Dst = (uint *)((longlong)((fd_set *)((longlong)_Dst + -0x208))->fd_array + 0x1ff)) {
      *(char *)&((fd_set *)param_2)->fd_count = (char)((fd_set *)pcVar83)->fd_count;
      pcVar83 = (char *)((longlong)&((fd_set *)pcVar83)->fd_count + 1);
      param_2 = (undefined **)((longlong)&((fd_set *)param_2)->fd_count + 1);
    }
  }
  else {
    *(undefined4 *)((longlong)pSVar163 + 0x2b) = *(undefined4 *)((longlong)pSVar163 + 0x83);
    *(undefined4 *)((longlong)pSVar163 + 0x28) = *(undefined4 *)((longlong)pSVar163 + 0x80);
    *(undefined8 *)((longlong)pSVar163 + -8) = 0x1400961fe;
    FUN_1400386fd((longlong)pfVar227,SVar82);
    _Src = *(uint **)((longlong)pSVar163 + 0x50);
    param_1 = pfVar233;
LAB_1400953cf:
    pvVar74 = *(void **)((longlong)pSVar163 + 0x68);
    uVar63 = *(undefined1 *)((longlong)pSVar163 + 0x90);
    pfVar107 = (fd_set *)pSVar163;
    _Dst = puVar223;
LAB_14009556b:
    *(undefined4 *)((longlong)pfVar107 + 0x7b) = *(undefined4 *)((longlong)pfVar107 + 0x2b);
    *(undefined4 *)((longlong)pfVar107 + 0x78) = *(undefined4 *)((longlong)pfVar107 + 0x28);
    ((fd_set *)param_2)->fd_array[3] = (SOCKET)pfVar84;
    ((fd_set *)param_2)->fd_array[4] = (SOCKET)param_3;
    *(undefined1 *)(((fd_set *)param_2)->fd_array + 5) = uVar63;
    uVar244 = *(undefined4 *)((longlong)pfVar107 + 0x7b);
    *(undefined4 *)((longlong)((fd_set *)param_2)->fd_array + 0x29) =
         *(undefined4 *)((longlong)pfVar107 + 0x78);
    *(undefined4 *)((longlong)((fd_set *)param_2)->fd_array + 0x2c) = uVar244;
    ((fd_set *)param_2)->fd_array[6] = (SOCKET)pvVar74;
    ((fd_set *)param_2)->fd_array[0] = (SOCKET)param_1;
    ((fd_set *)param_2)->fd_array[1] = (SOCKET)_Dst;
    ((fd_set *)param_2)->fd_array[2] = (SOCKET)_Src;
    *param_2 = (undefined1 *)((longlong)&pfVar227->fd_count + 1);
  }
  *(undefined8 *)((longlong)pfVar107 + -8) = 0x1400955b8;
  pfVar84 = (fd_set *)FUN_14009350d((ulonglong *)((longlong)pfVar107 + 0x408));
  return pfVar84;
code_r0x0001400969ec:
  *(byte *)&((fd_set *)_Dst)->fd_count = (byte)((fd_set *)_Dst)->fd_count | (byte)_Dst;
  return (fd_set *)UNRECOVERED_JUMPTABLE;
code_r0x0001400969ce:
  *(char *)&((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count =
       (char)((fd_set *)UNRECOVERED_JUMPTABLE)->fd_count + (char)UNRECOVERED_JUMPTABLE;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
code_r0x0001400975a0:
LAB_140097b64:
                    /* WARNING: Could not recover jumptable at 0x000140097b68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pfVar84 = (fd_set *)(*UNRECOVERED_JUMPTABLE)();
  return pfVar84;
code_r0x000140096b09:
  puVar225 = (uint *)pcVar83;
switchD_14007f6e5_caseD_c6:
  *(undefined8 *)((longlong)pfVar195 + -8) = 0x140096b0f;
  FUN_14009708b((undefined8 *)puVar97,(longlong)_Src);
  UNRECOVERED_JUMPTABLE = (code *)0x800000000000002f;
LAB_140096ea4:
  *(code **)puVar225 = UNRECOVERED_JUMPTABLE;
  return (fd_set *)UNRECOVERED_JUMPTABLE;
code_r0x00014009705b:
  pvVar74 = (void *)((fd_set *)_Src)->fd_array[0];
  uVar81 = ((fd_set *)_Src)->fd_array[1];
  *(undefined8 *)((ulonglong)((int)puVar197 - 0x28) - 8) = 0x140097071;
  FUN_140029ca0((undefined8 *)_Dst,pvVar74,uVar81);
  pfVar84 = (fd_set *)
            FUN_1400970be(((fd_set *)_Dst)->fd_array + 2,(void *)((fd_set *)_Src)->fd_array[3],
                          ((fd_set *)_Src)->fd_array[4]);
  return pfVar84;
LAB_140094841:
  puVar223 = (uint *)0x1;
code_r0x000140094844:
LAB_14009485f:
  return (fd_set *)((ulonglong)puVar223 & 0xffffffff);
}


// ==== FUN_140010c55 size=56

void FUN_140010c55(longlong *param_1,longlong param_2,ulonglong param_3,ulonglong param_4,
                  undefined8 param_5)

{
  code *pcVar1;
  
  if (param_4 <= param_3) {
    *param_1 = param_2;
    param_1[1] = param_4;
    param_1[2] = param_2 + param_4;
    param_1[3] = param_3 - param_4;
    return;
  }
  FUN_1400c3bc0("mid > len",0x13,param_5);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


