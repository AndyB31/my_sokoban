/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** get_next_line.c
*/

#include <get_next_line.h>
#include <my.h>

static char *my_str_from_listg(listg_t **head);
static char *filter_listg(listg_t **head, int fd, int init);
static int delete_listg(listg_t **head, int first);
static int add_endg(listg_t **head, char letter);

static int add_endg(listg_t **head, char letter)
{
	listg_t *element = malloc(sizeof(listg_t));
	listg_t *curr = *head;

	if (element == NULL)
		return (0);
	if (curr == NULL)
		*head = NULL;
	element->letter = letter;
	element->next = NULL;
	if (*head == NULL) {
		*head = element;
	} else {
		while (curr->next)
			curr = curr->next;
		curr->next = element;
	}
	return (1);
}

static int delete_listg(listg_t **head, int first)
{
	listg_t *curr = NULL;

	if (*head == NULL || head == NULL)
		return (0);
	curr = *head;
	if (first == 1) {
		*head = (*head)->next;
		free(curr);
	} else {
		while (curr && curr->letter != '\n') {
			first++;
			curr = curr->next;
		}
	}
	return (first);
}

char *my_str_from_listg(listg_t **head)
{
	char *str = NULL;
	listg_t *curr = *head;
	int i = 0;

	str = filter_listg(NULL, 0, delete_listg(head, 0) + 1);
	curr = *head;
	if (str == NULL || head == NULL || *head == NULL)
		return (NULL);
	while (curr) {
		if (curr->letter == '\n' || curr->letter < 0)
			break;
		str[i++] = curr->letter;
		curr = curr->next;
		delete_listg(head, 1);
	}
	delete_listg(head, 1);
	str[i] = '\0';
	return (str);
}

char *filter_listg(listg_t **head, int fd, int init)
{
	listg_t *curr = NULL;
	char *str = malloc((init + 1) * sizeof(char));

	if (init > 0 && str != NULL) {
		for (int i = 0; i < init + 1; i++)
			str[i] = '\0';
		return (str);
	}
	if (*head == NULL || head == NULL || str == NULL)
		return (NULL);
	curr = *head;
	while (curr) {
		if (curr->letter == '\n')
			return (my_str_from_listg(head));
		curr = curr->next;
	}
	free(str);
	return get_next_line(fd);
}

char *get_next_line(int fd)
{
	char *buf = filter_listg(NULL, 0, READ_SIZE + 1);
	static listg_t *list = NULL;
	int status;

	if (fd == -1 || buf == NULL || READ_SIZE <= 0)
		return (NULL);
	status = read(fd, buf, READ_SIZE);
	buf[READ_SIZE + 1] = '\0';
	if (status == 0 || buf == NULL) {
		free(buf);
		return (my_str_from_listg(&list));
	}
	for (int i = 0; buf[i] != '\0' && i < READ_SIZE; i++)
		if (add_endg(&list, buf[i]) == 0)
			return (NULL);
	free(buf);
	return filter_listg(&list, fd, 0);
}
