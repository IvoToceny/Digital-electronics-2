# Lab 6: Ivo Točený

## Link to your Digital-electronics-2 GitHub repository:

[https://github.com/Ivo-Toceny-222683/Digital-electronics-2/tree/main/Labs/06-lcd](https://github.com/Ivo-Toceny-222683/Digital-electronics-2/tree/main/Labs/06-lcd)

## 1. LCD display module:

In your words, describe what ASCII table is.

ASCII enables computers to display text via encoding characters with 7-bit binary codes. Each character has it own 7-bit code and ASCII contains letters, numbers and other symbols.

## ASCII

(Hand-drawn) picture of time signals between ATmega328P and LCD keypad shield (HD44780 driver) when transmitting three character data De2.

![]()

## Stopwatch

Flowchart figure for TIMER2_OVF_vect interrupt service routine which overflows every 16 ms but it updates the stopwatch LCD approximately every 100 ms (6 x 16 ms = 100 ms). Display tenths of a second and seconds 00:seconds.tenths. Let the stopwatch counts from 00:00.0 to 00:59.9 and then starts again. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

![]()

## Custom characters

Code listing with syntax highlighting of two custom character definition:

```c
/* Variables ---------------------------------------------------------*/
// Custom character definition
uint8_t customChar[8] = {
	0b01010,
	0b11111,
	0b11011,
	0b01110,
	0b00100,
	0b01110,
	0b11011,
	0b11111
};

uint8_t customChar2[8] = {
	0b10000,
	0b11000,
	0b11100,
	0b01110,
	0b00111,
	0b01110,
	0b11100,
	0b11000
};
```

## Kitchen alarm

Consider a kitchen alarm with an LCD, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

![]()