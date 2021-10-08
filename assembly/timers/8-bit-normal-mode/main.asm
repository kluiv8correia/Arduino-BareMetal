; Blink program
.include "../m328Pdef.inc"

; to calculate the frequency of the trigger ----------
; f_comp = f_osc / (2 * prescaler * (1 + upper_limit))
; ----------------------------------------------------

; defining labels for registers
.def temp = r16
.def overflows = r17

.org 0x0000
rjmp reset

.org 0x0020
rjmp overflow_handler

reset:
    ; using clock select 101 for prescaler 1024 (15625 times for 16MHz XTAL)
    ldi temp, 0b00000101
    out TCCR0B, temp ; load the timer/counter control register B
    
    ; now set the 0th bit of TIMSK0 to enable overflow interrupt
    ldi temp, 0b00000001
    sts TIMSK0, temp ; store direct to data space

    ; set the global interrupt enable bit
    sei

    ; reset the clock
    clr temp
    out TCNT0, temp ; load the timer/counter 0
    sbi DDRB, 5 ; set the 5th bit of DDRD to high

blink:
    sbi PORTB, 5
    rcall delay
    cbi PORTB, 5
    rcall delay
rjmp blink

delay:
    clr overflows ; clear overflow count
    sec_count: ; around 3 seconds
        cpi overflows, 183 ; check and loop until overflow count equals 20
    brne sec_count ; check the SREG Z flag to see if equality is set
    ret

overflow_handler: ; triggered when the TOV0 set in TIFR0 register and cleared by hardware
    inc overflows ; increment counter
    reti