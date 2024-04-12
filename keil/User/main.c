#include "delay.h"

#define LED_PORT P1

sbit KEY = P3^7;

void main(void)
{
	unsigned char display = 0;
	unsigned char i = 0, j = 0;
	while (1) {
		//����������£���ʼledЧ��
		if (!KEY) {
			display = 1;
		}
		
		//��ʼledЧ��
		if (display) {
			//������˸
			for (j = 0; j < 3; j++) {
				for (i = 0; i < 4; i++) {
					LED_PORT = ~(0x03 << (2 * i));
					delay_ms(500);
				}
			}
			LED_PORT = 0xFF;
			delay_ms(1000);
			
			//������˸
			LED_PORT = 0xaa;
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 3; i++) {
					delay_ms(500);
					LED_PORT = ~LED_PORT;
				}
			}
			LED_PORT = 0xFF;
			delay_ms(1000);
			
			//ȫ����˸
			LED_PORT = 0x00;
			for (j = 0; j < 5; j++) {
				delay_ms(500);
				LED_PORT = ~LED_PORT;
			}
			LED_PORT = 0xFF;
			display = 0;    //�ȴ��´ΰ�������
		}
	}
}
