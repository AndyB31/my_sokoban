/*
** EPITECH PROJECT, 2017
** strcat.c
** File description:
** str cat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
	int size = my_strlen(dest);
	int i = 0;

	while (src[i] != '\0') {
		dest[size + i] = src[i];
		i++;
	}
	return (dest);
}
