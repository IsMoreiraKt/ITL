/**
 * @file include/typing/ctypes.hpp
 * @brief Defines common C-style types for the itl namespace.
 * @category Typing
 *
 * This header provides typedefs for commonly used C-style types
 * within the itl namespace.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
 * @date May 5th, 2025
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

/**
 * @typedef i8
 * @brief Signed 8-bit integer type.
 */
typedef char i8;

/**
 * @typedef i16
 * @brief Signed 16-bit integer type.
 */
typedef short i16;

/**
 * @typedef i32
 * @brief Signed 32-bit integer type.
 */
typedef int i32;

/**
 * @typedef i64
 * @brief Signed 64-bit integer type.
 */
typedef long i64;

/**
 * @typedef u8
 * @brief Unsigned 8-bit integer type.
 */
typedef unsigned char u8;

/**
 * @typedef u16
 * @brief Unsigned 16-bit integer type.
 */
typedef unsigned short u16;

/**
 * @typedef u32
 * @brief Unsigned 32-bit integer type.
 */
typedef unsigned int u32;

/**
 * @typedef u64
 * @brief Unsigned 64-bit integer type.
 */
typedef unsigned long u64;

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

/**
 * @typedef i8
 * @brief Signed 8-bit integer type.
 */
typedef char i8;

/**
 * @typedef i16
 * @brief Signed 16-bit integer type.
 */
typedef short i16;

/**
 * @typedef i32
 * @brief Signed 32-bit integer type.
 */
typedef int i32;

/**
 * @typedef i64
 * @brief Signed 64-bit integer type.
 */
typedef long long i64;

/**
 * @typedef u8
 * @brief Unsigned 8-bit integer type.
 */
typedef unsigned char u8;

/**
 * @typedef u16
 * @brief Unsigned 16-bit integer type.
 */
typedef unsigned short u16;

/**
 * @typedef u32
 * @brief Unsigned 32-bit integer type.
 */
typedef unsigned int u32;

/**
 * @typedef u64
 * @brief Unsigned 64-bit integer type.
 */
typedef unsigned long long u64;
#endif // __i386__

#ifdef __INTPTR_TYPE__
/**
 * @typedef address_t
 * @brief Unsigned integer type for representing memory addresses.
 */
typedef __INTPTR_TYPE__ address_t;
#else
/**
 * @typedef address_t
 * @brief Unsigned integer type for representing memory addresses.
 */
typedef itl::size_t address_t;
#endif // __INTPTR_TYPE__

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
