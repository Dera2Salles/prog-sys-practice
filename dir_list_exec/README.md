# dir_list_exec

**dir_list_exec** is a C tool that lists directory contents using POSIX APIs and then hands over control to the system `ls -l` command.

It demonstrates the use of directory scanning combined with the `exec` family of system calls to replace the current process.

---

## Features

* Lists regular files, directories, and links
* Custom labels for file types (`[fichier]`, `[dossier]`, `[lien]`)
* Process replacement using `execl`
* ️ CLI tool
* POSIX-compliant filesystem interaction

---

## ️ Build

```bash
gcc dir_list_exec.c -o dir_list_exec
```

---

## ️ Usage

```bash
./dir_list_exec [directory_path]
```

---

## Example

Before:
```
(Standard directory listing)
```

Execution:
```bash
./dir_list_exec .
```

After:
```
main.c  [fichier]
data    [dossier]
(followed by output of ls -l)
```

---

## Concept

```
(directory_scan) → (label_output) → (system_ls)
```

---

## Internals

* `opendir / readdir` → directory scanning
* `entry->d_type` → file type identification (DT_REG, DT_DIR, etc.)
* `execl("/bin/ls", ...)` → process replacement
* `closedir` → resource management
* `perror` → error reporting

---

## Current Limitations

* Hardcoded for `/bin/ls`
* Non-recursive
* Linux / Unix only (requires `dirent.h`)
* Replaces current process (cannot do work after `ls`)

---

## Future Improvements

* Parameterized `exec` command
* Better filtering options
* Recursive mode
* Fallback if `exec` fails
