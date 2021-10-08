#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#define INTERVAL 200

uint8_t flag = 1;

ISR(INT0_vect, ISR_NAKED) { // ISR_NAKED enables proper implementation of reti()
    flag = !flag; // start/stop blinking
    reti();
}

int main(void) {
    // there are only 2 pins dedicated to external interrupts
    //set mode for led
    DDRB |= _BV(DDB5);

    // set digitalpin 4 to LOW for pull down action
    DDRD |= _BV(DDD4);
    PORTD &= ~_BV(PORTD4);

    // set the input and set pull up
    DDRD &= ~_BV(DDD2);
    PORTD |= _BV(PORTD2);

    // set the interrupt (check datasheet)
    EICRA |= _BV(ISC01); // fallin edge
    EIMSK |= _BV(INT0); // set the digital 2 as interrupt

    // enable global interrupts
    sei();

    while(1) {
        if (flag == 1) {
            PINB |= _BV(PIN5);
            _delay_ms(INTERVAL);
        }
    }
}