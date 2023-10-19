#include "main.h"

/**
 * _printf - A custom printf function that handles %c, %s, %d, %i, and %%
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

            case 'd':
            case 'i':
                int num = va_arg(args, int);
                int num_chars = num < 0 ? 1 : 0;
                int temp = num;
                while (temp != 0)
                {
                    temp /= 10;
                    num_chars++;
                }
                if (num < 0)
                {
                    chars_printed += write(1, "-", 1);
                    num = -num;
                }
                char num_str[12];  // Longest possible integer is -2147483648 (11 chars + null-terminator)
                int i = num_chars;
                while (i > 0)
                {
                    num_str[--i] = num % 10 + '0';
                    num /= 10;
                }
                chars_printed += write(1, num_str, num_chars);
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
