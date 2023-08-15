#include "sort.h"
/**
 * swap - the positions of 2 elements into an array
 * @array: array
 * @thing1: array element
 * @thing2: array element
 */
void swap(int *array, ssize_t thing1, ssize_t thing2)
{
	int tmp;

	tmp = array[thing1];
	array[thing1] = array[thing2];
	array[thing2] = tmp;
}
/**
 * lomuto_partition - its a sorting scheme
 * @array: array
 * @first: 1st array element
 * @last: last array element
 * @size: size of the array
 * Return: the position of the last element that's sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, seeker;

	for (seeker = first; seeker < last; seeker++)
	{
		if (array[seeker] < pivot)
		{
			if (array[current] != array[seeker])
			{
				swap(array, current, seeker);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t spot = 0;

	if (first < last)
	{
		spot = lomuto_partition(array, first, last, size);
		qs(array, first, spot - 1, size);
		qs(array, spot + 1, last, size);
	}
}
#include "sort.h"
/**
 * quick_sort - preparing for quicksort algo
 * @array: array
 * @size: size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
