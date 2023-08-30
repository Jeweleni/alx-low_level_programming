#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp; //4add_nodeint_end.c

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
