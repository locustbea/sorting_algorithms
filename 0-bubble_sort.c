#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - The implementation of bubble sort algorithm
 * @array: array of integers
 * @size: The size of the array of integers
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp_data, c_data, p_data;

	c_data = 0;
	p_data = 0;
	if (array == NULL)
		return;
	if (size <= 1)
		return;
	while (p_data < size)
	{
		for (i = 1, j = 0; i < size; i++, j++)
		{
			if (array[j] > array[i])
			{
				tmp_data = array[i];
				array[i] = array[j];
				array[j] = tmp_data;
				c_data++;
				print_array(array, size);
			}
		}
		p_data++;
		if (c_data == 0)
			return;
	}
}
