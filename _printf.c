#include "main.h"

/**
 * _printf - function that produces output according to a format.
 *
 * @format: is a character strin.
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuff = 0;
	va_list args;
	int (*function)(va_list, char *, unsigned int);
	char *buf;

	va_start(args, format), buf = malloc(sizeof(char) * 1024);
	if (!format || !buf || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buf, ibuff), free(buf), va_end(args);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buf, format[i], ibuff), len++, i--;
				}
				else
				{
					len += function(args, buf, ibuff);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buf, format[i], ibuff), len++;
		for (ibuff = len; ibuff > 1024; ibuff -= 1024)
			;
	}
	print_buf(buf, ibuff), free(buf), va_end(args);
	return (len);
}

