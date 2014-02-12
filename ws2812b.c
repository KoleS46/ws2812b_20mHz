/*
 * ws2812b.c
 *
 *  Created on: Feb 9, 2014
 *      Author: root
 */

#include <avr/io.h>
#include <util/delay.h>

#include "ws2812b.h"


void ws2812b_init(void) {
	WS_DIR |= WS_PIN;
}

static void send_zero(void) {
	WS_PORT |= WS_PIN;
	asm("nop");asm("nop");
	asm("nop");asm("nop");
	asm("nop");
	WS_PORT &= ~WS_PIN;
	asm("nop");asm("nop");
	asm("nop");asm("nop");
	asm("nop");asm("nop");
}

static void send_one(void) {
	WS_PORT |= WS_PIN;
	asm("nop");asm("nop");
	asm("nop");asm("nop");
	asm("nop");asm("nop");
	asm("nop");asm("nop");
	asm("nop");asm("nop");
	asm("nop");
	WS_PORT &= ~WS_PIN;
}

void send_rgb(uint8_t red, uint8_t green, uint8_t blue) {

	if(green & 128) send_one(); else send_zero();
	if(green & 64) send_one(); else send_zero();
	if(green & 32) send_one(); else send_zero();
	if(green & 16) send_one(); else send_zero();
	if(green & 8) send_one(); else send_zero();
	if(green & 4) send_one(); else send_zero();
	if(green & 2) send_one(); else send_zero();
	if(green & 1) send_one(); else send_zero();

	if(red & 128) send_one(); else send_zero();
	if(red & 64) send_one(); else send_zero();
	if(red & 32) send_one(); else send_zero();
	if(red & 16) send_one(); else send_zero();
	if(red & 8) send_one(); else send_zero();
	if(red & 4) send_one(); else send_zero();
	if(red & 2) send_one(); else send_zero();
	if(red & 1) send_one(); else send_zero();

	if(blue & 128) send_one(); else send_zero();
	if(blue & 64) send_one(); else send_zero();
	if(blue & 32) send_one(); else send_zero();
	if(blue & 16) send_one(); else send_zero();
	if(blue & 8) send_one(); else send_zero();
	if(blue & 4) send_one(); else send_zero();
	if(blue & 2) send_one(); else send_zero();
	if(blue & 1) send_one(); else send_zero();
}

void send_color(uint32_t color) {

	uint8_t red = color>>16, green = color>>8, blue = color;

	if(green & 128) send_one(); else send_zero();
	if(green & 64) send_one(); else send_zero();
	if(green & 32) send_one(); else send_zero();
	if(green & 16) send_one(); else send_zero();
	if(green & 8) send_one(); else send_zero();
	if(green & 4) send_one(); else send_zero();
	if(green & 2) send_one(); else send_zero();
	if(green & 1) send_one(); else send_zero();

	if(red & 128) send_one(); else send_zero();
	if(red & 64) send_one(); else send_zero();
	if(red & 32) send_one(); else send_zero();
	if(red & 16) send_one(); else send_zero();
	if(red & 8) send_one(); else send_zero();
	if(red & 4) send_one(); else send_zero();
	if(red & 2) send_one(); else send_zero();
	if(red & 1) send_one(); else send_zero();

	if(blue & 128) send_one(); else send_zero();
	if(blue & 64) send_one(); else send_zero();
	if(blue & 32) send_one(); else send_zero();
	if(blue & 16) send_one(); else send_zero();
	if(blue & 8) send_one(); else send_zero();
	if(blue & 4) send_one(); else send_zero();
	if(blue & 2) send_one(); else send_zero();
	if(blue & 1) send_one(); else send_zero();
}

void send_leds(TRGB * leds) {

	uint8_t i;
	uint8_t * wsk = (uint8_t*)leds;

	for(i = 0; i < LED_CNT; i++) {
		send_rgb(*wsk, *(wsk+1), *(wsk+2));
		wsk += 3;
	}
	_delay_us(7);
}

void erase_leds(TRGB * leds) {
	uint8_t i;

	for(i = 0; i < LED_CNT; i++) {
		send_rgb(0, 0, 0);
	}
	_delay_us(7);
}

