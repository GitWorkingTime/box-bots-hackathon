#include <stdint.h>
#include <Arduino.h>
#include <ESP32Servo.h>
#include <IRremote.hpp>
#include "DC_motor.hpp"

#define SERVO_PIN 18
#define IR_PIN 19

#define IR_REMOTE_2 0xE718FF00
#define IR_REMOTE_4 0xF708FF00
#define IR_REMOTE_6 0xA55AFF00
#define IR_REMOTE_5 0xE31CFF00
#define IR_REMOTE_8 0xAD52FF00

Servo trayServo;

uint32_t lastCode = 0;
unsigned long lastSignalTime = 0;
const unsigned long TIMEOUT_MS = 250;

void setup() {
    Serial.begin(115200);
    trayServo.attach(SERVO_PIN);
    IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
    motorInit();
}

void loop() {
    if (IrReceiver.decode()) {
        uint32_t code = IrReceiver.decodedIRData.decodedRawData;
        IrReceiver.resume();

        // Handle repeat signal (0xFFFFFFFF or 0x0)
        if ((code == 0xFFFFFFFF || code == 0x0) && lastCode != 0) {
            code = lastCode;
        } else {
            lastCode = code;
        }

        lastSignalTime = millis();

        Serial.print("IR code: 0x");
        Serial.println(code, HEX);

        if (code == IR_REMOTE_2) {  // Forward
            forward();
        } else if (code == IR_REMOTE_4) {  // Left
            turnLeft();
        } else if (code == IR_REMOTE_6) {  // Right
            turnRight();
        } else if (code == IR_REMOTE_5) {  // Open tray
            stop();
            trayServo.write(160);
            delay(1500);
        } else if (code == IR_REMOTE_8) {  // Close tray
            stop();
            trayServo.write(95);
            delay(1500);
        }
    }

    // Stop after no signal
    if (millis() - lastSignalTime > TIMEOUT_MS) {
        stop();
        lastCode = 0;
    }
}
