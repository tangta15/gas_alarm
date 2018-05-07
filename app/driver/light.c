/*
 * light.c
 *
 *  Created on: 2018Äê4ÔÂ13ÈÕ
 *      Author: TT
 */
#include "light.h"
#include "c_types.h"
#include "Adafruit_NeoPixel.h"

void ICACHE_FLASH_ATTR
warmup_indicate(void)
{
	setAllPixelColor(150, 0, 0);
	//rainbow(20);
}

void ICACHE_FLASH_ATTR
smartlink_indicate(void)
{
	setAllPixelColor(0, 20, 0);
}
void ICACHE_FLASH_ATTR
airkiss_indicate(void)
{
	setAllPixelColor(0, 0, 50);
}

void ICACHE_FLASH_ATTR
safe_indicate(void)
{
	setAllPixelColor(0, 150, 150);
}

void ICACHE_FLASH_ATTR
alarm_indicate(void)
{
	setAllPixelColor(50, 0, 0);

}

void ICACHE_FLASH_ATTR
fault_indicate(void)
{
	setAllPixelColor(50, 0, 0);
}

void ICACHE_FLASH_ATTR
test_indicate(void)
{
	colorWipe(Color(20, 0, 0), 5);

}



