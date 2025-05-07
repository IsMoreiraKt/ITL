/**
 * @file include/memory/allocator.hpp
 * @brief Provides memory allocation utilities for the ITL library.
 * @category Memory Management
 *
 * This header defines functions and data structures for dynamic memory
 * management, including allocation, aligned allocation, reallocation,
 * and deallocation.
 *
 * @author Ismael Moreira <ismaelmoreirakt@gmail.com>
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
#define MAX_BLOCKS 4096 ///< Maximum number of memory blocks in the memory map.
#define MIN_PAGE_SIZE 4096 ///< Minimum size of a memory page.
#define MIN_CHUNK_SIZE 8 ///< Minimum size of a memory chunk.

/**
 * @struct AllocationMetadata
 * @brief Metadata for a single memory allocation.
 *
 * This structure tracks the state of a memory allocation, including
 * whether it is in use, its size, and a pointer to the allocated memory.
 */
typedef struct {
    bool used; ///< Indicates whether the allocation is currently in use.
    itl::size_t startPosition; ///< Start position of the memory page.
    itl::size_t size; ///< The size of the allocated memory, in bytes.
    void* pointerToAllocatedMemory; ///< A pointer to the allocated memory.
} AllocationMetadata;

/**
 * @struct MemoryBlock
 * @brief Represents a block of memory managed by the allocator.
 *
 * A memory block contains a base pointer, chunk size, total number of chunks,
 * and an array of allocation metadata for tracking individual allocations.
 */
typedef struct {
    void* base; ///< Base address of the memory block.
    itl::size_t chunkSize; ///< Size of each chunk in the block, in bytes.
    itl::size_t totalChunks; ///< Total number of chunks in the block.
    itl::AllocationMetadata* chunks[MAX_CHUNKS]; ///< Metadata for each chunk.
} MemoryBlock;

/**
 * @struct MemoryMap
 * @brief Represents a map of memory blocks managed by the allocator.
 *
 * The memory map tracks multiple memory blocks and their count.
 */
typedef struct {
    itl::MemoryBlock* blocks[MAX_BLOCKS]; ///< Array of pointers to memory blocks.
    itl::size_t blockCount; ///< Number of memory blocks currently in use.
} MemoryMap;

/**
 * @struct AllocationSearch
 * @brief Represents the result of a memory allocation search.
 *
 * This structure contains information about the block, offset, and
 * whether a suitable allocation was found.
 */
typedef struct {
    itl::MemoryBlock* block; ///< Pointer to the memory block where the allocation was found.
    itl::size_t index; ///< Index in the list of chunks of the block.
    bool found; ///< Indicates whether a suitable allocation was found.
} AllocationSearch;

/**
 * @brief Allocates a block of memory of the specified size.
 *
 * @param size The size of the memory block to allocate, in bytes.
 * @return A pointer to the allocated memory block, or nullptr if
 * the allocation fails.
 */
void* alloc(itl::size_t size);

/**
 * @brief Allocates memory for an array and initializes it to zero.
 *
 * @param number The number of elements in the array.
 * @param size The size of each element, in bytes.
 * @return A pointer to the allocated and zero-initialized memory block,
 * or nullptr if the allocation fails.
 */
void* calloc(itl::size_t number, itl::size_t size);

/**
 * @brief Reallocates a previously allocated memory block to a new size.
 *
 * @param pointerToMemory A pointer to the memory block to reallocate.
 * @param newSize The new size of the memory block, in bytes.
 * @return A pointer to the reallocated memory block, or nullptr
 * if the reallocation fails.
 */
void* realloc(void* pointerToMemory, itl::size_t newSize);

/**
 * @brief Frees a previously allocated memory block.
 *
 * @param pointerToMemory A pointer to the memory block to free.
 * If the pointer is nullptr, no operation is performed.
 */
void free(void* pointerToMemory);
} // namespace itl

#endif // _ITL_MEMORY_ALLOCATOR_HPP
