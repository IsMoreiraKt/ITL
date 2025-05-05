#
# @file arch/x64/memory/0x9_mmap.S
# @brief Assembly implementation of the mmap system call for x86_64
# architecture.
# @category Memory Management
#
# This file provides a low-level wrapper for the mmap system call, which maps
# a region of memory into the address space of the calling process. It follows
# the x86_64 System V ABI calling convention.
#
# @note This implementation is specific to Linux systems on x86_64
# architecture.
#
# @author Ismael Moreira
# @date 05.05.2025
#
section.text
global mmap

# @brief Performs the mmap system call.
#
# This function maps a region of memory into the address space of the calling
# process.
#
# @param rdi The starting address for the mapping
# (or 0 for kernel-chosen address).
# @param rsi The length of the mapping, in bytes.
# @param rdx The desired memory protection of the mapping (e.g., read, write).
# @param r10 Flags that determine the nature of the mapping
# (e.g., shared, private).
# @param r8 The file descriptor of the file to map, or -1 for anonymous
# mapping.
# @param r9 The offset in the file where the mapping starts.
# @return rax A pointer to the mapped memory region, or -1 if the mapping fails.
#
mmap:
    mov $9, %rax # syscall number for mmap
    syscall # invoke syscall
    ret # return to caller (result is in rax)
