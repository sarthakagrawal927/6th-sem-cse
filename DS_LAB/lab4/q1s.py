import socket as s
import time as t
import sys

sock = s.socket(s.AF_INET, s.SOCK_DGRAM)

server_addr = ('localhost', 10000)

sock.bind(server_addr)

data, addr = sock.recvfrom(1024)

if(data.decode() == "Time?"):
    currTime = t.ctime(t.time())
    sock.sendto(currTime.encode('ascii'), addr)
    print('Sent time to client.')
else:
    sock.close()
