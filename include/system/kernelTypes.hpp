/**
 * @file include/system/kernelTypes.hpp
 * @brief Defines macros for kernel-style type manipulation.
 * @category System
 *
 * This header provides macros for type manipulation and bitwise operations
 * commonly used in low-level kernel programming. These macros are designed
 * to simplify the definition of constants and bit manipulation.
 *
 * @author Ismael Moreira
 * @date 05.06.2025
 */
#ifndef _ITL_SYSTEM_KERNEL_TYPES_HPP
#define _ITL_SYSTEM_KERNEL_TYPES_HPP

/**
 * @def __AC(X, Y)
 * @brief Concatenates the value `X` with the suffix `Y`.
 *
 * This macro is used to define constants with specific suffixes, such as
 * `UL` for unsigned long or `ULL` for unsigned long long.
 *
 * @param X The base value.
 * @param Y The suffix to concatenate.
 */
#define __AC(X, Y) (X##Y)

/**
 * @def _AC(X, Y)
 * @brief Wrapper for the `__AC` macro.
 *
 * This macro provides a shorthand for `__AC` and is used to define constants
 * with specific suffixes.
 *
 * @param X The base value.
 * @param Y The suffix to concatenate.
 */
#define _AC(X, Y) __AC(X, Y)

/**
 * @def _UL(x)
 * @brief Defines an unsigned long constant.
 *
 * This macro appends the `UL` suffix to the given value, defining it as
 * an unsigned long constant.
 *
 * @param x The value to define as unsigned long.
 */
#define _UL(x) (_AC(x, UL))

/**
 * @def _BITUL(x)
 * @brief Defines a bit mask as an unsigned long.
 *
 * This macro shifts the value `1` left by `x` bits and defines the result
 * as an unsigned long constant.
 *
 * @param x The number of bits to shift.
 */
#define _BITUL(x) (_UL(1) << (x))

#endif // _ITL_SYSTEM_KERNEL_TYPES_HPP