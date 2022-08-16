#include "sort.h"
/**
 * knuth_gap - gets the gap size for the sort
 * @size: size of array
 *
 * Return: the gap size
 */
size_t knuth_gap(size_t size)
{
	/* declarations */
	size_t gap = 1;

	/* looking for gap */
	while (gap < size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}
/**
 * shell_sort - sort an int array via shell sort
 * @array: the array
 * @size: the size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	/* declarations */
	size_t gap, i, j;
	int temp;

	/* check for bad stuff */
	if (!(array && size))
		return;
	/* do the sorting and printing */
	gap = knuth_gap(size);
	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}
