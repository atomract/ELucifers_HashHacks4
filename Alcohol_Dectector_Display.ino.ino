#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9,10);

const int Ao = 0; //A0{S} to A0{U} 
const int Do = 7; //D0{S} to D7{u}
int limit;
int value;
#define CW 8 
#define CCW 9 

//int Contrast = 145;
//LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
mySerial.begin(9600);
Serial.begin(115200);
pinMode(Ao,INPUT); 
pinMode(Do,INPUT); 

pinMode(CW, OUTPUT); 
pinMode(CCW, OUTPUT);
}

void loop() {
digitalWrite(CW,HIGH);  
value = analogRead(Ao);
limit = digitalRead(Do);
Serial.print("Alcohol Level :");
Serial.println(value);
Serial.print("Limit : ");
Serial.println(limit);
delay(100);

if(value>700 ){
digitalWrite(CCW, HIGH); 
mySerial.println("AT+CMGF=1");   
delay(1000);
mySerial.println("AT+CMGS=\"+919354843009\"\r");  
delay(1000);
mySerial.println("Warning");
delay(200);
mySerial.println((char)26);
delay(1000);
}
}
