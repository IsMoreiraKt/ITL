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

#include "typing/ctypes.hpp"

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

/**
 * @brief Returns a human-readable description of an error code.
 *
 * This function maps an error code (stored in errno) to a string
 * describing the error. It is useful for debugging and logging purposes.
 *
 * @return A constant string containing the description of the error.
 */
itl::cstring errno_str(void);

/**
 * @brief Array of human-readable error descriptions.
 *
 * This array maps error codes to their corresponding human-readable
 * descriptions. It is indexed by the error code minus one.
 */
constexpr const char* _error_description[34] = {
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
 * @def EPERM
 * @brief Operation not permitted.
 */
#define EPERM 1

/**
 * @def ENOENT
 * @brief No such file or directory.
 */
#define ENOENT 2

/**
 * @def ESRCH
 * @brief No such process.
 */
#define ESRCH 3

/**
 * @def EINTR
 * @brief Interrupted system call.
 */
#define EINTR 4

/**
 * @def EIO
 * @brief I/O error.
 */
#define EIO 5

/**
 * @def ENXIO
 * @brief No such device or address.
 */
#define ENXIO 6

/**
 * @def E2BIG
 * @brief Argument list too long.
 */
#define E2BIG 7

/**
 * @def ENOEXEC
 * @brief Exec format error.
 */
#define ENOEXEC 8

/**
 * @def EBADF
 * @brief Bad file number.
 */
#define EBADF 9

/**
 * @def ECHILD
 * @brief No child processes.
 */
#define ECHILD 10

/**
 * @def EAGAIN
 * @brief Try again.
 */
#define EAGAIN 11

/**
 * @def ENOMEM
 * @brief Out of memory.
 */
#define ENOMEM 12

/**
 * @def EACCES
 * @brief Permission denied.
 */
#define EACCES 13

/**
 * @def EFAULT
 * @brief Bad address.
 */
#define EFAULT 14

/**
 * @def ENOTBLK
 * @brief Block device required.
 */
#define ENOTBLK 15

/**
 * @def EBUSY
 * @brief Device or resource busy.
 */
#define EBUSY 16

/**
 * @def EEXIST
 * @brief File exists.
 */
#define EEXIST 17

/**
 * @def EXDEV
 * @brief Cross-device link.
 */
#define EXDEV 18

/**
 * @def ENODEV
 * @brief No such device.
 */
#define ENODEV 19

/**
 * @def ENOTDIR
 * @brief Not a directory.
 */
#define ENOTDIR 20

/**
 * @def EISDIR
 * @brief Is a directory.
 */
#define EISDIR 21

/**
 * @def EINVAL
 * @brief Invalid argument.
 */
#define EINVAL 22

/**
 * @def ENFILE
 * @brief File table overflow.
 */
#define ENFILE 23

/**
 * @def EMFILE
 * @brief Too many open files.
 */
#define EMFILE 24

/**
 * @def ENOTTY
 * @brief Not a typewriter.
 */
#define ENOTTY 25

/**
 * @def ETXTBSY
 * @brief Text file busy.
 */
#define ETXTBSY 26

/**
 * @def EFBIG
 * @brief File too large.
 */
#define EFBIG 27

/**
 * @def ENOSPC
 * @brief No space left on device.
 */
#define ENOSPC 28

/**
 * @def ESPIPE
 * @brief Illegal seek.
 */
#define ESPIPE 29

/**
 * @def EROFS
 * @brief Read-only file system.
 */
#define EROFS 30

/**
 * @def EMLINK
 * @brief Too many links.
 */
#define EMLINK 31

/**
 * @def EPIPE
 * @brief Broken pipe.
 */
#define EPIPE 32

/**
 * @def EDOM
 * @brief Math argument out of domain of func.
 */
#define EDOM 33

/**
 * @def ERANGE
 * @brief Math result not representable.
 */
#define ERANGE 34
} // namespace itl

#endif // _ITL_DEBUG_ERRNO_HPP