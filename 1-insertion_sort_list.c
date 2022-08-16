#include "sort.h"
/**
 * insertion_sort_list - sort a dlist via insertion sort
 * @list: the list to sort
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	/* declarations */
	listint_t *a, *b;

	/* check for bad things */
	if (!(list && *list && (*list)->next))
		return;

	/* set up for some insertion sort & swap */
	a = (*list)->next;

	while (a)
	{
		b = a;
		a = a->next;
		while (b && b->prev)
		{
			if (b->prev->n > b->n)
			{
				swapper(b->prev, b);
				if (!b->prev)
					*list = b;
				/* cast to const for print func */
				print_list((const listint_t *)*list);
			}
			else
				b = b->prev;
		}
	}

}


/**
 * swapper - a function to help swap 2 nodes in a dlist
 * @a: one node
 * @b: the other node
 *
 */
void swapper(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
