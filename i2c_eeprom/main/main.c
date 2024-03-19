/*
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */
#include "i2c_eeprom_demo.h"
#include "nvs_flash.h"
#include "esp_event.h"

void app_main(void) {
    i2c_eeprom_demo();
}
