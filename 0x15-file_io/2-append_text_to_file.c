#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int append_text_to_file(const char *filename, char *text_content)
{
    int fd, bytes_written = 0;

    if (filename == NULL)
        return (-1);

    // Open the file for writing, and set the file pointer to the end
    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    // If text_content is not NULL, write the text to the file
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
