#ifndef __I2C_H__
#define __I2C_H__

#include <stdio.h>
#include "sdkconfig.h"
#include "driver/i2c_master.h"

#define SCL_IO_PIN CONFIG_I2C_MASTER_SCL
#define SDA_IO_PIN CONFIG_I2C_MASTER_SDA
#define MASTER_FREQUENCY CONFIG_I2C_MASTER_FREQUENCY
#define PORT_NUMBER -1

void init_i2c_bus(i2c_master_bus_handle_t *bus_handle);

#endif // __I2C_H__