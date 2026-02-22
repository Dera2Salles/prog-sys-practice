# word_remover

**word_remover** is an efficient C tool that scans single files or entire directories to strip out every occurrence of a specific target word.

It uses low-level file I/O and a temporary file strategy to safely "edit" files in place by removing unwanted tokens while preserving the rest of the structure.

---

## Features

* Process individual files or entire directories
* Automatic detection of file vs directory targets
* Safe in-place editing via temp files
* Custom separator logic (spaces, newlines, tabs, punctuation)
* Dynamic file discovery for directory processing
* ️ CLI tool
* Fast, no-dependency C implementation

---

## ️ Build

```bash
gcc word_remover.c -o word_remover
```

---

## ️ Usage

### Single File
```bash
./word_remover file.txt wordToStrip
```

### Entire Directory
```bash
./word_remover ./data_folder wordToStrip
```

---

## Example

Before (`test.txt`):
```
Hello there, Dera is here.
```

Execution:
```bash
./word_remover test.txt Dera
```

After (`test.txt`):
```
Hello there,  is here.
```

---

## Concept

```
(target) → scan_words → (word == target ? skip : write)
```

---

## Internals

* `opendir / readdir` → directory walking
* `open / read / write` → low-level I/O
* `stat` → file type checks
* `unlink / rename` → safe file replacement
* `malloc / realloc` → dynamic file list storage
* `strcmp` → precise word matching

---

## Current Limitations

* Non-recursive for subdirectories
* Case-sensitive matching only
* Max word size limit (64 chars)
* Overwrites files (cannot undo)

---

## Future Improvements

* Recursive subdirectory processing
* Regex support
* Case-insensitive mode
* Move to trash instead of `unlink`
* Multi-word removal in one pass
