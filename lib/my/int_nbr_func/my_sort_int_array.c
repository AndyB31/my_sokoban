/*
** EPITECH PROJECT, 2017
** sort in array
** File description:
** sort number in an array
*/

void my_sort_int_array(int *tab, int size)
{
	int keep;

	for (int i = 0 ; i + 1 < size ; i++) {
		if (tab[i] > tab[i + 1]) {
			keep = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = keep;
			my_sort_int_array(tab, size);
		}
	}
}
