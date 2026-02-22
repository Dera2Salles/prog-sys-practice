# pointer_arithmetic

**pointer_arithmetic** is a minimal C program created to explore how memory addresses and offsets work in practice.

It specifically demonstrates how adding an integer to a character pointer allows jumping to different parts of a string.

---

## Features

* Direct memory address manipulation
* String offset demonstration
* Minimalist code
* Educational focus
* Zero dependencies

---

## ️ Build

```bash
gcc pointer_arithmetic.c -o pointer_arithmetic
```

---

## ️ Usage

```bash
./pointer_arithmetic
```

---

## Example

Code snippet:
```c
char *c = "Dera";
printf("%s", c + 1);
```

Output:
```
era
```

---

## Concept

```
pointer + N → memory_address(base + N * sizeof(type))
```

---

## Internals

* `char *` → pointer to character array
* `+ 1` → offset jumping (1 byte for `char`)
* `printf("%s", ...)` → printing from new memory location
* Stack vs Data segment visibility

---

## Current Limitations

* Hardcoded values
* educational only
* No protection against out-of-bounds
* Single use-case

---

## Future Improvements

* Add examples for `int*` (multi-byte jumps)
* Pointer subtraction demonstration
* Comparison with array indexing (`p[i]`)
* Command-line offset input
