This is a project which transforms the NodeMCU into a server throught which one can control different actuators and sensors.

This code utilises HTML website to control a LED wirelessly over a LAN connection to the NodeMCU.
This website can be used only if the client,device you want to connect the server to wirelessly, is connected to the network of the server.
This network can be seen with the name you have given in the variable SSID or username and can be cannecting to using the password given in the code to any device locally.
If you are using a NodeMCU then after successfully compiling and running the code open the serial monitor and use the IP address given along with the extension "/led" to access the webpage.
If the serial monitor is empty, press the reset button on the NodeMCU once and all print statements will appear again.
If you are using a NodeMCU then most probably the IP address will be 192.168.4.1 and the website you want to access will be http://192.168.4.1/led
This code can be adapted to the application of the sensor and actuator.
