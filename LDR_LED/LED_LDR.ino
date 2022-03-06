void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(16,OUTPUT);
}

void loop() {
  int data=analogRead(A0);
  if(data==1024)
  digitalWrite(16,LOW);
  else
  digitalWrite(16,HIGH);
  // put your main code here, to run repeatedly:

}
