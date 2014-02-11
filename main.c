/*
 * main.c
 *
 *  Created on: Feb 9, 2014
 *      Author: root
 */

#include <avr/io.h>
#include <util/delay.h>

#include "ws2812b.h"

TRGB LEDS[LED_CNT];

/*
 *			   R		 G		 B
 * 	RED 	11111111 00000000 00000000
 *	BLUE	00000000 00000000 11111111
 *	GREEN	00000000 11111111 00000000
 *	WHITE	11111111 11111111 11111111
 *	PURPLE	11111111 00000000 11111111
 *	YELLOW	11111111 11111111 00000000
 *	LBLUE	00000000 11111111 11111111
 */

int main(void) {

	ws2812b_init();
	erase_leds();

	while(1) {
		send_rgb(255, 0, 0);
		_delay_ms(255);
		send_rgb(0, 255, 0);
		_delay_ms(255);
		send_rgb(0, 0, 255);
		_delay_ms(255);
	}

	return 0;
}
