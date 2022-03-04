#include "DHT.h"        
#define DHTTYPE DHT11   
#define dht_dpin 5
DHT dht(dht_dpin, DHTTYPE); 
int RED = 14;
int GREEN = 16;
int BLUE = 4;
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature \n\n");
  Serial.println("==========================================");
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}
void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    if(t>30){
       digitalWrite(RED,LOW);
       digitalWrite(GREEN,HIGH);
       digitalWrite(BLUE,HIGH);  
    }
    else if(t>=20 && t<=30){
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,LOW);
      digitalWrite(BLUE,HIGH);
      Serial.println("green");
    }
    else {
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,HIGH);
      digitalWrite(BLUE,LOW);
      Serial.println("blue");
    } 
    delay(1000);
   
}
