# custom_cat

**custom_cat** is a lightweight C implementation of the standard `cat` command with a specific focus on file reading using standard I/O.

It supports a basic `-r` flag to read and display file contents to the standard output.

---

## Features

* Scan and read single files
* Standard I/O implementation
* ️ CLI tool
* Fast, lightweight, no dependencies
* Clean error handling with `perror`

---

## ️ Build

```bash
gcc custom_cat.c -o custom_cat
```

---

## ️ Usage

```bash
./custom_cat -r <filename>
```

---

## Example

Before:
```
(No output)
```

Execution:
```bash
./custom_cat -r hello.txt
```

After:
```
Hello World!
```

---

## Concept

```
(filename + flag) → stdout
```

---

## Internals

* `fopen` → file opening
* `fgetc` → character-by-character reading
* `putchar` → writing to stdout
* `strcmp` → flag validation
* `fclose` → stream management

---

## Current Limitations

* Only supports `-r` flag
* Single file at a time
* Linux / Unix primary (POSIX)
* No support for stdin redirection yet

---

## Future Improvements

* Support for multiple files
* More `cat` flags (e.g., `-n` for line numbering)
* Buffer-based reading for better performance
* Interactive mode
