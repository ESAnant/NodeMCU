//https://github.com/blynkkk/blynk-library/blob/master/src/BlynkSimpleEsp8266.h
//Download the above file which contains the library needed for the project
//Make a account blynk.cloud and create a new template
#define BLYNK_TEMPLATE_ID "xxxxx"//Write your Template ID from the blynk website 
#define BLYNK_DEVICE_NAME "xxxx"//Write your device name from the blynk website
#define BLYNK_AUTH_TOKEN "xxxxx"//Write the Authorization token from the blynk website
//You can find the above information under device info tab
#include <BlynkSimpleEsp8266.h>
char auth[] = "xxxx";//Paste the authorization token
int RED = 14;//Set the pin for Red
int GREEN = 12;//Set the pin for Green
int BLUE = 13;//Set the pin for Blue
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "SSID", "Password");//Give the SSID and password of your wifi or internet connection
  pinMode(RED, OUTPUT);//Set pinmode as output
  pinMode(GREEN, OUTPUT);//Set pinmode as output 
  pinMode(BLUE, OUTPUT);//Set pinmode as output
  analogWrite(RED,0);//This is for common cathode RGB
  analogWrite(GREEN,0);//This is for common cathode RGB
  analogWrite(BLUE,0);//This is for common cathode RGB
//analogWrite(RED,255);//This is for common anode RGB
//analogWrite(GREEN,255);//This is for common anode RGB
//analogWrite(BLUE,255);//This is for common anode RGB
}
BLYNK_CONNECTED() {
    Blynk.syncAll();
    Blynk.syncVirtual(V0);
    Blynk.syncVirtual(V1);
    Blynk.syncVirtual(V2);
}
BLYNK_WRITE(V0){
  int a = param.asInt();
  analogWrite(RED,a);//If you are using a common cathode RGB
  //int b = map(a,0,255,255,0);//If you are using a common anode RGB
  //analogWrite(RED,b);//If you are using common anode RGB
}

BLYNK_WRITE(V1){
  int c = param.asInt();
  analogWrite(GREEN,c);//If you are using a common cathode RGB
  //int d = map(c,0,255,255,0);//If you are using a common anode RGB
  //analogWrite(GREEN,d);//If you are using common anode RGB
  
}
BLYNK_WRITE(V2){
  int e = param.asInt();
  analogWrite(BLUE,e);//If you are using a common cathode RGB
  //int f = map(BLUE,0,255,255,0);//If you are using a common anode RGB
  //analogWrite(BLUE,f);//If you are using common anode RGB
}
void loop()
{
  Blynk.run();//Start the exchange of data

}
