/**
 * @file include/system/syscalls.hpp
 * @brief Provides system call wrappers for memory management.
 * @category System
 *
 * This header defines wrappers for system calls such as mmap and munmap,
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
#ifdef __x86_64__
/**
 * @brief Maps a region of memory (64-bit version).
 *
 * This function wraps the mmap system call, which maps a region of memory
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
 * @return A pointer to the mapped memory region, or nullptr if the
 * mapping fails.
 */
void* mmap(
    unsigned long address, unsigned long length, unsigned long protection,
    unsigned long flags, unsigned long fileDescriptor, unsigned long offset);

#elif __i386__
/**
 * @struct mmap_arg_struct
 * @brief Structure for passing arguments to the mmap system call (32-bit version).
 *
 * This structure encapsulates the parameters required for the mmap system call
 * on 32-bit systems.
 */
typedef struct {
    unsigned long address; ///< The starting address for the mapping (or 0 for kernel-chosen address).
    unsigned long length; ///< The length of the mapping, in bytes.
    unsigned long protection; ///< The desired memory protection of the mapping (e.g., read, write).
    unsigned long flags; ///< Flags that determine the nature of the mapping (e.g., shared, private).
    unsigned long fileDescriptor; ///< The file descriptor of the file to map, or -1 for anonymous mapping.
    unsigned long offset; ///< The offset in the file where the mapping starts.
} mmap_arg_struct;

/**
 * @brief Maps a region of memory (32-bit version).
 *
 * This function wraps the mmap system call, which maps a region of memory
 * into the address space of the calling process. On 32-bit systems, the
 * parameters are passed as a pointer to a mmap_arg_struct.
 *
 * @param arguments A pointer to a mmap_arg_struct containing the parameters
 * for the mapping.
 * @return A pointer to the mapped memory region, or nullptr if the mapping
 * fails.
 */
void* mmap(mmap_arg_struct arguments);

#endif // ifdef __x86_64__

/**
 * @brief Unmaps a region of memory.
 *
 * This function wraps the munmap system call, which unmaps a previously
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
