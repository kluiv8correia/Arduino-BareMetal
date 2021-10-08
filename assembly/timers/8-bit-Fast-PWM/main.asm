; Fast-PWM mode using the 8-bit timer
.include "../m328Pdef.inc"

.def temp = r16

; set the output
sbi DDRD, DDD6
sbi DDRB, DDB5

; setting MAX (non inverting)
ldi temp, (25 * 256 / 100)
out OCR0A, temp

; set the TCCR0A register (non inverting)
ldi temp, (1 << COM0A1) | (1 << WGM01) | (1 << WGM00)
out TCCR0A, temp

; set the TCCR0B register
ldi temp, 1 << CS00
out TCCR0B, temp

; ; set the interrupt mask register (comment since not using ISR)
; ldi temp, 0b00000010
; sts TIMSK0, temp

; ; enable the global interrupts
; sei

; loop
loop: rjmp loop