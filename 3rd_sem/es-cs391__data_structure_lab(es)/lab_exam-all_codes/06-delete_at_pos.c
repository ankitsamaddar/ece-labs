//6.Write a C Program containing a function which will delete an element at a Specified Position in a given Array.

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
void delete(){
    int  pos=0;
    printf("Enter the position you want to delete : \n");
    scanf("%d", &pos);
    if(pos>n || pos <0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        for(int i=pos-1;i<n;++i)
        {
            arr[i]=arr[i+1];
        }
        n--;
    }
}
void display(){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}