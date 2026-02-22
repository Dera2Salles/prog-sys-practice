# file_append

**file_append** is a minimal C tool that appends a single line of text to a specified file.

It's a straightforward utility for logging or updating text files from the command line without overwriting existing content.

---

## Features

* Append mode writing (`"a"`)
* Automatic newline addition
* Simple CLI interface
* Fast execution
* No dependencies

---

## ️ Build

```bash
gcc file_append.c -o file_append
```

---

## ️ Usage

```bash
./file_append <filename> "<text_to_append>"
```

---

## Example

Before (`notes.txt`):
```
First line
```

Execution:
```bash
./file_append notes.txt "Second line"
```

After (`notes.txt`):
```
First line
Second line
```

---

## Concept

```
(filename, text) → fopen(append) → fprintf
```

---

## Internals

* `fopen(path, "a")` → opening in append mode
* `fprintf` → formatted writing to file stream
* `fclose` → stream closure
* `argv` → CLI argument parsing

---

## Current Limitations

* Appends only one string at a time
* No error checking for `fopen` (minimalist)
* Single file target
* Linux / Unix / Windows (standard C)

---

## Future Improvements

* Add error handling for file permissions
* Support for multiple lines
* Quiet/Verbose modes
* Option to exclude the automatic newline
