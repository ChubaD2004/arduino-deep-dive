#ifndef I2C
#define I2C
#include <stdint.h>

void lesson_8_setup();
void lesson_8_loop(); 

void i2c_start(void);

void i2c_stop(void);

void i2c_write(uint8_t data);

#endif 