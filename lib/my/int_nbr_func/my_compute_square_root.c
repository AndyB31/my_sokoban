/*
** EPITECH PROJECT, 2017
** my compute square root
** File description:
** square root
*/

int my_compute_square_root(int nb)
{
	if (nb < 1)
		return (0);
	for (int i = 1 ; i <= nb / 2 ; i++) {
		if (i * i > 2147483647)
			return (0);
		if (nb == i * i) {
			return (i);
		}
	}
	return (0);
}
