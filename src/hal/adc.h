/**
 * \file
 * \brief
 * \author
 */

#ifndef TEST_FRAMEWORK_REVIEW_ADC_H
#define TEST_FRAMEWORK_REVIEW_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

enum adc_channels {
    ADC_CHANNEL_0 = 0,
    // private
    ADC_CHANNEL_COUNT
};

void adc_init(void);

uint16_t adc_read(enum adc_channels channel);

#ifdef __cplusplus
}
#endif

#endif /* TEST_FRAMEWORK_REVIEW_ADC_H */
