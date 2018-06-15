/*
** EPITECH PROJECT, 2017
** my str is lower
** File description:
** test if str is only lower alpha or not
*/

int my_str_islower(char const *str)
{
	int i = 0;
	char *strtest;

	if (strtest == str)
		return (1);
	while (str[i] != '\0') {
		if ((str[i] > 'z') || (str[i] < 'a'))
			return (0);
		i++;
	}
	return (1);
}
