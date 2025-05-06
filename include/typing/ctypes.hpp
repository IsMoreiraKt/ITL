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
/**
 * @typedef size_t
 * @brief Unsigned integer type for representing sizes.
 */
typedef unsigned long size_t;

/**
 * @typedef ssize_t
 * @brief Signed integer type for representing sizes or counts.
 */
typedef signed long ssize_t;

/**
 * @def NULL
 * @brief Macro representing a null pointer.
 *
 * This macro is defined as ((void*)0) and is used to represent a null pointer
 * in C-style programming.
 */
#define NULL ((void*)0)
} // namespace itl

#endif // _ITL_TYPING_C_TYPES_HPP
