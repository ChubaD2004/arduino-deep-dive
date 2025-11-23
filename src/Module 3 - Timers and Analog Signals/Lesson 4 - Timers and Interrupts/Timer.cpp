#include "Timer.h"
#include <avr/io.h>
#include <avr/interrupt.h> // Required for ISR() macro

// --- File-scope variables ---
// This counter is shared across functions in this file only.
// 'volatile' is crucial: tells the compiler that this variable can change unexpectedly.
// 'static' limits its visibility to this file.
volatile static uint8_t interrupt_counter = 0;

// We will toggle the LED every time we count this many interrupts.
// 16,000,000 Hz / 1024 (prescaler) / 256 (8-bit timer) ~= 61 interrupts per second.
const uint8_t INTERRUPT_THRESHOLD = 61;

// --- Initialization Function ---
void lesson_4_setup() {
    // 1. Configure LED pin (PB5) as an output.
    DDRB |= (1 << 5);

    // 2. Configure Timer0
    // Set clock source to clk/1024 to start the timer.
    TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);

    // 3. Enable the Timer0 Overflow Interrupt.
    TIMSK2 |= (1 << TOIE2);

    // 4. Globally enable all interrupts.
    sei();
}

// --- Main Loop (remains empty) ---
void lesson_4_loop() {
    // All the magic happens in the ISR. The main loop can do other things
    // or nothing at all.
}

// --- Interrupt Service Routine ---
// This function is automatically called by the hardware every time Timer0 overflows.
// (Approximately every 16.384 ms with our settings).
ISR(TIMER2_OVF_vect) {
    // Increment our software counter.
    interrupt_counter++;

    // Check if we have reached our desired threshold.
    if (interrupt_counter >= INTERRUPT_THRESHOLD) {
        // If yes, toggle the LED.
        // Writing a '1' to a PINx register bit toggles the corresponding PORTx bit.
        PINB = (1 << 5);

        // And reset the counter to start counting for the next interval.
        interrupt_counter = 0;
    }
}