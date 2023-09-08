#include <unistd.h>
#include "sleep.h"

void posix_sleep(int milliseconds) {
    usleep(milliseconds * 1000); // Convert milliseconds to microseconds
}

