//https://github.com/ekstrand/ESP8266wifi download the file and add it to the library file of arduino IDE
//https://github.com/adafruit/Adafruit_MQTT_Library
//Download the above files and add it to the library file of arduino IDE
#include <Adafruit_MQTT_Client.h>//Include the library
#include <ESP8266WiFi.h>//Include the library
#define wifi "SSID"//Give your home wifi name 
#define password "password"//Give your wifi password
#define server "io.adafruit.com"//Name of the server you will access
#define port 1883// Adafruit port number same for all
#define user  "xxxx"//Adafruit account username
#define key       "aio_xxxx"//Adafruit account key you can find these in the site
WiFiClient esp;//set the name of client
Adafruit_MQTT_Client mqtt(&esp,server,port,user,key);//Set the mqtt client
Adafruit_MQTT_Publish feed(&mqtt,user"/feeds/ldr");//Set the process to publish the data with the mqtt protocal and the extension of the feed that you have created
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);//Connect the LDR signal pin to A0
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
  Serial.print("Connection Established");
  Serial.print("Connecting to Adafruit");
  while(mqtt.connect())//Establish mqtt connection
  {
    Serial.print(".");
  }
  Serial.print("Connected to adafruit");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (mqtt.connected())//After the connection is established do the action required
  {
    int data=analogRead(A0);//Set signal to send as "data"
    Serial.println(data);
    if(feed.publish(data)){  //Push the data to the adafruit server
      Serial.print("Success");
      if(data==1024)//When data is 1024, which implies that the LDR sensor is placed in dark
      digitalWrite(16,LOW);//Turn on the LED connected
      else
      digitalWrite(16,HIGH);//Turn off the LED when it is not dark anymore
    }
    else{
      Serial.print("Failed");//If connection is not established print "failed"
      
    }
    
  }
  delay(2500);
}
