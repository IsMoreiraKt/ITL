#
# @file arch/x86/memory/0x5a_mmap.S
# @brief Assembly implementation of the mmap system call for x86 architecture
# (32-bit).
# @category Memory Management
#
# This file provides a low-level wrapper for the mmap system call, which maps
# a region of memory into the address space of the calling process. It follows
# the x86 System V ABI calling convention.
#
# @note This implementation is specific to Linux systems on x86 (32-bit)
# architecture.
#
# @warning The parameters and calling convention differ from the 64-bit version.
#
# @details The mmap system call is invoked using the int 0x80 instruction,
# which is the standard method for system calls in 32-bit Linux.
#
# @author Ismael Moreira
# @date 05.05.2025
#
section .text
global mmap

# @brief Performs the mmap system call.
#
# This function maps a region of memory into the address space of the calling
# process.
#
# @param ebx A pointer to a mmap_arg_struct containing the parameters for
# the mapping.
# @return eax A pointer to the mapped memory region, or -1 if the mapping
# fails.
#
mmap:
    mov $90, %eax # syscall number for mmap (32-bit)
    int $0x80 # invoke syscall
    ret # return to caller (result is in eax)
