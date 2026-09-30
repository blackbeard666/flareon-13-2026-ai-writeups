# crux ch8 - off56 gate + flag mechanism (agent, this session) - MAJOR CORRECTIONS

## off56 is an ERROR, not a Lisp value (prior notes were WRONG)
- Resolved Go type metadata (moduledata types base = 0x0000cb80 in mem_after.bin):
  - itab 0x4ef80 = itab(**error**, *okGTWgs28I.tefGNm63).  inter 0x25740 = `error` (1 method `Error`).
  - itab 0x4ef60 = itab(main.FPJNbG8y, *main.B1698pyli)  = PAIR (Lisp cons)
  - itab 0x4ef40 = itab(main.FPJNbG8y, *main.VSZ2lqvlggVb) = NIL
  - So off56 == 0x4ef80 means a NON-NIL error of concrete type *okGTWgs28I.tefGNm63.
- func3166 = crypto/cipher.NewCBCDecrypter(block, iv) -> cipher.BlockMode (result off40=itab, off48=data). Uses *aes.CBCDecrypter (type 0x2b1a0).
- call_indirect @0x6d6c = BlockMode.CryptBlocks(dst, src): decrypts the 64B ciphertext into dst. Returns void; off56 still 0 at this point.
- 3190 @0x6dc4 takes the decrypted 64B buffer and returns an ERROR at off56 = **PKCS#7 unpad / padding validation**.

## THE GATE (0x6dcf), corrected
`if mem[sp+56]==0 -> state 1414 (FLAG)  else -> Bad input`
- off56 = the unpad error. VALID PKCS#7 padding => nil error => state 1414.
- state 1414 returns the UNPADDED decrypted plaintext directly (no further crypto). VERIFIED.

## FLAG FORMULA (fully verified offline == wasm)
flag = PKCS7_unpad( AES-256-CBC-decrypt(CT, KEY, IV) )
- CT  = 78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232ff619632797e3708ad29b2cdd4491a3c2  (64B, STATIC, built by func3272 from static globals; identical for ALL valid certs)
- KEY = SHA256(message_bytes)   (message = the decrypted stage-1 cert bytes; VERIFIED sha256(certP)=a1c0cf...=captured NewCipher key)
- IV  = 5ff26040c4c20b9f2ffdefa7ecf65d91
- For certP: AESdec -> b757e1cbcc569f8b... last byte 0x4c -> INVALID pad -> error -> "Bad input".
- PROOF the gate = padding validity: certP with 2-leaf val=195498 (random valid-1-byte-pad) -> check() returns the raw plaintext 'zm1...' instead of "Bad input".

## THE REMAINING UNKNOWN: the 2-leaf certificate val
- The message MUST be a valid Pratt primality certificate for P=95681613235744740119807961018865688051340183696570761153419351987106658443873.
- The cert is FULLY FORCED by the eval:
  - factors of p-1 ascending WITH multiplicity (descending REJECTED)
  - witness = SMALLEST primitive root for every node (witness 5 or 7 -> REJECTED even though valid p.roots; g+p same-residue -> REJECTED; deep witness corruption -> REJECTED)
  - full recursion down to leaf key==2 (treating 3 or 5 as a leaf -> REJECTED)
  - childByteLen validated (corruption -> REJECTED); no trailing bytes allowed; little-endian canonical ints
- The ONLY thing the eval does NOT constrain is the **val field of the key==2 leaves** (uniform via memoization). All 2-leaf vals reach the decrypt (val=0,1,2,195498 all accepted).
- KEY = SHA256(cert) DEPENDS on the 2-leaf val, so the flag needs the AUTHOR's exact 2-leaf val.
- RULED OUT (no valid-padding flag): uniform 2-leaf val 0..16,000,000; ASCII words (crux/flare/prime/pratt/...); constants (1337/0xdeadbeef/...); P-derived keys (sha(P.le/be), sha(decimal), blobs).
- build_cert.py uses node([],2,0) (val empty) = certP -> garbage. Natural alternatives node([],2,1) [primitive_root(2)=1] and node([],2,2) also fail.

## OPEN
Recover the exact 2-leaf `val` the challenge author used (the sole remaining byte(s) of the message). Once known:
  msg = tree with that val ; flag = pkcs7_unpad(AES-CBC-dec(CT, sha256(msg), IV))
Everything else is solved.

## Tools written this session
zz_capdec.js (dump decrypted buf + ct + off56 at AES#2), zz_capkey.js (key/iv/ct via retaddr markers), zz_reach.js (does input reach AES#2 + key), zz_scanflag.js (mem scan), zz_finalbrute.py / /tmp/*brute*.py (2-leaf val brute via certP.hex tree reserialization - fast, no sympy).
