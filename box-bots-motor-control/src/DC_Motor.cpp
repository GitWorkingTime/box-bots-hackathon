#include "DC_motor.hpp"
#include <Arduino.h>


void motorInit(){
    pinMode(RIGHT_MOTOR, OUTPUT);
    pinMode(LEFT_MOTOR, OUTPUT);
}

void turnLeft(){
    digitalWrite(LEFT_MOTOR, LOW);
    digitalWrite(RIGHT_MOTOR, HIGH);
}

void turnRight(){
    digitalWrite(LEFT_MOTOR, HIGH);
    digitalWrite(RIGHT_MOTOR, LOW);
}

void forward(){
    digitalWrite(LEFT_MOTOR, HIGH);
    digitalWrite(RIGHT_MOTOR, HIGH);
}

void stop(){
    digitalWrite(LEFT_MOTOR, LOW);
    digitalWrite(RIGHT_MOTOR, LOW);
}

void motorTest(){
    stop();
    delay(2000);
    forward();
    delay(2000);
    turnLeft();
    delay(2000);
    turnRight();
    delay(2000);
}
