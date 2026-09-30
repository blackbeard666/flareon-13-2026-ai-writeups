// ref to "Usage: cpuminer-multi [OPTIONS]
Options:
  -a, --algo=ALGO       specify the algorithm to use
                          allium       Garlicoin double lyra2
                          axiom        Shabal-256 MemoHash
                          bitcore      Timetravel with 10 algos
                          blake        Blake-256 14-rounds (SFR)
                          blakecoin    Blake-256 single sha256 merkle
                          blake2b      Blake2-B (512)
                          blake2s      Blake2-S (256)
                          bmw          BMW 256
                          c11/flax     C11
                          cryptolight  Cryptonight-light
                          cryptonight  Monero
                          decred       Blake-256 14-rounds 180 bytes
                          dmd-gr       Diamond-Groestl
                          drop         Dropcoin
                          fresh        Fresh
                          geek         GeekCash
                          groestl      GroestlCoin
                          heavy        Heavy
                          jha          JHA
                          keccak       Keccak (Old and deprecated)
                          keccakc      Keccak (CreativeCoin)
                          luffa        Luffa
                          lyra2re      Lyra2RE
                          lyra2rev2    Lyra2REv2
                          lyra2v3      Lyra2REv3 (Vertcoin)
                          myr-gr       Myriad-Groestl
                          neoscrypt    NeoScrypt(128, 2, 1)
                          nist5        Nist5
                          pluck        Pluck:128 (Supcoin)
                          pentablake   Pentablake
                          phi          LUX initial algo
                          phi2         LUX newer algo
                          quark        Quark
                          qubit        Qubit
                          rainforest   RainForest (256)
                          scrypt       scrypt(1024, 1, 1) (default)
                          scrypt:N     scrypt(N, 1, 1)
                          scrypt-jane:N (with N factor from 4 to 30)
                          shavite3     Shavite3
                          sha256d      SHA-256d
                          sia          Blake2-B
                          sib          X11 + gost (SibCoin)
                          skein        Skein+Sha (Skeincoin)
                          skein2       Double Skein (Woodcoin)
                          sonoa        A series of 97 hashes from x17
                          s3           S3
                          timetravel   Timetravel (Machinecoin)
                          vanilla      Blake-256 8-rounds
                          x11evo       Permuted x11
                          x11          X11
                          x12          X12
                          x13          X13
                          x14          X14
                          x15          X15
                          x16r         X16R
                          x16rv2       X16Rv2 (Raven / Trivechain)
                          x16s         X16S (Pigeon)
                          x17          X17
                          x20r         X20R
                          xevan        Xevan (BitSend)
                          yescrypt     Yescrypt
                          yescryptr8   Yescrypt r8
                          yescryptr16  Yescrypt r16
                          yescryptr32  Yescrypt r32
                          zr5          ZR5
  -o, --url=URL         URL of mining server
  -O, --userpass=U:P    username:password pair for mining server
  -u, --user=USERNAME   username for mining server
  -p, --pass=PASSWORD   password for mining server
      --cert=FILE       certificate for mining server using SSL
  -x, --proxy=[PROTOCOL://]HOST[:PORT]  connect through a proxy
  -t, --threads=N       number of miner threads (default: number of processors)
  -r, --retries=N       number of times to retry if a network call fails
                          (default: retry indefinitely)
  -R, --retry-pause=N   time to pause between retries, in seconds (default: 30)
      --time-limit=N    maximum time [s] to mine before exiting the program.
  -T, --timeout=N       timeout for long poll and stratum (default: 300 seconds)
  -s, --scantime=N      upper bound on time spent scanning current work when
                          long polling is unavailable, in seconds (default: 5)
      --randomize       Randomize scan range start to reduce duplicates
  -f, --diff-factor     Divide req. difficulty by this factor (std is 1.0)
  -m, --diff-multiplier Multiply difficulty by this factor (std is 1.0)
  -n, --nfactor         neoscrypt N-Factor
      --coinbase-addr=ADDR  payout address for solo mining
      --coinbase-sig=TEXT  data to insert in the coinbase when possible
      --max-log-rate    limit per-core hashrate logs (default: 5s)
      --no-longpoll     disable long polling support
      --no-getwork      disable getwork support
      --no-gbt          disable getblocktemplate support
      --no-stratum      disable X-Stratum support
      --no-extranonce   disable Stratum extranonce support
      --no-redirect     ignore requests to change the URL of the mining server
  -q, --quiet           disable per-thread hashmeter output
      --no-color        disable colored output
  -D, --debug           enable debug output
  -P, --protocol-dump   verbose dump of protocol-level activities
      --hide-diff       Hide submitted block and net difficulty
  -B, --background      run the miner in the background
      --benchmark       run in offline benchmark mode
      --cputest         debug hashes from cpu algorithms
      --cpu-affinity    set process affinity to cpu core(s), mask 0x3 for cores 0 and 1
      --cpu-priority    set process priority (default: 0 idle, 2 normal to 5 highest)
  -b, --api-bind        IP/Port for the miner API (default: 127.0.0.1:4048)
      --api-remote      Allow remote control
      --max-temp=N      Only mine if cpu temp is less than specified value (linux)
      --max-rate=N[KMG] Only mine if net hashrate is less than specified value
      --max-diff=N      Only mine if net difficulty is less than specified value
  -c, --config=FILE     load a JSON-format configuration file
  -V, --version         display version information and exit
  -h, --help            display this help text and exit
" @1401b7db0 from 140103b47 in FUN_140103b20
// ==== FUN_140103b20 @ 140103b20

void FUN_140103b20(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    FUN_1400fe2f0(
                 "Usage: cpuminer-multi [OPTIONS]\nOptions:\n  -a, --algo=ALGO       specify the algorithm to use\n                          allium       Garlicoin double lyra2\n                          axiom        Shabal-256 MemoHash\n                          bitcore      Timetravel with 10 algos\n                          blake        Blake-256 14-rounds (SFR)\n                          blakecoin    Blake-256 single sha256 merkle\n                          blake2b      Blake2-B (512)\n                          blake2s      Blake2-S (256)\n                          bmw          BMW 256\n                          c11/flax     C11\n                          cryptolight  Cryptonight-light\n                          cryptonight  Monero\n                          decred       Blake-256 14-rounds 180 bytes\n                          dmd-gr       Diamond-Groestl\n                          drop         Dropcoin\n                          fresh        Fresh\n                          geek         GeekCash\n                          groestl      GroestlCoin\n                          heavy        Heavy\n                          jha          JHA\n                          keccak       Keccak (Old and deprecated)\n                          keccakc      Keccak (CreativeCoin)\n                          luffa        Luffa\n                          lyra2re      Lyra2RE\n                          lyra2rev2    Lyra2REv2\n                          lyra2v3      Lyra2REv3 (Vertcoin)\n                          myr-gr       Myriad-Groestl\n                          neoscrypt    NeoScrypt(128, 2, 1)\n                          nist5        Nist5\n                          pluck        Pluck:128 (Supcoin)\n                          pentablake   Pentablake\n                          phi          LUX initial algo\n                          phi2         LUX newer algo\n                          quark        Quark\n                          qubit        Qubit\n                          rainforest   RainForest (256)\n                          scrypt       scrypt(1024, 1, 1) (default)\n        ..." /* TRUNCATED STRING LITERAL */
                 );
  }
  else {
    uVar1 = __acrt_iob_func(2);
    FUN_1400fe2c0(uVar1,s_Try__cpuminer_multi___help__for_m_140442a48);
  }
                    /* WARNING: Subroutine does not return */
  exit(param_1);
}


