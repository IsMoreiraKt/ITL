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

            /**
             * @brief Opens a file and returns a file descriptor.
             *
             * This function is a wrapper for the open system call on
             * x86_64 systems.
             *
             * @param filename A pointer to the path of the file to open.
             * @param flags The flags for opening the file
             * (e.g., read, write).
             * @param mode The mode to set if a new file is created.
             * @return The file descriptor on success, or a negative value
             * on error.
             */
            itl::i64 sys_open(
                itl::cstring filename,
                itl::i32 flags,
                itl::__internal::system::linux::umode_t mode);

            /**
             * @brief Closes an open file descriptor.
             *
             * This function is a wrapper for the close system call on
             * x86_64 systems. It releases the file descriptor, making it
             * available for reuse. After calling this function, the file
             * descriptor should not be used unless reopened.
             *
             * @param file_descriptor The file descriptor to close.
             * @return 0 on success, or a negative value on error.
             */
            itl::i32 sys_close(itl::u32 file_descriptor);

            /**
             * @brief Retrieves file status information.
             *
             * This function is a wrapper for the stat system call on
             * x86_64 systems. It retrieves detailed information about a
             * file specified by its path, such as file size, permissions,
             * and modification times, and stores the information in the
             * provided stat_buffer.
             *
             * @param filename A pointer to the path of the file to retrieve
             * status information for.
             * @param stat_buffer A pointer to a structure of type __stat 
             * where the file status information will be stored.
             * The structure will be populated with data such as file type,
             * size, and timestamps.
             * @return 0 on success, or a negative value on error.
             */
            itl::i32 newstat(
                itl::cstring filename,
                itl::__internal::system::linux::__stat* stat_buffer);

#else /// i386 architecture
#endif /// __x86_64__
            } /// extern "C"
        } /// namespace linux
    } /// namespace system
} /// namespace __internal
} /// namespace itl

#endif /// _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__SYSCALLS_HPP
