import socket as s

sock = s.socket(s.AF_INET, s.SOCK_DGRAM)
server_addr = ('localhost', 10000)

msg = input("Type \"Time?\" to get current date and time: ")
sock.sendto(msg.encode(), server_addr)
data, server = sock.recvfrom(1024)
print("Current Date and time is : ", data.decode())
