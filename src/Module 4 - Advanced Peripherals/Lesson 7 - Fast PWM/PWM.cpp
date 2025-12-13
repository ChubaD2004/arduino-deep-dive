#include "PWM.h"
#include <avr/interrupt.h>
#include <Arduino.h>



// --- Initialization Function ---
void lesson_7_setup() {
    // 1. Set the PWM output pin (OC2A = PB3 = Arduino D11) as an output.
    DDRB |= (1 << PB3);

    // 2. Configure Timer2 Control Register A (TCCR2A).
    //    - Set Fast PWM mode (WGM21=1, WGM20=1). TOP is 0xFF.
    //    - Set non-inverting mode (COM2A1=1). This means:
    //      Clear OC2A on compare match, set OC2A at BOTTOM.
    TCCR2A |= (1 << WGM21) | (1 << WGM20) | (1 << COM2A1);
    
    // 3. Configure Timer2 Control Register B (TCCR2B).
    //    - Set prescaler to 64 (CS22=1).
    //    - This starts the timer. PWM frequency will be ~976 Hz.
    //      (16,000,000 Hz / 64 / 256 = 976.56 Hz)
    TCCR2B |= (1 << CS22);

    // 4. Set initial duty cycle (brightness).
    //    OCR2A is the "brightness knob" from 0 (off) to 255 (max).
    //    We start at 0.
    OCR2A = 0;
}

// --- Main Loop ---
void lesson_7_loop() {
    // Fade in from min (0) to max (255)
    // We use 'int' to prevent an infinite loop due to uint8_t overflow.
    for (int brightness = 0; brightness <= 255; brightness++){
        // Update the duty cycle on each step.
        OCR2A = brightness;
        // Wait a short moment to make the transition visible.        
        delay(10);
    }

    // Fade out from max (255) to min (0)
    for (int brightness = 255; brightness >= 0; brightness--) {
        OCR2A = brightness;
        delay(10);
    }    
}
