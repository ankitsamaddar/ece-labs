//1. Write a C Program containing functions which will create a singular linklist and display it.

#include <stdio.h>
#include <stdlib.h>

typedef struct node //typedef to give the struct type a new name
{
	int data;
	struct node* next; //self refferential struct (i.e. pointing to itself)
}nd; //name of the struct node

nd* createList(nd* head ) //funtion return type is node struct pointer(nd*) so we can return the head pointer
{
	nd*newNode,*tail=NULL; //
	int n;
	printf("Enter the number of nodes to enter : " );
	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
		newNode = (nd*)malloc(sizeof(nd)); //allocating memory space for the new node

		if (newNode==NULL){ //If System Memory Is Full i.e. no memory is allocated to newNode
			return head;
			printf("Memory Is Full\n");
		}

		printf("Enter the Node Data: ");
		scanf("%d",&newNode->data); // taking the new node input
		newNode->next=NULL;

		if (head==NULL) // if list is empty
		{
			head = newNode; //head is pointing to the new node
			tail = head; //tail is pointing to the head (i.e. current node)
		}
		else //to avoid edge cases
		{
			tail->next=newNode; //next pointing to next node address
			tail=newNode;//newNode is the new tail of the list
		}
	}
	return head;
}

void printList(nd* head)
{
	nd* current = head; //not needed as we are passing head value not address of head
	printf("The Linked List Is\n");
    if(current == NULL) {
        printf("List is empty\n");
        return;
    }
	while(current!=NULL){
		printf("%d  ",current->data);
		current=current->next; //pointing to the next node (i.e. increments the pointer)
	}
}

int main(int argc, char const *argv[])
{
	nd *head = NULL; //head is topmost or start of the list
	head = createList(head);
	printList(head);
	return 0;
}
