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
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
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
 * @def first_register
 * @brief Defines the register used for the first argument in system calls.
 */
#define first_register rdi

/**
 * @def second_register
 * @brief Defines the register used for the second argument in system calls.
 */
#define second_register rsi

/**
 * @def third_register
 * @brief Defines the register used for the third argument in system calls.
 */
#define third_register rdx

/**
 * @def fourth_register
 * @brief Defines the register used for the fourth argument in system calls.
 */
#define fourth_register r10

/**
 * @def fifth_type
 * @brief Defines the register used for the fifth argument in system calls.
 */
#define fifth_type r8

/**
 * @def sixth_register
 * @brief Defines the register used for the sixth argument in system calls.
 */
#define sixth_register r9

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
 * @def first_register
 * @brief Defines the register used for the first argument in system calls.
 */
#define first_register ebx

/**
 * @def second_register
 * @brief Defines the register used for the second argument in system calls.
 */
#define second_register ecx

/**
 * @def third_register
 * @brief Defines the register used for the third argument in system calls.
 */
#define third_register edx

/**
 * @def fourth_register
 * @brief Defines the register used for the fourth argument in system calls.
 */
#define fourth_register esi

/**
 * @def fifth_type
 * @brief Defines the register used for the fifth argument in system calls.
 */
#define fifth_type ebp

/**
 * @def sixth_register
 * @brief Defines the register used for the sixth argument in system calls.
 */
#define sixth_register edi

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

/**
 * @def SYS_ARG1
 * @brief Extracts the first argument from the system call arguments
 * structure.
 */
#define SYS_ARG1(arguments, first_type, first_name) \
    first_type first_name = (first_type)((arguments)->first_register);

/**
 * @def SYS_ARG2
 * @brief Extracts the first and second arguments from the system call
 * arguments structure.
 */
#define SYS_ARG2(arguments,                                            \
    first_type, first_name,                                            \
    second_type, second_name)                                          \
    first_type first_name = (first_type)((arguments)->first_register); \
    second_type second_name = (second_type)((arguments)->second_register);

/**
 * @def SYS_ARG3
 * @brief Extracts the first, second, and third arguments from the system
 * call arguments structure.
 */
#define SYS_ARG3(arguments,                                                \
    first_type, first_name,                                                \
    second_type, second_name,                                              \
    third_type, third_name)                                                \
    first_type first_name = (first_type)((arguments)->first_register);     \
    second_type second_name = (second_type)((arguments)->second_register); \
    third_type third_name = (third_type)((arguments)->third_register);

/**
 * @def SYS_ARG4
 * @brief Extracts the first, second, third, and fourth arguments from the
 * system call arguments structure.
 */
#define SYS_ARG4(arguments,                                                \
    first_type, first_name,                                                \
    second_type, second_name,                                              \
    third_type, third_name,                                                \
    fourth_type, fourth_name)                                              \
    first_type first_name = (first_type)((arguments)->first_register);     \
    second_type second_name = (second_type)((arguments)->second_register); \
    third_type third_name = (third_type)((arguments)->third_register);     \
    fourth_type fourth_name = (fourth_type)((arguments)->fourth_register);

/**
 * @def SYS_ARG5
 * @brief Extracts the first, second, third, fourth, and fifth arguments
 * from the system call arguments structure.
 */
#define SYS_ARG5(arguments,                                                \
    first_type, first_name,                                                \
    second_type, second_name,                                              \
    third_type, third_name,                                                \
    fourth_type, fourth_name,                                              \
    fifth_type, fifth_name)                                                \
    first_type first_name = (first_type)((arguments)->first_register);     \
    second_type second_name = (second_type)((arguments)->second_register); \
    third_type third_name = (third_type)((arguments)->third_register);     \
    fourth_type fourth_name = (fourth_type)((arguments)->fourth_register); \
    fifth_type fifth_name = (fifth_type)((arguments)->fifth_register);

/**
 * @def SYS_ARG6
 * @brief Extracts the first, second, third, fourth, fifth, and sixth
 * arguments from the system call arguments structure.
 */
#define SYS_ARG6(arguments,                                                \
    first_type, first_name,                                                \
    second_type, second_name,                                              \
    third_type, third_name,                                                \
    fourth_type, fourth_name,                                              \
    fifth_type, fifth_name,                                                \
    sixth_type, sixth_name)                                                \
    first_type first_name = (first_type)((arguments)->first_register);     \
    second_type second_name = (second_type)((arguments)->second_register); \
    third_type third_name = (third_type)((arguments)->third_register);     \
    fourth_type fourth_name = (fourth_type)((arguments)->fourth_register); \
    fifth_type fifth_name = (fifth_type)((arguments)->fifth_register);     \
    sixth_type sixth_name = (sixth_type)((arguments)->sixth_register);
    }; /// system
} /// __internal
} /// itl

#endif /// _ITL__INTERNAL__SYSTEM__SYSCALLS__SYS_ARGUMENTS_HPP
