#include "Timer.h"
#include <avr/io.h> 

void lesson_4_setup() {
    // Set clock source to clk/1024 to start the timer
    TCCR0B |= (1 << CS00) | (1 << CS02);

    TIMSK0 |= (1 << TOIE0);

    sei();
}

void lesson_4_loop() {

}

