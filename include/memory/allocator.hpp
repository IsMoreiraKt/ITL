/**
 * @file allocator.hpp
 * @brief Provides memory allocation utilities for the ITL library.
 * @category Memory Management
 *
 * This header defines functions and data structures for dynamic memory
 * management, including allocation, aligned allocation, reallocation,
 * and deallocation.
 *
 * @author Ismael Moreira
 * @date 05.05.2025
 */
#ifndef _ITL_MEMORY_ALLOCATOR_HPP
#define _ITL_MEMORY_ALLOCATOR_HPP

#include "typing/ctypes.hpp"

/**
 * @namespace itl
 * @brief A general-purpose namespace for the ITL library, containing
 * custom STL components, allocators, types, and utilities.
 */
namespace itl {
#define MAX_CHUNKS 4096 ///< Maximum number of chunks per memory block.
#define MAX_BLOCKS 33554432 ///< Maximum number of memory blocks in the memory map.

/**
 * @struct AllocationMetadata
 * @brief Metadata for a single memory allocation.
 *
 * This structure tracks the state of a memory allocation, including
 * whether it is in use, its size, and a pointer to the allocated memory.
 */
typedef struct {
  bool used; ///< Indicates whether the allocation is currently in use.
  itl::size_t size; ///< The size of the allocated memory, in bytes.
  void* ptr; ///< A pointer to the allocated memory.
} AllocationMetadata;

/**
 * @brief Allocates a block of memory of the specified size.
 *
 * @param size The size of the memory block to allocate, in bytes.
 * @return A pointer to the allocated memory block, or `nullptr` if
 * the allocation fails.
 */
static void* alloc(itl::size_t size);

/**
 * @brief Allocates a block of memory with the specified alignment.
 *
 * @param alignment The alignment requirement for the memory block.
 * @param size The size of the memory block to allocate, in bytes.
 * @return A pointer to the aligned memory block, or `nullptr` if the
 * allocation fails.
 */
static void* alignedAlloc(itl::size_t alignment, itl::size_t size);

/**
 * @brief Allocates memory for an array and initializes it to zero.
 *
 * @param number The number of elements in the array.
 * @param size The size of each element, in bytes.
 * @return A pointer to the allocated and zero-initialized memory block,
 * or `nullptr` if the allocation fails.
 */
static void* calloc(itl::size_t number, itl::size_t size);

/**
 * @brief Reallocates a previously allocated memory block to a new size.
 *
 * @param pointerToMemory A pointer to the memory block to reallocate.
 * @param newSize The new size of the memory block, in bytes.
 * @return A pointer to the reallocated memory block, or `nullptr`
 * if the reallocation fails.
 */
static void* realloc(void* pointerToMemory, itl::size_t newSize);

/**
 * @brief Frees a previously allocated memory block.
 *
 * @param pointerToMemory A pointer to the memory block to free.
 * If the pointer is `nullptr`, no operation is performed.
 */
static void free(void* pointerToMemory);
} // namespace itl

#endif // _ITL_MEMORY_ALLOCATOR_HPP
