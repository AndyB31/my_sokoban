/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** copy str
*/

#include "../include/my.h"

void my_strcp(char const *a, char *b)
{
	int i = 0;

	while (a[i] != '\0') {
		b[i] = a[i];
		i++;
	}
}

int test(char *keep, char *find, int i)
{
	int e = 0;
	int count = 0;

	while (find[e] != '\0') {
		if (find[e] == keep[e]) {
			count++;
		}
		e++;
	}
	if (count == (my_strlen(find) - 1)) {
		return (1);
	}
	return (0);
}

char *my_strstr(char *str, char const *to_find)
{
	char *a = malloc(sizeof(char) * (my_strlen(to_find) + 1));
	int i = 0;
	int c = 0;
	int nb;
	char keep[100];

	my_strcp(to_find, a);
	while (str[i] != '\0') {
		if ((c == 0) && (str[i] == a[c])) {
			keep[0] = str[i];
		} else if ((str[i] == a[c]) && (keep[c - 1] == a[c - 1])) {
			keep[c] = str[i];
		} else
			c = -1;
		c++;
		if (1 == test(keep, a, i))
			return (a);
		i++;
	}
	return (NULL);
}
