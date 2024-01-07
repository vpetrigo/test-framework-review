/**
 * \file
 * \brief
 * \author
 */

#include "temperature.h"

#include <windows.h>

#include <stdio.h>

int main(void) {
    for (;;) {
        printf("Periodic temperature reading: %+4d C\r\n", temperature_get());
        Sleep(2000);
    }

    return 0;
}