/*
** EPITECH PROJECT, 2018
** my_is_nbr
** File description:
** my_is_nbr
*/

#include <my.h>

int my_is_nbr(char const *str)
{
	int status = 0;

	if (str == NULL)
		return (-1);
	for (int i = 0; i < my_strlen(str); i++) {
		if (str[i] == '-') {
			status = -1;
			continue;
		}
		if (str[i] < '0' || str[i] > '9') {
			return (status);
		}
		status = -1;
	}
	return (1);
}