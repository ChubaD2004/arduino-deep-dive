#ifndef UART_H
#define UART_H

// Initializes the UART module.
void lesson_3_setup();

void lesson_3_loop();

// Transmits a single character.
void uart_send_char(unsigned char data);

// Transmits a null-terminated string.
void uart_send_string(const char* str);
    
void uart_send_hex(uint8_t num);

  

#endif // UART_H