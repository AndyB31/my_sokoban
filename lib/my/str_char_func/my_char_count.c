/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_str_split
*/

#include "../include/my.h"

int my_char_count(char *str, char c)
{
	int count = 0;

	for (int i = 0; str[i]; i++)
		if (str[i] == c)
			count++;
	return (count);
}
