#include <stdlib.h>
#include <string.h>

typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

list_t *add_node(list_t **head, const char *str) {
    if (str == NULL)
        return NULL;

    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    if (new_node == NULL)
        return NULL;

    new_node->str = strdup(str);
    if (new_node->str == NULL) {
        free(new_node);
        return NULL;
    }

    new_node->next = *head;
    *head = new_node;

    return new_node;
}
