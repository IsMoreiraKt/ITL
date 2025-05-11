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
 * @brief Array of human-readable error descriptions.
 *
 * This array maps error codes to their corresponding human-readable
 * descriptions. It is indexed by the error code minus one.
 */
static constexpr const char* _error_description[34] = {
    "Operation not permitted.", ///< EPERM
    "No such file or directory.", ///< ENOENT
    "No such process.", ///< ESRCH
    "Interrupted system call.", ///< EINTR
    "I/O error.", ///< EIO
    "No such device or address.", ///< ENXIO
    "Argument list too long.", ///< E2BIG
    "Exec format error.", ///< ENOEXEC
    "Bad file number.", ///< EBADF
    "No child processes.", ///< ECHILD
    "Try again.", ///< EAGAIN
    "Out of memory.", ///< ENOMEM
    "Permission denied.", ///< EACCES
    "Bad address.", ///< EFAULT
    "Block device required.", ///< ENOTBLK
    "Device or resource busy.", ///< EBUSY
    "File exists.", ///< EEXIST
    "Cross-device link.", ///< EXDEV
    "No such device.", ///< ENODEV
    "Not a directory.", ///< ENOTDIR
    "Is a directory.", ///< EISDIR
    "Invalid argument.", ///< EINVAL
    "File table overflow.", ///< ENFILE
    "Too many open files.", ///< EMFILE
    "Not a typewriter.", ///< ENOTTY
    "Text file busy.", ///< ETXBSY
    "File too large.", ///< EFBIG
    "No space left on device.", ///< ENOSPC
    "Illegal seek.", ///< ESPIPE
    "Read-only file system.", ///< EROFS
    "Too many links.", ///< EMLINK
    "Broken pipe.", ///< EPIPE
    "Math argument out of domain of func.", ///< EDOM
    "Math result not representable." ///< ERANGE
};

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
