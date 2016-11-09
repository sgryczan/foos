#!/usr/bin/python2.7

import sys
import serial
import time
import foosball.game as game
import foosball.clock as clock


DEBUG = True

ser = None
fb = game.Game("testgame")

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(3)
print "----- Connected -----"

while True:
  try:
    serial_data = ser.readline()
   
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
        print "cmd is " + str(len(cmd)) + "long"
      if event == "goal":
        print "We have a goal"
        fb.score(cmd)
        print fb.redScore
        print fb.blackScore
        print fb.getScore()
 
    # Flush the STDOUT buffer
    sys.stdout.flush()
  except:
    pass

