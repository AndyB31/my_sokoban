/*
** EPITECH PROJECT, 2018
** my_realloc
** File description:
** my_realloc
*/

#include <my.h>

static char *realloc_str(char *str, int len)
{
	int str_length = my_strlen(str);
	char *tmp = malloc(sizeof(char) * (str_length + 1));

	if (tmp == NULL)
		return (NULL);
	for (int i = 0; i < str_length + 1; i++)
		tmp[i] = '\0';
	my_strcpy(tmp, str);
	free(str);
	str = malloc(sizeof(char) * (str_length + 1 + len));
	if (str == NULL)
		return (NULL);
	for (int i = 0; i < my_strlen(tmp) + len + 1; i++)
		str[i] = '\0';
	my_strcpy(str, tmp);
	free(tmp);
	return (str);
}

char *my_realloc(char *str, int len)
{
	if (str == NULL) {
		str = malloc((len + 1) * sizeof(char));
		for (int i = 0; i < len; i++)
			str[i] = '\0';
		return (str);
	}
	str = realloc_str(str, len);
	return (str);
}