#include "api.h"
API api;

int servoPin = 10;
int driveIN1pin = 7;
int driveIN2pin = 6;
int driveIN3pin = 5;
int driveIN4pin = 4;

int firstIR = A0;
int secondIR = A1;
int thirdIR = A2;

void setup() {
    api.setupServo(servoPin);
    api.setupDrives(driveIN1pin, driveIN2pin, driveIN3pin, driveIN4pin);
    api.setupSensors(firstIR, secondIR, thirdIR, 1080);
    
    api.turnStraight();
    api.goStraight();    
}

void loop() {
    if(api.firstIRDistance() <= 20)
    {
        api.turnLeft();
    }
    else if(api.thirdIRDistance() <= 20)
    {
        api.turnRight();
    }
    else
    {
        api.turnStraight();
    }
}
