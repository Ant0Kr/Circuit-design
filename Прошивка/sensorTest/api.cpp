#include "api.h"

void API::setupServo(int pin)
{
    servo.attach(pin);
}

void API::setupDrives(int IN1pin, int IN2pin, int IN3pin, int IN4pin)
{
    driveIN1pin = IN1pin;
    driveIN2pin = IN2pin;
    driveIN3pin = IN3pin;
    driveIN4pin = IN4pin;
    pinMode(IN1pin, OUTPUT);
    pinMode(IN2pin, OUTPUT);
    pinMode(IN3pin, OUTPUT);
    pinMode(IN4pin, OUTPUT);
}

void API::setupSensors(int firstIRpin, int secondIRpin, int thirdIRpin, long model)
{
    firstIR = new SharpIR(firstIRpin, model);  
    secondIR = new SharpIR(secondIRpin, model);  
    thirdIR = new SharpIR(thirdIRpin, model);  
}

void setupSensors(int firstIRpin, long firstModel, int secondIRpin, long secondModel, int thirdIRpin, long thirdModel)
{
	firstIR = new SharpIR(firstIRpin, firstModel);  
    secondIR = new SharpIR(secondIRpin, secondModel);  
    thirdIR = new SharpIR(thirdIRpin, thirdModel);
}

void API::turnLeft()
{
    servo.write(mainAngle - rotateAngle);
}

void API::turnRight()
{
    servo.write(mainAngle + rotateAngle);
}

void API::turnStraight()
{
    servo.write(mainAngle);
}

void API::goStraight()
{
    digitalWrite (driveIN1pin, LOW);
    digitalWrite (driveIN2pin, HIGH);

    digitalWrite (driveIN3pin, LOW);
    digitalWrite (driveIN4pin, HIGH);
}

void API::goBack()
{
    digitalWrite (driveIN1pin, HIGH);
    digitalWrite (driveIN2pin, LOW);

    digitalWrite (driveIN3pin, HIGH);
    digitalWrite (driveIN4pin, LOW);
}

void API::stopDrives()
{
    digitalWrite (driveIN1pin, LOW);
    digitalWrite (driveIN2pin, LOW);

    digitalWrite (driveIN3pin, LOW);
    digitalWrite (driveIN4pin, LOW);
}

int API::firstIRDistance()
{
    return firstIR->distance();
}
    
int API::secondIRDistance()
{
    return secondIR->distance();
}

int API::thirdIRDistance()
{
    return thirdIR->distance();
}


