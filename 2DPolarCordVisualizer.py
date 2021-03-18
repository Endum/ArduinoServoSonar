import numpy as np
import cv2 as cv
from math import cos, sin, radians
import serial
from time import sleep

# Open serial port.
ser = serial.Serial('COM5') # Change this value for different port.
ser.flushInput()

# Wait for Arduino to restart.
sleep(5)

# Start misuration.
ser.write('i'.encode())
ser.flushOutput()

polar = []

# First value.
bs = ser.readline().decode()

while bs != "Cycle over\n":
    try:
        polar.append([float(bs.split(',')[0]),
                      float(bs.split(',')[1][:-1])])
        print(polar[-1])
        bs = ser.readline().decode()
    except Exception as e:
        print(str(e))
        break

polar = np.array(polar)

# From polar to cartesian coordinates.
coords = np.array([[int(d * cos(radians(a))),
                    int(d * sin(radians(a)))]
                    for d,a in polar])

# Shift coordinates to positive integers.
minX = np.amin(coords[:,0])
coords[:,0] -= minX

# Creating image.
im = np.zeros((np.amax(coords[:,0]) + 1,
               np.amax(coords[:,1]) + 1))
im[coords[:,0], coords[:,1]] = 255

# Coloring sonar.
im[-minX-5:-minX+5, :5] = 31

# Rotating (don't judge me).
im = cv.rotate(im, cv.ROTATE_90_CLOCKWISE)
im = cv.rotate(im, cv.ROTATE_90_CLOCKWISE)
im = cv.rotate(im, cv.ROTATE_90_CLOCKWISE)

cv.imshow("ciaone", im)
cv.waitKey(0)