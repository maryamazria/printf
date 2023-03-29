#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list arg_list;
    int printed_chars = 0;

    va_start(arg_list, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(arg_list, int);
                    putchar(c);
                    printed_chars++;
                    break;
                }
                case 's': {
                    char *s = va_arg(arg_list, char *);
                    fputs(s, stdout);
                    printed_chars += strlen(s);
                    break;
                }
                case '%': {
                    putchar('%');
                    printed_chars++;
                    break;
                }
                default:
                    break;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(arg_list);

    return printed_chars;
}

