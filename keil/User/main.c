#include "delay.h"

#define LED_PORT P1

sbit KEY = P3^7;

void main(void)
{
	unsigned char display = 0;
	unsigned char i = 0, j = 0;
	while (1) {
		//如果按键按下，开始led效果
		if (!KEY) {
			display = 1;
		}
		
		//开始led效果
		if (display) {
			//两两闪烁
			for (j = 0; j < 3; j++) {
				for (i = 0; i < 4; i++) {
					LED_PORT = ~(0x03 << (2 * i));
					delay_ms(500);
				}
			}
			LED_PORT = 0xFF;
			delay_ms(1000);
			
			//交替闪烁
			LED_PORT = 0xaa;
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 3; i++) {
					delay_ms(500);
					LED_PORT = ~LED_PORT;
				}
			}
			LED_PORT = 0xFF;
			delay_ms(1000);
			
			//全体闪烁
			LED_PORT = 0x00;
			for (j = 0; j < 5; j++) {
				delay_ms(500);
				LED_PORT = ~LED_PORT;
			}
			LED_PORT = 0xFF;
			display = 0;    //等待下次按键按下
		}
	}
}
