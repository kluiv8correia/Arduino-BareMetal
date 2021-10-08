.include "../m328Pdef.inc"

; defining some labels
.def temp = r16

rjmp init

init:
    ; set the output, input set by default
    ldi temp, (1 << 5)
    out DDRB, temp

    ; start looping
    super:
        in temp, PINB ; get the input using input register
        lsl temp ; left shift to copy the bit to PB5
        ldi r17, (1 << 4) ; store the value (1 << 4)
        or temp, r17 ; or it with temp
        out PORTB, temp ; apply the value with the pull up bit
    rjmp super