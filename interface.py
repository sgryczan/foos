#!/usr/bin/python2.7

import sys
import serial
import time
import foosball.game as game
from foosball.game import goal
import foosball.clock as clock
from datetime import datetime as dt


DEBUG = True

ser = None

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(.1)
print "----- Connected -----"
fb = game.Game("testgame")

ser.flushInput()
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
      event, arg = serial_data.replace('\r\n','').split(".")
      if DEBUG:
        print "event: " + event
        print "arg: " + arg
      if event == "goal":
        #fb.score(arg)
        ts = dt.now()
        g = goal(arg, ts)
        fb.addGoal(g)
        print "Goals : " + str(len(fb.goals))
        print fb.getScore()
        if game.winner != None:
          print "We have a winner!"
          fb.endGame()
          fb = game.Game("TestGame")
 
    # Flush the STDOUT buffer
    print " "
    sys.stdout.flush()
  except:
    pass

