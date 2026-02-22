# file_copy_std

**file_copy_std** is a C utility that performs file copying using standard library functions.

It demonstrates the "high-level" approach to file I/O in C, utilizing buffered streams and character-by-character processing.

---

## Features

* Standard C library implementation
* Buffered stream handling
* Copies source to destination exactly
* Simple CLI interface
* Fast and cross-platform compatible

---

## ️ Build

```bash
gcc file_copy_std.c -o file_copy_std
```

---

## ️ Usage

```bash
./file_copy_std <source_file> <destination_file>
```

---

## Example

Before:
```
source.txt (exists)
dest.txt (does not exist)
```

Execution:
```bash
./file_copy_std source.txt dest.txt
```

After:
```
dest.txt (identical to source.txt)
```

---

## Concept

```
(source_stream) → getc → putc → (dest_stream)
```

---

## Internals

* `fopen` → opening file streams
* `getc` → reading characters from input stream
* `putc` → writing characters to output stream
* `EOF` → end-of-file detection
* `fclose` → stream cleanup

---

## Current Limitations

* Non-recursive
* Overwrites destination without warning
* No progress bar
* No permission handling

---

## Future Improvements

* Add buffer-based copying (`fread`/`fwrite`)
* Add `-i` flag for interactive overwrite
* Support for huge files (>4GB)
* Progress indicator
