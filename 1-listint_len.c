#include <stddef.h> // For size_t
#include "lists.h" // Include your header file containing struct and prototype

/**
 * listint_len - Returns the number of elements in a listint_t list.
 * @h: Pointer to the head of the list.
 * Return: Number of elements.
 */
size_t listint_len(const listint_t *h)
{
    size_t count = 0; // Initialize a counter for elements

    // Traverse the linked list
    while (h)
    {
        h = h->next; // Move to the next node
        count++; // Increment the element count
    }

    return (count); // Return the number of elements
}
