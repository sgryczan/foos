var spawn = require('child_process').spawn,
py = spawn('python', ['../foos.py']),
MongoClient = require('mongodb').MongoClient,
assert = require('assert'),
objectID = require('mongodb').ObjectID,
dbUrl = 'mongodb://localhost:27017/foos';


MongoClient.connect(dbUrl, function(db, err) {
  if(!err) {
    console.log('Connected to Database.');
    // db.close();
  }
  else { return console.dir(err)};
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


