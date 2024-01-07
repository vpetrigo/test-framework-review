/**
 * \file
 * \brief
 * \author
 */

#include "temperature.h"

#include <unity.h>

#include "mock_adc.h"


void test_Temperature_Reading_Min(void) {
    adc_read_ExpectAndReturn(ADC_CHANNEL_0, 0);
    const int temperature_reading = temperature_get();
    TEST_ASSERT_EQUAL(-20, temperature_reading);
}

void test_Temperature_Reading_Max(void) {
    adc_read_ExpectAndReturn(ADC_CHANNEL_0, 4095);
    const int temperature_reading = temperature_get();
    TEST_ASSERT_EQUAL(180, temperature_reading);
}
