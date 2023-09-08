#include <limits.h>

#include "sleep.h"

// Cross-platform sleep function.
void portable_sleep(unsigned int seconds)
{
    platform_sleep(seconds); // The build system includes the appropriate platform-specific version
                             // of this function.
}
