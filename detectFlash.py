import cv2 as cv
import sys
from matplotlib import pyplot as plt

BRIGHT_LIMIT = 180 # Controls how how sensative the code is to brightness

cap = cv.VideoCapture(0)
if not cap.isOpened():
    print("Cannot open camera")
    exit()

while True:
    ret, frame = cap.read()
    if not ret:
        print("Cant recieve frame (stream end?). Exiting . . .")
        break
    
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    val = cv.mean(gray)

    cv.imshow('Video', gray) # Comment out to hide the camera


    if (val[0] > BRIGHT_LIMIT): # Greater than the brightness limit
        print(val)   ### Change this line to activate the Arduino code

    if cv.waitKey(1) == ord('q'):
        break


cap.release()
cv.destroyAllWindows()