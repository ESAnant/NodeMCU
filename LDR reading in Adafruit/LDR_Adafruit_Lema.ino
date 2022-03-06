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
Adafruit_MQTT_Publish feed(&mqtt,user"/feeds/lemaldr");
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
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
  Serial.print("Connection Established");
  Serial.print("Connecting to Adafruit");
  while(mqtt.connect())
  {
    Serial.print(".");
  }
  Serial.print("Connected to adafruit");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (mqtt.connected())
  {
    int data=analogRead(A0);
    Serial.println(data);
    if(feed.publish(data)){
      Serial.print("Success");
      if(data==1024)
      digitalWrite(16,LOW);
      else
      digitalWrite(16,HIGH);
    }
    else{
      Serial.print("Failed");
      
    }
    
  }
  delay(2500);
}
