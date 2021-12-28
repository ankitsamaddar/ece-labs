//1. Write a C program to implement insertion and deletion operation in a circular queue (using function functions and switch case and represent queue using array )

// insertion from rear and deletion from front in circular queue

#include <stdio.h>
#include <stdlib.h>
int front =-1,rear=-1,max;
int cqueue[10];
void insert();
void display();
void delete();
void op ();
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the size : ");
	scanf("%d",&n);
	if(n>10){
		printf("Size should be < 10\n");
		exit(0);
	}
	max=n;
	op();
	return 0;
}
void op (){
	int ch;
	printf("Circular Queue Implementation\n");
	printf("1.Insert\n2.Display\n3.Delete\n");
	printf("Enter Your Choice\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:insert();
		break;
		case 2: display();
		break;
		case 3 : delete();
		break;
		case 4 : exit(0);
		default : printf("Invalid Option\n");
	}

}
void insert(){
	int num;
	if((front==0&&rear==max-1)||(front==rear+1))
		printf("Queue Overflows\n");
	else{
		printf("Enter the number to insert\n");
		scanf("%d",&num);
		if(front==-1&&rear==-1)
			front=0,rear=0;
		else if (rear==max-1)
			rear=0;
		else
			rear ++;
		cqueue[rear]=num;
	}
	op();
}

void delete (){
	int ele;
	if(front==-1){
		printf("Queue UnderFlows\n");
		exit(0);
	}
	else {
		ele=cqueue[front];
		if(front==rear){
			front=-1; rear = -1;
		}
		else if(front==max-1)
			front=0;
		else
			front++;
	}
	printf("Element deleted is %d\n",ele );
	op();
}

void display (){
	int i;
	if (front==-1&&rear==-1){
		printf("Queue UnderFlows\n");
		exit(0);
	}
	else {
		printf("The Circular Queue Is\n");
/*	if(front>rear){
		for(i=front;i<max-1;i++)
			printf("%d\t",cqueue[i] );
		for (int i = 0; i <=rear; ++i)
			printf("%d\t",cqueue[i] );
	}
	else{
		for (int i = front; i <=rear; ++i)
			printf("%d\t",cqueue[i] );
	}

*/
for (i = front; i != rear; i = (i + 1) % max) { //when i+1 is max, i will reset to 0
	printf("%d ", cqueue[i]);
}
    printf("%d ", cqueue[i]); // when i is rear

    printf("\n");
}

op();
}
