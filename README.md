# Smart Waste Management System

This introduction part will provide you the basic introduction of my project.

STEP:1 (CLIENT_SIDE)
   In this Client_Side i.e. dustbin_side, the garbage level which is measured by the Ultrasonic Sensor(HC-SR04) connected to the NodeMCU      ESP8266, a WiFi-Module sends the data to the server with the help of WiFi.
 
STEP:2 (SERVER_SIDE)
   On the Server_Side i.e. the Raspberry Pi which will act as a server and NodeMCU ESP8266 are connected to the same WiFi ,so the data        which is sent by the NodeMCU will be recieved at the Raspberry Pi.
   
   At the same time the Raspberry Pi will store the data in the localhost database.
   
   Now the data has been recieved by the server but the server can't see that data so now we have created a website using HTML, CSS and        JavaScript. Also we have embeded the Google Maps in the website. Now to work with the Google Maps on the localhost we must have to use      Google Services and should generate the APi Key.
   
   Now with the help of the flask we have connected the database and our html code.
   
   Now it's all done, on refreshing the localhost webpage the data will be added in the database and at the same time it will be seen at      the webpage
