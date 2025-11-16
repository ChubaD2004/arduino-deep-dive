#ifndef UART_H
#define UART_H

// Initializes the UART module.
void uart_init();

// Transmits a single character.
void uart_send_char(unsigned char data);

// Transmits a null-terminated string.
void uart_send_string(const char* str);

#endif // UART_H