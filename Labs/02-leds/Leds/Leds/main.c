/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_0   PC4
#define LED_1   PC3 
#define LED_2   PC2 
#define LED_3   PB5 
#define LED_4   PB4 
#define BUTTON    PD0
#define BLINK_DELAY 200
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/sfr_defs.h>
#include <stdbool.h>

/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Green LED at port B
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_0);
    PORTC = PORTC & ~(1<<LED_0);

    DDRC = DDRC | (1<<LED_1);
    PORTC = PORTC  & ~(1<<LED_1);
	
	DDRC = DDRC | (1<<LED_2);
	PORTC = PORTC & ~(1<<LED_2);
	
	DDRB = DDRB | (1<<LED_3);
	PORTB = PORTB & ~(1<<LED_3);
	
	DDRB = DDRB | (1<<LED_4);
	PORTB = PORTB & ~(1<<LED_4);
    
    // Configure Push button at port D and enable internal pull-up resistor
    DDRD = DDRD & ~(1<<BUTTON);
    PORTD = PORTD | (1<<BUTTON);
    
	int counter = 0;
	bool appSwitch = false;
	bool isAddingDirection = false;
	
    // Infinite loop
    while (1)
    {      	
        if(bit_is_clear(PIND, BUTTON))    
        {
			appSwitch = !appSwitch;
			loop_until_bit_is_set(PIND, BUTTON);
			if(counter > 2)
			{
				PORTB = PORTB ^ (1<<counter);
			}
			else
			{
				PORTC = PORTC ^ (1<<counter);
			}
        }
		
		if(appSwitch)
		{		
			switch (counter)
			{
				case 0:
					PORTB = PORTB ^ (1<<LED_1);
					PORTC = PORTC ^ (1<<LED_0);
					isAddingDirection = true;
					break;
				case 1:
					if(isAddingDirection)
					{
						PORTC = PORTC ^ (1<<LED_0);
						PORTC = PORTC ^ (1<<LED_1);
					}
					else
					{
						PORTC = PORTC ^ (1<<LED_2);
						PORTC = PORTC ^ (1<<LED_1);
					}
					break;
				case 2:
					if(isAddingDirection)
					{
						PORTC = PORTC ^ (1<<LED_1);
						PORTC = PORTC ^ (1<<LED_2);
					}
					else
					{
						PORTB = PORTB ^ (1<<LED_3);
						PORTC = PORTC ^ (1<<LED_2);
					}
					break;
				case 3:
					if(isAddingDirection)
					{
						PORTC = PORTC ^ (1<<LED_2);
						PORTB = PORTB ^ (1<<LED_3);
					}
					else
					{
						PORTB = PORTB ^ (1<<LED_4);
						PORTB = PORTB ^ (1<<LED_3);
					}
					break;
				case 4:
					PORTB = PORTB ^ (1<<LED_3);
					PORTB = PORTB ^ (1<<LED_4);
					isAddingDirection = false;
					break;
			}
						
			isAddingDirection ? counter++ : counter--;
			_delay_ms(BLINK_DELAY);
		}
    }

    // Will never reach this
    return 0;
}

