/*
** EPITECH PROJECT, 2018
** init str
** File description:
** place \0 in str
*/

#include "../include/my.h"

char *my_init(char *str, int len)
{
	if (str == NULL)
		return (NULL);
	for (int i = 0; i < len; i++)
		str[i] = '\0';
	return (str);
}
