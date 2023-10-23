#include "sort.h"

/**
 * insert_node - inserts the node by swapping places.
 * @list: a double pointer to the head of list.
 * @swap: a double pointer to node to swap.
 * @insert: a pointer to node to insert.
 */
void insert_node(listint_t **list, listint_t **swap, listint_t *insert)
{
	(*swap)->next = insert->next;

	if (insert->next != NULL)
		insert->next->prev = *swap;

	insert->prev = (*swap)->prev;
	insert->next = *swap;

	if ((*swap)->prev != NULL)
		(*swap)->prev->next = insert;
	else
		*list = insert;

	(*swap)->prev = insert;
	*swap = insert->prev;
}

/**
 * insertion_sort_list - sorts a linked list using insertion sort
 * @list: a double pointer to the head of linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert = current->prev;

		while (insert != NULL && current->n < insert->n)
		{
			insert_node(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
