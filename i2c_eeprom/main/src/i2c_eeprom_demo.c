#include "i2c_eeprom_demo.h"

#define EEP_DATA_LEN 17
uint8_t eeprom_write_buf[EEP_DATA_LEN];
uint8_t eeprom_read_buf[EEP_DATA_LEN];
uint32_t eeprom_block_addr = 0x0001;

void i2c_eeprom_demo(void){
    i2c_master_bus_handle_t bus_handle;

    // 初始化 I2C 总线
    init_i2c_bus(&bus_handle);

    // 初始化 EEPROM
    i2c_eeprom_handle_t eeprom_handle = init_eeprom(bus_handle);

    // 数据处理
    init_eeprom_write_buf(eeprom_write_buf,EEP_DATA_LEN);

    while (1) {
        // 写入和读取数据
        rw_data(eeprom_handle);
        // 打印程序
        disp_buf(eeprom_read_buf, EEP_DATA_LEN);
        // 延时
        vTaskDelay(100);
    }
}

void init_eeprom_write_buf(uint8_t *array, size_t len) {
    for (int i = 0; i < len; i++) {
        array[i] = i + eeprom_block_addr;
    }
}

void rw_data(i2c_eeprom_handle_t eeprom_handle) {
    ESP_ERROR_CHECK(i2c_eeprom_write(eeprom_handle, eeprom_block_addr, eeprom_write_buf, EEP_DATA_LEN));
    // 等待 EEPROM 完成
    i2c_eeprom_wait_idle(eeprom_handle);
    ESP_ERROR_CHECK(i2c_eeprom_read(eeprom_handle, eeprom_block_addr, eeprom_read_buf, EEP_DATA_LEN));
}

void disp_buf(uint8_t *buf, int len){
    int i;
    for (i = 0; i < len; i++) {
        printf("%02x ", buf[i]);
        // if ((i + 1) % 16 == 0) {
        //     printf("\n");
        // }
    }
    printf("\n\n");
}
