#!/usr/bin/python2.7

import sys
import serial
import time
import jsonpickle as jsp
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
  serial_data = ser.readline().replace('\r\n','')
   
  # Write to stdout to return data to nodeJS
  print repr(serial_data)

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
      s = goal(arg, ts)
      s.convertTS()
      g_js = jsp.dumps(s)
      print g_js
      print "Goals : " + str(len(fb.goals))
  
      print fb.getScore()
      if fb.winner:
        print "We have a winner!"
        print fb.endGame()
        fb.convertGoals()
        jgame = jsp.dumps(fb)
        print "Game.Dump::" + jgame
        fb = game.Game("TestGame")
 
  # Flush the STDOUT buffer
  print " "
  sys.stdout.flush()
