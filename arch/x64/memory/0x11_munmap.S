#
# @file 0x11_munmap.S
# @brief Assembly implementation of the munmap system call for x86_64
# architecture.
# @category Memory Management
#
# This file provides a low-level wrapper for the munmap system call, which
# unmaps a previously mapped region of memory from the address space of the
# calling process.
# It follows the x86_64 System V ABI calling convention.
#
# @note This implementation is specific to Linux systems on x86_64 architecture.
#
# @author Ismael Moreira
# @date 05.05.2025
#
section.text
global munmap

# @brief Performs the munmap system call.
#
# This function unmaps a previously mapped region of memory from the address
# space of the calling process.
#
# @param rdi The starting address of the memory region to unmap.
# @param rsi The length of the memory region to unmap, in bytes.
# @return rax 0 on success, or -1 if the unmapping fails.
#
munmap:
    mov $11, %rax # syscall number for munmap
    syscall # invoke syscall
    ret # return to caller (result is in rax)
