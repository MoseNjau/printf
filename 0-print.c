#include "main.h"
/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
    int characters = 0;  // Initialize the character count to 0
    va_list arguments;

    va_start(arguments, format);
    
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(arguments, int);
                write(1, &c, 1);
                characters++;
            }
            else if (*format == 's')
            {
                char *string = va_arg(arguments, char *);
                size_t len = strlen(string);
                write(1, string, len);
                characters += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                characters++;
            }
        }
        else
        {
            write(1, format, 1);  // Print the character directly
            characters++;
        }
        format++;  // Move to the next character in the format string
    }

    va_end(arguments);  // Cleanup arguments

    return characters;  // Return the total number of characters printed
}
