#include "ADC.h"
#include <avr/io.h>
#include <Arduino.h>
#include "../../Module 2 - Communication Protocols/Lesson 3 - UART Communication/UART.h"



// --- Initialization Function ---
void lesson_5_setup() {
    ADMUX |= (1 << REFS0);

    ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);

}

// --- Main Loop ---
void lesson_5_loop() {
    // Read the analog value from channel 0 (A0)
    uint16_t adc_value = adc_read(0);

    // Send the value over UART
    // We need a function to send a number, not just a string.
    // Let's create a simple one.
    uart_send_string("ADC Value: ");
    uart_send_number(adc_value);
    uart_send_string("\n");

    // Wait a bit to not spam the serial monitor
    delay(500);
}

uint16_t adc_read(uint8_t channel) {
    // 1. Select ADC channel (0-5) and reference voltage (AVCC)
    // Clear the MUX bits (MUX3:0) by applying a mask
    ADMUX &= 0xF0;   // 0xF0 is 11110000 in binary
    // Set the new channel
    ADMUX |= channel;

    // 2. Start a single conversion
    ADCSRA |= (1 << ADSC);


    // 3. Wait for the conversion to complete
    // The ADSC bit is cleared by hardware when the conversion is finished
    while ((ADCSRA & (1 << ADSC))); // Loop as long as ADSC bit is 1
    
    // 4. Read the 10-bit result
    // Read ADCL first, then ADCH, as per the datasheet recommendation    
    uint8_t low_byte = ADCL;
    uint8_t high_byte = ADCH;

    uint16_t result = (high_byte << 8) | low_byte;
   
    // 5. Return the result
    return result;
}

void uart_send_number(uint16_t num) {
    char buffer[7]; // Buffer to hold the string representation of the number
    itoa(num, buffer, 10); // Convert integer to string (base 10)
    uart_send_string(buffer);
}