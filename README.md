### Running the demo
1. Clone this repo on both the edge(Beaglebone Black) and the server(Laptop)
2. Compile and run publisher codes on beaglebone
    ~~~
    $ cd rti_wisun/edge
    $ ./compile.sh
    $ ./rti_wisun/src/objs/armv6vfphLinux3.xgcc4.7.2/FireAlarm_publisher
3. Install npm packages including RTI connector
    ~~~
    $ cd rti_wisun/server
    $ npm install
4. Run the server on the laptop:
    ~~~
    $ cd rti_wisun/server
    $ nodejs server.js