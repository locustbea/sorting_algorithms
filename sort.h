#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_node(listint_t *curr_node, listint_t **list);
size_t dlistint_len(const listint_t *h);
void finder(int *partial, size_t size, int *array, size_t orig_size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
size_t check_if_sorted(listint_t *list);
void _swap(listint_t **node, listint_t **list)
void counting_sort(int *array, size_t size)
void merge_sort(int *array, size_t size)
void copy(int *src, int *dst, int size)
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
void printcheck(int *array, int r1, int r2)
void split(int *array, int *buff, int min, int max, int size)











#endif /* SORT_H */
