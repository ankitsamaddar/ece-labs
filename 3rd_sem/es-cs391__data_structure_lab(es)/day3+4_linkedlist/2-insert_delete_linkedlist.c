/* 2. Write a C Program containing functions which will perform the following operations in an existing link list:
A. Insert a new node at the beginning.
B. Insert a new node at the end.
C. Insert a new node after a given node with a specific value.
D. Insert a new node before a given node with a specific value.
E. Delete a node at the beginning.
F. Delete a node at the end.
G. Delete a node after a node with a specific value.
H. Delete a node before a node with a specific value.
I. Delete a node with a specific value. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}nd;
nd *head = NULL;

nd* createList(nd* head )
{
	nd* tail = NULL;
	for (int i = 1; i < 5; ++i)
	{
		nd *newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = i;
		newNode->next = NULL;
		if (newNode==NULL){
			return head;
			printf("Memory Is Full\n");
		}
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	return head;

}

void printList()
{
	nd* temp = head;
	printf("The Linked List Is\n");
	if(temp == NULL) {
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL){
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

nd* InsAtBeg (int data){
	nd *newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode==NULL){
		printf("Memory Is Full\n");
	}
	newNode->data=data;
	if(head==NULL){
		head=newNode;
	}
	else {
		newNode->next=head;
		head=newNode;
	}
	return head;
}
nd* insAtEnd (int data){
	nd *newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode==NULL){
		printf("Memory Is Full\n");
	}
	newNode->data=data;
	if(head==NULL){
		printf("The List Is Empty\n");
		head=newNode;
	}
	else {
	nd*temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->next=NULL;
}
	return head;
}
nd* insAtBfr (int data,int bfr){
	nd *newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode==NULL){
		printf("Memory Is Full\n");
	}
	newNode->data=data;
	nd* temp=head,*count;
	while(temp->next!=NULL){
		if(temp->data==bfr)
			break;
		count=temp;
		temp=temp->next;
	}
	newNode->next=count->next;
	count->next=newNode;
	return head;
}
void insAtAfr (int data,int aftr){
	nd *newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode==NULL){
		printf("Memory Is Full\n");
	}
	newNode->data=data;
	nd* temp=head;
	while(temp->next!=NULL){
		if(temp->data==aftr)
			break;
		temp=temp->next;
	}
	newNode->next=temp->next;
	temp->next=newNode;
}
int main(int argc, char const *argv[])
{
	head = createList(head);
	printList();
	head = InsAtBeg (21);
	printList();
	head=insAtEnd(34);
	printList();
	head=insAtBfr (69,3);
	printList();
	insAtAfr(47,2);
	printList();
	return 0;
}