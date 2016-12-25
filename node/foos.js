var spawn = require('child_process').spawn,
py = spawn('python', ['../foos.py']),
MongoServer = require('mongodb').Server,
MongoClient = require('mongodb').MongoClient,
assert = require('assert'),
objectID = require('mongodb').ObjectID,
dbUrl = 'mongodb://localhost:27017/foos';


var mongoClient = new MongoClient(new MongoServer('localhost', 27017));
mongoClient.open(function(err, mongoClient) {
  var foosdb = mongoClient.db("foos");
  console.log('Connected to Database.');
  mongoClient.close();
});

dataString = '';

py.stdout.on('data', function(data) {
  dataString = data.toString();
  if(dataString.indexOf("Game.Dump::") != -1) { 
      js = dataString.split("::")[1];
      jss = JSON.stringify(js);
      console.log(jss);
      console.log('output: ' + data.toString());
  }
  else {
      console.log('output: ' + data.toString());
  }
});

py.stdout.on('end', function() {
  console.log(dataString);
});


