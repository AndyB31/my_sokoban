/*
** EPITECH PROJECT, 2017
** swap integers
** File description:
** swap 2 integers
*/

void my_swap(int *a, int *b)
{
	int x = *a;

	*a = *b;
	*b = x;
}
