import socket as s

sock = s.socket(s.AF_INET, s.SOCK_DGRAM)
server_addr = ('localhost', 10000)

name = input(str("\nEnter your name: "))

sock.sendto(name.encode(), server_addr)
data, server = sock.recvfrom(1024)
data = data.decode()
print(data, "has joined the chat room\nEnter [e] to exit chat room\n")
while True:
    message, server = sock.recvfrom(1024)
    message = message.decode()
    print(data, ":", message)
    message = input(str("Me : "))
    if message == "[e]":
        message = "Left chat room!"
        sock.sendto(message.encode(), server)
        print("\n")
        break
    sock.sendto(message.encode(), server)
