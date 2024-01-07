/**
 * \file
 * \brief
 * \author
 */

#include "temperature.h"

#if defined(_WIN32) || defined(MINGW)
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#endif

#include <stdio.h>

#if defined(_WIN32) || defined(MINGW)
#define sleep(x) Sleep(x * 1000)
#endif

int main(void) {
    for (;;) {
        printf("Periodic temperature reading: %+4d C\r\n", temperature_get());
        sleep(2);
    }

    return 0;
}