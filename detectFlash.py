import cv2 as cv
import sys
from matplotlib import pyplot as plt

from smbus import SMBus
from datetime import datetime

addr=  0x7E
bus = SMBus(1)

BRIGHT_LIMIT = 180 # Controls how how sensative the code is to brightness
START_ANGLE = 20
END_ANGLE = 35
count = 0
is_flashing = False


cap = cv.VideoCapture(0)
if not cap.isOpened():
    print("Cannot open camera")
    exit()

cap.set(3,640) # Lower the resolution
bus.write_byte(addr, START_ANGLE) # Get the motor in position

print(f"Number of lightning strikes: {count} Time: {datetime.now()}")


while True:
    ret, frame = cap.read()
    if not ret:
        print("Cant recieve frame (stream end?). Exiting . . .")
        break
    
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    val = cv.mean(gray)

    cv.imshow('Video', gray)


    if (val[0] > BRIGHT_LIMIT) and not is_flashing: # Greater than the brightness limit
        bus.write_byte(addr, END_ANGLE)   ### Change this line to activate the Arduino code
        is_flashing = True
        
    
    if is_flashing and val[0] <= BRIGHT_LIMIT:
        bus.write_byte(addr, START_ANGLE)
        count += 1
        is_flashing = False
        print(f"Number of lightning strikes: {count} Time: {datetime.now()}")
        
        with open("ffxLighting.txt", "a+") as file:
            file.write(f"{count}, {datetime.now()}\n")
            #file.write(str(count) + "
    #write to file
    
        
        
        
    if cv.waitKey(1) == ord('q'):
        break


cap.release()
cv.destroyAllWindows()
