<h1 align="center">
	๐ get_next_line
</h1>

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br>
</p>

<p align="center">
	<img alt="GitHub language count" src="https://img.shields.io/github/languages/count/Kankuro2000000/GetNextLine">
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Kankuro2000000/GetNextLine?color=blue" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> ยท </span>
	<a href="#-testing">Testing</a>
</h3>

---

## ๐ก About the project

The aim of this project is to make you code a function that returns a line, read from a file descriptor.

	You will understand how files are opened, read and closed in an OS,
	and how they are interpreted by a programming language for further analysis.
	This task is crucial to understand for a future programmer since much of the time is based
	on manipulating files for data management and persistence.
	This project consists of coding a function that returns one line at a time from a text file.


## ๐ ๏ธ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## ๐ Testing

You only have to edit the get_next_line.c file and uncomment the main function and headers inside it.
You can edit test.txt files to put another text if you wish to test othe cases.
Then simply run this command (change "xx" with desired buffer size) :

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```

Or you can also use this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
