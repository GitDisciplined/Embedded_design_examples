
_main:

;led_blinking_port_B.c,1 :: 		void main() {
;led_blinking_port_B.c,3 :: 		TRISB= 0X00;
	CLRF       TRISB+0
;led_blinking_port_B.c,5 :: 		while(1)
L_main0:
;led_blinking_port_B.c,7 :: 		PORTB= 0XFF;
	MOVLW      255
	MOVWF      PORTB+0
;led_blinking_port_B.c,8 :: 		delay_ms(1000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
;led_blinking_port_B.c,9 :: 		PORTB= 0X00;
	CLRF       PORTB+0
;led_blinking_port_B.c,10 :: 		delay_ms(1000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
;led_blinking_port_B.c,11 :: 		}
	GOTO       L_main0
;led_blinking_port_B.c,12 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
