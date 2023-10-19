#include "main.h"

/**
 * _printf - A custom printf function that handles %d and %i specifiers.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    char buffer[1024];  /* A buffer to store the output */

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'd')
        {
            int num = va_arg(args, int);
            int len = 0;

            if (num < 0)
            {
                buffer[len++] = '-';
                num = -num;
            }

            while (num > 0)
            {
                buffer[len++] = '0' + (num % 10);
                num /= 10;
            }

            while (len > 0)
            {
                chars_printed += write(1, &buffer[--len], 1);
            }

            format += 2;  /* Move to the next character after 'd' */
        }
        else if (*format == '%' && *(format + 1) == 'i')
        {
            /* Handle 'i' in the same way as 'd' */
            int num = va_arg(args, int);
            int len = 0;

            if (num < 0)
            {
                buffer[len++] = '-';
                num = -num;
            }

            while (num > 0)
            {
                buffer[len++] = '0' + (num % 10);
                num /= 10;
            }

            while (len > 0)
            {
                chars_printed += write(1, &buffer[--len], 1);
            }

            format += 2;  /* Move to the next character after 'i' */
        }
        else
        {
            /* Handle other characters */
            chars_printed += write(1, format, 1);
            format++;
        }
    }

    va_end(args);
    return chars_printed;
}

