/**
 * @file include/system/mmacros.hpp
 * @brief Defines memory-related macros for the ITL library.
 * @category System
 *
 * This header provides macros for memory protection, mapping, and management
 * flags used in system calls such as mmap and munmap. These macros are
 * specific to Linux systems.
 *
 * @author Ismael Moreira
 * @date 05.06.2025
 */
#ifndef _ITL_SYSTEM_MEMORY_MACROS_HPP
#define _ITL_SYSTEM_MEMORY_MACROS_HPP

#include "system/kernelTypes.hpp"

namespace itl {
namespace linux {
    extern "C" {
#ifdef __linux__
// Page-related macros
#define PAGE_SHIFT 13 ///< Number of bits to shift for page size.
#define PAGE_SIZE _BITUL(PAGE_SHIFT) ///< Size of a memory page in bytes.
#define PAGE_MASK (~(PAGE_SIZE - 1)) ///< Mask to align addresses to page boundaries.

// Memory protection flags
#define PROT_READ 0x1 ///< Pages can be read.
#define PROT_WRITE 0x2 ///< Pages can be written.
#define PROT_EXEC 0x4 ///< Pages can be executed.
#define PROT_SEM 0x8 ///< Pages can be used for semaphores.
#define PROT_NONE 0x0 ///< Pages cannot be accessed.
#define PROT_GROWSDOWN 0x01000000 ///< Extend change to start of mmap for stacks.
#define PROT_GROWSUP 0x02000000 ///< Extend change to end of mmap for stacks.

// Memory mapping flags
#define MAP_FAILED ((void*)-1) ///< Indicates that mmap failed.
#define MAP_SHARED 0x01 ///< Share changes.
#define MAP_PRIVATE 0x02 ///< Changes are private to the process.
#define MAP_SHARED_VALIDATE 0x03 ///< Share changes with validation.
#define MAP_TYPE 0x0f ///< Mask for type of mapping.
#define MAP_FIXED 0x10 ///< Interpret the address exactly.
#define MAP_ANONYMOUS 0x20 ///< Mapping is not backed by any file.
#define MAP_FILE 0 ///< Mapping is backed by a file.
#define MAP_GROWSDOWN 0x0100 ///< Stack-like segment.
#define MAP_DENYWRITE 0x0800 ///< Deny writes to the mapped file.
#define MAP_EXECUTABLE 0x1000 ///< Mark the mapped file as executable.
#define MAP_LOCKED 0x2000 ///< Lock the mapped region into memory.
#define MAP_NORESERVE 0x4000 ///< Do not reserve swap space.
#define MAP_POPULATE 0x008000 ///< Populate (prefault) page tables.
#define MAP_NONBLOCK 0x010000 ///< Do not block on I/O.
#define MAP_STACK 0x020000 ///< Indicate region is for a stack.
#define MAP_HUGETLB 0x040000 ///< Use huge pages.
#define MAP_SYNC 0x080000 ///< Perform synchronous page faults.
#define MAP_FIXED_NOREPLACE 0x100000 ///< Do not replace existing mappings.
#define MAP_UNINITIALIZED 0x4000000 ///< Pages are not initialized.

// Memory locking flags
#define MLOCK_ONFAULT 0x01 ///< Lock pages on fault.

// Synchronization flags for msync
#define MS_ASYNC 1 ///< Perform asynchronous writes.
#define MS_INVALIDATE 2 ///< Invalidate cached data.
#define MS_SYNC 4 ///< Perform synchronous writes.

// Memory advice flags for madvise
#define MADV_NORMAL 0 ///< No special treatment.
#define MADV_RANDOM 1 ///< Expect random page references.
#define MADV_SEQUENTIAL 2 ///< Expect sequential page references.
#define MADV_WILLNEED 3 ///< Will need these pages.
#define MADV_DONTNEED 4 ///< Do not need these pages.
#define MADV_FREE 8 ///< Free pages only if memory pressure exists.
#define MADV_REMOVE 9 ///< Remove these pages and resources.
#define MADV_DONTFORK 10 ///< Do not inherit across fork.
#define MADV_DOFORK 11 ///< Do inherit across fork.
#define MADV_MERGEABLE 12 ///< Enable kernel merging of identical pages.
#define MADV_UNMERGEABLE 13 ///< Disable kernel merging of identical pages.
#define MADV_HUGEPAGE 14 ///< Enable transparent huge pages.
#define MADV_NOHUGEPAGE 15 ///< Disable transparent huge pages.
#define MADV_DONTDUMP 16 ///< Exclude from core dumps.
#define MADV_DODUMP 17 ///< Include in core dumps.
#define MADV_WIPEONFORK 18 ///< Wipe memory on fork.
#define MADV_KEEPONFORK 19 ///< Keep memory on fork.
#define MADV_COLD 20 ///< Mark pages as cold.
#define MADV_PAGEOUT 21 ///< Suggest pages be reclaimed.
#define MADV_POPULATE_READ 22 ///< Prefault pages for reading.
#define MADV_POPULATE_WRITE 23 ///< Prefault pages for writing.
#define MADV_DONTNEED_LOCKED 24 ///< Do not need locked pages.
#define MADV_COLLAPSE 25 ///< Collapse pages into a huge page.
#define MADV_HWPOISON 100 ///< Poison a page for testing.
#define MADV_SOFT_OFFLINE 101 ///< Soft offline a page.
#define MADV_GUARD_INSTALL 102 ///< Install a guard page.
#define MADV_GUARD_REMOVE 103 ///< Remove a guard page.

// Protection key flags
#define PKEY_DISABLE_ACCESS 0x1 ///< Disable access to the memory.
#define PKEY_DISABLE_WRITE 0x2 ///< Disable write access to the memory.
#define PKEY_ACCESS_MASK (PKEY_DISABLE_ACCESS | PKEY_DISABLE_WRITE) ///< Mask for access restrictions.
#endif // __linux__
    }; // extern "C"
}; // namespace linux
}; // namespace itl

#endif // _ITL_SYSTEM_MEMORY_MACROS_HPP
