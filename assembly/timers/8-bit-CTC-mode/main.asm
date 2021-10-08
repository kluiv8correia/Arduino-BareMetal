; 8-bit CTC mode usage
.include "../m328Pdef.inc"

.def temp = r16

.org 0x0000
rjmp start

.org 0x0030
start:
    ; TCCR0A to toggle mode and the WGM to CTC mode
    ldi temp, 0b01000010
    out TCCR0A, temp

    ; load prescaler 1024
    ldi temp, 0b00000101
    out TCCR0B, temp

    ; set the OC0A pin to output
    ldi temp, (1 << 6)
    out DDRD, temp

    ; define the OCR0A, compare limit
    ldi temp, 255
    out OCR0A, temp

    ; looping indefinately
    loop: rjmp loop

; NOTE: do NOT use handle the interrupt since the compare flag would get reset only during RETI
; the overhead of this handler won't give the correct output signal on OC0A 