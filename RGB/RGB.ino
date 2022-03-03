int RED = D8;
int GREEN = D2;
int BLUE = D3;
void setup() {
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED,HIGH);
digitalWrite(GREEN,HIGH);
digitalWrite(BLUE,HIGH);
}
void loop() {
digitalWrite(RED,LOW);
digitalWrite(GREEN,HIGH);
digitalWrite(BLUE,HIGH);
delay(1000);
digitalWrite(RED,HIGH);
digitalWrite(GREEN,LOW);
digitalWrite(BLUE,HIGH);
delay(1000);
digitalWrite(RED,HIGH);
digitalWrite(GREEN,HIGH);
digitalWrite(BLUE,LOW);
delay(1000);
}
