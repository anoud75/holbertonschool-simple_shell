# Simple Shell

A simple UNIX command line interpreter built as part of the Holberton School curriculum.

## Description

This project is a simple shell implementation that replicates basic functionality of the `/bin/sh` shell. It can execute commands, handle the PATH environment variable, implement built-in commands, and handle both interactive and non-interactive modes.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Built-in Commands](#built-in-commands)
- [Examples](#examples)
- [Compilation](#compilation)
- [Authors](#authors)

## Installation

Clone the repository and compile the shell:
```bash
git clone https://github.com/anoud75/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode
```bash
$ ./hsh
$ /bin/ls
file1 file2 file3
$ pwd
/home/user/holbertonschool-simple_shell
$ exit
$
```

### Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
file1 file2 file3
$
```

## Features

- Displays a prompt and waits for user input
- Executes commands with arguments
- Handles the PATH environment variable
- Implements built-in commands (exit and env)
- Handles end-of-file condition (Ctrl+D)
- Error handling with appropriate messages
- No memory leaks

## Built-in Commands

### exit
Exits the shell with the status of the last executed command.

Usage: `exit`

### env
Prints the current environment variables.

Usage: `env`

## Examples

### Basic Commands
```bash
$ ./hsh
$ ls
AUTHORS builtin.c error.c hsh main.c README.md shell.h
$ pwd
/home/user/holbertonschool-simple_shell
$ exit
$
```

### Commands with Arguments
```bash
$ ./hsh
$ ls -l
total 48
-rw-r--r-- 1 user user  239 Nov  7 16:41 AUTHORS
-rw-r--r-- 1 user user 1234 Nov  7 18:30 builtin.c
$ echo Hello World
Hello World
$ exit
$
```

### Non-Interactive Mode
```bash
$ echo "ls" | ./hsh
AUTHORS builtin.c error.c hsh main.c
$ cat commands.txt | ./hsh
file1 file2
/home/user
```

### Error Handling
```bash
$ ./hsh
$ invalidcommand
./hsh: 1: invalidcommand: not found
$ exit
$
```

## Compilation

Compile with:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Requirements

- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using gcc
- Code follows Betty style
- No more than 5 functions per file
- All header files are include guarded

## Files

- `shell.h` - Header file with prototypes
- `main.c` - Entry point
- `prompt.c` - Display prompt
- `read_line.c` - Read user input
- `trim.c` - Trim whitespace
- `parse_args.c` - Parse arguments
- `path.c` - Handle PATH
- `execute.c` - Execute commands
- `builtin.c` - Built-in commands
- `error.c` - Error handling

## Authors

See AUTHORS file for contributors.

## Acknowledgments

Holberton School for project requirements and support.

Project created: November 2025
