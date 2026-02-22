# word_search_std

**word_search_std** is a straightforward search tool that scans a file line by line to locate a specific word using standard C library functions.

It provides a quick way to find matches and identifies the exact line number where the target word is first found.

---

## Features

* Line-by-line scanning using `fgets`
* Real-time line numbering
* Standard I/O implementation
* Simple and readable logic
* ️ CLI tool
* No external dependencies

---

## ️ Build

```bash
gcc word_search_std.c -o word_search_std
```

---

## ️ Usage

```bash
./word_search_std <filename> <word_to_find>
```

---

## Example

Execution:
```bash
./word_search_std notes.txt secret
```

Output:
```
This is a test - ligne 1 
The secret is here - ligne 2 
Mot trouvé : secret
```

---

## Concept

```
(filename, word) → fgets(line) → strcmp(line, word)
```

---

## Internals

* `fopen / fclose` → file stream management
* `fgets` → buffered line reading
* `strcspn` → newline trimming
* `strcmp` → exact match verification
* `printf` → reporting progress and results

---

## Current Limitations

* Stops at first match
* Requires exact line match (no substring)
* Case-sensitive
* Fixed buffer size (256 bytes)

---

## Future Improvements

* Search for all occurrences
* Substring matching support
* Case-insensitive search
* Larger or dynamic buffer for long lines
