/**
 * \file
 * \brief
 * \author Vladimir Petrigo
 */

#include "adc.h"

#include <stdlib.h>

void adc_init(void)
{
    srand(2024U);
}

uint16_t adc_read(enum adc_channels channel)
{
    if (channel >= ADC_CHANNEL_COUNT) {
        return 0;
    }

    return (uint16_t)((unsigned)rand() % 4096);
}
