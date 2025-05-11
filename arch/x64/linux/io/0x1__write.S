# @file arch/x64/linux/io/0x1__write.S
# @brief Implements the write system call for x86_64 Linux.
# @category Input/Output
#
# This assembly file provides the implementation of the write system call
# for x86_64 Linux. It writes data from a buffer to a file descriptor.
# The function follows the x86_64 System V ABI calling convention.
#
# @author Ismael Moreira <ismaelmoreirakt@gmail.com>
# @date May 11th, 2025
section .text
global __write

# @brief Writes data from a buffer to a file descriptor.
#
# This function implements the write system call for x86_64 Linux.
# It writes the specified number of bytes from the buffer to the file
# descriptor.
#
# @param rdi -> file_descriptor: The file descriptor to write to.
# @param rsi -> buffer: A pointer to the buffer containing the data to write.
# @param rdx -> count: The number of bytes to write.
# @return rax -> bytes_written: The number of bytes written on success,
# or a negative value on error.
__write:
    mov rax, 1
    syscall
    ret