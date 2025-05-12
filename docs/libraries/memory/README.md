# Memory Management Module

This module is responsible for memory management within ITL. It provides a wide range of tools for _memory allocation_ and _management_, including basic functions such as **malloc** and **free**, as well as advanced solutions such as _garbage collection_ based on the [Boehm Garbage Collector](https://www.hboehm.info/gc/), memory arenas, object pools, and reference counters.

### Libraries

| Name                   | Description                                                                                                    | Implemented | Docs                                                             |
|------------------------|----------------------------------------------------------------------------------------------------------------|-------------|------------------------------------------------------------------|
| itl::allocator         | A library for customised memory allocation, including support for block alignment and tracking.                | No          | [allocator documentation](./allocator/README.md)                 |
| itl::arena             | It implements memory arenas for efficient batch allocation, thereby reducing allocation overhead.              | No          | [arena documentation](./arena/README.md)                         |
| itl::garbage_collector | It incorporates the Boehm Garbage Collector to provide automatic memory management and eliminate memory leaks. | No          | [garbage_collector documentation](./garbage_collector/README.md) |
| itl::pool              | Manages object pools to enable the quick allocation and efficient reuse of memory.                             | No          | [pool documentation](./pool/README.md)                           |
| itl::reference_counter | It implements reference counters for memory management based on shared use.                                    | No          | [reference_counter documentation](./reference_counter/README.md) |
