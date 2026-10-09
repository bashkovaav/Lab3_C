#include "ds18b20.h"

void ds18b20_fill(volatile ds18b20_t *ds) {
    int i;

    ds->temp_lsb        = 0x50;
    ds->temp_msb        = 0x05;
    ds->th_register     = 0x7F;
    ds->tl_register     = 0x00;
    ds->config_register = 0x1F;
    ds->reserved1       = 0xFF;
    ds->reserved2       = 0x00;
    ds->reserved3       = 0x10;
    ds->crc8            = 0x00;

    ds->family_code = 0x28;
    for (i = 0; i < 6; i++) {
        ds->serial_number[i] = (uint8_t)(i * 11 + 3);
    }
    ds->rom_crc = 0x00;

    for (i = 0; i < 100; i++) {
        ds->temperature_log[i] = (int16_t)(2000 + i * 5);
    }
    ds->log_index = 0;
}
