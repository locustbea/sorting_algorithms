#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 *
 * Description: sorts an array of integers in ascending order using the
 * selection sort algorithm
 *
 * @array: array of integer to sort
 * @size: size of the array of integer
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k, pos;
	int temp;

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
	for (i = 0; i < size - 1; i++)
	{
		temp = array[i];
		for (j = i; j < size; j++)
		{
			if (temp > array[j])
			{
				temp = array[j];
				pos = j;
			}
		}
		if (array[i] != temp)
		{
			array[pos] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
