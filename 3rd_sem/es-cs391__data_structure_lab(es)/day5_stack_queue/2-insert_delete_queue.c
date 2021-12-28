//2.Write a C program to implement insertion and deletion operation  in a  queue (using function functions and switch case and represent queue using array )

#include <stdio.h>
#include <stdlib.h>
int arr[20] ,f=-1,r=-1,n;
void op();
void insert(int item){
	if(r==n-1)
		printf("Queue Overflows\n");
	else {
		if(f==-1&&r==-1){
			f=0;
			r=0;
		}
		else
			r=r+1;
		arr[r]=item;
	}
	op();
}
void delete (){
	if(f==-1&&r==-1)
		printf("Queue Underflows\n");
	else {
		int val = arr[r];
		if(f==r){ //base case
			f=-1;
			r=-1;
		}
		else
			f++;
		printf("Element Deleted:%d\n", val);
	}
	op();
}
void display(){
	if (f==-1&&r==-1)
	{
		printf("Queue Is Empty\n");
	}
	else
	{
		printf("The Queue Is \n");
		for (int i = f; i<=r; i++)
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
	printf("Enter Your choice :\n1.To Delete\n2.To Insert\n3.To Display The Queue\nEnter: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: delete();
		break;
		case 2: printf("Enter The Item To Push\n");
		scanf("%d",&item);
		insert(item);
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
