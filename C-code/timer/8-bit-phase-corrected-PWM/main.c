#include<avr/io.h>

int main(void) {
    // set the output
    DDRD |= _BV(DDD6);

    // set the TCCR0A in non-inverting mode
    TCCR0A |= _BV(COM0A1) | _BV(WGM00);

    // set the TCCR0B, no prescaler
    TCCR0B |= _BV(CS00);

    // set the OCR0A, for duty cycle
    OCR0A = (10 * 255 / 100);
}