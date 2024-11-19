#define _POSIX_C_SOURCE 199309L
#include "./input.h"
#include "./stopwatch.h"
#include <fcntl.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>


#define ESCAPE_KEY '\x1b'

int main() {
  setNonCanonicalMode(true);

  struct StopWatch stopwatch;
  reset(&stopwatch);

  char C;
  while ((C = getch()) != ESCAPE_KEY ) {
    switch (C) {
    case ' ':
      if (stopwatch.running == false) {
        play(&stopwatch);
      } else {
        stop(&stopwatch);
        stopwatch.running = false;
      }
      break;
    case 'r':
      reset(&stopwatch);
      break;
    default:
      break;
    }
    display(&stopwatch, C);
  }

  setNonCanonicalMode(false);
  return 0;
}