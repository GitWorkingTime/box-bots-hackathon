#include <stdint.h>
#include <Arduino.h>
#include "DC_motor.hpp"
#include "Servo_motor.hpp"
#include "IRReceiver.hpp"

void setup() {
    Serial.begin(115200);
    irInit();
    motorsInit();
    servoInit();
}

void loop() {
    // Serial.println(irAvailable());
    if(irAvailable()){
        uint32_t code = irGetRawData();
        motorsOff();

        Serial.print("IR Code: 0x");
        Serial.println(code, HEX);
        if(code == 0xE718FF00){
            Serial.println("Forward!!!!!!!");
            motorOneOn();
            motorTwoOn();
        }
        if(code == 0xF708FF00){
            Serial.println("LEFT!!!!");
            motorOneOn();
        }
         if(code == 0xA55AFF00){
            Serial.println("RIGHT!!");
            motorOneOn();
        }
        irResume();
    }
}