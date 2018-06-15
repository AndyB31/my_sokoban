/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** copy str size n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
