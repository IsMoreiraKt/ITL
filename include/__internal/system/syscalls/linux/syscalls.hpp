/**
 * @file include/__internal/system/syscalls/linux/syscalls.hpp
 * @brief Defines system call wrappers for Linux.
 * @category System Interaction
 *
 * This header provides architecture-specific wrappers for Linux
 * system calls.
 * Separate implementations are provided for 64-bit (x86_64) and
 * 32-bit (i386) architectures.
 * These wrappers standardize the way system calls are invoked and ensure
 * compatibility across different platforms.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
 * @date May 10th, 2025
 */
#ifndef _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__SYSCALLS_HPP
#define _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__SYSCALLS_HPP

#include "__internal/system/syscalls/linux/linux_types.hpp"
#include "typing/ctypes.hpp"

/**
 * @namespace itl
 * @brief A general-purpose namespace for the ITL library, containing
 * custom STL components, allocators, types, and utilities.
 */
namespace itl {
/**
 * @namespace __internal
 * @brief Namespace for internal ITL components.
 */
namespace __internal {
    /**
     * @namespace system
     * @brief Namespace for system-level utilities and abstractions.
     */
    namespace system {
        /**
         * @namespace linux
         * @brief Namespace for Linux-specific system call wrappers.
         */
        namespace linux {
            extern "C" {
#if defined __x86_64__
            /**
             * @brief Reads data from a file descriptor into a buffer.
             *
             * This function is a wrapper for the  read  system call on
             * x86_64 systems.
             *
             * @param file_descriptor The file descriptor to read from.
             * @param buffer A pointer to the buffer where the read data
             * will be stored.
             * @param count The number of bytes to read.
             * @return The number of bytes read on success, or a negative
             * value on error.
             */
            itl::u64 sys_read(
                itl::u32 file_descriptor,
                itl::char_ptr buffer,
                itl::size_t count);

            /**
             * @brief Writes data from a buffer to a file descriptor.
             *
             * This function is a wrapper for the  write  system call on
             * x86_64 systems.
             *
             * @param file_descriptor The file descriptor to write to.
             * @param buffer A pointer to the buffer containing the data
             * to write.
             * @param count The number of bytes to write.
             * @return The number of bytes written on success, or a
             * negative value on error.
             */
            itl::ssize_t sys_write(
                itl::u32 file_descriptor,
                itl::cstring buffer,
                itl::size_t count);
#else /// i386 architecture
#endif /// __x86_64__
            } /// extern "C"
        } /// namespace linux
    } /// namespace system
} /// namespace __internal
} /// namespace itl

#endif /// _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__SYSCALLS_HPP
