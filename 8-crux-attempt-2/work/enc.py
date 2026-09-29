import sys,base64
from cryptography.hazmat.primitives.ciphers import Cipher,algorithms,modes
K=bytes.fromhex('cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723')
IV=bytes.fromhex('5ff26040c4c20b9f2ffdefa7ecf65d91')
def enc(p):
    n=16-len(p)%16;p=p+bytes([n])*n
    e=Cipher(algorithms.AES(K),modes.CBC(IV)).encryptor();return base64.b64encode(e.update(p)+e.finalize()).decode()
if __name__=='__main__':print(enc(sys.argv[1].encode('latin1')))
