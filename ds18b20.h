#ifndef DS18B20_H
#define DS18B20_H

#include <stdint.h>

#define DS_ADDR  ((volatile ds18b20_t *)0x20000500)

#define DS_CMD_SEARCH_ROM     0xF0
#define DS_CMD_READ_ROM       0x33
#define DS_CMD_MATCH_ROM      0x55
#define DS_CMD_SKIP_ROM       0xCC
#define DS_CMD_ALARM_SEARCH   0xEC
#define DS_CMD_CONVERT_T      0x44
#define DS_CMD_WRITE_SCRATCH  0x4E
#define DS_CMD_READ_SCRATCH   0xBE
#define DS_CMD_COPY_SCRATCH   0x48
#define DS_CMD_RECALL_E2      0xB8
#define DS_CMD_READ_POWER     0xB4

typedef struct {
    uint8_t  temp_lsb;
    uint8_t  temp_msb;
    uint8_t  th_register;
    uint8_t  tl_register;
    uint8_t  config_register;
    uint8_t  reserved1;
    uint8_t  reserved2;
    uint8_t  reserved3;
    uint8_t  crc8;

    uint8_t  family_code;
    uint8_t  serial_number[6];
    uint8_t  rom_crc;

    int16_t  temperature_log[100];
    uint8_t  log_index;
} ds18b20_t;

void ds18b20_fill(volatile ds18b20_t *ds);

#endif
