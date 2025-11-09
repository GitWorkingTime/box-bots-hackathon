#include "Servo_motor.hpp"

Servo servoOne;

// Measured speed: ~1 + 1/3 rotations per second = 480 degrees/sec
const float degPerSec = 480.0;
// Adjusted neutral for this servo
const int NEUTRAL_PWM = 93;

void servoInit() {
    servoOne.attach(SERVO_ONE_PIN);
    servoOne.write(NEUTRAL_PWM); // neutral → stop
}

// Move continuous servo to approximate angle (0-180)
void servoSetAngleOne(int angle) {
    angle = constrain(angle, 0, 180);
    int direction = (angle > NEUTRAL_PWM) ? 1 : -1;          // forward/backward
    float angleChange = abs(angle - NEUTRAL_PWM);            // relative to neutral
    int pwm = (direction > 0) ? 180 : 0;                     // full speed
    int timeMs = (angleChange / degPerSec) * 1000;           // duration in ms

    servoOne.write(pwm);         // start moving
    delay(timeMs);               // wait approximate movement
    // servoOne.write(NEUTRAL_PWM); // stop
}

void returnToOrigin() {
    servoOne.write(NEUTRAL_PWM);
}
