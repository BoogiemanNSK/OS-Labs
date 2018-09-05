#include <stdio.h>
#include <stdlib.h>

#define NODE struct node

struct node {
	int data;
	NODE *next;
	NODE *prev;
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
		list->prev = NULL;
		return list;
	}

	NODE* cur = list;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = (NODE*)malloc(sizeof(NODE));
	cur = cur->next;
	cur->data = to_insert;
	cur->next = NULL;
	cur->prev = NULL;

	return list;
}

NODE* delete_node(NODE *list, int to_delete) {
	if (list == NULL) { return list; }

	NODE* cur = list;
	while (cur != NULL) {
		if (cur->data == to_delete) {
			NODE* temp = cur;
			cur = cur->next;

			if (list == temp) { list = cur; }
			if (temp->prev != NULL) { temp->prev->next = temp->next; }
			if (temp->next != NULL) { temp->next->prev = temp->prev; }

			free(temp);
		} else {
			cur = cur->next;
		}
	}

	return list;
}

int main() {
	NODE *dll = NULL;

	dll = insert_node(dll, 1);
	dll = insert_node(dll, 2);
	dll = insert_node(dll, 3);

	dll = delete_node(dll, 1);

	print_list(dll);

	return 0;
}
