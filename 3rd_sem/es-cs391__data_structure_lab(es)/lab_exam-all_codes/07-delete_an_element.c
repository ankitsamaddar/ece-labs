//7. Write a C Program containing a function which will delete a specific element from a given Array.
#include <stdio.h>
#include <stdlib.h>
int arr[]={10,20,30,65,41};
int n = sizeof(arr)/sizeof(arr[0]);
void display();
void delete();
int main () {
	display();
	delete();
	display();
	return 0;
}
void display(){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}
void delete(){
	int ele,pos=0;
	printf("Enter the element to delete \n");
	scanf("%d", &ele);
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]==ele){
			pos=i;
			break;
		}
	}
	if (pos==0){
		printf("Element Not Found:(\n");
		exit(0);
	}
	else {
		for (int i = pos ; i < n - 1; i++)
			arr[i] = arr[i+1];
		n--;
	}
}