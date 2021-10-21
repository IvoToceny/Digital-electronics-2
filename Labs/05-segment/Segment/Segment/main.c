/***********************************************************************
 * 
 * Decimal counter with 7-segment output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <util/delay.h>
#include "timer.h"          // Timer library for AVR-GCC
#include "gpio.h"
#include "segment.h"        // Seven-segment display library for AVR-GCC

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Display decimal counter values on SSD (Seven-segment 
 *           display) when 16-bit Timer/Counter1 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Configure SSD signals
    SEG_init();

    // Test of SSD: display number '3' at position 0
    SEG_update_shift_regs(0, 0);

    // Configure 16-bit Timer/Counter1 for Decimal counter
    // Set the overflow prescaler to 262 ms and enable interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();
    
    int counter = 0;

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
        _delay_ms(3000);
        SEG_update_shift_regs(counter, 0);
        counter++;
        
        if(counter == 10)
        {
            counter = 0;
        }
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment decimal counter value and display it on SSD.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
    counter++;
    
    dis0 = counter / 10;
    dis1 = counter % 10;
}

ISR(TIMER0_OVF_vect)
{
    // WRITE YOUR CODE HERE
    static uint8_t pos = 0; 
    static uint8_t dis1 = 0;
    static uint8_t dis0 = 0;
    
    if(pos == 0)
    {
        SEG_update_shift_regs(dis0, 0);
        pos++;
    }
    else
    {
        SEG_update_shift_regs(dis1, 1);
        pos = 0;
    }
}