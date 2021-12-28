//2. Write a C program to implement insertion and deletion operation in a dequeue (using function and switch case and represent queue using array)

// inserstion and deletion occurs at both ends in dequeue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int front =-1,rear=-1,max;
int dequeue[10];
bool isfull();
bool isempty();
void insertrear(); // insert from end
void insertfront(); //insert from front
void deleterear (); //delete from back
void deletefront(); //delete from front
void display();
void op();
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
	printf("\nDeQueue Implementation\n");
	printf("1.insertrear\n2.insertfront\n3.deleterear\n4.deletefront\n5.Display\n");
	printf("Enter Your Choice\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:insertrear();
		break;
		case 2: insertfront();
		break;
		case 3 : deleterear();
		break;
		case 4 : deletefront();
		break;
		case 5: display();
		break;
		default : printf("Invalid Option\n");

	}
}
bool isfull (){
	if((front==0&&rear==max-1)||(front==rear+1))
		return true;
	else
		return false;
}
bool isempty(){
	if(front==-1)
		return true;
	else
		return false;
}
void insertrear (){
	int num;
	if(isfull())
		printf("Queue Overflows\n");
	else{
		printf("Enter the number to insert at the end\n");
		scanf("%d",&num);
		if(isempty())
			front=0,rear=0;
		else if (rear==max-1)
			rear=0;
		else
			rear++;
		dequeue[rear]=num;
	}
	op();
}

void insertfront(){
	int num;
	if(isfull())
		printf("Queue Overflows\n");
	else{
		printf("Enter the number to insert at the front\n");
		scanf("%d",&num);
		if(front==0)
			front=max-1; //move Front to points last index of array
		else if (isempty())
			front=rear=0;
		else
			front--;
		dequeue[front]=num;
	}
	op();
}

void deleterear (){
	int ele;
	if(isempty()){
		printf("Queue UnderFlows\n");
		exit(0);
	}
	else {
		ele=dequeue[rear];
		if(front==rear){
			front=-1; rear = -1;
		}
		else if(rear==0)  //it's means we have to move rear to points last index
			rear=max-1; //[ now first inserted element at front end become rear end ]
		else
			rear--;
	}
	printf("Element deleted from rear is %d\n",ele );
	op();
}

void deletefront(){
	int ele;
	if(isempty()){
		printf("Queue UnderFlows\n");
		exit(0);
	}
	else {
		ele=dequeue[rear];
		if(front==rear)
			front=rear=-1;
		else if(front==max-1)
			front=0;
		else
			front++;
		printf("Element deleted from front is %d\n",ele );

	}
	op();
}

void display(){
	if (isempty()){
		printf("Queue UnderFlows\n");
		exit(0);
	}
	printf("The DeQueue Is\n");
	for (int i = 0; i < max; ++i)
		printf("|  %d  |", dequeue[i]);
	op();
}
