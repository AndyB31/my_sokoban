/*
** EPITECH PROJECT, 2017
** my_intcpy
** File description:
** copy int array
*/

int *my_intcpy(int *dest, int const *src, int len)
{
	int i = 0;

	while (i < len)
		dest[i] = src[i++];
	return (dest);
}
