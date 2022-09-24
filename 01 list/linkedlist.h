#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct list_node_type
{
	int data;
	struct list_node_type	*link;
} list_node;

typedef struct linked_list_type
{
	int current_element_count;	// 현재 노드 개수
	list_node *header_node;		// 해더 노드(Header Node)
} linked_list;

linked_list	*create_linked_list();
list_node   *create_linked_list_node(list_node element);
int			add_ll_element(linked_list	*list, int position, list_node element);
int			remove_ll_element(linked_list	*list, int position);
list_node	*get_ll_element(linked_list	*list, int position);
void		clear_linked_list(linked_list	*list);
int			get_linked_list_length(linked_list	*list);
void		delete_linked_list(linked_list	*list);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif