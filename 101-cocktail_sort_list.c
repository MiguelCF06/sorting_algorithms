#include "sort.h"
/**
 * swap - change to values
 * @tmp: value to change
 * @head: head of the list
 */
void swap(listint_t *tmp, listint_t **head)
{
	tmp = tmp->next;
	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	tmp->next = tmp->prev;
	tmp->prev = tmp->next->prev;
	tmp->next->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = tmp;
	else
		*head = tmp;
}

/**
 * cocktail_sort_list - sort a list with cocktail algorithm
 * @list: head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr = NULL, *tmp = NULL;
	int i = 0, size = 0, j;

	if (!list || !*list || !(*list)->next)
		return;
	ptr = *list;
	while (ptr)
		size++, ptr = ptr->next;
	while (i == 0)
	{
		i = 1;
		tmp = *list;
		for (j = 0; j < size - 1 && tmp; j++)
		{
			if (tmp->n > tmp->next->n)
				swap(tmp, list), i = 0, print_list(*list);
			else
				tmp = tmp->next;
		}
		if (i == 1)
			break;
		i = 1;
		tmp = tmp->prev->prev;
		for (j = size - 2; j >= 0 && tmp; j--)
		{
			if (tmp->n > tmp->next->n)
			{
				swap(tmp, list), i = 0, print_list(*list);
				tmp = tmp->prev->prev;
			}
			else
				tmp = tmp->prev;
		}
	}
}
