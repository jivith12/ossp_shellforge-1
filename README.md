# ShellForge

ShellForge is a Unix-like shell developed as part of the Operating Systems and Systems Programming (OSSP) Project-Based Learning course.

## Features (Week 1)
- Interactive REPL loop
- Makefile-based build
- Git repository
- Linux development environment

## Project Structure
```
ShellForge/
├── Makefile
├── README.md
├── .gitignore
├── include/
│   └── shell.h
├── src/
│   └── main.c
├── docs/
├── tests/
├── screenshots/
└── bin/
```

## Build
```bash
make
```

## Run
```bash
make run
```

## Week 2 Features
- Dynamic command input
- Memory allocation using malloc()
- Automatic buffer expansion using realloc()
- Proper memory cleanup using free()

## Week 3 Features
- Command parsing using strtok()
- Dynamic argv[] construction
- Modular parser implementation
- Ready for process execution with execvp()

## Week 4 Features
- Process creation using fork()
- Command execution using execvp()
- Parent-child synchronization using waitpid()
- Error handling using perror()

## Week 5 Features
- Built-in command support
- cd
- pwd
- help
- clear
- exit
- Environment variables

## Week 6 Features
- Signal handling
- SIGINT support
- SIGCHLD support
- Zombie cleanup
- Shell survives Ctrl+C
