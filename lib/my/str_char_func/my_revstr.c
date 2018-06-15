/*
** EPITECH PROJECT, 2017
** my revstr
** File description:
** reverse
*/

int my_compt(char const *str)
{
	int f = 0;

	while (str[f] != '\0') {
		f = 1 + f;
	}
	return (f);
}

char *my_revstr(char *str)
{
	int a = 0;
	int b = my_compt(str) - 1;
	char g;

	while (a <= b){
		g = str[a];
		str[a] = str[b];
		str[b] = g;
		a++;
		b--;
	}
	return (str);
}
