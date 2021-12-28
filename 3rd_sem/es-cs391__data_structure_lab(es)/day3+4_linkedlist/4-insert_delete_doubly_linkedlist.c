/* 4. Write a C Program containing functions which will perform the following operations in an existing doubly link list:

J. Insert a new node at the beginning.
K. Insert a new node at the end.
L. Insert a new node after a given node with a specific value.
M. Insert a new node before a given node with a specific value.
N. Delete a node at the beginning.
O. Delete a node at the end.
P. Delete a node after a node with a specific value.
Q. Delete a node before a node with a specific value.
R. Delete a node with a specific value. */

#include <stdio.h>
#include <stdlib.h>
struct node
{ int data; struct node
*prev,*next;
};
struct node *head, *tail=NULL;
void insert_front(int val)
{
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=val; new_node->prev=NULL; new_node->next=NULL; if(head==NULL)
{
head=new_node;
tail=new_node;
}
else
{
new_node->next=head;
head=new_node;
}
}
void insert_at_back(int val)
{
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=val; new_node->prev=NULL; new_node->next=NULL;
if(tail==NULL)
{
head=new_node;
tail=new_node;
}
else
{
new_node->prev=tail; tail->next=new_node;
tail=new_node;
}
}
void insert_after_given_node(int val ,int val1)
{
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=val1; new_node->prev=NULL; new_node->next=NULL; if(head==NULL)
{
printf("The linked list is empty\n");
head=new_node; tail=new_node;
}
else
{
struct node *curr=head;
while(curr->data!=val)
{
curr=curr->next;
}
new_node->next=curr->next;
new_node->prev=curr; curr->next=new_node;
}
}
void insert_before_given_node(int val, int val1)
{
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=val1; new_node->prev=NULL; new_node->next=NULL; if(head==NULL)
{
printf("The list is empty\n");
head=new_node;
tail=new_node;
}
else
{
struct node *previous=NULL;
struct node *curr=head;
while(curr->data != val)
{
previous=curr; curr=curr->next;
}
new_node->next=previous->next; previous->next=new_node; new_node->prev=previous;
}
}
void delete_front()
{
if(head==NULL)
{
printf("The list is empty\n");
}
else
{
struct node *temp=head;
head=head->next; free(temp);
}
}
void delete_end()
{
if(head==NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr=head;
while(curr->next->next!=NULL)
{
curr=curr->next;
}
struct node *temp=curr->next;
curr->next=NULL; free(temp);
}
}
void delete_after_node(int val)
{
if(head==NULL)
{
printf("The list is empty");
}
else
{
struct node *curr=head;
while(curr->data != val)
{
curr=curr->next;
}
if(curr->next!=NULL)
{
struct node *temp=curr->next;
curr->next=temp->next; temp->next->prev=curr; free(temp);
}
}
}
void delete_node_before(int val)
{
if(head==NULL)
{
printf("The list is empty\n");
}
else if(head->next->data==val)
{
struct node *temp=head;
head=head->next; free(temp);
}
else
{
struct node *previous=NULL;
struct node *curr=head;
while(curr->next->data != val)
{
previous=curr; curr=curr->next;
}
struct node *temp=previous->next;
previous->next=temp->next; temp->next->prev=previous; free(temp);
}
}
void delete_specific(int val)
{
if(head==NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr=head;
struct node *previous=NULL;
while(curr->data != val)
{
previous=curr; curr=curr->next;
}
previous->next=curr->next; curr->next->prev=previous;
}
}
void display()
{
struct node *curr=head;
while(curr!=NULL)
{
printf("%d ", curr->data);
curr=curr->next;
}
}
int main()
{
insert_front(1);
insert_front(2); insert_front(3);
insert_front(4); insert_front(5);
//Insert at back
insert_at_back(10);
insert_at_back(11);
insert_at_back(12);
insert_at_back(13); //Insert after a given node
insert_after_given_node(11,14);
//Insert new node before a given node
insert_before_given_node(12,17); //Delete a node at the begening
delete_front();
//Delete node from end
delete_end();
//Delete a node after a node with specific value
delete_after_node(14); //Delete a specific node
delete_specific(10); //Delete the node before
delete_node_before(1); //Display the doublylinked list
display();
return 0;
}