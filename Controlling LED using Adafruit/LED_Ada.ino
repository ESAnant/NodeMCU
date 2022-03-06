//https://github.com/adafruit/Adafruit_MQTT_Library
//Download the above files and add it to the library file of arduino IDE
#include <Adafruit_MQTT_Client.h>//Include the library
#include <ESP8266WiFi.h>
#define wifi "SSID"//Give your home wifi name 
#define password "password"//Give your wifi password
#define server "io.adafruit.com"//Name of the server you will access
#define port 1883// Adafruit port number same for all
#define user  "xxxx"//Adafruit account username
#define key       "aio_xxxx"//Adafruit account key you can find these in the site
WiFiClient esp;//set the name of client
Adafruit_MQTT_Client mqtt(&esp,server,port,user,key);//Set the mqtt client
Adafruit_MQTT_Subscribe feed(&mqtt,user"/feeds/lemaled");//Set the process to subcribe the data from adafruit with the mqtt protocal and the extension of the feed that you have created
void setup() {
  // put your setup code here, to run once:
  
  pinMode(16,OUTPUT);//Led connection
  Serial.begin(115200);//Set baud rate
  Serial.print("Connecting to the wifi: ");
  Serial.print(wifi);
  WiFi.begin(wifi,password);//Start the wifi in NodeMCU
  while(WiFi.status()!=WL_CONNECTED)//To check if the NodeMCU has been connected to the Wifi you want to connect
  {
   delay(500);
   Serial.print(".");  
  }
  Serial.println("Connection Established");
  Serial.println("Connecting to Adafruit");
  mqtt.subscribe(&feed);
  while(mqtt.connect())//Establish mqtt connection
  {
    Serial.print(".");
  }
  Serial.println("Connected to Adafruit");
 
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (mqtt.connected())
  {
    while(mqtt.readSubscription(5000))//After the connection is established do the action required
    {
      Serial.print("Got: ");
      int a =atoi((char*)feed.lastread);//Get the latest data from the feed 
      Serial.println(a);
      if(a==0)//When the the data is 0
        digitalWrite(16,LOW);//Turn on the LED connected
      else
        digitalWrite(16,HIGH);//Turn off the LED
      }
    }
    
    else{
      Serial.print("Failed");
      
    }
    
  
  delay(2500);
}
