#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	struct Node* next;
} Node;

void init(struct Node* head){
	head->key = 0;
	head->next = NULL;
}

void printList(struct Node* head){
	static int i = 0;
	for(struct Node* current = head; current != NULL; current = current->next){
		printf("%d) %d\n", i, current->key);
		i++;
	}
	i = 0;
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
			result = current;
			return result;
		}
	}
	return NULL;
}

void push(struct Node** head, int key){
	struct Node* new = malloc(sizeof(Node));
	if(new == NULL) exit(1);
	new->key = key;
	new->next = (*head);
	(*head) = new;
}

int pop(struct Node** head){
	struct Node* del = (*head);
	(*head) = (*head)->next;
	int result = del->key;
	free(del);
	return result;
}

void delete(struct Node* head, int key){
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
			return;
		}
	}
}

void popLastNode(struct Node* head){
	for(struct Node* current = head; current != NULL; current = current->next){
		if(current->next->next == NULL){
			free(current->next);
			current->next = NULL;
		}
	}
}

void insert(struct Node* head, int n, int key){
	int i = 0;
	struct Node* new = malloc(sizeof(struct Node));
	while(i < n && head->next){ //List.size() <= n
		head = head->next;
		i++;
	}
	new->key = key;
	if(head->next != NULL){
		new->next = head->next;
	}else{ //lastNode
		new->next = NULL;
	}
	head->next = new;
}

void deleteList(struct Node** head){
	while(*head){
		printf("deleted: %d\n", pop(head));
	}
}

void fromArray(struct Node** head, int* array, int size){
	if(array == NULL || size == 0) exit(1);
	for(int i = 0; i < size; i++){
		push(head, array[i]);
	}
}

void test(){
	struct Node* head = malloc(sizeof(struct Node));
	if(head == NULL) exit(1);
	init(head);
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	printList(head);
	struct Node* a;

	a = search(head, 3);
	if(a != NULL) printf("Search(3) : %d\n", a->key);

	printf("Delete(3)\n");
	delete(head, 3);

	printf("Pop: %d\n", pop(&head));

	printf("popLastNode()\n");
	popLastNode(head);

	printList(head);

	deleteList(&head);

	int arr[] = {5,6,7,8};
	fromArray(&head, arr, 4);

	insert(head, 2, 555);
	printList(head);


}

int main(){
	test();
	return 0;
}