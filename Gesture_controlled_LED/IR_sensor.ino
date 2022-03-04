int ledPin = 13; // choose pin for the LED
int inputPin = 16; // choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status
int led=0;
int count=1;
void setup() 
{ 
   pinMode(ledPin, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input
   Serial.begin(115200);
}

void loop()
{ 
   val = digitalRead(inputPin); // read input value 
 
   if (val == LOW)
   {  
      if (led==1)
      {
        digitalWrite(ledPin,LOW);
        led=0;
      }
      else
      {
        digitalWrite(ledPin,HIGH);
        led=1;
        
      }
   }
    Serial.println(count);
}
