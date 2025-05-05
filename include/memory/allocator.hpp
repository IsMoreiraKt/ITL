/**
 * @file allocator.hpp
 * @brief Provides memory allocation utilities for the ITL library.
 * @category Memory Management
 * 
 * This header defines functions for dynamic memory management, including 
 * allocation, aligned allocation, reallocation, and deallocation.
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
  /**
   * @brief Allocates a block of memory of the specified size.
   *
   * @param size The size of the memory block to allocate, in bytes.
   * 
   * @return A pointer to the allocated memory block, or `nullptr` if
   * the allocation fails.
   */
  void* alloc(itl::size_t size);

  /**
   * @brief Allocates a block of memory with the specified alignment.
   * 
   * @param alignment The alignment requirement for the memory block.
   * @param size The size of the memory block to allocate, in bytes.
   * 
   * @return A pointer to the aligned memory block, or `nullptr` if the
   * allocation fails.
   */
  void* alignedAlloc(itl::size_t alignment, itl::size_t size);

  /**
   * @brief Allocates memory for an array and initializes it to zero.
   * 
   * @param number The number of elements in the array.
   * @param size The size of each element, in bytes.
   * 
   * @return A pointer to the allocated and zero-initialized memory block,
   * or `nullptr` if the allocation fails.
   */
  void* calloc(itl::size_t number, itl::size_t size);

  /**
   * @brief Reallocates a previously allocated memory block to a new size.
   * 
   * @param pointerToMemory A pointer to the memory block to reallocate.
   * @param newSize The new size of the memory block, in bytes.
   * 
   * @return A pointer to the reallocated memory block, or `nullptr`
   * if the reallocation fails.
   */
  void* realloc(void* pointerToMemory, itl::size_t newSize);

  /**
   * @brief Frees a previously allocated memory block.
   * 
   * @param pointerToMemory A pointer to the memory block to free.
   * If the pointer is `nullptr`, no operation is performed.
   */
  void free(void* pointerToMemory);
} // namespace itl

#endif // _ITL_MEMORY_ALLOCATOR_HPP
