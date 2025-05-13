# System Interaction Module

This module provides ITL with tools for interacting with the operating system, allowing them to manipulate environment variables, processes, signals, threads and much more. It also supports system calls and provides information about the system, as well as functionalities related to networks and time.

### Libraries

| Name         | Description                                                                                                | Implemented | Docs                                         |
| ------------ | ---------------------------------------------------------------------------------------------------------- | ----------- | -------------------------------------------- |
| itl::env     | It enables you to manipulate environment variables, including reading, writing and deleting them.          | No          | [env documentation](./env/README.md)         |
| itl::fswatch | It monitors changes to files and directories in real time.                                                 | No          | [fswatch documentation](./fswatch/README.md) |
| itl::process | It provides tools for creating, managing and communicating processes.                                      | No          | [process documentation](./process/README.md) |
| itl::signals | It implements signal manipulation, enabling it to capture and respond to system events.                    | No          | [signals documentation](./signals/README.md) |
| itl::simd    | It supports SIMD (single instruction, multiple data) operations for vector processing.                     | No          | [simd documentation](./simd/README.md)       |
| itl::socket  | It provides an interface for socket-based network communication.                                           | No          | [socket documentation](./socket/README.md)   |
| itl::syscall | It implements wrappers for system calls, enabling direct interaction with the kernel.                      | No          | [syscall documentation](./syscall/README.md) |
| itl::sysinfo | It gives you access to system information, such as memory usage and CPU usage.                             | No          | [sysinfo documentation](./sysinfo/README.md) |
| itl::thread  | It provides support for thread creation and management, including synchronisation.                         | No          | [thread documentation](./thread/README.md)   |
| itl::time    | It provides tools for manipulating time, including high-precision measurement and formatting capabilities. | No          | [time documentation](./time/README.md)       |
