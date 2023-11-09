#include "max6675.h"
int tank1 = 4;  // Her defineres porten for når tank 1 skal måles  
int tank2 = 3;  // Her defineres porten for når tank 1 skal måles  

int thermoDO = 10;  // Dette er porten for data fra MAX6675
int thermoCS = 9;  // Dette er porten for CS signlet 
int thermoCLK = 11;  // Dette er porten for CLK signalet 

int buttonState1 = 0; 
int buttonState2 = 0;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600);
  pinMode(tank1, INPUT);
  pinMode(tank2, INPUT);  
 
  

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
} 



void loop() {
  delay(500);
  buttonState1 = digitalRead(tank1); 
  buttonState2 = digitalRead(tank2);  // Her defineres hver buttonState som digitalt input fra tank 1 og 2 
  
  if (buttonState1 == HIGH) { 
    Serial.println(String(1)+String(thermocouple.readCelsius()));  // Hvis tank 1 sender signal på logisk 1, skal temperaturen skrived med et 1. tall foran , 
  } 
  if (buttonState2 == HIGH) {
    Serial.println(String(2)+String(thermocouple.readCelsius()));  // Hvis tank 1 sender signal på logisk 1, skal temperaturen skrived med et 1. tall foran , 
  } 

}