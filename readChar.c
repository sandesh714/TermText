#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios orig_attr, new_attr;

    // Get the current terminal attributes
    tcgetattr(STDIN_FILENO, &orig_attr);
    new_attr = orig_attr;

    // Disable canonical mode (line buffering)
    new_attr.c_lflag &= ~(ICANON);

    // Set the new terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);

    char c;
    printf("Enter characters (press 'q' to quit):\n");

    while (1) {
        read(STDIN_FILENO, &c, 1);
        if (c == 'q') {
            break;
        }
        printf("You entered: %c\n", c);
    }

    // Restore original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_attr);

    return 0;
}
