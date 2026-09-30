
// ===== [lambda] FUN_140008400 @ 140008400 =====

undefined8 * FUN_140008400(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = &PTR_FUN_1400ddd58;
  return param_2;
}


// no function at 1400083d0
// no function at 1400083a0
// no function at 140008370
// no function at 1400082f0
// no function at 1400082b0
// no function at 140008270

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
