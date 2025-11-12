#include <Arduino.h>
#include "Button.h"

// Define pin numbers for clarity. We will use these later.
const int BUTTON_BIT = 2; // PD2
const int LED_BIT = 5;   // PB5

void button_setup() {
  // 1. Configure LED pin (PB5) as an OUTPUT.
  DDRB |= (1 << LED_BIT);
  
  // 2. Configure Button pin (PD2) as an INPUT.
  // We don't need to write to DDRD, because by default all pins are inputs (DDRD is 0x00).
  
  // 3. Enable the internal pull-up resistor for the button pin (PD2).
  // We do this by writing a '1' to the corresponding bit in the PORTD register.
  PORTD |= (1 << BUTTON_BIT);
}

void button_loop() {
  // Check if the button pin (PD2) is LOW (button is pressed).
  // We do this by checking the 2nd bit of the PIND register.
  if ((PIND & (1 << BUTTON_BIT)) == 0) {
    // If pressed, turn the LED ON by setting the 5th bit of PORTB.
    PORTB |= (1 << LED_BIT);
  } else {
    // If not pressed, turn the LED OFF by clearing the 5th bit of PORTB.
    PORTB &= ~(1 << LED_BIT);
  } 
}