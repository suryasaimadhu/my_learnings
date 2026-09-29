#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(void)
{
    struct winsize window;
    int ret;

    ret = ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

    if (ret < 0) {
        perror("ioctl");
        return 1;
    }

    printf("Rows    : %u\n", window.ws_row);
    printf("Columns : %u\n", window.ws_col);

    return 0;
}
