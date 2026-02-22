# word_replacer

**word_replacer** is a powerful C tool for finding and substituting target words within a file using low-level I/O.

It implements a safe "replace-in-place" mechanism by writing to a temporary file, ensuring data integrity during the replacement process.

---

## Features

* Low-level search and replace
* Temporary file-based editing
* Custom separator logic
* Dynamic word buffer for varying word lengths
* ️ CLI tool
* Fast and efficient

---

## ️ Build

```bash
gcc word_replacer.c -o word_replacer
```

---

## ️ Usage

```bash
./word_replacer <filename> <target_word> <replacement_word>
```

---

## Example

Before (`data.txt`):
```
The cat is on the mat.
```

Execution:
```bash
./word_replacer data.txt cat dog
```

After (`data.txt`):
```
The dog is on the mat.
```

---

## Concept

```
(target, replacement) → scan → (match ? write(replacement) : write(original))
```

---

## Internals

* `open / read / write` → direct system I/O
* `malloc / realloc` → growing word buffer
* `isSeparator` → precise boundary detection
* `unlink / rename` → safe file substitution
* `strcmp` → string comparison for matches

---

## Current Limitations

* Case-sensitive only
* Single file processing
* No backup of original file
* Linux / Unix primary

---

## Future Improvements

* Multi-file support
* Regex / Pattern matching
* Case-insensitive mode
* Interactive confirmation
* Undo functionality
