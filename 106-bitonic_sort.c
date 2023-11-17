#include "sort.h"
#include <stdio.h>

/**
 * swap - change two values in ascending or descending order
 * @arr: array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending order, 0 descending order
 */

void swap(int arr[], int item1, int item2, int order)

{
	int tmp;

	if (order == (arr[item1] > arr[item2]))
	{
		tmp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = tmp;
	}
}
/**
 * merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element
 * @nelemnt: elements number
 * @order: 1: ascending order, 0 descending order
 */

void merge(int arr[], int low, int nelemnt, int order)

{
	int middle, i;

	if (nelemnt > 1)
	{
		middle = nelemnt / 2;
		for (i = low; i < low + middle; i++)
			swap(arr, i, i + middle, order);
		merge(arr, low, middle, order);
		merge(arr, low + middle, middle, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */

void bitonicsort(int arr[], int low, int nelemnt, int order, int size)

{
	int middle;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		middle = nelemnt / 2;
		bitonicsort(arr, low, middle, 1, size);
		bitonicsort(arr, low + middle, middle, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */

void bitonic_sort(int *array, size_t size)

{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
