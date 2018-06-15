/*
** EPITECH PROJECT, 2017
** my str is printable
** File description:
** test if str is only printable or not
*/

int my_str_isprintable(char const *str)
{
	int i = 0;
	char *strtest;

	if (strtest == str)
		return (1);
	while (str[i] != '\0') {
		if ((str[i] > 255) || (str[i] < 32))
			return (0);
		i++;
	}
	return (1);
}
