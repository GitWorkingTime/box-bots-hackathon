#include "IRReceiver.hpp"
#include <Arduino.h>
#include <IRremote.hpp>


#define IR_RECV_PIN 19
void irInit() {
    IrReceiver.begin(IR_RECV_PIN, true);
}

// Check if new IR data is available
bool irAvailable() {
    return IrReceiver.decode();
}

// Return raw IR data
uint32_t irGetRawData() {
    return IrReceiver.decodedIRData.decodedRawData;
}


// Must call after reading data to resume
void irResume() {
    IrReceiver.resume();
}
