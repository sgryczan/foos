# sgryczan/foos - An IoT-enabled foosball table

# Overview

Hardware - Buttons and Sensors are run from an Arduino Uno; program code written in C++

Application - Application layer written in Python, implementation of a simple 'foosball' library for instantiating and managing games.

Web - FrontEnd written in using NodeJS

Database - MongoDB. Game Data is passed from Python to NodeJS in JSON format to be logged in Mongo.

Docker runtime params:

docker run --rm -itd --name foos -p 3000:3000 --device=/dev/ttyACM0 foos:latest


