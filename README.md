# Welcome to My Printf

Welcome to My Printf projeckt.

Here I will try to explain basics of the program and how to make it work.

## Task

The task for the this assignment was to create my own printf function.

I created the my_printf.c file with contains different sequences for printing different type of values:

1. Signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
2. 'c' The int argument is converted to an unsigned char, and the resulting character is written.
3. 's' The char \* argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
4. 'p' The void \* pointer argument is printed in hexadecimal. Which uses string '0x' and long number.

## Description

To be able to solve this problem I used individual print statements for each type.

My printf function receives the type it wants to print and sends it to the designed other funcions which can print them.

For example when you want to print a string my_printf function will receive the char\* and make print_string function do its job.
After that print_string function will call for the print_char function which uses write(2) to print the chars one by one.

my_printf("Hello world!\n") -> output: "Hello world!"

## Installation

You can find the project on GitHub and after accessinng it use make command in the terminal to make the program work.

Makefile has been flagged with the -Wall -Wextra -Werror and -g3 -fsanitize=address for against the memmory errors.

After calling make in terminal just write ./my_printf and you will execute the program.

## Usage

After accessinng the files you need to use a terminal to execute Makefile by command "make".\

The program should compile and ready to use.

```
./my_project argument1 argument2
./my_printf
```

Make sure to have a main funtion with the

### The Core Team

Selcuk Ata Aksoy aksoy_s

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
