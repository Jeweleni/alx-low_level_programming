#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void print_usage_and_exit()
{
    dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
    exit(97);
}

int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        print_usage_and_exit();

    // Open source file for reading
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    // Open or create destination file for writing, and truncate if it exists
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

    // Copy content from source to destination
    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        if (write(fd_to, buffer, bytes_read) != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    // Check for read error
    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    // Close both files and check for errors
    if (close(fd_from) == -1 || close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
        exit(100);
    }

    return 0;
}
