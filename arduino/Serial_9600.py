#!/usr/bin/python2.7

import serial
import time

ser = None
try:
    ser = serial.Serial('/dev/ttyACM1', 9600)
    time.sleep(3)

    while True:
	try:
            serial_data = ser.readline()
            print serial_data
        except:
            pass

except:
    pass

finally:
    if ser:
	ser.close()
