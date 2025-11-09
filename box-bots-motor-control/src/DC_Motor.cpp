#include "DC_motor.hpp"
#include <Arduino.h>

// Turn Motor 1 ON
void motorOneOn() {
    digitalWrite(MOTOR_ONE_EN, HIGH);
}

// Turn Motor 2 ON
void motorTwoOn() {
    digitalWrite(MOTOR_TWO_EN, HIGH);
}

// Turn both motors OFF
void motorsOff() {
    digitalWrite(MOTOR_ONE_EN, LOW);
    digitalWrite(MOTOR_TWO_EN, LOW);
}

// Optional: initialize pins
void motorsInit() {
    pinMode(MOTOR_ONE_EN, OUTPUT);
    pinMode(MOTOR_TWO_EN, OUTPUT);
    motorsOff();
}
