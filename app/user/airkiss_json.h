/*
 * airkiss_json.h
 *
 *  Created on: 2016Äê4ÔÂ1ÈÕ
 *      Author: itmaktub
 */

#ifndef APP_USER_AIRKISS_JSON_H_
#define APP_USER_AIRKISS_JSON_H_

#if defined(GLOBAL_DEBUG)
#define AIRKISS_JSON_DEBUG(format, ...)  log_printf("AIRKISS_JSON: ", format,  ##__VA_ARGS__)
#else
#define AIRKISS_JSON_DEBUG(format, ...)
#endif

int airkiss_json_upload(char * _buf, uint8_t _operation_status, bool _is_gas_detected,uint16_t _gas_value);
int airkiss_json_ask_get(char * _buf, uint64_t _msg_id, char *_user, uint8_t _operation_status, bool _is_gas_detected);
//int airkiss_json_ask_set(char * _buf, uint64_t _msg_id, uint8_t _operation_status, bool _is_gas_detected);

#endif /* APP_USER_AIRKISS_JSON_H_ */
