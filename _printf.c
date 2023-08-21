#include "main.h"

/**
 * _printf - function that produces output according to a format.

 * @format: an input character string.
 *
 * Return: the number of characters printed.
 */


int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int written = 0;
	char ch;

	while ((ch = *format) != '\0') {
		if (ch == '%') {
			format++;  // Move past '%'
			ch = *format;
			if (ch == '\0')
				break;

			if (ch == 'd') {
				int num = va_arg(args, int);
				written += printf("%d", num);
			} else if (ch == 'f') {
				double num = va_arg(args, double);
				written += printf("%f", num);
			} else if (ch == 'c') {
				int letter = va_arg(args, int);
				written += printf("%c", letter);
			} else {
				written += putchar(ch);
			}
		} else {
			written += putchar(ch);
		}

		format++;
	}

	va_end(args);
	return written;
}
