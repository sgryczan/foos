#!/usr/bin/python

from time import sleep
import sys

def main():
  for i in range(10):
    print "Hello, world!!!"
    sys.stdout.flush()
    sleep(1)



if __name__ == '__main__':
  main()
