/**
 * @file include/typing/ctypes.hpp
 * @brief Defines common C-style types for the itl namespace.
 * @category Typing
 *
 * This header provides typedefs for commonly used C-style types
 * within the itl namespace.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
 * @date 05.05.2025
 */
#ifndef _ITL_TYPING_C_TYPES_HPP
#define _ITL_TYPING_C_TYPES_HPP

/**
 * @namespace itl
 * @brief A general-purpose namespace for the itl library, containing
 * custom STL components, allocators, types, and utilities.
 */
namespace itl {
#if defined(__x86_64__)
/**
 * @typedef size_t
 * @brief Unsigned integer type for representing sizes (64-bit).
 */
typedef unsigned long size_t;

/**
 * @typedef ssize_t
 * @brief Signed integer type for representing sizes or counts (64-bit).
 */
typedef signed long ssize_t;

/**
 * @typedef intptr_t
 * @brief Signed integer type capable of holding a pointer (64-bit).
 */
typedef signed long intptr_t;

/**
 * @typedef uintptr_t
 * @brief Unsigned integer type capable of holding a pointer (64-bit).
 */
typedef unsigned long uintptr_t;

#elif defined(__i386__)
/**
 * @typedef size_t
 * @brief Unsigned integer type for representing sizes (32-bit).
 */
typedef unsigned int size_t;

/**
 * @typedef ssize_t
 * @brief Signed integer type for representing sizes or counts (32-bit).
 */
typedef signed int ssize_t;

/**
 * @typedef intptr_t
 * @brief Signed integer type capable of holding a pointer (32-bit).
 */
typedef signed int intptr_t;

/**
 * @typedef uintptr_t
 * @brief Unsigned integer type capable of holding a pointer (32-bit).
 */
typedef unsigned int uintptr_t;
#endif // __i386__

/**
 * @typedef char_ptr
 * @brief Pointer to a character.
 */
typedef char* char_ptr;

/**
 * @typedef strvec
 * @brief Pointer to an array of modifiable strings.
 */
typedef char** strvec;

/**
 * @typedef cstrvec
 * @brief Pointer to an array of constant strings.
 */
typedef const char** cstrvec;

/**
 * @typedef cstring
 * @brief Pointer to a constant string.
 */
typedef const char* cstring;

#ifndef NULL
/**
 * @def NULL
 * @brief Macro representing a null pointer.
 */
#define NULL ((void*)0)
#endif // NULL
} // namespace itl

#endif // _ITL_TYPING_C_TYPES_HPP
