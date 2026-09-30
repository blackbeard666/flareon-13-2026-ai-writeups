import base64, json, re, struct, sys
# Manual pcapng parser: extract all Enhanced Packet Block payloads, concat TCP payloads.
data=open("challenge.pcapng","rb").read()
# Just brute-force: find all HTTP POST /telemetry bodies in the whole file (client stream is plaintext).
# feedback_b64 is long base64; grab JSON objects containing feedback_length.
blob=data
tn=0
for m in re.finditer(rb'\{"request_id"', blob):
    s=m.start()
    # find matching end brace (telemetry JSON has no nested braces)
    e=blob.find(b'}', s)
    if e<0: continue
    obj=blob[s:e+1]
    try:
        j=json.loads(obj)
    except Exception:
        continue
    fb=j.get('feedback_b64','')
    raw=base64.b64decode(fb) if fb else b''
    nz=sum(1 for c in raw if c)
    tn+=1
    print("TEL#%d fb_len=%s b64len=%d decoded=%d nonzero=%d games=%s head=%s"%(
        tn,j.get('feedback_length'),len(fb),len(raw),nz,j.get('games_played'),raw[:24].hex()))
print("total telemetry JSON found:",tn)
