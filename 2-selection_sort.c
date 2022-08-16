#include "sort.h"
/**
 * selection_sort - sort array of size with selection sorting
 * @array: int array to sort
 * @size: how big is the array?
 *
 *
 */
void selection_sort(int *array, size_t size)
{
	/* declarations */
	size_t a, b, c;
	int temp;

	if (!(array && size))
		return;
	/* traverse it, if needed sort it */
	for (a = 0; a < size - 1; a++)
	{
		for (b = size - 1, c = a + 1; b > a; b--)
		{
			if (array[b] < array[c])
				c = b;
		}

		if (array[a] > array[c])
		{
			temp = array[a];
			array[a] = array[c];
			array[c] = temp;
			/* print every swap */
			print_array(array, size);
		}
	}
}
