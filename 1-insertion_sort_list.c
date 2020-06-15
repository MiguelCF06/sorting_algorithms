#include "sort.h"
/**
 * sort - set position of node
 * @tmp: current position
 * @head: head of linked list
 */
void sort(listint_t *tmp, listint_t **head)
{
	listint_t *ptr = NULL;

	while (tmp->prev && tmp->n < tmp->prev->n)
	{
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
		ptr = *head;
		print_list(ptr);
	}
}
/**
 * insertion_sort_list - insert value to linked list
 * @list: head of linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = NULL;

	ptr = *list;
	while (ptr)
	{
		if (ptr->prev != NULL)
		{
			sort(ptr, list);
		}
		ptr = ptr->next;
	}
}
