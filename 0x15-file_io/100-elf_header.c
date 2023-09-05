#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_usage_and_exit()
{
    dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
    exit(97);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header; // Use Elf64_Ehdr for 64-bit ELF files, you can use Elf32_Ehdr for 32-bit ELF files

    if (argc != 2)
        print_usage_and_exit();

    // Open the ELF file for reading
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    // Read the ELF header
    if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    // Check if it's a valid ELF file
    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    // Display the ELF header information
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
           header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2], header.e_ident[EI_MAG3],
           header.e_ident[EI_CLASS], header.e_ident[EI_DATA], header.e_ident[EI_VERSION],
           header.e_ident[EI_OSABI], header.e_ident[EI_ABIVERSION], header.e_ident[EI_PAD]);

    printf("  Class:                             ELF%d\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
    printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Unknown");
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header.e_type)
    {
    case ET_NONE:
        printf("NONE (No file type)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

    // Close the file and check for errors during closing
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
        exit(100);
    }

    return 0;
}
