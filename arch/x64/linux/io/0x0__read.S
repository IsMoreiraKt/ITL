# @file arch/x64/linux/io/0x0__read.S
# @brief Implements the read system call for x86_64 Linux.
# @category Input/Output
#
# This assembly file provides the implementation of the read system call
# for x86_64 Linux. It reads data from a file descriptor into a buffer.
# The function follows the x86_64 System V ABI calling convention.
#
# @author Ismael 
# @date May 10th, 2025
section .text
global __read

# @brief Reads data from a file descriptor into a buffer.
#
# @param rdi -> file_descriptor: The file descriptor to read from.
# @param rsi -> buffer: A pointer to the buffer where the read data
# will be stored.
# @param rdx -> count: The number of bytes to read.
# @return rax -> bytes read: The number of bytes read on success, or a negative value on error.
__read:
    mov rax, 0
    syscall
    ret
