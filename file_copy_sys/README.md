# file_copy_sys

**file_copy_sys** is a low-level C utility designed to copy files using direct Linux system calls.

It bypasses the standard C library buffering to demonstrate how data moves between files at the kernel level.

---

## Features

* POSIX system call implementation (`open`, `read`, `write`)
* Manual buffer management (256-byte chunks)
* Low-level file descriptor handling
* Explicit file permissions control
* Minimal overhead

---

## ️ Build

```bash
gcc file_copy_sys.c -o file_copy_sys
```

---

## ️ Usage

```bash
./file_copy_sys <source_file> <destination_file>
```

---

## Example

Before:
```
source.dat (bin)
dest.dat (not found)
```

Execution:
```bash
./file_copy_sys source.dat dest.dat
```

After:
```
dest.dat (created with 0644 permissions)
```

---

## Concept

```
(fd_in) → read(buffer) → write(buffer) → (fd_out)
```

---

## Internals

* `open` → acquiring file descriptors
* `read` → direct data transfer to user memory
* `write` → direct data transfer to kernel buffers
* `O_RDONLY / O_WRONLY | O_CREAT` → mode flags
* `0644` → file permission bits
* `close` → descriptor cleanup

---

## Current Limitations

* Fixed buffer size (256 bytes)
* Linux / Unix only (non-portable)
* No support for directory copying
* Minimal error checking

---

## Future Improvements

* Parameterized buffer size
* Direct I/O (`O_DIRECT`) support
* Asynchronous I/O (`aio`)
* Performance comparison with `std` version
