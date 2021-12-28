//22.Write a C program to implement insertion and deletion operation in a stack (using   functions and switch case and represent stack using singular link list)
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int);
void pop();
void display();

int main()
{
    int choice, value;

    printf("\n:: Stack using Linked List ::\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
    return 0;
}
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
    printf("\nInsertion is Success!!!\n");
}
void pop()
{
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else
    {
        struct Node *temp = top;
        printf("\nDeleted element: %d\n", temp->data);
        top = temp->next;
        free(temp);
    }
}
void display()
{
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else
    {
        struct Node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n", temp->data);
    }
}
