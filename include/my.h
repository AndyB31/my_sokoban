/*
** EPITECH PROJECT, 2017
** my
** File description:
** all the declaration
*/

#ifndef MY_H_
#define MY_H_

/* include for the lib */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* define for my_remalloc*/
enum REMALLOC {
	STR,
	STR_2D,
	INT,
	INT_2D,
	LONG,
	LONG_2D,
	FLOAT,
	FLOAT_2D,
	NONE,
};

/* STR fonct*/
int my_puterror(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_init(char *str, int len);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strbcat(char *dest, char const *src, int nb);
char *int_to_octastr(unsigned long number, int len);
int my_char_count(char *str, char c);
char **my_str_split(char *str, char c);
int my_is_nbr(char const *str);
char *my_realloc(char *str, int len);
char *set_str_to(char *src, char *new_str);
int my_are_equals(char *str1, char *str2);

/* Display fonct */
int my_printf(char *format, ...);
int my_print_str(char *);
void hexaprint(unsigned long number, char maj);
void octaprint(unsigned long number);
void binprint(unsigned long number);
void my_put_pt(void *pt);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_unbr(unsigned int nb);
int my_put_lnbr(long nb);
int my_put_lunbr(unsigned long nb);
int my_putstr(char const *str);
int my_showstr(char const *str);
int my_shownem(char const *str, int size);

/* CALC / NUMBER fonct */
int power(int i);
int longlen(unsigned long number);
int my_testneg(char *str, int i);
void my_swap(int *a, int *b);
int my_getnbr(char const *str);
int my_get_nbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int *my_intcpy(int *dest, int const *src, int len);
char *my_nbr_to_str(int nbr);
int get_nb_size(int nb, int size);

/* Memory fonct */
void *my_remalloc(void *pt, int len, enum REMALLOC type, int prelen);
char *get_next_line(int fd);

typedef struct posi_s {
	int x;
	int y;
}posi_t;

#endif
