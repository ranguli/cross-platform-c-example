#include <unistd.h>
#include "sleep.h"

#include "platforms/posix.h"

void platform_sleep(unsigned int seconds)
{
    sleep(seconds);
}
