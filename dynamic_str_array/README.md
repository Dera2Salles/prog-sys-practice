# dynamic_str_array

**dynamic_str_array** is a technical demonstration of manual memory management in C, specifically focusing on building and resizing arrays of strings.

It serves as a reference for using `malloc`, `realloc`, and `free` to handle dynamic data structures.

---

## Features

* Dynamic string array creation
* Array resizing using `realloc`
* Manual memory allocation and deallocation
* Safe memory handling patterns (setting to NULL after free)
* Deep copying strings with `strdup`

---

## ️ Build

```bash
gcc dynamic_str_array.c -o dynamic_str_array
```

---

## ️ Usage

```bash
./dynamic_str_array
```

---

## Example

Output:
```
Dera
Test
Encore
Dera
```

---

## Concept

```
(initial_malloc) → (data_fill) → (realloc_expand) → (free_all)
```

---

## Internals

* `malloc` → initial heap allocation
* `realloc` → dynamic resizing of pointers
* `strdup` → cloning string literals into heap
* `free` → manual lifecycle management
* Pointer arithmetic for array access

---

## Current Limitations

* hardcoded data for demonstration
* no CLI arguments
* simple index-based access
* no search or sort functions

---

## Future Improvements

* Generic dynamic array implementation (void*)
* Add/Remove/Insert functions
* Circular buffer or linked list comparisons
* Performance benchmarks vs stack allocation
