#include<avr/io.h>
#include<util/delay.h>

#define INTERVAL 100

int main(void) {
    // set the pin to input (by default on startup all are inputs)
    DDRB &= ~_BV(DDB4); // digitalpin 12

    DDRB |= _BV(DDB5); // pinmode digitalpin 13 to output

    PORTB |= _BV(PORTB4); // set the pullup resistor

    // now start looping and send the input to pin 13
    while(1) {
        uint8_t reading = PINB & _BV(PINB4);
        if(reading)
            DDRB |= _BV(DDB5);
        else
            DDRB &= ~_BV(DDB5);
        
        _delay_ms(INTERVAL);
    }
}