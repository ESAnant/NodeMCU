//This is a NodeMCU interfaced with a DHT11 sensor and a Common-Anode RGB diode.
#include "DHT.h"   //Install the dht library from library manager and include it here     
#define DHTTYPE DHT11   //Define the type of DHT sensor used here
#define dht_dpin 5     // Set the pin number for DHT signal pin
DHT dht(dht_dpin, DHTTYPE); 
int RED = 14; //Set pin number for Red pin
int GREEN = 16;//Set pin number for Green pin
int BLUE = 4;//Set pin number for Blue pin
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature Sensor \n\n");
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
    if(t>30){          //Set limits according to the application 
       digitalWrite(RED,LOW);  
       digitalWrite(GREEN,HIGH);
       digitalWrite(BLUE,HIGH);  
     //  Serial.println("Red"); uncomment to check the output and connection
    }
    else if(t>=20 && t<=30){
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,LOW);
      digitalWrite(BLUE,HIGH);
    //  Serial.println("Green");
    }
    else {
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,HIGH);
      digitalWrite(BLUE,LOW);
    //  Serial.println("Blue");
    } 
    delay(1000);
   
}
