#include "sort.h"
/**
 * check_tree - swiftdown checking
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @i: index as a root of the tree
 *
**/

void check_tree(int *array, size_t size_init, size_t size, size_t i)

{

	int n, branch1, branch2;
	size_t braches1, branches2;

	braches1 = i * 2 + 1;
	branches2 = braches1 + 1;
	branch1 = array[braches1];
	branch2 = array[branches2];
	if (((braches1 < size) && (branches2 < size) &&
		(branch1 >= branch2 && branch1 > array[i]))
		|| ((braches1 == size - 1) && branch1 > array[i]))
	{
		n = array[i];
		array[i] = branch1;
		array[braches1] = n;
		print_array(array, size_init);
	}
	else if ((braches1 < size) && (branches2 < size) &&
		(branch2 > branch1 && branch2 > array[i]))
	{
		n = array[i];
		array[i] = branch2;
		array[branches2] = n;
		print_array(array, size_init);
	}
	if (braches1 < size - 1)
		check_tree(array, size_init, size, braches1);
	if (branches2 < size - 1)
		check_tree(array, size_init, size, branches2);
}
/**
 * heap_sort - sorts an array of theintegers
 * in ascending order using the Heap sorting algorithm
 * @array: pointer to the array
 * @size: size of the pointer
 *
**/

void heap_sort(int *array, size_t size)

{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}

}
