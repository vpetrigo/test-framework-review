/**
 * \file
 * \brief
 * \author
 */

#include "temperature.h"

#include "adc.h"

#include <stdint.h>

/**
 * \brief
 * \details It reads values from the ADC channel and convert it to degrees Celsius using a linear equation:
 *  - -20 °C  - 0
 *  - +180 °C - 4095
 *
 *  K = (y2 - y1) / (x2 - x1) -> 200 / 4095 -> 0,049
 *  b = y1 - K * x1 = -20 - 0 = -20
 * \return
 */
int temperature_get(void) {
    const uint16_t adc_value = adc_read(ADC_CHANNEL_0);
    const int32_t k_milli_degree = 49;
    const int32_t b_milli_degree = -20000;
    const int degrees = (k_milli_degree * adc_value + b_milli_degree) / 1000;

    return degrees;
}
