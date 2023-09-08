#include <stdio.h>
#include "sleep.h"


int main(void) {
    const int sleep_time = 5000;
    printf("Boy I sure am tired, I'm going to take a %d millisecond nap.\n", sleep_time);

    portable_sleep(sleep_time); // Sleep for 5 seconds

    printf("I do not feel well-rested.\n");

    return 0;
}

