# Simple Shell

A simple UNIX command line interpreter built as part of the Holberton School curriculum.

## Description

This is a simple shell program that can execute commands, handle the PATH, and implements built-in commands. It's designed to replicate basic functionality of the sh shell.

## Features

- Display a prompt and wait for user input
- Execute simple commands
- Handle command lines with arguments
- Implement the PATH
- Implement built-ins (exit, env)
- Handle Ctrl+D (EOF)
- Error handling

## Installation

Clone the repository and compile:
```bash
git clone https://github.com/YOUR_USERNAME/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode
```bash
$ ./hsh
($) /bin/ls
file1 file2 file3
($) exit
$
```

### Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
file1 file2 file3
$
```

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

Test your shell against sh:
```bash
# Interactive
./hsh

# Non-interactive
echo "ls" | ./hsh
```

## Project Requirements

- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using gcc
- Code follows Betty style
- No memory leaks
- Maximum 5 functions per file

## Authors

See [AUTHORS](AUTHORS) file for list of contributors.

## License

This project is part of the Holberton School curriculum.
