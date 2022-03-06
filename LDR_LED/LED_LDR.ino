void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);//Connect the signal pin of LDR to A0
pinMode(16,OUTPUT);//Connect the LED pin to 16
}

void loop() {
  int data=analogRead(A0);//Get the readings from A0
  if(data==1024)//When the signal reaches 1024(dark)
  digitalWrite(16,HIGH);//Turn ON LED
  else
  digitalWrite(16,LOW);//Turn OFF LED
  // put your main code here, to run repeatedly:
}
