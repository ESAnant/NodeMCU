//https://github.com/esp8266/ESPWebServer
#include <ESP8266WebServer.h>//Download this library from the link above which helps convert NodeMCU into a server
const char username[]="username";//Give any username(SSID) to the NodeMCU
const char password[]="03052001";//Give any password(password) to the NodeMCU
ESP8266WebServer server;//name the server
void setup() {
  pinMode(16,OUTPUT);//Set pinmode for LED
  Serial.begin(115200);//set baud rate
  Serial.println("\nConfiguring access point....");//Print if run successfully
  WiFi.softAP(username,password);//Set up the server
  IPAddress myIP=WiFi.softAPIP();//Fetch the IP address of the server and store it in myIP variable
  Serial.print("AP IP address: ");//Print the IP address
  Serial.println(myIP); //The IP address gets printed
  server.on("/led",led);//Extension for the IP address
  server.begin();//Start the server
  Serial.println("HTTP server started");//Confirmation that the server has started
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();//The server stays on until the connection is removed
}
void led()
{
  //myHTML contains the HTML code of the website with buttons that represent the state of the LED.
  //This code can be edited according to the application and need of the user.
  String myhtml="<html><head><title>LemaNode Webserver</title></head><body style=\"background-color: cyan\"><h1><center>IOT LED</center></h1><form><center><button type=\"submit\" name=\"state\" value=\"0\">LED ON</button></center><center><button type=\"submit\" name=\"state\" value=\"1\">LED OFF</button></center></form></body></html>";
  if (server.arg("state")=="0")//State of the LED
  {
  digitalWrite(16,LOW);//For Common Anode LED it turns on and off for Common Cathode
  }
  else
  {
  digitalWrite(16,HIGH);//For Common Anode LED it turns off and on for Common Cathode
  }
  server.send(200, "text/html",myhtml);//Sends the HTML page to the server
}
