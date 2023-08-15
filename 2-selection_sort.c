#include "sort.h"
/**
 * selection_sort - sort an array using selection method
 * @array: an array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	unsigned int min, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)

		{
			if (array[j] < array[min])
			{
				min = j;
			}

		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
