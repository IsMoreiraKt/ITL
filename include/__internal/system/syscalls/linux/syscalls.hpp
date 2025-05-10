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
             * @param file_descriptor The file descriptor to close.
             * @return 0 on success, or a negative value on error.
             */
            itl::i32 sys_close(itl::u32 file_descriptor);

            /**
             * @brief Retrieves file status information.
             *
             * @param filename A pointer to the path of the file to retrieve
             * status information for.
             * @param stat_buffer A pointer to a structure of type __stat
             * where the file status information will be stored.
             * The structure will be populated with data such as file type,
             * size, and timestamps.
             * @return 0 on success, or a negative value on error.
             */
            itl::i32 sys_newstat(
                itl::cstring filename,
                itl::__internal::system::linux::__stat* stat_buffer);

            /**
             * @brief Retrieves file status information for an open
             * file descriptor.
             *
             * @param file_descriptor The file descriptor of the open file
             * to retrieve status information for. This descriptor should
             * be obtained from a prior call to sys_open or similar system
             * calls.
             * @param stat_buffer A pointer to a structure of type __stat
             * where the file status information will be stored.
             * The structure will be populated with data such as file type,
             * size, and timestamps.
             * @return 0 on success, or a negative value on error.
             */
            itl::i32 sys_newfstat(
                itl::u32 file_descriptor,
                itl::__internal::system::linux::__stat* stat_buffer);

            /**
             * @brief Retrieves file status information for a
             * symbolic link.
             *
             * @param filename A pointer to the path of the symbolic link
             * to retrieve status information for.
             * @param stat_buffer A pointer to a structure of type __stat
             * where the file status information will be stored.
             * The structure will be populated with data such as file type,
             * size, and timestamps.
             * @return 0 on success, or a negative value on error.
             */
            itl::i32 sys_newlstat(
                itl::cstring filename,
                itl::__internal::system::linux::__stat* stat_buffer);

            /**
             * @brief Waits for events on multiple file descriptors.
             *
             * @param file_descriptors_array A pointer to an array of
             * __pollfd structures, each representing a file descriptor and
             * the events to monitor.
             * @param file_descriptors_count The number of elements in
             * the file_descriptors_array.
             * @param timeout The time in milliseconds to wait for an event.
             * A value of -1 causes the call to block indefinitely, 0
             * returns immediately, and any positive value specifies the
             * maximum wait time.
             * @return The number of file descriptors with events,
             * 0 on timeout, or a negative value on error.
             */
            itl::i32 sys_pool(
                itl::__internal::system::linux::__pollfd* file_descriptors_array,
                itl::u32 file_descriptors_count,
                itl::i32 timeout);

            /**
             * @brief Repositions the offset of an open file descriptor.
             *
             * @param file_descriptor The file descriptor of the open file
             * whose offset is to be modified.
             * @param offset The number of bytes to offset, relative to
             * the position specified by the whence argument.
             * @param whence The reference point for the offset.
             * It must be one of:
             *    0 (beginning of file),
             *    1 (current position),
             *    2 (end of file).
             * @return The resulting offset from the beginning of the file
             * on success, or a negative value on error.
             */
            itl::__internal::system::linux::off_t sys_lseek(
                itl::u32 file_descriptor,
                itl::__internal::system::linux::off_t offset,
                itl::u32 whence);

            /**
             * @brief Maps files or anonymous memory into the process address space.
             *
             * @param address The preferred starting address for the mapping.
             * If zero, the kernel chooses the address.
             * @param length The number of bytes to map.
             * Must be greater than zero.
             * @param protection Memory protection flags
             * (e.g., read, write, execute).
             * @param flags Mapping flags controlling the nature of the
             * mapping (e.g., shared, private, anonymous).
             * @param file_descriptor The file descriptor to map.
             * Ignored if the mapping is anonymous.
             * @param offset The offset in the file where the mapping starts.
             * Must be aligned to the system page size.
             * @return The starting address of the mapped region on success,
             * or a value in the range -4095 to -1 on error.
             */
            itl::u64 sys_mmap(
                itl::u64 address,
                itl::u64 length,
                itl::u64 protection,
                itl::u64 flags,
                itl::u64 file_descriptor,
                itl::u64 offset);

#else /// i386 architecture

#endif /// __x86_64__

            } /// extern "C"
        } /// namespace linux
    } /// namespace system
} /// namespace __internal
} /// namespace itl

#endif /// _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__SYSCALLS_HPP
