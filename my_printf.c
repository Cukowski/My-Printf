#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define DECIMAL_BASE 10
#define OCTAL_BASE 8
#define HEX_BASE 16

int print_d(long number); // d
int print_o(long number); // o
int print_u(long number); // u
int print_x(long number, char type); // x, p
int print_p(); // p The void * pointer argument is printed in hexadecimal.
int print_char(int character); // char
int print_string(char *string); // string
int my_printf(char * restrict format, ...);

int print_d(long number) // decimal (d)
{
    int len = 0;
    
    if (number < 0) // for negativ numbers
    {
        print_char('-');
        number = -number;
        len++;
    }

    if (number >= DECIMAL_BASE) 
        len += print_d(number / DECIMAL_BASE);

    len += print_char(number % DECIMAL_BASE + '0');

    return len;
}

int print_o(long number) // unsigned octal (o)
{
    int len = 0;
    int octalNumber[10], i, j;

    for(i = 0; number > 0; i++) // converting octal to decimal
    {
        octalNumber[i] = number % OCTAL_BASE; 
        number = number / OCTAL_BASE;
    }
    
    for(j = i - 1; j >= 0; j--)  
    {
        len += print_d(octalNumber[j]);
    }

    return len;
}

int print_u(long number) // unsigned decimal (u)
{
    int len = 0;

    if (number > 0)
    {
        len += print_d(number);
    }

    return len;
}

int print_x(long number, char type) // unsigned hexadecimal (x). type = pointer(p) or number(default)
{
    int len = 0;
    int i = 1, j, temp;
    char hexa_Number[100];
    
    while (number != 0) 
    {
        temp = number % HEX_BASE;
        
        // converting hexadecimal number in to a decimal number
        if (temp < 10)
            temp = temp + 48; 
        else
            temp = temp + 55;
    
        hexa_Number[i++] = temp;
        number = number / HEX_BASE;
    }

    // printing the hexadecimal number
    for (j = i - 1; j > 0; j--)
    {
        if (type == 'p' && hexa_Number[j] > 64 && hexa_Number[j] < 91)
            len += print_char(hexa_Number[j] + 32);
        else
        len += print_char(hexa_Number[j]);
    }

    return len;
}

int print_char(int character)
{
    int len = 0;

    // printing chars and calculating length
    write(1, &character, 1);
    len++;

    return len; 
}

int print_string(char *string)
{   
    int len = 0;
    
    if (string == NULL) // if we have a NULL value we will print (null)
    {
        char* null1 = "(null)";
        len += write(1, null1, strlen(null1));
        return len;
    }
    
    for (len = 0; *string != '\0'; len++)
    {
        print_char(*string++);
    }

    return len;
}

int my_printf(char * restrict format, ...)
{
    va_list args;
    int len = 0;

    void *ptr;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            switch (*format)
            {
                case 'd':
                    len += print_d(va_arg(args, int));
                    break;
                case 'o':
                    len += print_o(va_arg(args, unsigned int));
                    break;
                case 'u':
                    len += print_u(va_arg(args, unsigned int));
                    break;
                case 'x':
                    len += print_x(va_arg(args, unsigned int), 'd');
                    break;
                case 'c':
                    len += print_char(va_arg(args, int));
                    break;
                case 's':
                    len += print_string(va_arg(args, char *));
                    break;
                case 'p':
                    ptr = va_arg(args, intptr_t *); // intptr_t
                    len += print_string("0x");
                    len += print_x((long long) ptr, 'p');
                    break;
                default:
                    print_char(*format);
                    len++;
            }

        } else {
            print_char(*format);
            len++;
        }

        format++;
    }

    va_end(args);

    return len;
}

int main()
{
    return EXIT_SUCCESS;
}