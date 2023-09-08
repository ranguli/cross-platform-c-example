#include <Windows.h>
#include "sleep.h"

void platform_sleep(unsigned int seconds)
{
    // On Windows, the Sleep() function expects miliseconds, not seconds.
    // So we must multiply by 1000, but for the sake of completeness we will
    // check that the multiplication operation won't cause an integer overflow.

    // DWORD is equivalent to an unsigned long, so the comparison to UINT_MAX
    // is valid.
    if (seconds > UINT_MAX / 1000)
    {
        return SLEEP_OVERFLOW_ERROR;
    }

    DWORD sleep_duration_milliseconds = (DWORD) seconds * 1000;
    Sleep(sleep_duration_milliseconds);
}
