#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#define MOTOR_ONE_EN 16
#define MOTOR_TWO_EN 17

#include <Arduino.h>
#include "DC_motor.hpp"
// Turn Motor 1 ON
void motorOneOn();

// Turn Motor 2 ON
void motorTwoOn();

// Turn both motors OFF
void motorsOff();

// Optional: initialize pins
void motorsInit();

#endif