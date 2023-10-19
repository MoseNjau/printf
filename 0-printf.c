#include "main.h"

/**
 * _printf - A custom printf function that handles %c, %s, and %%
 * @format: The format string.
 * @...: Variable number of arguments.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    char c;
    char *str;

    while (*format)
    {
        if (*format != '%')
        {
            chars_printed += write(1, format, 1);
            format++;
            continue;
        }

        format++;
        switch (*format)
        {
            case 'c':
                c = va_arg(args, int);
                chars_printed += write(1, &c, 1);
                break;

            case 's':
                str = va_arg(args, char *);
                if (str)
                {
                    int len = 0;
                    while (str[len])
                        len++;
                    chars_printed += write(1, str, len);
                }
                else
                {
                    chars_printed += write(1, "(null)", 6);
                }
                break;

            case '%':
                chars_printed += write(1, "%", 1);
                break;

            default:
                chars_printed += write(1, "%", 1);
                chars_printed += write(1, format, 1);
                break;
        }
        format++;
    }

    va_end(args);
    return chars_printed;
}
