# prog-sys-practice

**prog-sys-practice** is a collection of high-performance C tools designed to explore and master system-level programming concepts.

This repository serves as a personal laboratory for implementing core utilities ranging from file management to low-level string manipulation, emphasizing POSIX APIs and manual memory management.

---

## Project Overview

* **Goal**: Deepening understanding of Linux Internals & C efficiency.
* **Scope**: File I/O, Directory manipulation, Pointer arithmetic, Memory allocation.
* **Ethics**: Clean, readable, and dependency-free C code.

---

## Tools Included

| Tool | Core Concept |
| :--- | :--- |
| **range** | File organization by extension groups |
| **word_remover** | In-place word stripping from files/dirs |
| **dir_list_ext** | File discovery with extension extraction |
| **word_search_sys** | Low-level search with exact/substring modes |
| **file_copy_sys** | High-speed copying using direct system calls |
| ... and many more. | (See individual folders for details) |

---

## ️ Build System

Most tools can be compiled using a standard C compiler:

```bash
gcc workspace/tool_folder/tool.c -o tool
```

---

## Concept

```
(Concept) → (POSIX/C Implementation) → (Practical Tool)
```

---

## Internals Explored

* `open / read / write` (File Descriptors)
* `opendir / readdir` (Directory Streams)
* `malloc / realloc / free` (Heap Management)
* `stat / mkdir / unlink` (Filesystem metadata)
* `execl` (Process management)

---

## Future Roadmap

* Centralized `Makefile` for all tools
* Comprehensive test suite
* Windows (Mingw) compatibility layer
* Integration into a single shell helper
* More advanced concepts (Sockets, Signals, Threads)
