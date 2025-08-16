# Arduino Deep Dive: Low-Level Programming

## Project Goal
This repository is dedicated to learning the low-level aspects of programming for AVR microcontrollers (specifically the ATmega328P used in Arduino boards). 
The main goal is to move beyond the high-level Arduino functions and learn how to control the hardware by directly manipulating its registers.

---

## Learning Roadmap
Each lesson will be implemented in two ways for comparison:
1.  **The Arduino Way:** Using standard, high-level Arduino library functions.
2.  **The Engineer's Way:** Achieving the same result by direct register manipulation.

### Module 1: Digital I/O
- [ ] **Lesson 1: The "Blink" Re-engineered**
  - **Goal:** Control a digital output pin to blink an LED.
  - **Concepts:** I/O Ports, Data Direction Registers (`DDRx`), Port Data Registers (`PORTx`).
- [ ] **Lesson 2: Reading a Button**
  - **Goal:** Read the state of a digital input pin.
  - **Concepts:** Input Pull-up Resistors, Port Input Pins Registers (`PINx`).

### Module 2: Communication Protocols
- [ ] **Lesson 3: UART Communication**
  - **Goal:** Send and receive data between the microcontroller and a computer.
  - **Concepts:** UART registers (`UDR0`, `UCSRnA/B/C`, `UBRRn`), Baud Rate, Frame Format.
- [ ] **Lesson 4: I2C Communication**
  - **Goal:** Read data from a simple I2C sensor.
  - **Concepts:** Master/Slave, Start/Stop conditions, Acknowledge bit, I2C registers (`TWBR`, `TWSR`, `TWCR`, `TWDR`).

### Module 3: Timers and Analog Signals
- [ ] **Lesson 5: Timers and Interrupts**
  - **Goal:** Create a precise, non-blocking delay using a hardware timer and interrupts.
  - **Concepts:** Timers/Counters, Prescalers, Interrupt Service Routines (ISR), Timer registers (`TCNTx`, `TCCRxA/B`, `TIMSKx`, `TIFRx`).
- [ ] **Lesson 6: Analog to Digital Conversion (ADC)**
  - **Goal:** Read an analog value from a potentiometer.
  - **Concepts:** ADC principles, voltage reference, ADC registers (`ADMUX`, `ADCSRA`).

*(This roadmap will be updated as the project progresses.)*