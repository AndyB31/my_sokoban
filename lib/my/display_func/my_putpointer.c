/*
** EPITECH PROJECT, 2017
** my put pointer
** File description:
** can put pointer
*/

#include "../include/my.h"

void my_put_pt(void *pt)
{
	unsigned long adress = (unsigned long)pt;

	if (pt != NULL) {
		my_putstr("0x");
		hexaprint(adress, 'x');
	} else
		my_putstr("(nil)");
}
