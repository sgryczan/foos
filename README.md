# sgryczan/foos - An IoT-enabled foosball table

# Overview

Hardware - Buttons and Sensors are run from an Arduino Uno; program code written in C++

Application - Application layer written in Python, implementation of a simple 'foosball' library for instantiating and managing games.

Web - FrontEnd written in using NodeJS

Database - MongoDB. Game Data is passed from Python to NodeJS in JSON format to be logged in Mongo.


Recommended to bring this up with docker-compose: 'docker-compose up'

If you prefer to run the containers manually, this can be done with the following:

db:
docker run -d --rm -p 27017:27017 -p 28017:28017 -e AUTH=no -v /var/lib/mongodb/:/data/db/ --name=foos-db mangoraft/mongodb-arm

app:
docker run --rm -itd --name foos-app -p 3000:3000 --link foos-db --device=/dev/ttyACM0 foos-app:latest

