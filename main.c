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

int main(void) {

	ws2812b_init();
	erase_leds();

	while(1) {
		send_rgb(255, 0 ,0);
		_delay_ms(50);
	}

	return 0;
}
