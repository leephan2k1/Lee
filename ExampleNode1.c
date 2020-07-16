#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

void printList(Node *L){
	while(L != NULL){
		printf("%d ", L->data);
		L = L->next; 
	}
}
int main(){
	Node *Head = NULL;
	Node *Second = NULL;
	Node *Third = NULL;
	// Khoi tao
	Head = (Node *)malloc(sizeof(Node));
	Second = (Node *)malloc(sizeof(Node));
	Third = (Node *)malloc(sizeof(Node));
	
	Head->data = 2; //Gan data cho node 1
	Head->next = Second; //Lien ket node dau voi node 2
	
	Second->data = 3; //Gan data cho node 2
	Second->next = Third; //Lien ket node 2 voi node 3
	
	Third->data = 4; //Gan data cho node 3
	Third->next = NULL; //Ket thuc list
	
	printList(Head);
return 0;
}

