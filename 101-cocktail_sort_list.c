#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

void smallest(listint_t **list, listint_t *current);

/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail sort
 * @list: double pointer to head of linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list, *temp;
	bool sort = false;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (!sort)
	{
		sort = true;

		while (current->next)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				if (current->prev)
					current->prev->next = current->next;
				if (current->next->next)
					current->next->next->prev = current;
				temp->prev = current->prev;
				current->next = temp->next;
				current->prev = temp;
				temp->next = current;
				if (!temp->prev)
					*list = temp;
				print_list(*list);
				sort = false;
			}
			else
				current = current->next;
		}

		smallest(list, current);
	}
}

/**
 * smallest - finds the smallest and put it in the correct position
 * @list: double pointer to the linked list
 * @current: the current node being compared to
*/
void smallest(listint_t **list, listint_t *current)
{
	listint_t *temp;

	while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				temp->next = current->next;
				current->next = temp;
				current->prev = temp->prev;
				if(current->prev)
					temp->prev->next = current;
				temp->prev = current;
				if(!current->prev)
					*list = current;
				if (temp->next)
					temp->next->prev = temp;
				print_list(*list);
			}
			else
				current = current->prev;
		}
}