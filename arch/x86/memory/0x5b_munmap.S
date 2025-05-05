#
# @file arch/x86/memory/0x5b_munmap.S
# @brief Assembly implementation of the munmap system call for x86
# architecture (32-bit).
# @category Memory Management
#
# This file provides a low-level wrapper for the munmap system call, which
# unmaps a previously mapped region of memory from the address space of the
# calling process. It follows the x86 System V ABI calling convention.
#
# @note This implementation is specific to Linux systems on x86 (32-bit)
# architecture.
#
# @details The munmap system call is invoked using the int 0x80 instruction,
# which is the standard method for system calls in 32-bit Linux.
#
# @warning The parameters and calling convention differ from the 64-bit version.
#
# @author Ismael Moreira
# @date 05.05.2025
#
section .text
global munmap

# @brief Performs the munmap system call.
#
# This function unmaps a previously mapped region of memory from the address
# space of the calling process.
#
# @param ebx The starting address of the memory region to unmap.
# @param ecx The length of the memory region to unmap, in bytes.
# @return eax 0 on success, or -1 if the unmapping fails.
#
munmap:
    mov $91, %eax # syscall number for munmap (32-bit)
    int $0x80 # invoke syscall
    ret # return to caller (result is in eax)
