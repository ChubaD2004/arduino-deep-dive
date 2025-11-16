#include "UART.h"
#include <avr/io.h> 

void uart_init() {
    // 1. Set the Baud Rate for 9600 bps at 16MHz clock.
    unsigned int ubrr_value = 103;
    UBRR0H = (ubrr_value >> 8);
    UBRR0L = ubrr_value;

    // 2. Enable the Transmitter.
    UCSR0B |= (1 << TXEN0); 

    // 3. Set the frame format: 8 data bits, 1 stop bit (8N1).
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send_char(unsigned char data) {
    // Wait for the transmit buffer to be empty.
    while ( (UCSR0A & (1 << UDRE0)) == 0 );
    
    // Put data into the buffer, which initiates the transmission.
    UDR0 = data;
}

// Beginner-friendly version of the function
void uart_send_string(const char* str) {
    // Start with the first character of the string.
    int i = 0;

    // Loop until we find the null terminator character ('\0').
    while (str[i] != '\0') {
        // Send the current character.
        uart_send_char(str[i]);
        
        // Move to the next character.
        i++;
    }
}