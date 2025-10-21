# Get Next Line (get_next_line)

![Grade](https://img.shields.io/badge/Grade-125%25-brightgreen)

## Project Overview

`get_next_line` is a fundamental project at 42 that involves writing a C function to read content from a file descriptor, one line at a time. The function must return a single line (ending with a newline character, `\n`, if present) each time it's called, and `NULL` when the end of the file is reached or an error occurs.

---

## Core Concept: Static Variables

The primary challenge and core concept of this project is the correct use of a **static variable**.

Because the `get_next_line` function must be able to read a file line by line, it will likely read more data from the file descriptor using the `read()` function than what it returns in a single line.

A **static variable** is used to "remember" this leftover data between function calls. When `get_next_line` is called again for the same file descriptor, it first checks this static variable for any remaining characters from the previous read before attempting to read more data from the file descriptor. This ensures that no data is lost and the reading position is effectively maintained across multiple calls.

---

## Function Prototype

The mandatory function prototype is:

```c
char *get_next_line(int fd);
```

-----

## How It Works (Logic)

### Mandatory Part

The mandatory part requires the function to work correctly for a single file descriptor. The logic is as follows:

1.  A **static variable** (e.g., `static char *leftover`) is used to store any data that was read but not returned in the previous call.
2.  The function first checks this `leftover` buffer. If it contains a newline, a line is extracted, and the remainder is saved back into `leftover`.
3.  If `leftover` doesn't contain a newline, the function enters a loop, calling `read()` to fill a temporary buffer from the file descriptor (`fd`).
4.  This new data is appended to the `leftover` variable.
5.  The loop continues until `read()` returns 0 (end of file) or -1 (error), or until a newline character (`\n`) is found within the `leftover` buffer.
6.  Once a newline is found (or the file ends), the line is extracted from `leftover`, returned to the user, and the remaining characters (if any) are stored back in the `leftover` variable for the next call.

### Bonus Part

The bonus part adds the complexity of managing **multiple file descriptors at the same time**.

To achieve this, instead of a single static variable, we use a **static array of strings**. 42 subjects impose a limit of `FOPEN_MAX` or `OPEN_MAX` for the number of simultaneously open files, which is often 1024.

The implementation uses a static array indexed by the file descriptor:
`static char *leftover_buffers[1024];`

When `get_next_line(fd)` is called:

  * The function uses `fd` as the **index** to access `leftover_buffers[fd]`.
  * This specific element `leftover_buffers[fd]` acts as the persistent "leftover" buffer for *that specific file only*.
  * This allows the function to be called with different file descriptors (e.g., `get_next_line(3)`, then `get_next_line(4)`, then `get_next_line(3)` again) without losing its place in any of the files, as each file's leftover data is stored independently in the static array.

-----

## Usage & Compilation

First, clone the repository:

```bash
git clone https://github.com/RafaelyRezende/GetNextLine.git
cd GetNextLine
```

The project is compiled using the provided `Makefile`.

**Compilation Flags**

The buffer size for the `read()` function is passed as a compilation flag. The code is robust and works with any buffer size.

```bash
make -D BUFFER_SIZE=42

make -D BUFFER_SIZE=1

make -D BUFFER_SIZE=10000000
```

**Makefile Rules**

  * `make all`: Compiles the mandatory part (`libgnl.a`).
  * `make bonus`: Compiles the bonus part (`libgnl_bonus.a`).
  * `make clean`: Removes the object files.
  * `make fclean`: Removes the object files and the final executables/libraries.
  * `make re`: Runs `fclean` followed by `all`.

-----

## File Structure

### Mandatory Part

  * `get_next_line.c`
  * `get_next_line.h`
  * `get_next_line_utils.c`

### Bonus Part

  * `get_next_line_bonus.c`
  * `get_next_line_bonus.h`
  * `get_next_line_utils_bonus.c`

-----

## Testing

This project was successfully tested for leaks, errors, and functionality using the **Francinette** tester.

  * **Francinette Repository:** [https://github.com/xicodomingues/francinette](https://github.com/xicodomingues/francinette)

**How to run the tester:**

```bash
git clone https://github.com/xicodomingues/francinette.git
cd francinette
./tester.sh /path/to/your/GetNextLine/
```
