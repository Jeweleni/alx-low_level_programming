#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int create_file(const char *filename, char *text_content)
{
    int fd, bytes_written = 0;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[bytes_written] != '\0')
            bytes_written++;
        if (write(fd, text_content, bytes_written) == -1)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}