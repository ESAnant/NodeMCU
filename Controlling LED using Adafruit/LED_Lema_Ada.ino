#include <Adafruit_MQTT_Client.h>
#include <ESP8266WiFi.h>
#define wifi "Anant2"
#define password "Adi_1996"
#define server "io.adafruit.com"
#define port 1883
#define user  "SaiAnant"
#define key       "aio_CECh981DB2aYP4J7XOsM9C6nW6AR"
WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp,server,port,user,key);
Adafruit_MQTT_Subscribe feed(&mqtt,user"/feeds/lemaled");
void setup() {
  // put your setup code here, to run once:
  
  pinMode(16,OUTPUT);
  Serial.begin(115200);
  Serial.print("Connecting to the wifi: ");
  Serial.print(wifi);
  WiFi.begin(wifi,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
   delay(500);
   Serial.print(".");  
  }
  Serial.println("Connection Established");
  Serial.println("Connecting to Adafruit");
  mqtt.subscribe(&feed);
  while(mqtt.connect())
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
    while(mqtt.readSubscription(5000))
    {
      Serial.print("Got: ");
      int a =atoi((char*)feed.lastread);
      Serial.println(a);
      if(a==0)
        digitalWrite(16,LOW);
      else
        digitalWrite(16,HIGH);
      }
    }
    
    else{
      Serial.print("Failed");
      
    }
    
  
  delay(2500);
}
