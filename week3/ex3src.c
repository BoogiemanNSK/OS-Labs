#include <stdio.h>
#include <stdlib.h>

#define NODE struct node

struct node {
	int data;
	NODE *next;
};

void print_list(NODE *cur) {
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

NODE* insert_node(NODE *list, int to_insert) {
	if (list == NULL) {
		list = (NODE*)malloc(sizeof(NODE));
		list->data = to_insert;
		list->next = NULL;
		return list;
	}

	NODE* cur = list;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = (NODE*)malloc(sizeof(NODE));
	cur->next->data = to_insert;
	cur->next->next = NULL;

	return list;
}

NODE* delete_node(NODE *list, int to_delete) {
	if (list == NULL) { return list; }
	
	while (list != NULL && list->data == to_delete) {
		NODE* temp = list;
		list = list->next;
		free(temp);	
	}

	if (list == NULL) { return list; }

	NODE* cur = list;
	while (cur->next != NULL) {
		if (cur->next->data == to_delete) {
			NODE* temp = cur->next;
			cur->next = cur->next->next;
			free(temp);
		} else {
			cur = cur->next;
		}
	}

	return list;
}

int main() {
	NODE *linked_list = NULL;

	linked_list = insert_node(linked_list, 1);
	linked_list = insert_node(linked_list, 2);
	linked_list = insert_node(linked_list, 3);

	linked_list = delete_node(linked_list, 1);

	print_list(linked_list);

	return 0;
}
