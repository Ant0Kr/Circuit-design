#include <Arduino.h>
#include <Servo.h>
#include "SharpIR.h"

const int mainAngle = 87;
const int rotateAngle = 17;

class API
{
    Servo servo;
    SharpIR* firstIR;
    SharpIR* secondIR;
    SharpIR* thirdIR;
    
    int driveIN1pin;
    int driveIN2pin;
    int driveIN3pin;
    int driveIN4pin;

public:
    void setupServo(int pin);
    void setupDrives(int IN1pin, int IN2pin, int IN3pin, int IN4pin);
    void setupSensors(int firstIRpin, int secondIRpin, int thirdIRpin, long model);
	void setupSensors(int firstIRpin, long firstModel, int secondIRpin, long secondModel, int thirdIRpin, long thirdModel);

    void turnLeft();
    void turnRight();
    void turnStraight();

    void goStraight();
    void goBack();
    void stopDrives();

    int firstIRDistance();
    int secondIRDistance();
    int thirdIRDistance();    
};
