/*
 * Copyright (c) 2005-2015 Real-Time Innovations, Inc. All rights reserved.
 * Permission to modify and use for internal purposes granted.
 * This software is provided "as is", without warranty, express or implied.
 */
var sleep = require('sleep');
var rti = require('rticonnextdds-connector');
var connector = new rti.Connector("MyParticipantLibrary::Zero", __dirname + "/server.xml");
var input = connector.getInput("MySubscriber::FireAlarmReader");
var express = require('express');
var stdin = process.openStdin();
var bodyParser = require("body-parser");

var app = express();
var server = require('http').createServer(app);
var io = require('socket.io')(server);
//either use cloud service port or local port:3000
var port = process.env.PORT || 8000;

var case_index = 0;
var case_list = [];
server.listen(port, function() {
    console.log('Server listening at port %d', port);
});

app.use(express.static(__dirname));
app.use(bodyParser.urlencoded({
    extended: false
}));
app.use(bodyParser.json());

app.post('/caseupdate', function(req, res) {
    /*
    http://localhost:8000/caseupdate
    {
    "case_no" : 1,
    "status" : "DONE"
    }
    */
    var case_no = req.body.case_no;
    var status = req.body.status;

    //make sure there's a case lodged 
    var result;
    result = updateCase(case_no, status);
    res.end(String(result));
});

app.get('/firecase', function(request, response) {
    //http://localhost:8000/firecase

    if (case_list.length == 0)
        response.send(null);
    else
        response.send(case_list);

    console.log(request.query);
});


io.on('connection', function(socket) {
    //send all the current states of the lamppost if new client is open
    //this is to prevent the UI from displaying the defualt view "all off" every time the client is refreshed
    io.emit("case_list", case_list);
})

connector.on('on_data_available',
    function() {
        input.take();
        for (i = 1; i <= input.samples.getLength(); i++) {
            if (input.infos.isValid(i)) {
                var jsonObj = input.samples.getJSON(i);
                var alarm_id = jsonObj.alarm_id;
                var state = jsonObj.state;
                if(state)
                    lodgeCase(String(alarm_id));
                // var id = jsonObj.alarm_id;
                // console.log(id)
                // lodgeCase(id);
                // io.sockets.emit('case', jsonObj);
            }
        }
    });

stdin.addListener("data", function(d) {
    id = d.toString().trim();
    console.log("you entered: " + id);
    lodgeCase(id);
});

function lodgeCase(id) {
    if (caseIsLodged(id)) {
        return false;
        //Do nothing..
    } else {
        //pull the case's info from the database
        var case_info = getCaseInfo(id);

        //some check if the id is valid
        if (case_info == null) {
            console.log("ID not found. Case Ignored.");
            return false;
        } else {
            //store the pulled data from DB to the list of cases
            case_list[case_index] = case_info;
            //assign case no for the new case
            case_list[case_index].case_no = case_index;
            //time stamp the new case
            var time_stamp = getTime();
            case_list[case_index].time_lodged = time_stamp;
            case_list[case_index].last_update = time_stamp;
            //send to the client
            io.sockets.emit('new_case', case_info);
            console.log("New case lodged:");
            console.log(case_info);
            case_index++;
            return true;
        }
    }
}

function caseIsLodged(id) {
    //check if the list of lodged cases is empty
    if (case_list.length == 0) {
        return false;
    } else {
        //check the case if it has been lodged
        for (var i = 0; i < case_list.length; i++) {
            if (case_list[i].id == id)
                return true;
        }
        //when nothing found
        return false;
    }
}

function updateCase(case_no, status) {
    //make sure a case has been lodged and the case no is sane
    if (case_list.length == 0 || case_list.length <= parseInt(case_no)) {
        return false;
    }

    if (status == "DONE" || status == "RECEIVED" || status == "REACHED") {
        console.log("STATUS UPDATE - Case NO: " + case_no + " STATUS: " + status);
        var time_stamp = getTime();
        var updates = {
            case_no: case_no,
            status: status,
            last_update: time_stamp
        }
        //update the list of current cases
        case_list[case_no].status = status;
        case_list[case_no].last_update = time_stamp;
        io.sockets.emit('update_case', updates);
        return true;

    } else
        return false;
}

function getCaseInfo(id) {
    var fire_case = null;
    console.log(id);
    //TODO:: Change this with a database
    switch (id) {
        case "abcdefg":
            var fire_case = {
                case_no: null,
                time_lodged: null,
                last_update: null,
                status: "ACTIVE",
                id: "abcdefg",
                name: "A Wee Lit Hau",
                address: "01234 Hougang Ave 56 #78-90 654321",
                type: "HDB",
                contact: 87654321,
                postalcode: 654321,
                lat: 1.372944,
                lng: 103.88253
            };
            break;

        case 'b':
            var fire_case = {
                case_no: null,
                time_lodged: null,
                last_update: null,
                status: "ACTIVE",
                id: "b",
                name: "B Wee Lit Hau",
                address: "01234 Hougang Ave 56 #78-90 654321",
                type: "HDB",
                contact: 87654321,
                postalcode: 654321,
                lat: 1.372944,
                lng: 103.98253
            };
            break;

        case 'c':
            var fire_case = {
                case_no: null,
                time_lodged: null,
                last_update: null,
                status: "ACTIVE",
                id: "c",
                name: "C Wee Lit Hau",
                address: "01234 Hougang Ave 56 #78-90 654321",
                type: "HDB",
                contact: 87654321,
                postalcode: 654321,
                lat: 1.372944,
                lng: 103.78253
            };
            break;
    }

    return fire_case;
}

function getTime() {
    var date = new Date();
    return date.getHours().toString() + ":" + date.getMinutes().toString() + ":" + date.getSeconds().toString();
}