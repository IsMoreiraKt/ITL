/**
 * @file src/debug/errno.cpp
 * @brief Implements the thread-local errno variable for error handling.
 * @category Error Handling
 *
 * This file provides the definition of the thread-local errno variable,
 * which is used to store error codes set by system calls and
 * library functions. Each thread has its own instance of errno, ensuring
 * thread-safe error handling.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
 * @date May 10th, 2025
 */
#include "debug/errno.hpp"
#include "typing/ctypes.hpp"

/**
 * @namespace itl
 * @brief A general-purpose namespace for the ITL library, containing
 * custom STL components, allocators, types, and utilities.
 */
namespace itl {
/**
 * @brief Thread-local variable for storing error codes.
 */
__thread int errno = 0;

/**
 * @brief Returns a human-readable description of an error code.
 *
 * This function maps an error code (stored in errno) to a string
 * describing the error. It is useful for debugging and logging purposes.
 *
 * @return A constant string containing the description of the error.
 */
itl::cstring errno_str(void)
{
    if (itl::errno <= 0 || itl::errno > 34)
        return nullptr;
    return itl::_error_description[itl::errno - 1];
}
} /// namespace itl
