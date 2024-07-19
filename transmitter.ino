#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 4; 
//create an RF24 object
RF24 radio(9,8);  // CE, CSN
int buttonState = 0;
//address through which two modules communicate.
const byte address[6] = "00001";
//Initialise Arduino to NodeMCU (5=Rx & 6=Tx)
SoftwareSerial nodemcu(5, 6);
struct x{
  char phone;
  char button;
};
struct x t;

void setup() {
 
 pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  nodemcu.begin(9600);
  pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  while (!Serial) continue;
   radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}

void loop() {
  char text;
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& buzzer = jsonBuffer.parseObject(nodemcu);
 buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
      t.button= 'a';
      text='a';
      digitalWrite(3,HIGH);
         radio.write(&text, sizeof(text));
      Serial.println("sai");
  } else {
    // turn LED off:
     t.button = 'b';
     text='b';digitalWrite(3, LOW);
    digitalWrite(ledPin, LOW);
  }
  
// radio.write(&text, sizeof(text));
  if (buzzer == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }else{
    if(buzzer["l"]==1 ){
      Serial.println("yes");
      digitalWrite(3,HIGH);
         t.phone= 'a';
         text='a';
         
//          t.fan= 'a';
// radio.write(&text, sizeof(text));
    }if(buzzer["l"]==0){digitalWrite(3,LOW);
     t.phone = 'b';
//        t.fan = 'b';
//  radio.write(&t, sizeof(t));
    }
  }
//  if(t.phone=='a' || t.button=='a')digitalWrite(4,HIGH);
//    if(t.phone=='b' && t.button=='b')digitalWrite(4,LOW);
if(t.phone=='a'|| t.button=='a'){
  text='a';
   radio.write(&text, sizeof(text));
}
if(t.phone=='b'&& t.button=='b'){
  text='b';
   radio.write(&text, sizeof(text));
}
  
  }
