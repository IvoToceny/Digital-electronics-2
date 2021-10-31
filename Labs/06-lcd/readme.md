Lab 6: Ivo Točený
Link to your Digital-electronics-2 GitHub repository:

https://github.com/your-github-account/repository-name/lab_name

LCD display module
In your words, describe what ASCII table is.

ASCII
(Hand-drawn) picture of time signals between ATmega328P and LCD keypad shield (HD44780 driver) when transmitting three character data De2.

your figure

Stopwatch
Flowchart figure for TIMER2_OVF_vect interrupt service routine which overflows every 16 ms but it updates the stopwatch LCD approximately every 100 ms (6 x 16 ms = 100 ms). Display tenths of a second and seconds 00:seconds.tenths. Let the stopwatch counts from 00:00.0 to 00:59.9 and then starts again. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

your figure

Custom characters
Code listing with syntax highlighting of two custom character definition:
/* Variables ---------------------------------------------------------*/
// Custom character definition
uint8_t customChar[16] = {
    // WRITE YOUR CODE HERE

};
Kitchen alarm
Consider a kitchen alarm with an LCD, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

your figure