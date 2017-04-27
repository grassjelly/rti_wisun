/*
 * Copyright (c) 2005-2015 Real-Time Innovations, Inc. All rights reserved.
 * Permission to modify and use for internal purposes granted.
 * This software is provided "as is", without warranty, express or implied.
 */

var sleep = require('sleep');
var rti   = require('rticonnextdds-connector');
var connector = new rti.Connector("MyParticipantLibrary::Zero", __dirname + "/server.xml");
var input = connector.getInput("MySubscriber::FireAlarmReader");
var express = require('express');

var app = express();
var server = require('http').createServer(app);
var io = require('socket.io')(server);
//either use cloud service port or local port:3000
var port = process.env.PORT || 8000;


server.listen(port, function () {
  console.log('Server listening at port %d', port);
});

app.use(express.static(__dirname));


connector.on('on_data_available',
   function() {
     input.take();
     for (i=1; i <= input.samples.getLength(); i++) {
         if (input.infos.isValid(i)) {
            var jsonObj = input.samples.getJSON(i);
             console.log(JSON.stringify(jsonObj));
             io.sockets.emit('case', jsonObj);
         }
     }

});

