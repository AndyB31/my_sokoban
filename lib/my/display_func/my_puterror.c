/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** put str one by one
*/

#include "../include/my.h"

int my_puterror(char const *str)
{
	write(2, str, my_strlen(str));
	return (0);
}
