import socket, threading
def serve():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    s.bind(('127.0.0.1',8080)); s.listen(16)
    print('[c2] listening 127.0.0.1:8080',flush=True)
    while True:
        c,a=s.accept()
        threading.Thread(target=handle,args=(c,),daemon=True).start()
def handle(c):
    try:
        data=b''
        c.settimeout(3)
        try:
            while b'\r\n\r\n' not in data: data+=c.recv(4096)
        except: pass
        # respond 200 with small body
        body=b'\x00'*32
        resp=b'HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n'%len(body)+body
        c.sendall(resp)
    except Exception as e: pass
    finally:
        try: c.close()
        except: pass
serve()
