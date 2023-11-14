#include "main.h"
/**
 * _printf - C program for the duplicate of c
 * @format: The format of the specifier
 * Return: 0
 */
int _printf(const char *format, ...)
{
        va_list pointer;
        char *store;
        char *buffer;
        int i = 0;
	int lenght = 0;

	while (format[lenght] != '\0')
	{
		lenght++;
	}

        buffer = (char *)malloc((lenght + 1) * sizeof(char));
        store = (char *)malloc((lenght + 1) * sizeof(char));

        va_start (pointer, format);

        while (format[i] != '\0')
        {
                buffer[i] = va_arg(pointer, int);

                switch (format[i])
                {
                        case 'c':
                                store = va_arg(pointer, int);
                                if (store[i] == ',')
                                {
                                        buffer[i] = '\0';
                                        printf("%s", buffer);
                                        printf("%c", store);
                                }
                                break;

                        default:
                                break;

                }
                i++;
        }

	va_end(pointer);
	free(store);
	free(buffer);

        return (0);
}
