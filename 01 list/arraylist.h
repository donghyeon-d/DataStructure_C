#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct array_list_node_type
{
	int data;
} array_list_node;

typedef struct array_list_type
{
	int max_element_count;		// 최대 원소 개수
	int current_element_count;	// 현재 원소의 개수
	array_list_node *p_element;	// 원소 저장을 위한 1차원 배열
} array_list;

array_list* create_array_list(int max_element_count);
void delete_array_list(array_list* list); // free
int is_array_list_full(array_list* list);
int add_al_element(array_list* list, int position, array_list_node element);
int remove_al_element(array_list* list, int position);
array_list_node* get_al_element(array_list* list, int position);
void display_array_list(array_list* list);
void clear_array_list(array_list* list); // data 초기화

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif