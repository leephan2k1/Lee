#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
void print(Node *Head){
	while(Head != NULL){
		printf("%d ", Head->data);
		Head = Head->next;
	}
}
void read(Node **head, int value){
	Node *p;
	Node *i = *head;
	p = (Node *)malloc(sizeof(Node));
	p->data = value;
	p->next = NULL;
	if(*head == NULL){
		*head = p;
		return;
	}
	while( i->next != NULL){
		i=i->next;
	}
	i->next = p;
	return;
}
int main(){
	Node *Head = NULL;
	int i, value;
	int n =3;
	for(i=0;i<n;i++){
		scanf("%d",&value);
		read(&Head, value);
	}
	print(&(*Head));
return 0;
}

