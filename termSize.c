#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>


int main() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        printf("Terminal size: %d rows x %d columns\n", w.ws_row, w.ws_col);
    } else {
        perror("Failed to get terminal size");
        return 1;
    }

    return 0;
}
