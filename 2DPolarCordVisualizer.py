import numpy as np
import cv2 as cv
from math import cos, sin, radians
import serial
from time import sleep

ser = serial.Serial('COM5')
ser.flushInput()

sleep(5)

ser.write('i'.encode())
ser.flushOutput()

bs = ser.readline()

polar = []

while bs != "Cycle over\n":
    try:
        bs = ser.readline().decode()
        polar.append([float(bs.split(',')[0]),
        	          float(bs.split(',')[1][:-1])])
        print(polar[-1])
    except Exception as e:
        print(str(e))
        break

polar = np.array(polar)

coords = np.array([[int(d * cos(radians(a)) * 100),
	                int(d * sin(radians(a)) * 100)]
	                for d,a in polar])
minX = np.amin(coords[:,0])
coords[:,0] -= minX

im = np.zeros((np.amax(coords[:,0]) + 1,
	           np.amax(coords[:,1]) + 1))
im[coords[:,0], coords[:,1]] = 255

im = cv.rotate(im, cv.ROTATE_90_CLOCKWISE)
im = cv.rotate(im, cv.ROTATE_90_CLOCKWISE)
im = cv.rotate(im, cv.ROTATE_90_CLOCKWISE)

cv.imshow("ciaone", im)
cv.waitKey(0)