#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int file_fd;
    int saved_stdout;

    char message1[] = "Message 1: Terminal output\n";
    char message2[] = "Message 2: File output\n";
    char message3[] = "Message 3: Terminal output restored\n";

    /* Message 1 goes to the terminal */
    if (write(STDOUT_FILENO, message1, strlen(message1)) < 0) {
        perror("write");
        return 1;
    }

    file_fd = open("redirect.txt",
                   O_CREAT | O_WRONLY | O_TRUNC,
                   0666);

    if (file_fd < 0) {
        perror("open");
        return 1;
    }

    /* Save the current stdout, which points to the terminal */
    saved_stdout = dup(STDOUT_FILENO);

    if (saved_stdout < 0) {
        perror("dup");
        close(file_fd);
        return 1;
    }

    /* Redirect stdout to redirect.txt */
    if (dup2(file_fd, STDOUT_FILENO) < 0) {
        perror("dup2 redirect");
        close(file_fd);
        close(saved_stdout);
        return 1;
    }

    /* Message 2 goes to redirect.txt */
    if (write(STDOUT_FILENO, message2, strlen(message2)) < 0) {
        perror("write");
    }

    /* Restore stdout to the terminal */
    if (dup2(saved_stdout, STDOUT_FILENO) < 0) {
        perror("dup2 restore");
        close(file_fd);
        close(saved_stdout);
        return 1;
    }

    /* Message 3 goes to the terminal */
    if (write(STDOUT_FILENO, message3, strlen(message3)) < 0) {
        perror("write");
    }

    close(file_fd);
    close(saved_stdout);

    return 0;
}
