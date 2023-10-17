#include "main.h"

/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int characters = 0;
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
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(arguments, int);
                char buffer[12];
                int j = 0;

                if (num == 0)
                {
                    write(1, "0", 1);
                    characters++;
                }
                else if (num < 0)
                {
                    write(1, "-", 1);
                    characters++;
                    num = -num;
                }
                while (num != 0)
                {
                    buffer[j++] = (num % 10) + '0';
                    num /= 10;
                }
                while (j > 0)
                {
                    write(1, &buffer[--j], 1);
                    characters++;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                characters++;
            }
        }
        else
        {
            write(1, format, 1);
            characters++;
        }
        format++;
    }

    va_end(arguments);

    return (characters);
}
