#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	struct Node* next;
};

void init(struct Node* head){
	head->key = 0;
	head->next = NULL;
}

void print(struct Node* head){
	for(struct Node* current = head; current != NULL; current = current->next){
		printf("%d\n",current->key);
	}
/*
	if(head == NULL) return;
	printf("HEAD: %d\n", head->key);
	print(head->next);
*/
}

struct Node* search(struct Node* head, int key){
	struct Node* result;
	for(struct Node* current = head; current != NULL; current = current->next){
		if(current->key == key){
			//printf("Search %d\n", current->key);
			result = current;
			//printf("ok\n");
			return result;
		}
	}
	return NULL;
}

void push(struct Node** head, int key){
	struct Node* new = malloc(sizeof(struct Node));
	if(new == NULL) exit(1);
	new->key = key;
	new->next = *head;
	*head = new;
	//printf("ok");
}

void pop(struct Node* head, int key){
	struct Node* del;
	del = search(head, key);
	if(del){
		if(del->next != NULL){
			struct Node* buf = del->next;
			del->key = del->next->key;
			del->next = del->next->next;
			free(buf);
		}else{
			printf("Last Element\n");
		}
	}
}
/*
struct Node* pop(struct Node** head, int key){
	for(;*head != NULL; *head = *head->next){
		if(*head->key == key){
			if(*head->next != NULL){
				int rez = *head->key;
				struct Node* del = *head->next;
				*head->key = *head->next->key;
				*head->next = *head->next->next;
				free(del);
			}else{
				free(*head);
				*head = NULL;
			}
		}
	}
}
*/

int main(){
	struct Node* head = malloc(sizeof(struct Node));
	if(head == NULL) exit(1);
	init(head);
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	print(head);
	struct Node* a;

	a = search(head, 3);
	if(a != NULL) printf("Search(3) : %d\n", a->key);

	pop(head, 0);
	print(head);
	return 0;
}