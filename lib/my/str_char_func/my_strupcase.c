/*
** EPITECH PROJECT, 2017
** my strupcase
** File description:
** upper case
*/

char *my_strupcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((96 < str[i]) && (str[i] < 123))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
