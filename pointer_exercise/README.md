# pointer_exercise

**pointer_exercise** is a compact C snippet designed to test and demonstrate advanced pointer concepts such as pointing to compound literals.

It illustrates how to create and access anonymous memory locations directly using pointer syntax.

---

## Features

* Compound literal usage (`(int){1}`)
* Anonymous memory allocation
* Direct pointer dereferencing
* Simple, focused exercise
* Fast compilation

---

## ️ Build

```bash
gcc pointer_exercise.c -o pointer_exercise
```

---

## ️ Usage

```bash
./pointer_exercise
```

---

## Example

Execution:
```bash
./pointer_exercise
```

Output:
```
1
```

---

## Concept

```
pointer → &(anonymous_value) → dereference(*)
```

---

## Internals

* `int *pTab` → integer pointer declaration
* `&(int){1}` → address of a compound literal
* `*pTab` → accessing value via pointer
* Scope rules for anonymous literals

---

## Current Limitations

* Extremely short
* educational only
* Hardcoded value
* Limited scope of demonstration

---

## Future Improvements

* Add array of compound literals
* Extend to structs
* Heap allocation comparison
* More complex pointer chains
