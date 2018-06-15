/*
** EPITECH PROJECT, 2018
** get_nbr_size
** File description:
** get_nbr_size
*/

#include "../include/my.h"

int get_nb_size(int nb, int size)
{
	while (nb >= 1) {
		nb /= 10;
		size++;
	}
	return (size);
}