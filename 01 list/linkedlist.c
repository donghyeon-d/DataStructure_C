#include <stdlib.h>
#include "linkedlist.h"

linked_list *create_linked_list()
{
    linked_list *new_list;

    new_list = malloc(sizeof(linked_list));
    if (new_list == NULL)
        return (NULL);
    new_list->current_element_count = 0;
    new_list->header_node = NULL;
    return (new_list);
}

list_node   *create_linked_list_node(list_node element)
{
    list_node   *new_node;

    new_node = malloc(sizeof(list_node));
    if (new_node == NULL)
        return (NULL);
    *new_node = element;
    return (new_node);
}

int add_ll_element(linked_list* list, int position, list_node element)
{
    list_node   *new_node;
    list_node   *temp;
    int         i;

    if (list == NULL || position > list->current_element_count || position < 0)
        return (ERROR);
    new_node = create_linked_list_node(element);
    if (new_node == NULL)
        return (-1);
    if (position == 0)
    {
        if (list->header_node != NULL)
            new_node->link = list->header_node->link;
        list->header_node = new_node;
    }
    else
    {
        i = 0;
        temp = list->header_node;
        while (i < position - 1)
        {
            temp = temp->link;
            i++;
        }
        new_node = temp->link;
        temp->link = new_node;
    }
    list->current_element_count++;
    return (TRUE);
}

int remove_ll_element(linked_list* list, int position)
{
    list_node   *remove_node;
    list_node   *temp;
    int         i;

    if (list == NULL || list->current_element_count < 1 || \
    position >= list->current_element_count || position < 0)
        return (ERROR);
    if (position == 0)
    {
        list->header_node = list->header_node->link;
        remove_node = list->header_node;
    }
    else
    {
        i = 0;
        temp = list->header_node;
        while (i < position - 1)
        {
            temp = temp->link;
            i++;
        }
        remove_node = temp->link;
        temp->link = remove_node->link;
    }
    free(remove_node);
    list->current_element_count--;
    return (TRUE);
}

list_node* get_ll_element(linked_list* list, int position);
void clear_linked_list(linked_list* list);
int get_linked_list_length(linked_list* list);
void delete_linked_list(linked_list* list);
