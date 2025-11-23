# \_printf 📄

A custom implementation of the C standard library `printf` function.

## 📖 Description

`_printf` is a variadic function in C that formats and prints data to the standard output (`stdout`). It was developed as part of the Holberton School curriculum to understand the underlying mechanics of variadic functions, format specifiers, and memory management in C.

This implementation replicates the core functionality of the standard `printf`, handling specific format specifiers to convert and print arguments such as characters, strings, and integers.

## ⚙️ Prototype

```c
int _printf(const char *format, ...);
```
```c
int handle_specifier(const char *format, int *i, va_list args);
```
### Return Value

  * **Success:** Returns the number of characters printed (excluding the null byte used to end output to strings).
  * **Error:** Returns `-1` if the format string is `NULL` or if an error occurs.

## 🚀 Usage

To use `_printf` in your project, include the header file `main.h` and call the function with a format string and any necessary arguments.

### Compilation

Compile the program using `gcc` with the following flags (as per project requirements):

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```
note! dont forget to add your main file that uses (_printf) function

### Example Main File

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Character: %c\n", 'A');
    _printf("Integers: %d, %i\n", 1024, -42);
    return (0);
}
```

## 📋 Supported Format Specifiers

The function processes the format string and handles the following conversion specifiers:

| Specifier | Description | Example Usage | Output |
| :--- | :--- | :--- | :--- |
| `%c` | Prints a single character. | `_printf("%c", 'H');` | `H` |
| `%s` | Prints a string of characters. Handles `NULL` strings by printing `(null)`. | `_printf("%s", "Hello");` | `Hello` |
| `%%` | Prints a literal percent sign. | `_printf("100%%");` | `100%` |
| `%d` | Prints a signed decimal integer. | `_printf("%d", 10);` | `10` |
| `%i` | Prints a signed integer. | `_printf("%i", -10);` | `-10` |

## 📂 File Structure

| File | Description |
| :--- | :--- |
| `_printf.c` | Contains the main logic for the `_printf` function, loop for parsing the format string, and specifier selection. |
| `functions.c` | Contains helper functions: `_putchar` (writes char to stdout), `print_string` (writes strings), `print_int` (handles %d/%i), and `print_number` (recursive integer printing). |
| `main.h` | Header file containing function prototypes and standard library includes (`<stdarg.h>`, `<unistd.h>`, `<string.h>`). |
| `man_3_printf` | Custom manual page documenting the function's usage, synopsis, and examples. |

## 👥 Authors
  * **Badr Alshaya**
  * **Rama Al Shehri**

-----

*this Project completed for Holberton School.*

## FlowChart

```mermaid
flowchart TD
    A["Start _printf"] --> B["Initialize count_chars and va_list"]
    B --> C["Loop over format string"]
    C --> D{"Is char '%' ?"}
    D -->|No| E["Print char directly"] --> C
    D -->|Yes| F["Call handle_specifier"]
    F --> G["Check flags (+, space, #)"]
    G --> H{"Specifier type"}
    H -->|c| I["Print char"]
    H -->|s| J["Print string"]
    H -->|d/i| K["Print integer"]
    H -->|u| L["Print unsigned int"]
    H -->|o| M["Print octal"]
    H -->|x/X| N["Print hex"]
    H -->|b| O["Print binary"]
    H -->|S| P["Print escaped string"]
    H -->|p| Q["Print pointer"]
    H -->|Other| R["Print char with flags"]
    C --> S{"End of format string?"}
    S -->|Yes| T["va_end and return count_chars"]
    S -->|No| C
