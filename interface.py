#!/usr/bin/python2.7

import sys
import serial
import time
import foosball.game as game
import foosball.clock as clock


ser = None
try:
    ser = serial.Serial('/dev/ttyACM0', 9600)
    time.sleep(3)
    print "----- Connected -----"

    while True:
	try:
            serial_data = ser.readline()
            print serial_data
            sys.stdout.flush()
        except:
            pass

except:
    pass

finally:
    if ser:
	ser.close()
