var spawn = require('child_process').spawn,
py = spawn('python', ['../foos.py']),
dataString = '';

py.stdout.on('data', function(data) {
    dataString = data.toString();
    if(dataString.indexOf("Game.Dump::") != -1) { 
        js = dataString.split("::")[1];
        jss = JSON.stringify(js);
        console.log(jss);
    }
    else {
        console.log('output: ' + data.toString());
    }
});

py.stdout.on('end', function() {
    console.log(dataString);
});


