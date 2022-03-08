#define BLYNK_TEMPLATE_ID "TMPL22u3n8eq"
#define BLYNK_DEVICE_NAME "NodeLemaAnt"
#define BLYNK_AUTH_TOKEN "pqE0iVHHem4604z2159aPoxhbP_kH0Wg"
#include <BlynkSimpleEsp8266.h>
char auth[] = "pqE0iVHHem4604z2159aPoxhbP_kH0Wg";
int RED = 14;
int GREEN = 12;
int BLUE = 13;
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "Anant2", "Adi_1996");
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  analogWrite(RED,255);
  analogWrite(GREEN,255);
  analogWrite(BLUE,255);
  
}
BLYNK_CONNECTED() {
    Blynk.syncAll();
    Blynk.syncVirtual(V0);
    Blynk.syncVirtual(V1);
    Blynk.syncVirtual(V2);
}
BLYNK_WRITE(V0){
  int a = param.asInt();
  int b = map(a,0,255,255,0);
  analogWrite(RED,b);
  
}

BLYNK_WRITE(V1){
  int c = param.asInt();
  int d = map(c,0,255,255,0);
  
  analogWrite(GREEN,d);
  
}
BLYNK_WRITE(V2){
  int e = param.asInt();
  int f = map(e,0,255,255,0);
  analogWrite(BLUE,f);
}
void loop()
{
  Blynk.run();

}
