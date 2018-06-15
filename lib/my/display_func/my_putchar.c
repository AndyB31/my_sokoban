/*
** EPITECH PROJECT, 2017
** putchar
** File description:
** put a char with a write
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
