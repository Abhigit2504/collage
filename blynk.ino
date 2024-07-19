#define BLYNK_PRINT Serial
#include <SoftwareSerial.h> 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPLb7C9b3Ai"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "el0Kui2VnjjMKPi4JenwCAa9WUvdqC7_"

char auth[]= BLYNK_AUTH_TOKEN;
char ssid[]="abhi";
char pass[]="abhi1234";
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//D6 = Rx & D5 = Tx
SoftwareSerial nodemcu(D6, D5);
//SoftwareSerial nodemcu1(D4, D3);

BLYNK_WRITE(V3){
digitalWrite(D7,param.asInt());
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& buzzer = jsonBuffer.createObject();
  if(param.asInt()){
    digitalWrite(D7,HIGH);
    buzzer["l"]=1;
     buzzer.printTo(nodemcu);
  jsonBuffer.clear();
  }else {
    buzzer["l"]=0;
      digitalWrite(D7,LOW);
     buzzer.printTo(nodemcu);
  jsonBuffer.clear();
  }

}


void setup() {
  // put your setup code here, to run once:
pinMode(D7,OUTPUT);

Blynk.begin(auth,ssid,pass,"blynk.cloud",80);
 nodemcu.begin(9600);

  while (!Serial) continue;
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
  
}
