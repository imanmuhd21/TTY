# Bare-Metal TTY Stack (STM32F401RE)

A fully bare-metal TTY (teletype) implementation for STM32F401RE using CMSIS only.
This project focuses on **interrupt-driven UART communication**, **RX/TX ring buffer management**, and **line discipline handling**, without relying on HAL, LL, or any third-party libraries.

## Features

* Interactive TTY interface
* Character echo and prompt handling (`>`)
* Backspace support
* Newline handling
* Printable character filtering
* 16-byte RX and TX ring buffers
* Non-blocking main loop design
* ISR-driven UART transmission and reception
* Linear input buffer for line acquisition

## Project Structure

```
Driver Layer
├── gpio.c / gpio.h
├── usart.c / usart.h
├── systick.c / systick.h

Transport Layer
├── ringbuffer.c / ringbuffer.h

TTY Layer
├── ttys.c / ttys.h

Application Layer
└── main.c
```

## UART & Interrupt Design

* CPU sends only the first byte directly to `TDR` to start transmission
* Remaining bytes are transmitted via **TXE ISR**
* TX ring buffer stores outgoing data
* RXNE ISR reads incoming bytes and places them in RX ring buffer
* Echoing is handled safely with TXE gating to avoid race conditions

This ensures minimal CPU usage and avoids blocking delays even during interactive input.

## Ring Buffers

* Separate TX and RX buffers, each fixed at 16 bytes
* Head and tail indices track data
* Detects empty and full conditions
* Safely synchronizes CPU and UART ISRs

## TTY Line Discipline

* Prompts user with `>`
* Echoes typed characters
* Supports backspace and delete
* Handles newline and carriage return
* Filters out non-printable characters
* Buffers full lines for further command processing (command parser not implemented yet)

## Initialization

### ttys_init() / uart2rx_int()

* Initializes GPIO pins and USART peripheral
* Configures TXE and RXNE interrupts
* Initializes TX/RX ring buffers
* Sets up NVIC for USART interrupts
* Prepares TTY line buffer

## Main Loop Example

```c
int main(void)
{
    ttys_init();
    gpio_init(GPIOA, PIN3, ALTFUNC);
    usart_init(USART2, GPIOA, PIN3, ALTFUNC7);
    uart2rx_int();

    while (1) {
        ttys_run(); // Handles line input, echo, and prompt
    }
}
```

## Target Hardware

* MCU: STM32F401RE
* Core: ARM Cortex-M4
* Framework: CMSIS only
* Language: C (bare-metal)

## Purpose

This project demonstrates real-world embedded firmware challenges such as:

* Interrupt-driven UART RX/TX
* RX/TX buffer synchronization
* CPU vs UART baudrate mismatch handling
* Interactive terminal line discipline
* Layered firmware architecture
