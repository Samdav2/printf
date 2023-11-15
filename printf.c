#include "main.h"
/**
 * _printf - C program for the duplicate of c
 * @format: The format of the specifier
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list pointer;
	char c;
	int count = 0;
	char *str;

	va_start(pointer, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;


			switch (*format)
			{
			case 'c':
			{
				c = va_arg(pointer, int);
				_putchar(c);
				count++;
				break;
			}

			case 's':
			{
				str = va_arg(pointer, char *);
				if (str == NULL)
					str = "(null)";
				while(*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}

				break;
			}

			case '%':
			{
				_putchar('%');
				count++;
				break;
			}

			default:
			{
				_putchar('%');
				putchar(*format);
				count += 2;
				break;
			}
			}
		}

		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(pointer);

	return (count);
}
