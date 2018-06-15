/*
** EPITECH PROJECT, 2017
** my compute power rec
** File description:
** power
*/

int my_loop_power(int nb, int p, int po)
{
	if (p < 0) {
		nb = 0;
	}
	if (p == 0) {
		nb = 1;
	}
	if (p > 1) {
		if (my_loop_power(nb, p - 1, po) * nb > 2147483647) {
			return (0);
		} else if (my_loop_power(nb, p - 1, po) * nb < -2147483647) {
			return (0);
		} else {
			nb = my_loop_power(nb, p - 1, po) * nb;
		}
	}
	return (nb);
}

int my_compute_power_rec(int nb, int p)
{
	int po = nb;
	nb = my_loop_power(nb, p, po);
	return (nb);
}
