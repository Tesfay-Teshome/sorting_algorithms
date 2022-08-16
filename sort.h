#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* linked list struct they gave us */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* prototypes - theirs*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* prototypes - mine */
void swap(int *array, int a, int b);
void swapper(listint_t *a, listint_t *b);
size_t knuth_gap(size_t size);
void kwiksort(int *array, size_t size, ssize_t low, ssize_t high);
size_t partition(int *array, size_t size, ssize_t low, ssize_t high);
void swaps(int *array, size_t size, int *a, int *b);
#endif /* SORT_H */
