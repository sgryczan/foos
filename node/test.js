var spawn = require('child_process').spawn,
py = spawn('python', ['test_out.py']),
dataString = '';



py.stdout.on('data', function(data) {
    dataString += data.toString();
    console.log('output: ' + data.toString());
});

py.stdout.on('end', function() {
    console.log(dataString);
});


