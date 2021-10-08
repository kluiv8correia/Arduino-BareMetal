; Simple blinking program
; blinks digital pin 13 or PB5 (PORTB)
.include "./m328Pdef.inc"

; load the value into register 16
; ldi loads into the upper half register r16-r31
ldi r16, (1 << 5)

; output to data direction register, mode set to output
out DDRB, r16

; set the pin
out PORTB, r16

; loop forever
loop: rjmp loop
