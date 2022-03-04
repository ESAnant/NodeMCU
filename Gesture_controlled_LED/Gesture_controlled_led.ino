int ledPin = 13; // choose pin for the LED
int inputPin = 16; // choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status
int led=0;// variable for LED state
void setup() 
{ 
   pinMode(ledPin, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input
   Serial.begin(115200);
}

void loop()
{ 
   val = digitalRead(inputPin); // read input value 
 
   if (val == LOW)// object detected
   {  
      if (led==1)// if led state-on
      {
        digitalWrite(ledPin,LOW);// turn led off
        led=0;// set led state-off
      }
      else
      {
        digitalWrite(ledPin,HIGH);// turn led on
        led=1;// set led state-on
        
      }
   }
}
