#include "sort.h"
#include <stdbool.h>

/**
 * insertion_sort_list - sorts a list using insertion algorithm
 * @list: a double pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list,  *insert, *previous;

	if (current == NULL || current->next == NULL)
		return;

	while (current != NULL)
	{
		if (current->next == NULL)
			break;
		if (current->n > current->next->n)
		{
			insert = current->next;
			current->next = insert->next;
			if (insert->next)
				insert->next->prev = current;

			insert->prev = current->prev;
			current->prev = insert;
			insert->next = current;
			if (insert->prev)
				insert->prev->next = insert;
			else
				(*list) = insert;
			print_list(*list);

			previous = insert->prev;

			insert_smallest(list, previous, insert);
		}
		else
			current = current->next;
	}
}

/**
 * insert_smallest - finds the correct position to insert
 * @list: double pointer to the original list
 * @previous: the previous node before the node to insert
 * @insert: node to insert to correct position
*/
void insert_smallest(listint_t **list, listint_t *previous, listint_t *insert)
{
	listint_t *temp;

	while (previous)
	{
		if (insert->n < previous->n)
		{
			temp = insert->next;
			temp->prev = previous;
			insert->next = previous;
			insert->prev = previous->prev;
			if (previous->prev)
				previous->prev->next = insert;
			else
				(*list) = insert;
			previous->next = temp;
			previous->prev = insert;
			previous = insert->prev;
			print_list(*list);
			continue;
		}
		break;
	}
}
