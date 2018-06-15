/*
** EPITECH PROJECT, 2017
** strncat
** File description:
** str n cat
*/

#include "../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
	int size = my_strlen(dest);
	int i = 0;

	while (src[i] != '\0' && nb > 0) {
		dest[size + i] = src[i];
		i++;
		nb--;
	}
	return (dest);
}
