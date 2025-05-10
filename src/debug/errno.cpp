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

/**
 * @brief Thread-local variable for storing error codes.
 */
__thread int errno = 0;
