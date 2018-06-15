/*
** EPITECH PROJECT, 2017
** my low case
** File description:
** upper case
*/

char *my_strlowcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((64 < str[i]) && (str[i] < 91))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
