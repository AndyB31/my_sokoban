/*
** EPITECH PROJECT, 2017
** my str is num
** File description:
** test if str is only num or not
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
	int i = 0;

	if (NULL == str)
		return (-1);
	while (str[i] != '\0') {
		if (str[i] < 48 || str[i] > 57);
			return (0);
		i++;
	}
	return (1);
}
