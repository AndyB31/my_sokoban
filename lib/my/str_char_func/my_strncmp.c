/*
** EPITECH PROJECT, 2017
** my strncmp
** File description:
** like strcmp
*/

int comp(int in1, int in2)
{
	int marvin;

	if (in1 < in2)
		return (-1);
	else if (in1 > in2)
		return (1);
	return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;
	int in1;
	int in2;
	int res;

	while ((i != n) && (s1[i] != '\0') && (s2[i] != '\0')) {
		if (s1[i] != s2[i]) {
			in1 = s1[i];
			in2 = s2[i];
			res = comp(in1, in2);
			return (res);
		}
		i++;
	}
	return (0);
}
