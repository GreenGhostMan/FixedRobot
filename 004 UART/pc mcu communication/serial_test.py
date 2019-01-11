import serial
import time

time.sleep(1)
num_points = 100
data_list = [0]*num_points
f = open("Data.txt","w")
a=[]
j=0

s = serial.Serial('/dev/ttyACM0',baudrate=9600,timeout=1)

now = time.time()
while True:
    #s.write(b'50')
    #s.write(b'\n\r')
    a = s.readline()
    f.write("%s" %a)
    print("%s" %a)
    #print("%s" %a)
    
f.close()
s.close()
print("done!")
