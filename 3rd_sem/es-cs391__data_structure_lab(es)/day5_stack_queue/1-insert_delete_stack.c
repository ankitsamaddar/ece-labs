//1. Write a C program to implement insertion and deletion operation in a stack (using function functions and switch case and represent stack using array)

#include <stdio.h>
#include <stdlib.h>
int arr[20] ,sp=-1,n;
void op();
void pop(){
	int v;
	if (sp==-1)
		printf("Stack Underflows\n");

	else {
		v=arr[sp];
		printf("Popped Out Element Is: %d\n",v );
		sp--;
	}
	op();
}
void push(int item){
	if(sp==n-1)
		printf("Stack Overflow\n");
	else {
		sp++;
		arr[sp]=item;
	}
	op();
}
void display(){
	if (sp==-1)
	{
		printf("Stack Is Empty\n");
	}
	else
	{
		printf("The Stack Is \n");
		for (int i = sp; i>=0; i--)
		{
			printf("%d\n",arr[i] );
		}
	}
	op();
}
void op(){
	int choice,item;
	if(n>20){
		printf("Beyond Limit\n");
		abort();
	}
	printf("Enter Your choice :\n1.To Pop\n2.To Push\n3.To Display The Stack\nEnter: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: pop();
		break;
		case 2: printf("Enter The Item To Push\n");
		scanf("%d",&item);
		push(item);
		break;
		case 3: display();
		break;
		default : break;
	}
}
int main(int argc, char const *argv[])
{
	printf("Enter the Size Of The Stack \n");
	scanf("%d",&n);
	op();
	return 0;
}