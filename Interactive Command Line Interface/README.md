# File Explorer (CLI)

This project is an interactive command-line file explorer written entirely in C, which simulates a virtual file system.

## Aim of the project

The primary objective of this project is to model a functional file system in user space using C, reinforcing key concepts such as:

- Dynamic memory allocation and pointer management

- Trees, linked list and stack data structures

- Command parsing and argument handling

- Recursive traversal and data manipulation

- Simulating file operations

## Features list

| Feature               | Data Structure Used        | Description                                    |
| --------------------- | -------------------------- | ---------------------------------------------- |
| Folder/File hierarchy | Tree (Parent-Children)     | Each node is either a file or directory        |
| Multiple entries      | Linked list (Next sibling) | Enables multiple files/folders in the same dir |
| Navigation            | Stack + Tree Traversal     | Tracks navigation history                      |
| Create dir/file       | Tree node creation         | Dynamically adds nodes at current location     |
| Rename / Remove       | Tree editing               | Recursively delete or rename nodes             |
| List files / dirs     | Tree traversal             | Display current directory and path             |
| Move / Copy           | Tree re-linking            | Move or duplicate subtrees                     |


## Build & Run Instructions

Go to root directory of repository and do `make`.

## Commands Supported

| Command                     | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| `mkdir <name>`              | Create a new directory in the current location               |
| `touch <name>`              | Create a new empty file in the current directory             |
| `cd <name>`                 | Navigate into the specified subdirectory                     |
| `cd ..`                     | Move up one level to the parent directory                    |
| `ls`                        | List all files and folders in the current directory          |
| `pwd`                       | Display the full path of the current directory               |
| `rm <name>`                 | Delete the specified file or directory (recursive if folder) |
| `rename <old> <new>`        | Rename a file or folder                                      |
| `mv <source> <destination>` | Move a file or directory to a new location                   |
| `cp <source> <destination>` | Copy a file or directory to a new location                   |
| `clear`                     | Clear the command-line screen                                |
| `exit`                      | Exit the file explorer                                       |



