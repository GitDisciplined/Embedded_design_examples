#line 1 "E:/PIC16F877A/Mickro C coding/led_blinking_port B_coding/led_blinking_port_B.c"
void main() {

TRISB= 0X00;

while(1)
{
 PORTB= 0XFF;
 delay_ms(1000);
 PORTB= 0X00;
 delay_ms(1000);
}
}
