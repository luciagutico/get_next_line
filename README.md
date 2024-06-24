# get_next_line

The "Get Next Line" project focuses on creating a function that reads and returns a line from a file descriptor. This function simplifies the process of reading lines from files or standard input in C.

Function Details:

    Prototype: char *get_next_line(int fd);
    Parameters:
        fd: The file descriptor to read from.
    Return Value:
        Returns the line read from the file.
        Returns NULL if there is nothing more to read or an error occurs.
    External Functions Used: read, malloc, free
    Buffer Size: Configurable using the BUFFER_SIZE macro.

Key Requirements:

    Must be written in C and adhere to coding standards.
    Handle all allocated memory properly to avoid leaks.
    Include a Makefile with rules for compiling the project (all, clean, fclean, re, and bonus).
    Prepare your code to handle different buffer sizes and line lengths.
