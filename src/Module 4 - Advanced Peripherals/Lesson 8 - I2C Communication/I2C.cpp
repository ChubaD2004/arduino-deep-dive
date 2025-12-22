#include "I2C.h"
#include <avr/interrupt.h>
#include <Arduino.h>
#include "../../Module 2 - Communication Protocols/Lesson 3 - UART Communication/UART.h"


// --- Initialization Function ---
void lesson_8_setup() {
    // 1. Set I2C clock speed to 100 kHz.
    // SCL_freq = CPU_freq / (16 + 2 * TWBR * Prescaler)
    // For Prescaler = 1, TWBR = ( (CPU_freq / SCL_freq) - 16) / 2
    // TWBR = ( (16,000,000 / 100,000) - 16) / 2 = (160 - 16) / 2 = 72
    TWBR = 72;

    // 2. Enable the TWI (I2C) interface.
    // We only set the TWEN bit for now.
    TWCR = (1 << TWEN);
}

// --- Main Loop ---
void lesson_8_loop() {
    uart_send_string("Scanning I2C bus...\n");

    for (int address = 1; address <= 127; address++)
    {
        i2c_start();
        i2c_write((address << 1));
        if ((TWSR & 0xF8) == 0x18){
            uart_send_string("Device found at address 0x");
            uart_send_hex(address); 
            uart_send_string("\n");        
        }
        i2c_stop();
    }
    
    uart_send_string("Scan complete.\n");

    delay(5000);
}

void i2c_start(void) {
    // Send START condition
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    // Wait for TWINT Flag to be set. This indicates that the
    // START condition has been transmitted.
    while (!(TWCR & (1 << TWINT)));
}

void i2c_stop(void) {
    // Transmit STOP condition
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void i2c_write(uint8_t data) {
    // Load data into TWDR Register
    TWDR = data;
    // Start transmission of data
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Wait for TWINT Flag to be set. This indicates that the
    while (!(TWCR & (1 << TWINT)));
}