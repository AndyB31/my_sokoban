/*
** EPITECH PROJECT, 2017
** my printf
** File description:
** print everythings
*/

#include <stdarg.h>
#include "../include/my.h"

int find_mod2(char *option, va_list list, int index)
{
	if (option[index] == 'u')
		my_put_unbr(va_arg(list, unsigned int));
	if (option[index] == 'p')
		my_put_pt(va_arg(list, void *));
	if (option[index] == 'c')
		my_putchar((char)va_arg(list, int));
	if (option[index] == 'x' || option[index] == 'X')
		hexaprint((unsigned long)va_arg(list, unsigned int),
		option[index]);
	if (option[index] == 'o')
		octaprint((unsigned long)va_arg(list, unsigned int));
	if (option[index] == 'b')
		binprint((unsigned long)va_arg(list, unsigned int));
	if (option[index] == 'S')
		my_print_str(va_arg(list, char *));
	return (0);
}

int find_mod(char *option, va_list list, int index)
{
	if (option[index] == 's')
		my_putstr(va_arg(list, char *));
	if (option[index] == 'i' || option[index] == 'd')
		my_put_nbr(va_arg(list, int));
	if (option[index] == 'h') {
		my_put_nbr(va_arg(list, int));
		return (1);
	}
	if (option[index] == 'l') {
		if (option[index + 1] == 'u')
			my_put_lunbr(va_arg(list, unsigned long));
		else if (option[index + 1] == 'd' || option[index + 1] == 'd')
			my_put_lnbr(va_arg(list, long));
		else {
			my_putchar('%');
			return (0);
		}
		return (1);
	}
	return (find_mod2(option, list, index));
}

int my_printf(char *format, ...)
{
	va_list list;
	int i = 0;
	int size = my_strlen(format);

	va_start(list, format);
	while (i < size) {
		while (format[i] != '%' && i < size)
			my_putchar(format[i++]);
		if (i == size)
			break;
		i++;
		i = i + find_mod(format, list, i++);
	}
	return (my_strlen(format));
}
