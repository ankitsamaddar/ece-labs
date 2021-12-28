/* 3. Write a C Program containing functions which will perform the following operations in an existing circular link list:

A. Insert a new node at the beginning.
B. Insert a new node at the end.
C. Insert a new node after a given node with a specific value.
D. Insert a new node before a given node with a specific value.
E. Delete a node at the beginning.
F. Delete a node at the end.
G. Delete a node with a specific value.
H. Delete a node after a node with a specific value.
I. Delete a node before a node with a specific value. */

#include <stdio.h>
#include <stdlib.h>
struct node
{ int data; struct
node *next;
};
struct node *head, *tail = NULL;
void insert_front(int val)
{
struct node *new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = val; new_node->next = NULL; if (head == NULL)
{
head = new_node; new_node->next = head;
}
else
{
struct node *curr = head;
while (curr->next != head)
{
curr = curr->next;
}
new_node->next = head;
curr->next = new_node; head
= new_node;
}
}
void insert_at_end(int val)
{
struct node *new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = val; new_node->next = NULL;
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr = head;
while (curr->next != head)
{
curr = curr->next;
}
new_node->next = curr->next; curr->next = new_node;
}
}
void insert_after(int val, int val1)
{
struct node *new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = val1; new_node->next = NULL; if (head ==
NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr = head;
while (curr->data != val)
{
curr = curr->next;
}
new_node->next = curr->next; curr->next = new_node;
}
}
void insert_before(int val, int val1)
{
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
struct node *new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = val1; new_node->next = NULL; struct node
*curr = head; struct node *prev = NULL; while (curr->data != val)
{
prev = curr;
curr = curr->next;
}
new_node->next = prev->next;
prev->next = new_node;
}
}
void delete_front()
{
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr = head;
struct node *temp = head;
while (curr->next != head)
{
curr = curr->next;
}
curr->next = head->next;
head = head->next;
free(temp);
}
}
void delete_back()
{
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
struct node *prev = NULL;
struct node *curr = head; while
(curr->next != head)
{
prev = curr;
curr = curr->next;
}
struct node *temp = curr; prev->next = curr->next; free(temp);
}
}
void delete_specific(int val)
{
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr = head;
struct node *prev = NULL;
while (curr->data != val)
{
prev = curr;
curr = curr->next;
}
struct node *temp = curr; prev->next = curr->next; free(temp);
}
}
void delete_after(int val)
{
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr = head;
while (curr->data != val)
{
curr = curr->next;
}
if (curr->next != head)
{
struct node *temp = curr->next;
curr->next = temp->next; free(temp);
}
}
}
void delete_before(int val)
{
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
struct node *curr = head;
struct node *prev = NULL;
while (curr->next->data != val)
{
prev = curr;
curr = curr->next;
}
if (head->next->data == val)
{
struct node *temp = head;
head = head->next; free(temp);
}
else
{
struct node *temp = curr->next; prev->next = temp->next; free(temp);
};
}
}
void display()
{
struct node *curr = head;
if (head == NULL)
{
printf("The list is empty\n");
}
else
{
while (curr->next != head)
{
printf("%d ", curr->data);
curr = curr->next;
}
printf("%d ", curr->data);
}
}
int main()
{
insert_front(1);
insert_front(2); insert_front(3);
insert_front(4); insert_front(5);
// Insert a node at the end
insert_at_end(10);
insert_at_end(12);
insert_at_end(13);
insert_at_end(14);
insert_at_end(15); //Insert after a given node
insert_after(5, 50); // Insert a node before a node
insert_before(13, 65); // Delete an element from the front
delete_front(); // Delete an element from the back
delete_back(); // Delete the specific delete_specific(13); //Delete after a given node
delete_after(14); // Delete before a given node
delete_before(4); display();
return 0;
}