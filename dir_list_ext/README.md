# dir_list_ext

**dir_list_ext** is a robust C tool designed to scan directories and specifically identify and list files along with their extensions.

It utilizes dynamic memory allocation to store and manage the list of found files, providing a clear mapping from filename to extension.

---

## Features

* Identifies all regular files in a directory
* Extracts and displays file extensions
* Handles files without extensions gracefully
* Dynamic memory management for file lists
* ️ CLI tool
* Fast and efficient directory scanning

---

## ️ Build

```bash
gcc dir_list_ext.c -o dir_list_ext
```

---

## ️ Usage

```bash
./dir_list_ext [directory_path]
```

---

## Example

Before:
```
(Directory containing multiple files)
```

Execution:
```bash
./dir_list_ext .
```

After:
```
Fichiers trouvés : 3

[0] main.c  ->  c
[1] data.txt  ->  txt
[2] script  ->  no extension
```

---

## Concept

```
(filename) → (strrchr) → extension
```

---

## Internals

* `opendir / readdir` → directory scanning
* `malloc / realloc` → dynamic array management
* `strdup` → string duplication for storage
* `strrchr` → extension parsing
* `struct stat` → file validation
* `free` → cleanup of dynamic memory

---

## Current Limitations

* Non-recursive
* Linux / Unix only
* Limited to regular files
* Simple dot-based extension parsing

---

## Future Improvements

* Recursive mode
* Sorting by extension
* Filtering by extension type
* File count summary per extension
* Support for hidden files
