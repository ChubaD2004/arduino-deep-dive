#include <Arduino.h>
#include "Blink.h"

/*
=================================================================
 Lesson 1: Blink, The Engineer's Way
=================================================================
*/

void blink_setup() {
  // Set pin PB5 (Arduino pin 13) as an OUTPUT.
  DDRB |= (1 << 5); 
}

void blink_loop() {
  // Turn the LED ON.
  PORTB |= (1 << 5);
  delay(500);

  // Turn the LED OFF.
  PORTB &= ~(1 << 5);
  delay(500);
}