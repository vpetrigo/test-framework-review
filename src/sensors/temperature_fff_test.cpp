/**
 * \file
 * \brief
 * \author
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

#include "adc.h"
#include "temperature.h"

FAKE_VALUE_FUNC(uint16_t, adc_read, enum adc_channels);

TEST_GROUP(FFF_TemperatureReading){
    void setup() override {
        RESET_FAKE(adc_read);
    }
};

TEST(FFF_TemperatureReading, Min_Value) {
    adc_read_fake.return_val = 0;

    const int temperature_reading = temperature_get();

    CHECK_EQUAL(-20, temperature_reading);
    CHECK_EQUAL(1, adc_read_fake.call_count);
}

TEST(FFF_TemperatureReading, Max_Value) {
    adc_read_fake.return_val = 4095;

    const int temperature_reading = temperature_get();

    CHECK_EQUAL(180, temperature_reading);
    CHECK_EQUAL(1, adc_read_fake.call_count);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS(argc, argv);
}