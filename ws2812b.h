/*
 * ws2812b.h
 *
 *  Created on: Feb 9, 2014
 *      Author: root
 */

#ifndef WS2812B_H_
#define WS2812B_H_

#define WS_PIN (1<<PB0)
#define WS_PORT PORTB
#define WS_DIR DDRB

#define LED_CNT 15

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} TRGB;

void ws2812b_init(void);
void send_color(uint32_t color);
void send_rgb(uint8_t red, uint8_t green, uint8_t blue);
void send_leds(TRGB * leds);
void erase_leds();

#endif /* WS2812B_H_ */
