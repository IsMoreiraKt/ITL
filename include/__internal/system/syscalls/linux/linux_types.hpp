/**
 * @file include/__internal/system/syscalls/linux/linux_types.hpp
 * @brief Defines Linux-specific types for system call wrappers.
 * @category Typing
 *
 * This header provides type definitions specific to Linux system calls.
 * These types are used to standardize and simplify the interaction with
 * Linux kernel-level system calls.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
 * @date May 10th, 2025
 */
#ifndef _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__LINUX_TYPES_HPP
#define _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__LINUX_TYPES_HPP

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
            /**
             * @typedef umode_t
             * @brief Represents a Linux-specific mode type.
             *
             * This type is used to represent file modes and permissions
             * in Linux system calls. It is defined as an unsigned short.
             */
            typedef itl::u16 umode_t;

            /**
             * @typedef off_t
             * @brief Represents a file offset type.
             */
            typedef itl::i64 off_t;

            /**
             * @typedef pollfd
             * @brief Represents a poll file descriptor structure.
             *
             * This structure is used in system calls like poll to monitor
             * multiple file descriptors for events such as readiness for
             * reading or writing.
             */
            typedef struct {
                itl::i32 file_descriptor; ///< The file descriptor to monitor.
                itl::i16 events; ///< The events to monitor (e.g., POLLIN, POLLOUT).
                itl::i16 revents; ///< The events that occurred (set by the kernel).
            } __pollfd;

#if defined __x86_64__
            /**
             * @struct __stat
             * @brief Represents file status information for x86_64 systems.
             *
             * This structure is used to store metadata about files, such as
             * device ID, inode number, file size, and timestamps.
             */
            typedef struct {
                itl::u64 device_id; ///< The ID of the device containing the file.
                itl::u64 inode_number; ///< The inode number of the file.
                itl::u64 links_count; ///< The number of hard links to the file.
                itl::u32 mode; ///< The file mode (permissions and type).
                itl::u32 user_id; ///< The user ID of the file owner.
                itl::u32 group_id; ///< The group ID of the file owner.
                itl::u32 reserved_0; ///< Reserved for future use.
                itl::u64 real_device_id; ///< The ID of the device where the file resides.
                itl::i64 size; ///< The size of the file in bytes.
                itl::i64 block_size; ///< The block size for filesystem I/O.
                itl::i64 number_blocks; ///< The number of blocks allocated to the file.
                itl::u64 last_access_time; ///< The last access time (seconds since epoch).
                itl::u64 last_access_time_nsec; ///< Nanoseconds of the last access time.
                itl::u64 last_modification_time; ///< The last modification time (seconds since epoch).
                itl::u64 last_modification_time_nsec; ///< Nanoseconds of the last modification time.
                itl::u64 last_status_change_time; ///< The last status change time (seconds since epoch).
                itl::u64 last_status_change_time_nsec; ///< Nanoseconds of the last status change time.
                itl::i64 reserved_for_future_use[3]; ///< Reserved fields for future use.
            } __stat;

#else /// i386 architecture
            /**
             * @struct __stat
             * @brief Represents file status information for i386 systems.
             *
             * This structure is used to store metadata about files, such as
             * device ID, inode number, file size, and timestamps.
             */
            typedef struct {
                itl::u64 device_id; ///< The ID of the device containing the file.
                itl::u64 inode_number; ///< The inode number of the file.
                itl::u16 mode; ///< The file mode (permissions and type).
                itl::u16 links_count; ///< The number of hard links to the file.
                itl::u16 user_id; ///< The user ID of the file owner.
                itl::u16 group_id; ///< The group ID of the file owner.
                itl::u64 real_device; ///< The ID of the device where the file resides.
                itl::u64 size; ///< The size of the file in bytes.
                itl::u64 block_size; ///< The block size for filesystem I/O.
                itl::u64 number_blocks; ///< The number of blocks allocated to the file.
                itl::u64 last_access; ///< The last access time (seconds since epoch).
                itl::u64 last_access_nanoseconds; ///< Nanoseconds of the last access time.
                itl::u64 last_modification; ///< The last modification time (seconds since epoch).
                itl::u64 last_modification_nanoseconds; ///< Nanoseconds of the last modification time.
                itl::u64 last_status_change; ///< The last status change time (seconds since epoch).
                itl::u64 last_status_change_nanoseconds; ///< Nanoseconds of the last status change time.
                itl::u64 reserved_for_future_use_4; ///< Reserved fields for future use.
                itl::u64 reserved_for_future_use_5; ///< Reserved fields for future use.
            } __stat;
#endif /// defined __x86_64__
        } /// namespace linux
    } /// namespace system
} /// namespace __internal
} /// namespace itl

#endif // _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__LINUX_TYPES_HPP
