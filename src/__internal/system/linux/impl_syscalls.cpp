/**
 * @file src/__internal/system/linux/impl_syscalls.cpp
 * @brief Implements Linux-specific system call wrappers.
 * @category System Interaction
 *
 * This file provides the implementation of Linux-specific system call
 * wrappers. These functions interact with the kernel using low-level
 * system call interfaces and provide a standardized interface for
 * higher-level abstractions.
 * 
 * Currently, it includes the implementation of the sys_read function,
 * which wraps the read system call.
 * 
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com> 
 * @date May 10th, 2025
 */
#include "__internal/system/syscalls/linux/impl_syscalls.hpp"
#include "__internal/system/syscalls/linux/extern_syscalls.hpp"
#include "debug/errno.hpp"

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
             * This function implements the read system call for Linux.
             * It uses the __SysArguments structure to pass arguments to
             * the kernel in a platform-specific manner.
             *
             * @param arguments A pointer to a __SysArguments structure
             * containing the file descriptor, buffer, and size of the data
             * to read.
             * @return The number of bytes read on success, or a negative
             * value on error.
             */
            itl::ssize_t sys_read(itl::__internal::system::__SysArguments* arguments)
            {
                SYS_ARG3(
                    arguments,
                    itl::u32, file_descriptor,
                    itl::cstring, buffer,
                    itl::size_t, count)
                itl::ssize_t syscall_return = itl::__internal::system::linux::__read(
                    file_descriptor, buffer, count);

                if (syscall_return < 0) {
                    errno = -syscall_return;
                    return -1;
                }

                return syscall_return;
            }
        } /// namespace linux
    } /// namespace system
} /// namespace __internal
} /// namespace itl