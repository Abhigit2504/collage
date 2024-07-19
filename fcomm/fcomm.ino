#include <EEPROM.h>
#include "GravityTDS.h"
#define TdsSensorPin A2
#include <LiquidCrystal.h>
#define Turbsens A0
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
float calibration_value = 9.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;
#define phsens A3
GravityTDS gravityTds;
float temperature = 25,tdsValue = 0;
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS=0;
float ph_act;
float turbidity;
//float tdsValue;
const int Flowsens = A1;
void setup() {
  // put your setup code here, to run once:
 //Serial.begin(9600); //Baud rate: 9600
 Serial.begin(115200);
//espSerial.begin(115200);
  pinMode(Turbsens,INPUT);
  pinMode(Flowsens,INPUT);
  Wire.begin(8);                /* join i2c bus with address 8 */
/*Wire.onReceive(receiveEvent); /* register receive event */
//Wire.onRequest(requestEvent); /* register request event */
//Serial.begin(9600);           

   gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  
    gravityTds.setAdcRange(1024);  
    gravityTds.begin(); 
}

void loop() {
 
 //flow
 X = pulseIn(Flowsens, HIGH);
Y = pulseIn(Flowsens, LOW);
TIME = X + Y;
FREQUENCY = 1000000/TIME;
WATER = FREQUENCY/7.5;
LS = WATER/60;
if(FREQUENCY >= 0)
{
TOTAL = TOTAL + LS;
Serial.println(FREQUENCY);
Serial.println("RATE: ");
Serial.println(WATER);
Serial.println(" L/M");
Serial.println("TOTAL VOLUME:");
Serial.println(TOTAL);
Serial.println("L");
}
//turb
float sensorValue = analogRead(Turbsens);

  turbidity=map(sensorValue,0,850,100,0);
 if(turbidity>=0&&turbidity<=20){
  Serial.println("WATER IS GOOD");
 }
  if(turbidity>20&&turbidity<=40){
  Serial.println("WATER IS cloudy");
 }
 if(turbidity>40){
  Serial.println("WATER IS dirty");
 }
 Serial.println("turbidity:");
Serial.println(turbidity);
  

 //tds
  gravityTds.setTemperature(temperature);  
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();  // then get the value
    Serial.println("tds:");
    Serial.print(tdsValue,0);
    Serial.println("ppm");
    //ph
    for(int i=0;i<10;i++) 
 { 
 buffer_arr[i]=analogRead(phsens);
 delay(30);
 }
 for(int i=0;i<9;i++)
 {
 for(int j=i+1;j<10;j++)
 {
 if(buffer_arr[i]>buffer_arr[j])
 {
 temp=buffer_arr[i];
 buffer_arr[i]=buffer_arr[j];
 buffer_arr[j]=temp;
 }
 }
 }
 avgval=0;
 for(int i=2;i<8;i++)
 avgval+=buffer_arr[i];
 float volt=(float)avgval*5.0/1024/6;
  ph_act = -5.70 * volt + calibration_value;
 Serial.println("ph:");
 Serial.println(ph_act);
 espSerial.println(ph_act);
 espSerial.println(tdsValue);
 espSerial.println(turbidity);
     delay(1000);
}
/*void requestEvent() {
Wire.write(ph_act);
Wire.write(tdsValue);
//Wire.write(turbidity);/*send string on request */
}*/
