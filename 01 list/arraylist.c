#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "arraylist.h"

array_list* create_array_list(int max_element_count)
{
    array_list  *new_list;

    new_list == malloc(sizeof(array_list));
    if (new_list == NULL)
        return (NULL);
    new_list->max_element_count = max_element_count;
    new_list->current_element_count = 0;
    new_list->p_element = malloc(sizeof(array_list_node) * max_element_count);
    if (new_list->p_element == NULL)
    {
        free(new_list);
        return (NULL);
    }
    bzero(new_list, sizeof(array_list_node) * max_element_count);
    return (new_list);
}

void delete_array_list(array_list* list)
{
    if (list == NULL)
        return ;
    if (list->p_element != NULL)
        free(list->p_element);
    free(list);
}

int is_array_list_full(array_list* list)
{
    if (list == NULL)
        return (ERROR);
    if (list->max_element_count == list->current_element_count)
        return (TRUE);
    return (FALSE);
}

int add_al_element(array_list* list, int position, array_list_node element)
{
    if (list == NULL || is_array_list_full(list) == TRUE)
        return (ERROR);
    if (position < 0 || position > list->max_element_count)
        return (ERROR);
    (list->p_element)[position] = element;
    list->current_element_count++;
    return (TRUE);
}

int remove_al_element(array_list* list, int position)
{
    if (list == NULL || list->current_element_count == 0)
        return (ERROR);
    if (position < 0 || position > list->max_element_count)
        return (ERROR);
    bzero(&((list->p_element)[position]), sizeof(array_list_node));
    list->current_element_count--;
}

array_list_node* get_al_element(array_list* list, int position)
{
    if (list == NULL || position < 0 || position > list->max_element_count)
        return (NULL);
    return (&((list->p_element)[position]));
}

void display_array_list(array_list* list)
{
    if (list == NULL)
        return ;
    for (int i = 0; i < list->max_element_count; i++)
        printf("[%d] %d\n", i, (list->p_element)[i]);
}

void clear_array_list(array_list* list)
{
    if (list == NULL)
        return ;
    bzero(list->p_element, sizeof(array_list_node) * list->max_element_count);
    list->current_element_count = 0;
}
