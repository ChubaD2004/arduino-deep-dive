#include <Arduino.h>
#include "Module 2 - Communication Protocols/Lesson 3 - UART Communication/UART.h" 

void setup() {
  // Initialize our custom UART module.
  uart_init();
}

void loop() {
  // Send our test string.
  uart_send_string("Hello from ATmega328P!\n"); // \n is the newline character.
  
  // Wait for 2 seconds.
  delay(2000);
}