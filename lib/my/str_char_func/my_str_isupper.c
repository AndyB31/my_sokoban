/*
** EPITECH PROJECT, 2017
** my str is upper
** File description:
** test if str is only upper alpha or not
*/

int my_str_isupper(char const *str)
{
	char *strtest;
	int i = 0;

	if (strtest == str)
		return (1);
	while (str[i] != '\0') {
		if ((str[i] > 'Z') || (str[i] < 'A'))
			return (0);
		i++;
	}
	return (1);
}
