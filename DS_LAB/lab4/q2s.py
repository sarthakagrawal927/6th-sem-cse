import socket as s
import time as t
import sys

sock = s.socket(s.AF_INET, s.SOCK_DGRAM)

server_addr = ('localhost', 10000)

sock.bind(server_addr)

s_name, addr = sock.recvfrom(1024)
s_name = s_name.decode()
print(s_name, "has connected to the chat room\nEnter [e] to exit chat room\n")
name = input(str("Enter your name: "))
sock.sendto(name.encode(), addr)

while True:
    message = input(str("Me : "))
    if message == "[e]":
        message = "Left chat room!"
        sock.sendto(message.encode(), addr)
        print("\n")
        break
    sock.sendto(message.encode(), addr)
    message, addr = sock.recvfrom(1024)
    print(s_name, ":", message.decode())
