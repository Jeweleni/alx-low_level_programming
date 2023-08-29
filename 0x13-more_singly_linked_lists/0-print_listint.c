#include "lists.h" // Include your header file containing struct and prototype

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the list.
 * Return: Number of nodes.
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0; // Initialize a counter for nodes

    // Traverse the linked list
    while (h)
    {
        printf("%d\n", h->n); // Print the value of the current node
        count++; // Increment the node count
        h = h->next; // Move to the next node
    }

    return (count); // Return the number of nodes
}
