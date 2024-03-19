#ifndef __I2C_EEPROM_DEMO__
#define __I2C_EEPROM_DEMO__

#include <string.h>
#include <stdio.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "driver/i2c_master.h"
#include "i2c.h"
#include "eeprom.h"

void i2c_eeprom_demo(void);
void init_eeprom_write_buf(uint8_t *array, size_t len);
void rw_data(i2c_eeprom_handle_t eeprom_handle);
void disp_buf(uint8_t *buf, int len);

#endif // __I2C_EEPROM_DEMO__
