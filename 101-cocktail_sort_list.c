#include "sort.h"

/**
 * _swap - Swaps two nodes of doubly linked list
 *
 * @node: node base to change
 * @list: double link list head
 *
 * Return: Nothing
 */
void _swap(listint_t **node, listint_t **list)

{
	listint_t *tmp_data = *node, *tmp_data2, *tmp_data3;


	if (!(*node)->prev)
		*list = (*node)->next;

	tmp_data = tmp_data3 = *node;
	tmp_data2 = tmp_data->next;

	tmp_data->next = tmp_data2->next;
	tmp_data3 = tmp_data->prev;
	tmp_data->prev = tmp_data2;
	tmp_data2->next = tmp_data;
	tmp_data2->prev = tmp_data3;

	if (tmp_data2->prev)
		tmp_data2->prev->next = tmp_data2;


	if (tmp_data->next)
		tmp_data->next->prev = tmp_data;

	*node = tmp_data2;

}
/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of the integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: head of Double Linked list to be sorted
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)

{
	listint_t *head, *aux;
	int count = 0, n = -1, m_data = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m_data >= n)
	{
		n++;
		while (head->next && count != m_data)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       _swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			count++;
			head = head->next;
		}

		if (n == 0)
			m_data = count;
		m_data--;
		while (head->prev && count >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			count--;
			head = head->prev;
		}
	}
}
