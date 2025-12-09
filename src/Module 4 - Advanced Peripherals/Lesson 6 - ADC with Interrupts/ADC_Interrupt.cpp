#include "ADC_Interrupt.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <Arduino.h>
#include "../../Module 2 - Communication Protocols/Lesson 3 - UART Communication/UART.h"

volatile uint16_t adc_result; 

// --- Initialization Function ---
void lesson_6_setup() {
    ADMUX |= (1 << REFS0);

    ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);

    sei();
}

// --- Main Loop ---
void lesson_6_loop() {
    ADCSRA |= (1 << ADSC);

    uart_send_string("ADC Value: ");
    uart_send_number(adc_result);
    uart_send_string("\n");

    delay(500);

}

ISR(ADC_vect) {
    uint8_t low_byte = ADCL;
    uint8_t high_byte = ADCH;
    
    adc_result = (high_byte << 8) | low_byte;
}

