//This code is for common cathode RGB diode using NodeMCU ESP8266.
int RED = D5;//GPIO-14 for NodeMCU
int GREEN = D6;//GPIO-12 for NodeMCU
int BLUE = D7;//GPIO-13 for NodeMCU
void setup() {
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED,LOW);
digitalWrite(GREEN,LOW);
digitalWrite(BLUE,LOW);
}
void loop() {
digitalWrite(RED,HIGH);
digitalWrite(GREEN,LOW);
digitalWrite(BLUE,LOW);
delay(1000);
digitalWrite(RED,LOW);
digitalWrite(GREEN,HIGH);
digitalWrite(BLUE,LOW);
delay(1000);
digitalWrite(RED,LOW);
digitalWrite(GREEN,LOW);
digitalWrite(BLUE,HIGH);
delay(1000);
}
