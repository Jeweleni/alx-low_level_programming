#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to retrieve (starting at 0).
 * Return: Address of the nth node, or NULL if it doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i = 0;
    listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
