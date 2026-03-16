#include "headers/debug.h"
#include <NEMain.h>
#include <time.h>

int fpscount = 0;
int seconds_old = 0;
int seconds = 0;
int currentQuads = 0;

int debug_class::GetFPS() {
    // Get time
    time_t unixTime = time(NULL);
    struct tm* timeStruct = gmtime((const time_t *)&unixTime);
    seconds = timeStruct->tm_sec;

    // If new second
    if (seconds != seconds_old)
    {
        // Reset fps count and print current
        seconds_old = seconds;
        printf("\x1b[10;0HFPS: %d", fpscount);
        fpscount = 0;
    }
    return 0;
}

void debug_class::DebugInit() {
    currentQuads = 0;
}

void debug_class::FramePassed() {
    fpscount++;
    printf("\x1b[11;0HCPU: %d", NE_GetCPUPercent());
}