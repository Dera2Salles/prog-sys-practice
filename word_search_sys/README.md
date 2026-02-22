# word_search_sys

**word_search_sys** is a high-performance, low-level word search utility that uses direct system calls for maximum efficiency.

It supports both exact word matching and substring searching, providing detailed reports on matches and their line locations.

---

## Features

* POSIX system call implementation (`open`, `read`)
* Exact match vs Substring search (`-i` flag)
* Global match count
* Accurate line number tracking
* ️ CLI tool
* Fast, no-dependency C implementation

---

## ️ Build

```bash
gcc word_search_sys.c -o word_search_sys
```

---

## ️ Usage

### Exact Match
```bash
./word_search_sys <filename> <word>
```

### Substring Search
```bash
./word_search_sys -i <filename> <partial_word>
```

---

## Example

Execution:
```bash
./word_search_sys -i logs.txt error
```

Output:
```
Mot trouvé : 'critical_error_88' à la ligne 12
Mot trouvé : 'null_pointer_error' à la ligne 45

Nombre total d'occurrences : 2
```

---

## Concept

```
(search_term, flag) → byte_read → word_reconstruct → match_check
```

---

## Internals

* `open / read` → low-level data access
* `strstr` → substring search logic
* `strcmp` → exact match logic
* `isEndOfSentence` → custom word boundary detection
* `BUF_SIZE` → small, optimized reading buffer

---

## Current Limitations

* Linux / Unix only (POSIX)
* Case-sensitive
* Fixed word size limit (64 chars)
* Single file target

---

## Future Improvements

* Recursive directory search
* Case-insensitive mode
* Regular expression support
* Colorized output for terminal
* Interactive search mode
