/*
** EPITECH PROJECT, 2017
** my strcmp
** File description:
** like strcmp
*/

int my_count_str(char const *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

int comp2(int in1, int in2)
{
	if (in1 < in2)
		return (-1);
	else if (in1 > in2)
		return (1);
	return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
	int a = my_count_str(s1);
	int b = my_count_str(s2);
	int nb;
	int i = 0;
	int res;

	if (a <= b)
		nb = b;
	else
		nb = a;
	while (i != nb) {
		if (s1[i] != s2[i]) {
			res = comp2((int)s1[i], (int)s2[i]);
			return (res);
		}
		i++;
	}
	return (0);
}
