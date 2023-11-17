#include "sort.h"

/**
 * bubble_sort - implementation of bubble sort algorithm
 * @array: array of integers
 * @size: size of the array of integers
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp, counter, passages;

	counter = 0;
	passages = 0;
	if (array == NULL)
		return;
	if (size <= 1)
		return;
	while (passages < size)
	{
		for (i = 1, j = 0; i < size; i++, j++)
		{
			if (array[j] > array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				counter++;
				print_array(array, size);
			}
		}
		passages++;
		if (counter == 0)
			return;
	}
}
