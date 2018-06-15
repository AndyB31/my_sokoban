/*
** EPITECH PROJECT, 2017
** my str is alpha
** File description:
** test if str is only alpha or not
*/

int my_str_isalpha(char const *str)
{
	int i = 0;
	char *strtest;

	if (strtest == str)
		return (1);
	while (str[i] != '\0') {
		if ((str[i] > 'z') || (str[i] < 'a') && (str[i] > 'Z'))
			return (0);
		if (str[i] < 65)
			return (0);
		i++;
	}
	return (1);
}