// ref to "127.0.0.1" @1401b9d80 from 140106e9e in FUN_140106b70
// ==== FUN_140106b70 @ 140106b70

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140106b70(void)

{
  char cVar1;
  int iVar2;
  u_long uVar3;
  SOCKET *_Memory;
  SOCKET SVar4;
  int *piVar5;
  char *pcVar6;
  __time64_t _Var7;
  __time64_t _Var8;
  size_t sVar9;
  longlong lVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  undefined **ppuVar14;
  char *pcVar15;
  bool bVar16;
  undefined1 auStack_4198 [32];
  undefined *local_4178;
  int local_4168 [2];
  sockaddr local_4160;
  undefined1 local_4150 [24];
  char local_4138 [254];
  char acStack_403a [16386];
  ulonglong local_38;
  
  pcVar6 = DAT_140491be8;
  uVar13 = DAT_140441310;
  local_38 = DAT_1404455c0 ^ (ulonglong)auStack_4198;
  if ((DAT_140441310 == 0) && (DAT_140491aa4 != 0)) {
    FUN_140117b70(4,"API disabled");
  }
  else {
    if ((DAT_140491be8 != (char *)0x0) && (FUN_1401074a0(), DAT_140442fa0 == 0)) {
      FUN_140117b70(1,"API not running (no valid IPs specified)%s",
                    PTR_s___API_will_not_be_available_140442fb0);
    }
    _Memory = calloc(1,8);
    *_Memory = 0xffffffffffffffff;
    Sleep(1000);
    SVar4 = socket(2,1,0);
    *_Memory = SVar4;
    if (SVar4 == 0xffffffffffffffff) {
      piVar5 = _errno();
      pcVar6 = strerror(*piVar5);
      FUN_140117b70(0,"API initialisation failed (%s)%s",pcVar6,
                    PTR_s___API_will_not_be_available_140442fb0);
    }
    else {
      local_4160.sa_data[6] = '\0';
      local_4160.sa_data[7] = '\0';
      local_4160.sa_data[8] = '\0';
      local_4160.sa_data[9] = '\0';
      local_4160.sa_data[10] = '\0';
      local_4160.sa_data[0xb] = '\0';
      local_4160.sa_data[0xc] = '\0';
      local_4160.sa_data[0xd] = '\0';
      local_4160.sa_family = 2;
      local_4160.sa_data._2_4_ = inet_addr(pcVar6);
      if (local_4160.sa_data._2_4_ == 0xffffffff) {
        piVar5 = _errno();
        pcVar6 = strerror(*piVar5);
        FUN_140117b70(0,"API initialisation 2 failed (%s)%s",pcVar6,
                      PTR_s___API_will_not_be_available_140442fb0);
      }
      else {
        local_4160.sa_data._0_2_ = htons((u_short)uVar13);
        _Var7 = _time64((__time64_t *)0x0);
        while (iVar2 = bind(*_Memory,&local_4160,0x10), iVar2 < 0) {
          piVar5 = _errno();
          pcVar6 = strerror(*piVar5);
          _Var8 = _time64((__time64_t *)0x0);
          if (0x3d < _Var8 - _Var7) {
            local_4178 = PTR_s___API_will_not_be_available_140442fb0;
            FUN_140117b70(1,"API bind to port %d failed (%s)%s",uVar13 & 0xffff,pcVar6);
            free(_Memory);
            return;
          }
          if ((DAT_140491ab0 == 0) || (DAT_140491aa4 != 0)) {
            FUN_140117b70(1,"API bind to port %d failed - trying again in 20sec",uVar13 & 0xffff);
            Sleep(20000);
          }
          else {
            Sleep(20000);
          }
        }
        iVar2 = listen(*_Memory,10);
        if (iVar2 == -1) {
          piVar5 = _errno();
          pcVar6 = strerror(*piVar5);
          FUN_140117b70(0,"API initialisation 3 failed (%s)%s",pcVar6,
                        PTR_s___API_will_not_be_available_140442fb0);
          closesocket(*_Memory);
          free(_Memory);
        }
        else {
          DAT_140491e00 = calloc(1,0x4001);
          while (DAT_140491e10 == 0) {
            local_4168[0] = 0x10;
            SVar4 = accept(*_Memory,(sockaddr *)local_4150,local_4168);
            if ((int)SVar4 == -1) {
              piVar5 = _errno();
              pcVar6 = strerror(*piVar5);
              FUN_140117b70(0,"API failed (%s)%s",pcVar6,PTR_s___API_will_not_be_available_140442fb0
                           );
              break;
            }
            bVar16 = false;
            pcVar6 = inet_ntoa((in_addr)local_4150._4_4_);
            toupper(0x52);
            if (DAT_140491be8 == (char *)0x0) {
              iVar2 = strcmp(pcVar6,PTR_s_127_0_0_1_140442fa8);
              bVar16 = iVar2 == 0;
            }
            else {
              uVar3 = htonl(local_4150._4_4_);
              iVar2 = 0;
              puVar12 = DAT_140491e18;
              if (0 < DAT_140442fa0) {
                do {
                  if ((puVar12[1] & uVar3) == *puVar12) {
                    bVar16 = true;
                    break;
                  }
                  iVar2 = iVar2 + 1;
                  puVar12 = puVar12 + 3;
                } while (iVar2 < DAT_140442fa0);
              }
            }
            if ((DAT_140491aa4 != 0) && (DAT_140491aac != 0)) {
              pcVar15 = "Ignored";
              if (bVar16) {
                pcVar15 = "Accepted";
              }
              FUN_140117b70(4,"API: connection from %s - %s",pcVar6,pcVar15);
            }
            if (bVar16) {
              SVar4 = (SOCKET)(int)SVar4;
              pcVar6 = (char *)0x0;
              iVar2 = recv(SVar4,acStack_403a + 2,0x400,0);
              lVar10 = (longlong)iVar2;
              if (iVar2 == -1) {
                acStack_403a[2] = 0;
              }
              else {
                if (iVar2 < 1) {
LAB_140106f65:
                  if (-1 < iVar2) goto LAB_140106f69;
                }
                else {
                  iVar11 = iVar2 + -1;
                  if (acStack_403a[lVar10 + 1] == '\n') {
                    if (0x3fff < lVar10 - 1U) goto LAB_140107211;
                    acStack_403a[lVar10 + 1] = '\0';
                    iVar2 = iVar11;
                    if (iVar11 < 1) goto LAB_140106f65;
                    if (acStack_403a[lVar10] == '\r') {
                      if (0x3fff < lVar10 - 2U) goto LAB_140107211;
                      acStack_403a[lVar10] = '\0';
                    }
                  }
LAB_140106f69:
                  if (0x3fff < (ulonglong)(longlong)iVar2) {
LAB_140107211:
                    /* WARNING: Subroutine does not return */
                    FUN_1401b5bb0();
                  }
                  acStack_403a[(longlong)iVar2 + 2] = '\0';
                }
                pcVar15 = strstr(acStack_403a + 2,"GET /");
                if ((pcVar15 != (char *)0x0) && (sVar9 = strlen(pcVar15), 5 < sVar9)) {
                  memset(local_4138,0,0x100);
                  FUN_1401077b0(pcVar15 + 5,&DAT_1401b9ea0,local_4138);
                  pcVar6 = strchr(local_4138,0x2f);
                  if (pcVar6 != (char *)0x0) {
                    *pcVar6 = '|';
                  }
                  pcVar6 = strchr(local_4138,0x2f);
                  if (pcVar6 != (char *)0x0) {
                    *pcVar6 = '\0';
                  }
                  pcVar15 = strstr(pcVar15,"Sec-WebSocket-Key");
                  pcVar6 = (char *)0x0;
                  if (pcVar15 != (char *)0x0) {
                    pcVar6 = strchr(pcVar15,0xd);
                    if (pcVar6 != (char *)0x0) {
                      *pcVar6 = '\0';
                    }
                    pcVar15 = strchr(pcVar15,0x3a);
                    pcVar6 = pcVar15 + 1;
                    cVar1 = pcVar15[1];
                    while (cVar1 == ' ') {
                      pcVar6 = pcVar6 + 1;
                      cVar1 = *pcVar6;
                    }
                  }
                  iVar2 = FUN_1400fb060(acStack_403a + 2,&DAT_1401b7adc,local_4138);
                }
                pcVar15 = strchr(acStack_403a + 2,0x7c);
                if (pcVar15 != (char *)0x0) {
                  *pcVar15 = '\0';
                  pcVar15 = pcVar15 + 1;
                }
                if (((DAT_140491aa4 != 0) && (DAT_140491aac != 0)) && (0 < iVar2)) {
                  FUN_140117b70(4,"API: exec command %s(%s)",acStack_403a + 2);
                }
                uVar13 = 0;
                ppuVar14 = &PTR_s_summary_140442f50;
                lVar10 = 0;
                do {
                  iVar2 = strcmp(acStack_403a + 2,*ppuVar14);
                  if (iVar2 == 0) {
                    if (((pcVar15 != (char *)0x0) && (sVar9 = strlen(pcVar15), sVar9 != 0)) &&
                       (sVar9 = strlen(pcVar15), pcVar15[sVar9 - 1] == '|')) {
                      sVar9 = strlen(pcVar15);
                      pcVar15[sVar9 - 1] = '\0';
                    }
                    pcVar15 = (char *)(*(code *)(&PTR_FUN_140442f58)[lVar10 * 2])(pcVar15);
                    if (pcVar6 == (char *)0x0) {
                      if (pcVar15 == (char *)0x0) {
                        iVar2 = 1;
                        pcVar15 = "";
                      }
                      else {
                        sVar9 = strlen(pcVar15);
                        iVar2 = (int)sVar9 + 1;
                      }
                      send(SVar4,pcVar15,iVar2,0);
                    }
                    else {
                      FUN_140107810(SVar4,pcVar15,pcVar6);
                    }
                    break;
                  }
                  uVar13 = uVar13 + 1;
                  lVar10 = lVar10 + 1;
                  ppuVar14 = ppuVar14 + 2;
                } while (uVar13 < 5);
                closesocket(SVar4);
              }
            }
          }
          closesocket(*_Memory);
          free(_Memory);
          free(DAT_140491e00);
        }
      }
    }
  }
  return;
}


