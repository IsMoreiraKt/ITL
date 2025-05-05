/**
 * @file syscalls.hpp
 * @brief Provides system call wrappers for memory management.
 * @category System
 *
 * This header defines wrappers for system calls such as `mmap` and `munmap`,
 * which are used for memory mapping and unmapping in Linux systems.
 *
 * @note These functions are only available on Linux systems.
 *
 * @author Ismael Moreira
 * @date 05.05.2025
 */
#ifndef _ITL_SYSTEM_SYSCALLS_HPP
#define _ITL_SYSTEM_SYSCALLS_HPP

#include "typing/ctypes.hpp"

/**
 * @namespace itl
 * @brief A general-purpose namespace for the ITL library, containing
 * custom STL components, allocators, types, and utilities.
 */
namespace itl {
extern "C" {
#ifdef __linux__
/**
 * @brief Maps a region of memory.
 *
 * This function wraps the `mmap` system call, which maps a region of memory
 * into the address space of the calling process.
 *
 * @param address The starting address for the mapping. If set to 0, the kernel
 * will choose the address.
 * @param length The length of the mapping, in bytes.
 * @param protection The desired memory protection of the mapping
 * (e.g., read, write).
 * @param flags Flags that determine the nature of the mapping
 * (e.g., shared, private).
 * @param fileDescriptor The file descriptor of the file to map, or -1 for
 * anonymous mapping.
 * @param offset The offset in the file where the mapping starts.
 * @return A pointer to the mapped memory region, or `nullptr` if the
 * mapping fails.
 */
void* mmap(
    unsigned long address, unsigned long length, unsigned long protection,
    unsigned long flags, unsigned long fileDescriptor, unsigned long offset);

/**
 * @brief Unmaps a region of memory.
 *
 * This function wraps the `munmap` system call, which unmaps a previously
 * mapped region of memory.
 *
 * @param address The starting address of the memory region to unmap.
 * @param length The length of the memory region to unmap, in bytes.
 * @return 0 on success, or -1 if the unmapping fails.
 */
int munmap(unsigned long address, itl::size_t length);
#endif // #ifdef __linux__
}; // extern "C"
} // namespace itl

#endif // _ITL_SYSTEM_SYSCALLS_HPP
