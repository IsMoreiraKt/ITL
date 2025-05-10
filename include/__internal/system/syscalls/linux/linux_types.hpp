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
            typedef unsigned short umode_t;
        } /// namespace linux
    } /// namespace system
} /// namespace __internal
} /// namespace itl

#endif // _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__LINUX_TYPES_HPP
