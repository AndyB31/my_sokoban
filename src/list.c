/*
** EPITECH PROJECT, 2017
** utils for list
** File description:
** list of obj manager
*/

#include "soko.h"
#include "my.h"

case_t *find_case(posi_t pos, case_t *head)
{
	case_t *current = head;

	while (current) {
		if (pos.x == current->pos.x && pos.y == current->pos.y)
			return (current);
		current = current->next;
	}
	return (NULL);
}