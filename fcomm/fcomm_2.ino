#define BLYNK_PRINT Serial
#include <SoftwareSerial.h> 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Wire.h>
#define BLYNK_TEMPLATE_ID "TMPLiglBxRU4"
#define BLYNK_DEVICE_NAME "test1"
#define BLYNK_AUTH_TOKEN "131hX1G62i7oCHDZKQJtaibUzVHe8OW8"
char auth[]= BLYNK_AUTH_TOKEN;
char ssid[]="Room-144";
char pass[]="iiits@2022";
BLYNK_WRITE(V0){
  digitalWrite(D7,param.asInt());
}
//BLYNK_WRITE(V1){
 // digitalWrite(D7,param.asInt());

//}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
pinMode(D7,OUTPUT);
Wire.begin(D1, D2); 

Blynk.begin(auth,ssid,pass,"blynk.cloud",80);
 Blynk.virtualWrite(V1,"ABHIVARDHAN TEAM");
}

void loop() {
  // put your main code here, to run repeatedly:
 /*Wire.requestFrom(8, 13); /* request & read data of size 13 from slave */
while(Wire.available()){
char c = Wire.read();
Serial.print(c);
}
*/
if (Serial.available()) {
Serial.write(Serial.read());
}
Blynk.run();
}
