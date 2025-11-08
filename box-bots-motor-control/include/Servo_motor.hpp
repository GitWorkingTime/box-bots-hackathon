#ifndef SERVO_MOTOR_HPP
#define SERVO_MOTOR_HPP

#include <Arduino.h>
#include <ESP32Servo.h>

// Change these to your actual servo GPIO pins
#define SERVO_ONE_PIN 18
#define SERVO_TWO_PIN 19


// Function declarations
void servoInit();
void servoSetAngleOne(int angle);
void servoSetAngleTwo(int angle);
void servosOff();

#endif
