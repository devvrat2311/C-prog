#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include <termios.h>
#include <fcntl.h>

struct Stopwatch {
    struct timespec start_time;
    struct timespec end_time;
    bool running;
};

void start(struct Stopwatch *sw) {
    if (!sw->running) {
        clock_gettime(CLOCK_MONOTONIC, &sw->start_time);
        sw->running = true;
    }
}

void stop(struct Stopwatch *sw) {
    if (sw->running) {
        clock_gettime(CLOCK_MONOTONIC, &sw->end_time);
        sw->running = false;
    }
}

void reset(struct Stopwatch *sw) {
    sw->running = false;
}

double getElapsedTime(const struct Stopwatch *sw) {
    struct timespec end_time;
    if (sw->running) {
        clock_gettime(CLOCK_MONOTONIC, &end_time);
    } else {
        end_time = sw->end_time;
    }
    double start_sec = sw->start_time.tv_sec + sw->start_time.tv_nsec / 1e9;
    double end_sec = end_time.tv_sec + end_time.tv_nsec / 1e9;
    return end_sec - start_sec;
}

void displayTime(struct Stopwatch *sw) {
    printf("\t\tStopwatch\n");

    int seconds = 0, minutes = 0, hours = 0;
    int time = getElapsedTime(sw);

    seconds = time % 60;
    minutes = (time / 60) % 60;
    hours = time / 3600;
    printf("\n\t\t%02d:%02d:%02d\n", hours, minutes, seconds);
    // system("clear");
}

void displayControls() {
    printf("Controls\n S - start/stop  R - Reset  L - Lap\n");
}

void listenEvent(struct Stopwatch *sw) {
    char ch = getchar();
    switch(ch) {
        case 's':
            if(sw->running == false)
                start(sw);
            else
                stop(sw);
            break;
        case 'r':
            reset(sw);
            break;
        case 'q':

    default:
            break;
    }
}

// Set terminal to non-canonical mode for non-blocking input
void setNonCanonicalMode(bool enable) {
    static struct termios oldt;
    struct termios newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); // save old settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // disable buffering and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new settings
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // make getchar non-blocking
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore old settings
    }
}

int main() {
    struct Stopwatch stopwatch = { .running = false };
    fd_set set;
    struct timeval timeout;
    char ch;

    setNonCanonicalMode(true); // Enable non-canonical mode

    start(&stopwatch);
    while(1) {
        system("clear");
        displayTime(&stopwatch);
        displayControls();

        // Monitor stdin for input
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;
        int rv = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);
        if (rv > 0) {
            listenEvent(&stopwatch);
        }

        sleep(1);
    }

    setNonCanonicalMode(false); // Restore canonical mode
    return 0;
}

