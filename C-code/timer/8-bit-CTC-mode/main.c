#include<avr/io.h>

int main(void) {
    // set the output
    DDRD |= _BV(DDD6);

    // set the TCCR0A register for toggle and CTC
    TCCR0A |= _BV(COM0A0) | _BV(WGM01);

    // set the TCCR0B register for prescaler 1024
    TCCR0B |= _BV(CS00) | _BV(CS02);

    // set the OCR0A limit
    OCR0A = 255;

    // indefinately loop
    while(1);
}