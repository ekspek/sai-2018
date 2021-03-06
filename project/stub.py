import sys
import socket
import struct
import time

if len(sys.argv) != 2:
    print("Usage: {} <port>".format(sys.argv[0]))
    sys.exit(1)

data = [0,0,0,0,0,0,0]
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
address = ('localhost', int(sys.argv[1]))

print("Insert altitude, IAS, GS, vpath, pitch, roll, heading")

while 1:
    data[0], data[1], data[2], data[3], data[4], data[5],data[6] = [float(x) for x in input("> ").split()]
    package = struct.pack("!10f",0,0,data[0],data[3],0,data[2],data[1],data[4],data[5],data[6])
    sent = sock.sendto(package, address)
    print("Sent {} bytes".format(sent))
