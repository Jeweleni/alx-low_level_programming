#include "lists.h" // Including the header file containing struct and prototype

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: linked list of type listint_t to print
 * Return: Number of nodes.
 */
size_t print_listint(const listint_t *h)
{
    size_t num = 0; // Initializing a counter for nodes

// Traversed the linked list
    while (h)
    {
        printf("%d\n", h->n); // Print the value of the current node
        num++; // Increment the node count
        h = h->next;
    }

    return (num); // Return the number of nodes
}
