/**
 * @file include/__internal/system/syscalls/linux/impl_syscalls.hpp
 * @brief Provides implementations for Linux system call wrappers.
 * @category System Interaction
 *
 * This header defines the implementation of low-level Linux system call
 * wrappers. These functions interact directly with the kernel using
 * architecture-specific conventions and structures.
 *
 * The implementations are designed to standardize system call handling
 * across different platforms and provide a consistent interface for
 * higher-level abstractions.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
 * @date May 10th, 2025
 */
#ifndef _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__IMPLEMENTATION_SYSCALLS_HPP
#define _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__IMPLEMENTATION_SYSCALLS_HPP

#include "__internal/system/syscalls/sys_arguments.hpp"
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
             * @brief Reads data from a file descriptor into a buffer.
             *
             * This function implements the `read` system call for Linux. It uses
             * the `__SysArguments` structure to pass arguments to the kernel in
             * a platform-specific manner.
             *
             * @param arguments A pointer to a `__SysArguments` structure containing
             * the file descriptor, buffer, and size of the data to read.
             * @return The number of bytes read on success, or a negative value on error.
             */
            itl::ssize_t sys_read(itl::__internal::system::__SysArguments* arguments);
        } /// namespace linux
    } /// namespace system
} /// namespace __internal
} /// namespace itl

#endif /// _ITL__INTERNAL__SYSTEM__SYSCALLS__LINUX__IMPLEMENTATION_SYSCALLS_HPP
