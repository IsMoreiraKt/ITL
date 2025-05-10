/**
 * @file include/__internal/system/syscalls/sys_arguments.hpp
 * @brief Defines structures for encapsulating system call arguments.
 * @category System Interaction
 *
 * This header provides architecture-specific structures for encapsulating
 * arguments passed to system calls. Separate definitions are provided for
 * 64-bit (x86_64) and 32-bit (i386) architectures.
 *
 * These structures are used to standardize the way arguments are passed
 * to system calls, ensuring compatibility across different platforms.
 *
 * @author Ismael Moreira
 * @date May 10th, 2025
 */
#ifndef _ITL__INTERNAL__SYSTEM__SYSCALLS__SYS_ARGUMENTS_HPP
#define _ITL__INTERNAL__SYSTEM__SYSCALLS__SYS_ARGUMENTS_HPP

/**
 * @namespace itl
 * @brief A general-purpose namespace for the itl library, containing
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
#if defined __x86_64__
        /**
         * @struct __SysArguments
         * @brief Encapsulates arguments passed to system calls on x86_64
         * systems.
         *
         * This structure represents the registers used to pass arguments
         * to system calls on 64-bit architectures.
         */
        typedef struct alignas(8) {
            void* rdi; ///< First argument  (destination index register).
            void* rsi; ///< Second argument (source index register).
            void* rdx; ///< Third argument  (data register).
            void* r10; ///< Fourth argument (temporary register).
            void* r9; ///< Fifth argument   (general-purpose register).
            void* r8; ///< Sixth argument   (general-purpose register).
        } __SysArguments;

#else /// i386 architecture
        /**
         * @struct __SysArguments
         * @brief Encapsulates arguments passed to system calls on i386
         * systems.
         *
         * This structure represents the registers used to pass arguments
         * to system calls on 32-bit architectures.
         */
        typedef struct alignas(4) {
            void* ebx; ///< First argument  (base register).
            void* ecx; ///< Second argument (counter register).
            void* edx; ///< Third argument  (data register).
            void* esi; ///< Fourth argument (source index register).
            void* edi; ///< Fifth argument  (destination index register).
            void* ebp; ///< Sixth argument  (base pointer register).
        } __SysArguments;
#endif /// __x86_64__
    }; /// system
} /// __internal
} /// itl

#endif /// _ITL__INTERNAL__SYSTEM__SYSCALLS__SYS_ARGUMENTS_HPP
