/**
 * @file src/memory/allocator.cpp
 * @brief Implements memory allocation utilities for the ITL library.
 * @category Memory Management
 *
 * This file contains the implementation of functions for dynamic memory
 * management, including allocation, aligned allocation, reallocation,
 * and deallocation.
 *
 * @author Ismael
 * @date 05.06.2025
 */
#include "memory/allocator.hpp"
#include "system/mmacros.hpp"
#include "system/syscalls.hpp"
#include "typing/ctypes.hpp"

/**
 * @namespace itl
 * @brief A general-purpose namespace for the ITL library, containing
 * custom STL components, allocators, types, and utilities.
 */
namespace itl {
/**
 * @brief Internal memory map used by the allocator.
 *
 * This structure tracks all memory blocks managed by the allocator.
 * It contains an array of pointers to memory blocks and a counter
 * indicating the number of blocks currently in use.
 */
itl::MemoryMap internalMemoryMap = {
    .blocks = { nullptr }, ///< Array of pointers to memory blocks.
    .blockCount = 0 ///< Number of memory blocks currently in use.
};

/**
 * @brief Normalizes the requested size to be aligned with a base size.
 *
 * This function ensures that the requested size is aligned to the nearest
 * multiple of the base size. If the size is smaller than the base, it is
 * rounded up to the base size.
 *
 * @param size The requested size to normalize.
 * @param base The base size to align to (e.g., page size).
 * @return The normalized size, aligned to the base size.
 */
static itl::size_t __internal_normalizeSize(itl::size_t size, itl::size_t base)
{
    if (size < base)
        return base;

    return (size + base - 1) & ~(base - 1);
}
} // namespace itl
