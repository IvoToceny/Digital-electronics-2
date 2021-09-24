# Lab 1: Ivo Točený

Link to your `Digital-electronics-2` GitHub repository:

   [GitHub link - 01-tools](https://github.com/...)


### Blink example

1. What is the meaning of the following binary operators in C?
   * `|`  - Bit Or
   * `&`  - Bit And
   * `^`  - Bit Xor
   * `~`  - Bit Nor
   * `<<` - Bit Left Shift
   * `>>` - Bit Right Shift

2. Complete truth table with operators: `|`, `&`, `^`, `~`

| **b** | **a** |**b or a** | **b and a** | **b xor a** | **not b** |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |


### Morse code

1. Listing of C code with syntax highlighting which repeats one "dot" and one "comma" on a LED:

```c
#define LED_GREEN   PB5 // AVR pin where green LED is connected
#define DOT_DELAY 100 // Delay in milliseconds
#define COMMA_DELAY 300 // Delay in milliseconds
#define PAUSE_DELAY 150  
#ifndef F_CPU           // Preprocessor directive allows for conditional
                        // compilation. The #ifndef means "if not defined".
# define F_CPU 16000000 // CPU frequency in Hz required for delay
#endif                  // The #ifndef directive must be closed by #endif

int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN); 
    
    // Infinite loop
    while (1)
    {
        Make_D_Morse();
        
        Make_E_Morse();
        
        Make_2_Morse();
    }
    
    
    // Will never reach this
    return 0;
}

void Make_D_Morse()
{
    PORTB = PORTB ^ (1<<LED_GREEN); //LED ON

    _delay_ms(COMMA_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); // LED OFF

    _delay_ms(PAUSE_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); // LED ON
    
    _delay_ms(DOT_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); 

    _delay_ms(PAUSE_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); // LED ON
    
    _delay_ms(DOT_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN);

    _delay_ms(PAUSE_DELAY);
} 

void Make_E_Morse()
{
    PORTB = PORTB ^ (1<<LED_GREEN); // LED ON
    
    _delay_ms(DOT_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN);

    _delay_ms(PAUSE_DELAY);
}

void Make_2_Morse()
{
    PORTB = PORTB ^ (1<<LED_GREEN); // LED ON
    
    _delay_ms(DOT_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN);

    _delay_ms(PAUSE_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); // LED ON
    
    _delay_ms(DOT_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN);

    _delay_ms(PAUSE_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); //LED ON

    _delay_ms(COMMA_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); 

    _delay_ms(PAUSE_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); //LED ON

    _delay_ms(COMMA_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN);

    _delay_ms(PAUSE_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN); //LED ON

    _delay_ms(COMMA_DELAY);

    PORTB = PORTB ^ (1<<LED_GREEN);

    _delay_ms(PAUSE_DELAY);
}
```


2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure]()