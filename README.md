# Arduino Deep Dive: Low-Level Programming

## Project Goal
This repository is dedicated to learning the low-level aspects of programming for AVR microcontrollers (specifically the ATmega328P used in Arduino boards). 
The main goal is to move beyond the high-level Arduino functions and learn how to control the hardware by directly manipulating its registers.

---

## Learning Roadmap

Each lesson is implemented using direct register manipulation ("The Engineer's Way").
The code for each lesson is located in the `src/` directory, structured by modules.
Schematics are located in the `schematics/` directory.

---

### Module 1: Digital I/O
- [x] **Lesson 1: The Blink Re-engineered**
  - **Goal:** Control a digital output pin to blink an LED.
  - **Concepts:** I/O Ports, Data Direction Registers (`DDRx`), Port Data Registers (`PORTx`).
  - **[Code]**(src/Module%201%20-%20Digital%20IO/Lesson%201%20-%20The%20Blink%20Re-engineered/Blink.cpp)

- [x] **Lesson 2: Reading a Button**
  - **Goal:** Read the state of a digital input pin.
  - **Concepts:** Input Pull-up Resistors, Port Input Pins Registers (`PINx`).
  - **[Code]**(src/Module%201%20-%20Digital%20IO/Lesson%202%20-%20Reading%20a%20Button/Button.cpp)
  - **[Schematic]**(schematics/lesson-02-button-schematic.svg)
    ![Lesson 2 Schematic](./schematics/lesson-02-button-schematic.svg)

### Module 2: Communication Protocols
- [x] **Lesson 3: UART Communication**
  - **Goal:** Send and receive data between the microcontroller and a computer.
  - **Concepts:** UART registers (`UDR0`, `UCSRnA/B/C`, `UBRRn`), Baud Rate, Frame Format.

### Module 3: Timers and Analog Signals
- [x] **Lesson 4: Timers and Interrupts**
  - **Goal:** Create a precise, non-blocking delay using a hardware timer and interrupts.
  - **Concepts:** Timers/Counters, Prescalers, Interrupt Service Routines (ISR), Timer registers (`TCNTx`, `TCCRxA/B`, `TIMSKx`, `TIFRx`).
- [x] **Lesson 5: Analog to Digital Conversion (ADC)**
  - **Goal:** Read an analog value from a potentiometer using a blocking method.
  - **Concepts:** ADC principles, voltage reference, ADC registers (`ADMUX`, `ADCSRA`).

### Module 4 - Advanced Peripherals
- [x] **Lesson 6: ADC with Interrupts**
  - **Goal:** Read analog values asynchronously without blocking the main loop.
  - **Concepts:** ADC Interrupts, `volatile` variables, combining ADC and Interrupt knowledge.
- [x] **Lesson 7: Fast PWM**
  - **Goal:** Control LED brightness using hardware PWM.
  - **Concepts:** PWM principles, Fast PWM Mode, Output Compare Registers (`OCRnx`), Timer Control Registers (`TCCRxA/B`).
  - **[View Schematic](./src/Module%204%20-%20Advanced%20Peripherals/Lesson%207%20-%20Fast%20PWM/schematic/lesson-07-pwm-schematic.svg)**
- [ ] **Lesson 8: I2C Communication**
  - **Goal:** Read data from a simple I2C sensor.
  - **Concepts:** Master/Slave, Start/Stop conditions, Acknowledge bit, I2C registers (`TWBR`, `TWSR`, `TWCR`, `TWDR`).

*(This roadmap will be updated as the project progresses.)*