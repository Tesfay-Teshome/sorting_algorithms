#include "sort.h"
/**
 * swaps - swaps and prints ints from an array without temp
 * @array: the array for printing func
 * @size: the size of array for printing func
 * @a: one int
 * @b: the other int
 */
void swaps(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}
/**
 * kwiksort - quick sort via lamuto partition
 * @array: the array
 * @size: size of array
 * @low: low [] of sort
 * @high: high [] of sort
 *
 */
void kwiksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t part = partition(array, size, low, high);

		kwiksort(array, size, low, part - 1);
		kwiksort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - to quick sort, basically a junk func prototype i had to
 * embetter
 * @array: the array to sort
 * @size: size of array
 *
 */
void quick_sort(int *array, size_t size)
{
	/* if bad things, return */
	if (!array || !size)
		return;
	/* else, sort it baby */
	kwiksort(array, size, 0, size - 1);
}
/**
 * partition - "partition" array
 * @array: the array
 * @size: the size of array
 * @low: the bottom of the index
 * @high: the top of it
 * Return: size_t part, the partition value
 */
size_t partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	/*declarations */
	int i, j, pivot;

	/* set the pivot */
	pivot = array[high];

	for (j = low, i = j; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swaps(array, size, &array[j], &array[i++]);
		}
	}
	/* final swap */
	swaps(array, size, &array[i], &array[high]);
	/* the size_t return value here is needed for the part */
	return (i);
}
