/**
 * \file
 * \brief
 * \author
 */

#include "adc.h"
#include "temperature.h"

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupport_c.h"

TEST_GROUP(TemperatureReading) {

};

TEST(TemperatureReading, Min_Value) {
    mock().expectOneCall("adc_read").withIntParameter("channel", ADC_CHANNEL_0).andReturnValue(0);

    const int temperature_reading = temperature_get();
    mock().checkExpectations();
    mock().clear();

    CHECK_EQUAL(-20, temperature_reading);
}

TEST(TemperatureReading, Max_Value) {
    mock().expectOneCall("adc_read").withIntParameter("channel", ADC_CHANNEL_0).andReturnValue(4095);

    const int temperature_reading = temperature_get();
    mock().checkExpectations();
    mock().clear();

    CHECK_EQUAL(180, temperature_reading);
}

#ifdef __cplusplus
extern "C" {
#endif

uint16_t __wrap_adc_read(enum adc_channels channel) {
    mock_c()->actualCall("adc_read")->withIntParameters("channel", channel);

    return (uint16_t) mock_c()->returnIntValueOrDefault(0);
}

#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS(argc, argv);
}