/**
 * @file include/debug/errno.hpp
 * @brief Defines the thread-local errno variable for error handling.
 * @category Error Handling
 *
 * This header provides a thread-local implementation of the errno
 * variable, which is used to store error codes set by system calls
 * and library functions. Each thread has its own instance of errno,
 * ensuring thread-safe error handling.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
 * @date May 10th, 2025
 */
#ifndef _ITL_DEBUG_ERRNO_HPP
#define _ITL_DEBUG_ERRNO_HPP

/**
 * @namespace itl
 * @brief A general-purpose namespace for the ITL library, containing
 * custom STL components, allocators, types, and utilities.
 */
namespace itl {
/**
 * @brief Thread-local variable for storing error codes.
 *
 * The errno variable is used to store error codes set by system calls
 * and library functions. It is declared as thread-local to ensure that
 * each thread has its own instance, making it safe for multi-threaded
 * applications.
 */
extern __thread int errno;
} // namespace itl

#endif // _ITL_DEBUG_ERRNO_HPP