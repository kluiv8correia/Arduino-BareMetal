#include<avr/io.h>
#include <avr/interrupt.h> // use this library

// SUGGESTION: check the datasheet to find out defs
// define ISR
ISR(PCINT0_vect) {
    if (PINB & _BV(PINB4))
        PORTB &= ~_BV(PORTB5);
    else
        PORTB |= _BV(PORTB5);
}

int main(void) {
    // set the  PCMSK0 – Pin Change Mask Register 0
    PCMSK0 |= _BV(PCINT4);

    // set the PCICR – Pin Change Interrupt Control Register
    PCICR |= _BV(PCIE0);

    // enable the output/input
    DDRB |= _BV(DDB5);
    DDRB &= ~_BV(DDB4);
    PORTB |= _BV(PORTB4);

    // enable interrupts by enabling the SREG (global interrupts)
    sei();

    while(1); // NOP
}