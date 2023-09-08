#include "sleep.h"

#ifdef _WIN32
#include "platforms/windows.h"
#endif

#ifdef __linux__
#include "platforms/posix.h"
#endif

// Cross-platform sleep function.
// All platform-specific code is in platforms/
// and this function simply serves as a wrapper
// around the platform-specific functions. 
void portable_sleep(int milliseconds) {
    #ifdef _WIN32
    windows_sleep(milliseconds);
    #else 
    posix_sleep(milliseconds);
    #endif
}

