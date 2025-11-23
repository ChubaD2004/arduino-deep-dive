#include <Arduino.h>

// --- Step 1: Lesson Selection ---
// Define which lesson to run. Comment out the others.
// #define LESSON_1_BLINK
// #define LESSON_2_BUTTON
// #define LESSON_3_UART
#define LESSON_4_TIMERS

// --- Step 2: Include Headers based on Selection ---
#ifdef LESSON_1_BLINK
  #include "Module 1 - Digital IO/Lesson 1 - The Blink Re-engineered/Blink.h"
#endif

#ifdef LESSON_2_BUTTON
  #include "Module 1 - Digital IO/Lesson 2 - Reading a Button/Button.h"
#endif

#ifdef LESSON_3_UART
  #include "Module 2 - Communication Protocols/Lesson 3 - UART Communication/UART.h"
#endif

#ifdef LESSON_4_TIMERS
  #include "Module 3 - Timers and Analog Signals/Lesson 4 - Timers and Interrupts/Timer.h"
#endif

// --- Step 3: Main Program Logic ---
void setup() {
  #if defined(LESSON_1_BLINK)
    lesson_1_setup();
  #elif defined(LESSON_2_BUTTON)
    lesson_2_setup();
  #elif defined(LESSON_3_UART)
    lesson_3_setup();
  #elif defined(LESSON_4_TIMERS)
    lesson_4_setup();
  #else
    #error "No lesson selected. Please define a lesson at the top of main.cpp"
  #endif
}

void loop() {
  #if defined(LESSON_1_BLINK)
    lesson_1_loop();
  #elif defined(LESSON_2_BUTTON)
    lesson_2_loop();
  #elif defined(LESSON_3_UART)
    lesson_3_loop();
  #elif defined(LESSON_4_TIMERS)
    lesson_4_loop();
  #endif
}