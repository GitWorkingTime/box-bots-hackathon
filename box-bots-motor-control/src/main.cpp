#include <Arduino.h>
#include "DC_motor.hpp"
#include "Servo_motor.hpp"


void setup() {
    Serial.begin(115200);
    motorsInit();
    servoInit();
    motorOneOn();
    motorTwoOn();
    delay(10000);
    motorsOff();
}

void loop() {
    // if (Serial.available() > 0) {
    //     int angle = Serial.parseInt();  // read the number you type
    //     servoSetAngleOne(angle);      // move Servo 1
    //     Serial.print("Servo 1 moved to ");
    //     Serial.println(angle);
    // }

    // Serial.print("Servo 1 moved to ");
    // Serial.println(angle)
    // for(int i = 0; i < 180; i++){
    //     servoSetAngleOne(i);
    //     delay(10);
    // }
    // for(int i = 180; i > 0; i--){
    //     servoSetAngleOne(i);
    //     delay(10);
    // }
    //  motorOneOn();
    // delay(1000);
    
    // motorsOff();
    // delay(500);

    // motorTwoOn();
    // delay(1000);

    // motorsOff();
    // delay(500);
}