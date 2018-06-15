/*
** EPITECH PROJECT, 2017
** strcapitalize
** File description:
** capitalize
*/

char *my_strcapitalize(char *str)
{
	int i = 0;
	int test = 1;

	while (str[i] != '\0') {
		if ((64 < str[i]) && (str[i] < 91)) {
			str[i] = str[i] + 32;
			test = 0;
		}
		if ((str[i] > 96) && (str[i] < 123) && (test == 1)) {
			str[i] = str[i] - 32;
			test = 0;
		}
		if ((str[i] > 122) || (str[i] < 97) && (str[i] > 90))
			test = 1;
		if ((str[i] < 48) || (str[i] < 65) && (str[i] > 57))
			test = 1;
		i++;
	}
	return (str);
}
