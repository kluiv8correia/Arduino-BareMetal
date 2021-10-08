#include<avr/io.h>
#include<util/delay.h>

#define INTERVAL 1000

int main(void) {
    DDRB |= _BV(DDB5); // converting to output pin

    while(1) {
        // PORTB |= _BV(PORTB5);
        // _delay_ms(INTERVAL);
        // PORTB &= ~_BV(PORTB5);
        // _delay_ms(INTERVAL);

        PINB = _BV(PIN5); // toggling using pin input register
        _delay_ms(INTERVAL);
    }
}
