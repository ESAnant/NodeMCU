const int Button = D3; // NodeMCU pin connected to Button's pin
const int Buzzer = D7; // NodeMCU pin connected to Buzzer's pin
 
void setup() {
  Serial.begin(9600);                
  pinMode(Button, INPUT); 
  pinMode(Buzzer, OUTPUT);       
}
 
void loop() {
  int buttonState = digitalRead(Button); // read state
 
  if (buttonState == LOW) {
    Serial.println("The button is being pressed");//When the button is pressed
    digitalWrite(Buzzer, HIGH); // turn on
  }
  else if (buttonState == HIGH) {
    Serial.println("The button is unpressed");//When the button is ideal
    digitalWrite(buzzer, LOW);  // turn off
  }
}
