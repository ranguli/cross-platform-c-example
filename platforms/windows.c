#ifdef _WIN32
#include <Windows.h>
#include "sleep.h"

void windows_sleep(int milliseconds) {
    Sleep(milliseconds);
}

#endif

