#include "sort.h"
/**
 * swapper - a function to help swap 2 nodes in a dlist
 * @a: one node
 * @b: the other node
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
/**
 * cocktail_sort_list - sort list
 * @list: the list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	/* declarations */
	listint_t *l;
	int needssort = 1;

	if (!(list && *list))
		return;
	l = *list;
	while (needssort)
	{
		needssort = 0;
		while (l && l->next)
		{
			if (l->n > l->next->n)
			{
				swapper(l, l->next);
				if (l->prev->prev == NULL)
					*list = l->prev;
				print_list(*list);
				needssort = 1;
			}
			else
				l = l->next;
		}
		if (!needssort)
			break;
		needssort = 0;
		while (l->prev)
		{
			if (l->prev->n > l->n)
			{
				swapper(l->prev, l);
				if (l->prev == NULL)
					*list = l;
				print_list(*list);
				needssort = 1;
			}
			else
				l = l->prev;
		}
	}
}
