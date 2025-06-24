🖨️ my_printf – Minimal printf clone in C

A lightweight, custom implementation of printf written in pure C using only the unistd.h system call for output. Inspired by Jonas Birch’s low-level programming tutorials.
✅ Features Implemented

    Basic format parsing with %

    %s – Print strings

    %c – Print individual characters

    %d – Print positive integers (no negatives yet)

    Escaped %% prints a literal %

    \r\n, \n, and \r handled gracefully

    Graceful fallback (💣) for unsupported formats

📁 Project Structure

.
├── helper.c         # Helper functions (strlen, chardup, itoa, etc.)
├── helper.h         # Shared macro definitions and function declarations
├── printf.c         # Core printf implementation
├── printf.h         # `my_printf` function declaration
├── Main.c           # Test/demo runner
├── Makefile         # Build instructions
└── print            # The compiled executable

🛠️ Build & Run

make
./print

🔧 To-Do / WIP

Handle negative numbers for %d

Add %x, %X (hex)

Add %o (octal)

%u (unsigned integer)

%b (binary, just for fun)

Width/precision formatting (maybe 👀)


Why?

For fun, learning, and mastering how printf really works under the hood —using only minimal standard support (stdarg.h + unistd.h). 
No stdio.h, no stdlib.h. Just raw syscalls, variadic arguments, and handcrafted logic.
