/*
 * gas_detect.h
 *
 *  Created on: 2018年4月7日
 *      Author: TT
 */

#ifndef _GAS_DETECT_H_
#define _GAS_DETECT_H_
#define BEEP_IO_NUM     	5
#define BEEP_IO_MUX     	PERIPHS_IO_MUX_GPIO5_U
#define BEEP_IO_FUNC    	FUNC_GPIO5
#define WARM_UP_TIME        5   // UNIT S   3分钟
#define THRESHOLD       	500 //UNIT PPM  2500ppm

void gas_detect_start(void);
void gas_detect_check(void);

#endif /* APP_DRIVER_GAS_DETECT_H_ */
