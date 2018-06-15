/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** lenght of a string
*/

#include <stdio.h>

int my_strlen(char const *str)
{
	int f = 0;

	if (str == NULL)
		return (0);
	while (str[f] != '\0') {
		f = 1 + f;
	}
	return (f);
}
