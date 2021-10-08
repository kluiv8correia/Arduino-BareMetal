; Phase Corrected PWM provides greater resolution for a PWM signal
; It however almost halves in PWM frequency as compared to fast PWM
; used for motor driving, as it is more effective due to dual sloping
; counts from BOTTOM to TOP and then TOP to BOTTOM
.include "./m328Pdef.inc"

.def temp = r16

; set the output pin
sbi DDRD, DDD6
sbi DDRB, DDB5 ; to turn the builtin led off (optional)

; set the limit
ldi temp, 20
out OCR0A, temp

; set the TCCR0A register
ldi temp, (1 << COM0A1) | (1 << WGM00)
out TCCR0A, temp

; set the TCCR0B register
ldi temp, 1 << CS00
out TCCR0B, temp

; loop
loop: rjmp loop