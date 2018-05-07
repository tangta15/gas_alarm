/*
 * gas_detect.c
 *
 *  Created on: 2018年4月7日
 *      Author: TT
 */
#include "gas_detect.h"
#include "ctype.h"
#include "osapi.h"
#include "user_config.h"
#include "user_interface.h"
#include "gpio16.h"
#include "gpio.h"

uint16_t run_time;
uint16_t gas_value;
uint16_t last_time;
uint16_t now_time;
bool     warm_up_flag=TRUE;
void ICACHE_FLASH_ATTR gas_detect_start(void)
{
	run_time=system_get_time()/1000000; //取得系统运行的时间，单位秒
	os_printf("the system has runned for %d s\r\n",run_time);
	gas_value= system_adc_read();
	os_printf("the gas value is : %d;\r\n",gas_value);
	PIN_FUNC_SELECT(BEEP_IO_MUX, BEEP_IO_FUNC);
	if(warm_up_flag== TRUE)
	{
		if(run_time<= WARM_UP_TIME )
		{
			os_printf("the system are heating the sensor!");
			warmup_indicate();
		}
		else
		{
			warm_up_flag= FALSE;
			GPIO_OUTPUT_SET(GPIO_ID_PIN(BEEP_IO_NUM), 1);
			os_delay_us(100000);
			GPIO_OUTPUT_SET(GPIO_ID_PIN(BEEP_IO_NUM), 0);
		}

	}

	if(warm_up_flag== FALSE)
	{
		if(gas_value< THRESHOLD)
			   {
				   safe_indicate();
			   }

		if(gas_value>= THRESHOLD)
			{
				GPIO_OUTPUT_SET(GPIO_ID_PIN(BEEP_IO_NUM), 1);
				os_delay_us(100000);
				GPIO_OUTPUT_SET(GPIO_ID_PIN(BEEP_IO_NUM), 0);
				os_delay_us(100000);
				GPIO_OUTPUT_SET(GPIO_ID_PIN(BEEP_IO_NUM), 1);
				os_delay_us(50000);
				GPIO_OUTPUT_SET(GPIO_ID_PIN(BEEP_IO_NUM), 0);
				os_delay_us(50000);
				alarm_indicate();
			}

	}


}
