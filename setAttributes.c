#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios orig_attr, new_attr;

    // Get the current terminal attributes
    tcgetattr(STDIN_FILENO, &orig_attr);
    new_attr = orig_attr;

    // Disable echo and enable raw mode
    new_attr.c_lflag &= ~(ECHO | ICANON);

    // Set the new terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);

    // Read and process input in raw mode
    char c;
    printf("Enter a character: ");
    read(STDIN_FILENO, &c, 1);
    printf("You entered: %c\n", c);

    // Restore original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_attr);

    return 0;
}
