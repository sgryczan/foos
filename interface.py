#!/usr/bin/python2.7

import sys
import serial
import time
import foosball.game as game
import foosball.clock as clock


DEBUG = True

ser = None

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(.1)
print "----- Connected -----"
dump = ser.readline()
sys.stdout.flush()
fb = game.Game("testgame")

while True:
  try:
    serial_data = ser.readline().replace('\r\n','')
   
    # Write to stdout to return data to nodeJS
    print serial_data

    if serial_data == "game.startNew":
      print "Starting new game."
      fb = None
      fb = game.Game("testgame")
    else:
      event, cmd = serial_data.replace('\r\n','').split(".")
      if DEBUG:
        print "event: " + event
        print "cmd: " + cmd
      if event == "goal":
        fb.score(cmd)
        print fb.getScore()
 
    # Flush the STDOUT buffer
    print " "
    sys.stdout.flush()
  except:
    pass

