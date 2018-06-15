/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** put str one by one
*/

#include "../include/my.h"

void my_put_zero(char *str)
{
	int size = my_strlen(str);
	int i = 2;
	char *res = malloc(sizeof(char) * 5);

	my_revstr(str);
	while (i > size - 1)
		str[i--] = 48;
	my_revstr(str);
}

int my_print_str(char *str)
{
	long i = 0;
	int len;
	char *res = malloc(sizeof(char) * 5);

	while (str[i] != '\0') {
		if (str[i] >= 32 && str[i] < 127)
			my_putchar(str[i]);
		else {
			my_putchar('\\');
			len = longlen((unsigned long)str[i]);
			res = int_to_octastr((unsigned long)str[i], len);
			my_put_zero(res);
			my_print_str(res);
		}
		i++;
	}
	free(res);
	return (0);
}
