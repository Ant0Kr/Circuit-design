#include "api.h"
API api;

int firstIR = A0;
int secondIR = A1;
int thirdIR = A2;

void setup() {
    api.setupSensors(firstIR, secondIR, thirdIR, 1080);
    Serial.begin(9600);
}

void loop() {
    delay(2000);
    Serial.println("            IR1  IR2  IR3"); 
    Serial.print("Distance:   "); 
    Serial.print(api.firstIRDistance()); 
    Serial.print("    "); 
    Serial.print(api.secondIRDistance()); 
    Serial.print("    "); 
    Serial.println(api.thirdIRDistance()); 
}
