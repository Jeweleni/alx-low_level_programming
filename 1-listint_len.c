#include "lists.h" // Include your header file containing struct and prototype

/**
 * listint_len - Returns the number of elements in a listint_t list.
 * @h: Pointer to the head of the list.
 * Return: Number of elements.
 */
size_t listint_len(const listint_t *h)
{
    size_t num = 0; // Initialize a counter for elements

    while (h)
    {
        num++; // Increment the element count
        h = h->next; // Move to the next node
    }

    return (num); // Return the number of elements
}
