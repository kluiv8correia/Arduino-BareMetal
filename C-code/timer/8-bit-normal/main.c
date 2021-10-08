#include <avr/io.h>
#include <avr/interrupt.h>

// volatile signals the compiler to not apply any optimization to
// a memory location that may change without any source code mention
volatile uint8_t counter = 0; // only then accessible by ISR

ISR(TIMER0_OVF_vect) {
    counter = counter + 1;
}

int delay(void) {
    counter = 0; // reset the counter
    while(counter < 31); //  roughly half a second per toggle
    return 0; // return from function
}

int main(void) {
    // set the output pin as
    DDRB |= (1 << DDB5);

    // set the timer mask register
    TIMSK0 |= 1 << TOIE0;

    // set the timer control register
    TCCR0B |= (1 << CS00) | (1 << CS02);

    // set the global interrupt
    sei();

    while (1) {
        delay();
        PINB |= (1 << PIN5);
    }
}