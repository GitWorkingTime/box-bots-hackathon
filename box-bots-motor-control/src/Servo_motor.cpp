#include "Servo_motor.hpp"

Servo servoOne;
Servo servoTwo;

void servoInit() {
    servoOne.attach(SERVO_ONE_PIN);
    servoTwo.attach(SERVO_TWO_PIN);
    servoOne.write(90);
    servoTwo.write(90);
}

void servoSetAngleOne(int angle) {
    angle = constrain(angle, 0, 180);
    servoOne.write(angle);
}

void servoSetAngleTwo(int angle) {
    angle = constrain(angle, 0, 180);
    servoTwo.write(angle);
}

void servosOff() {
    servoOne.detach();
    servoTwo.detach();
}
