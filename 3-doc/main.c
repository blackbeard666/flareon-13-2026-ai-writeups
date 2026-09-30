// ==== FUN_100035510 size=800

/* WARNING: Removing unreachable block (ram,0x000100035744) */
/* WARNING: Removing unreachable block (ram,0x00010003574c) */
/* WARNING: Removing unreachable block (ram,0x000100035760) */
/* WARNING: Removing unreachable block (ram,0x000100035780) */
/* WARNING: Removing unreachable block (ram,0x000100035794) */

undefined8 FUN_100035510(undefined4 param_1,undefined8 param_2)

{
  long *plVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  void *pvVar8;
  long lVar9;
  code *pcVar10;
  sigaction local_70;
  
  local_70.__sigaction_u.__sa_handler = FUN_1000358d8;
  local_70._8_8_ = DAT_100037500;
  _sigemptyset(&local_70.sa_mask);
  _sigaction(0x19,&local_70,(sigaction *)0x0);
  local_70.__sigaction_u.__sa_handler = FUN_10003591c;
  local_70.sa_mask = 0;
  local_70.sa_flags = 0;
  _sigemptyset(&local_70.sa_mask);
  _sigaction(0x18,&local_70,(sigaction *)0x0);
  puVar6 = _calloc(1,0x20);
  uVar7 = FUN_1000066ac();
  *(undefined8 *)(puVar6 + 6) = uVar7;
  *puVar6 = 0x81;
  DAT_100058028 = puVar6;
  puVar6 = _calloc(1,0x20);
  uVar7 = FUN_1000066ac();
  *(undefined8 *)(puVar6 + 6) = uVar7;
  *puVar6 = 0x80;
  DAT_100058090 = 0;
  DAT_100058098 = 0;
  DAT_100058020 = puVar6;
  FUN_100000750(param_1,param_2);
  if (DAT_100058178 != 0) {
    while( true ) {
      lVar4 = DAT_100058208;
      iVar5 = _pthread_mutex_lock((pthread_mutex_t *)(DAT_100058208 + 8));
      lVar3 = DAT_100058178;
      if (iVar5 != 0) {
        FUN_100005464(&DAT_100038580);
                    /* WARNING: Subroutine does not return */
        FUN_100005798();
      }
      if ((DAT_100058178 == 0) || (iVar5 = *(int *)(DAT_100058178 + 4), iVar5 == 0)) {
        pcVar10 = (code *)0x0;
        lVar9 = 0;
      }
      else {
        if (SBORROW4(iVar5,1)) {
                    /* WARNING: Subroutine does not return */
          FUN_100003b88();
        }
        plVar1 = (long *)(DAT_100058178 + 0x10);
        *(int *)(DAT_100058178 + 4) = iVar5 + -1;
        puVar2 = (undefined8 *)(*plVar1 + (long)(iVar5 + -1) * 0x10);
        pcVar10 = (code *)*puVar2;
        lVar9 = puVar2[1];
        *puVar2 = 0;
        puVar2[1] = 0;
        if ((*(int *)(lVar3 + 4) == 0) && (iVar5 = *(int *)(lVar3 + 0xc), iVar5 != 0)) {
          *(undefined4 *)(lVar3 + 0xc) = 0;
          *(long *)(lVar3 + 0x10) = *(long *)(lVar3 + 0x10) + (long)iVar5 * -0x10;
        }
      }
      iVar5 = _pthread_mutex_unlock((pthread_mutex_t *)(lVar4 + 8));
      if (iVar5 != 0) {
        FUN_100005464(&DAT_100038650);
                    /* WARNING: Subroutine does not return */
        FUN_100005798();
      }
      if (pcVar10 == (code *)0x0) break;
      if (lVar9 == 0) {
        (*pcVar10)(0,0);
      }
      else {
        (*pcVar10)(lVar9,0,0);
      }
    }
  }
  lVar3 = DAT_100058218;
  iVar5 = *(int *)(DAT_100058218 + 0x68);
  if (0 < iVar5) {
    pvVar8 = *(void **)(DAT_100058218 + 0x50);
    if (pvVar8 == (void *)0x0) {
      if ((int)*(uint *)(DAT_100058218 + 0x70) < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100003b88();
      }
      pvVar8 = _malloc((ulong)*(uint *)(DAT_100058218 + 0x70));
      *(void **)(lVar3 + 0x50) = pvVar8;
    }
    FUN_1000261d8(lVar3,iVar5,0,pvVar8);
  }
  *(undefined4 *)(lVar3 + 0x68) = 0;
  if ((DAT_10005818a & 1) == 0) {
    FUN_100034520(&DAT_10005818a,FUN_100025d90);
  }
  lVar3 = DAT_1000581f0;
  iVar5 = *(int *)(DAT_1000581f0 + 0x68);
  if (0 < iVar5) {
    pvVar8 = *(void **)(DAT_1000581f0 + 0x50);
    if (pvVar8 == (void *)0x0) {
      if ((int)*(uint *)(DAT_1000581f0 + 0x70) < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100003b88();
      }
      pvVar8 = _malloc((ulong)*(uint *)(DAT_1000581f0 + 0x70));
      *(void **)(lVar3 + 0x50) = pvVar8;
    }
    FUN_1000261d8(lVar3,iVar5,0,pvVar8);
  }
  *(undefined4 *)(lVar3 + 0x68) = 0;
  return 0;
}