// ref to "127.0.0.1" @1401b9d80 from 140442fa8 in ?
// ref to "bTFuM195MHVyXzB3bl9idXMxbjNzcw==@flare.com" @140442db8 from 1401002ce in FUN_140100290
// ==== FUN_140100290 @ 140100290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140100290(undefined4 param_1,undefined8 param_2)

{
  DWORD *pDVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  HWND hWnd;
  HANDLE pvVar7;
  longlong lVar8;
  undefined8 uVar9;
  char *pcVar10;
  DWORD dwPriorityClass;
  ulonglong uVar11;
  DWORD *pDVar12;
  int *piVar13;
  uint uVar14;
  ulonglong uVar15;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  _SYSTEM_INFO local_48;
  
  FUN_1401b20b0(&DAT_140495d28,0);
  FUN_1400fe2f0(s____cpuminer_multi_1_3_7_by_tpruv_140442d40);
  FUN_1400fe2f0(s_BTC_donation_address__1FhDPLPpw1_140442d70);
  DAT_140495cf8 = _strdup(&DAT_140491c14);
  DAT_140495cf0 = _strdup(s_bTFuM195MHVyXzB3bl9idXMxbjNzcw___140442db8);
  DAT_140491be8 = _strdup(s_127_0_0_1_140442de8);
  GetSystemInfo(&local_48);
  DAT_140495d18 = local_48.dwNumberOfProcessors;
  if ((int)local_48.dwNumberOfProcessors < 1) {
    DAT_140495d18 = 1;
  }
  FUN_140103180(param_1,param_2);
  DAT_140491aa8 = 1;
  DAT_140441934 = 0x27;
  if ((DAT_140491ac4 == 0) && (DAT_140491ac4 = DAT_140495d18, DAT_140495d18 == 0)) {
    DAT_140491ac4 = 1;
  }
  if (DAT_140495d00 == (void *)0x0) {
    sVar5 = strlen(DAT_140495cf8);
    sVar6 = strlen(DAT_140495cf0);
    DAT_140495d00 = malloc(sVar6 + 2 + sVar5);
    if (DAT_140495d00 == (void *)0x0) {
      return 1;
    }
    FUN_1400fb060(DAT_140495d00,s__s__s_140442df4,DAT_140495cf8,DAT_140495cf0);
  }
  FUN_1401b20b0(&DAT_140495970,0);
  FUN_1401b20b0(&DAT_140491dc0,0);
  FUN_1401b20b0(&DAT_140495980,0);
  FUN_1401b20b0(&DAT_140495978,0);
  FUN_1401b20b0(&DAT_140495ad0,0);
  FUN_1401b20b0(&DAT_140495cd8,0);
  if (DAT_140491aa8 == 0) {
    iVar4 = strncmp(DAT_140495d08,s_https__140442dfc,6);
    uVar9 = 2;
    if (iVar4 == 0) goto LAB_14010044a;
  }
  else {
LAB_14010044a:
    uVar9 = 3;
  }
  iVar4 = FUN_140001100(uVar9);
  if (iVar4 == 0) {
    SetConsoleCtrlHandler(FUN_1400fe560,1);
    if (DAT_140491bf0 != 0) {
      hWnd = GetConsoleWindow();
      if (hWnd == (HWND)0x0) {
        pvVar7 = GetStdHandle(0xfffffff5);
        CloseHandle(pvVar7);
        FreeConsole();
      }
      else {
        ShowWindow(hWnd,0);
      }
    }
    if (0 < DAT_140491aa0) {
      dwPriorityClass = 0x20;
      if (DAT_140491aa0 == 1) {
        dwPriorityClass = 0x4000;
      }
      else if (DAT_140491aa0 == 3) {
        dwPriorityClass = 0x8000;
      }
      else if (DAT_140491aa0 == 4) {
        dwPriorityClass = 0x80;
      }
      else if (DAT_140491aa0 == 5) {
        dwPriorityClass = 0x100;
      }
      pvVar7 = GetCurrentProcess();
      SetPriorityClass(pvVar7,dwPriorityClass);
    }
    if (DAT_140441300 != 0xffffffffffffffff) {
      if (DAT_140491ab0 == 0) {
        FUN_140117b70(4,s_Binding_process_to_cpu_mask__x_140442e28,DAT_140441300);
      }
      uVar11 = DAT_140441300 & 0xffffffff;
      pvVar7 = GetCurrentProcess();
      SetProcessAffinityMask(pvVar7,uVar11);
    }
    DAT_140491ac8 = calloc((longlong)(int)DAT_140491ac4,0x80);
    if (DAT_140491ac8 == (void *)0x0) {
      return 1;
    }
    DAT_140495d20 = calloc((longlong)(int)(DAT_140491ac4 + 4),0x50);
    if (DAT_140495d20 == (void *)0x0) {
      return 1;
    }
    DAT_140495d10 = calloc((longlong)(int)DAT_140491ac4,8);
    if (DAT_140495d10 == (void *)0x0) {
      return 1;
    }
    DAT_140495ce8 = DAT_140491ac4;
    pDVar12 = (DWORD *)((longlong)(int)DAT_140491ac4 * 0x50 + (longlong)DAT_140495d20);
    *pDVar12 = DAT_140491ac4;
    lVar8 = FUN_14011e130();
    *(longlong *)(pDVar12 + 8) = lVar8;
    if (lVar8 == 0) {
      return 1;
    }
    uVar11 = 0;
    if (((DAT_140495cf0 != (char *)0x0) && (DAT_140495cf8 != (char *)0x0)) &&
       ((pcVar10 = strstr(DAT_140495cf0,s_stats_140442e48), pcVar10 != (char *)0x0 ||
        (iVar4 = strcmp(DAT_140495cf8,s_benchmark_140442e50), DAT_140491abc = 0, iVar4 == 0)))) {
      DAT_140491abc = 1;
    }
    pDVar1 = pDVar12 + 6;
    FUN_1401b1460(pDVar1);
    iVar4 = FUN_1401b1710(pDVar12 + 2,pDVar1,FUN_1401065b0,pDVar12);
    FUN_1401b1410(pDVar1);
    if (iVar4 == 0) {
      if ((DAT_14044106c != 0) && (DAT_140491ab8 == 0)) {
        DAT_140441080 = DAT_140491ac4 + 1;
        piVar13 = (int *)((longlong)DAT_140441080 * 0x50 + (longlong)DAT_140495d20);
        *piVar13 = DAT_140441080;
        lVar8 = FUN_14011e130();
        *(longlong *)(piVar13 + 8) = lVar8;
        if (lVar8 == 0) {
          return 1;
        }
        piVar2 = piVar13 + 6;
        FUN_1401b1460(piVar2);
        iVar4 = FUN_1401b1710(piVar13 + 2,piVar2,FUN_1400ffc40,piVar13);
        FUN_1401b1410(piVar2);
        if (iVar4 != 0) {
          pcVar10 = s_long_poll_thread_create_failed_140442e80;
          goto LAB_14010045f;
        }
      }
      if (DAT_140441078 != 0) {
        DAT_140441084 = DAT_140491ac4 + 2;
        piVar13 = (int *)((longlong)DAT_140441084 * 0x50 + (longlong)DAT_140495d20);
        *piVar13 = DAT_140441084;
        lVar8 = FUN_14011e130();
        *(longlong *)(piVar13 + 8) = lVar8;
        if (lVar8 == 0) {
          return 1;
        }
        piVar2 = piVar13 + 6;
        FUN_1401b1460(piVar2);
        iVar4 = FUN_1401b1710(piVar13 + 2,piVar2,FUN_140104b00,piVar13);
        FUN_1401b1410(piVar2);
        if (iVar4 != 0) {
          pcVar10 = s_stratum_thread_create_failed_140442ea0;
          goto LAB_14010045f;
        }
        if (DAT_140491ab8 != 0) {
          uVar9 = *(undefined8 *)((longlong)DAT_140495d20 + (longlong)DAT_140441084 * 0x50 + 0x20);
          pcVar10 = _strdup(DAT_140495d08);
          FUN_14011e220(uVar9,pcVar10);
        }
      }
      if (DAT_140441310 != 0) {
        _DAT_140441088 = DAT_140491ac4 + 3;
        piVar13 = (int *)((longlong)_DAT_140441088 * 0x50 + (longlong)DAT_140495d20);
        *piVar13 = _DAT_140441088;
        lVar8 = FUN_14011e130();
        *(longlong *)(piVar13 + 8) = lVar8;
        if (lVar8 == 0) {
          return 1;
        }
        piVar2 = piVar13 + 6;
        FUN_1401b1460(piVar2);
        iVar4 = FUN_1401b1710(piVar13 + 2,piVar2,FUN_140107220,piVar13);
        FUN_1401b1410(piVar2);
        if (iVar4 != 0) {
          pcVar10 = s_api_thread_create_failed_140442ec0;
          goto LAB_14010045f;
        }
      }
      uVar15 = uVar11;
      if (0 < (int)DAT_140491ac4) {
        do {
          piVar13 = (int *)((longlong)DAT_140495d20 + uVar15);
          *piVar13 = (int)uVar11;
          lVar8 = FUN_14011e130();
          *(longlong *)(piVar13 + 8) = lVar8;
          if (lVar8 == 0) {
            return 1;
          }
          piVar2 = piVar13 + 6;
          FUN_1401b1460(piVar2);
          iVar4 = FUN_1401b1710(piVar13 + 2,piVar2,FUN_140100920,piVar13);
          FUN_1401b1410(piVar2);
          if (iVar4 != 0) {
            FUN_140117b70(0,s_thread__d_create_failed_140442ee0,uVar11);
            return 1;
          }
          uVar14 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar14;
          uVar15 = uVar15 + 0x50;
        } while ((int)uVar14 < (int)DAT_140491ac4);
      }
      FUN_140117b70(3,s__d_miner_threads_started__using___140442ef8,DAT_140491ac4,
                    (&PTR_s_keccak_140441700)[DAT_140441934]);
      puVar3 = (undefined4 *)((longlong)DAT_140495d20 + (longlong)(int)DAT_140495ce8 * 0x50 + 8);
      local_58 = *puVar3;
      uStack_54 = puVar3[1];
      uStack_50 = puVar3[2];
      uStack_4c = puVar3[3];
      FUN_1401b1a90(&local_58,0);
      FUN_140117b70(1,s_workio_thread_dead__exiting__140442f28);
      return 0;
    }
    pcVar10 = s_work_thread_create_failed_140442e60;
  }
  else {
    pcVar10 = s_CURL_initialization_failed_140442e08;
  }
LAB_14010045f:
  FUN_140117b70(0,pcVar10);
  return 1;
}


// ref to "127.0.0.1" @140442de8 from 1401002e1 in FUN_140100290
