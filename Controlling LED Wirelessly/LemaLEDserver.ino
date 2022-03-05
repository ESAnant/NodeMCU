#include <ESP8266WebServer.h>
const char username[]="LemaNode";
const char password[]="03052001";
ESP8266WebServer server;
void setup() {
  pinMode(16,OUTPUT);
  Serial.begin(115200);
  Serial.println("\nConfiguring access point....");
  WiFi.softAP(username,password);
  IPAddress myIP=WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP); 

  server.on("/led",led);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
void led()
{
  String myhtml="<html><head><title>LemaNode Webserver</title></head><body style=\"background-color: cyan\"><h1><center>IOT LED</center></h1><form><center><button type=\"submit\" name=\"state\" value=\"0\">LED ON</button></center><center><button type=\"submit\" name=\"state\" value=\"1\">LED OFF</button></center></form></body></html>";
  if (server.arg("state")=="0")
  {
  digitalWrite(16,LOW);
  }
  else
  {
  digitalWrite(16,HIGH);
  }
  server.send(200, "text/html",myhtml);
}
