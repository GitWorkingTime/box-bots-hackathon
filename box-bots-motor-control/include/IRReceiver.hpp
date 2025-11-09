#ifndef IRRECEIVE_HPP
#define IRRECEIVE_HPP

#include <Arduino.h>

// Define your IR receiver pin
#define IR_RECV_PIN 19

// Function declarations
void irInit();                // Initialize IR receiver
bool irAvailable();           // Check if IR data is available
uint32_t irGetRawData();      // Get raw IR code
void irResume();
#endif
