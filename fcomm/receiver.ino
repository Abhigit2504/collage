#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int t=5;
int e=6;
//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
//struct temp{
//  char phone;
//  char button;
//};
//temp t;
void setup()
{
  
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
    pinMode(t,OUTPUT);
  pinMode(e,INPUT);
  //set the address
  radio.openReadingPipe(0, address);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  //Set module as receiver
  radio.startListening();
}

void loop()
{      char text = {0};
  //Read the data if available in buffer
  if (radio.available())
  {Serial.println("kl");

    radio.read(&text, sizeof(text));
//    if(t.phone=='a' || t.button=='a')digitalWrite(3,HIGH);
//    if(t.phone=='b' && t.button=='b')digitalWrite(3,LOW);
//    delay(1000);
    Serial.println(text);
  }
  digitalWrite(t,LOW);
delayMicroseconds(5);
digitalWrite(t,HIGH);
delayMicroseconds(10);
digitalWrite(t,LOW);
unsigned int tim=pulseIn(e,HIGH);
int k=tim*0.034/2;
Serial.println(k);
if(k<15 )digitalWrite(4,HIGH);
if(k>15 )digitalWrite(4,LOW);
if(text=='a'){digitalWrite(3,HIGH);
delay(1000);}
else digitalWrite(3,LOW);
}
