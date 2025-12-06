#ifndef ADC_H
#define ADC_H
#include <stdint.h>

void lesson_5_setup();
void lesson_5_loop(); 
void uart_send_number(uint16_t num);

uint16_t adc_read(uint8_t channel);

#endif 