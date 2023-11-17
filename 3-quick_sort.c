#include "sort.h"

/**
 * quick_sort- sorts an array of integer
 *
 * Description: This function sorts an array of integer using
 * quick sort algorithm (Lomuto partition scheme)
 *
 * @array: array of integer to sort
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t k;

	if (array == NULL)
		return;
	if (size <= 1)
		return;
	for (k = 1; k < size; k++)
	{
		if (array[k - 1] > array[k])
			break;
	}
	if (k == size)
		return;
	helper(array, size, array, size);
}

/**
 * helper - finds the correct position of pivot in an array of integer
 *
 * @partition: partition of array
 * @array: array of integer to sort
 * @size: size of the partition
 * @orig_size: original size of the array to sort
 * Return: nothing
 */
void helper(int *partition, size_t size, int *array, size_t orig_size)
{
	int pivot, temp;
	size_t i, j, k;

	i = 0;
	j = 0;
	k = 0;
	if (size <= 1 || orig_size <= 1)
		return;
	pivot = partition[size - 1];
	while (k <= size - 1)
	{
		if (partition[i] <= pivot && i < size - 1)
			i++;
		else
		{
			j = i;
			while (partition[j] > pivot)
				j++;
			if (i != size - 1)
			{
				temp = partition[i];
				partition[i] = partition[j];
				partition[j] = temp;
				print_array(array, orig_size);
			}
			if (j == size - 1)
				break;
		}
		k = i;
	}
	helper(partition, i, array, orig_size);
	partition += (i + 1);
	helper(partition, size - (i + 1), array, orig_size);
}
