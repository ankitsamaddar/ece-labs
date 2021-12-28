//12.Write a program in C to count total number of duplicate elements in an array and print them.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[]={10,20,30,65,41,10,41,65,30,10};
int n = sizeof(arr)/sizeof(arr[0]);
void display();
void Tdup();
int main (){
	display();
	Tdup();
}

void Tdup(){

	int max=0,ct=0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	max++;
    int freq[max];
    int rep[50];
    memset(freq,0,max*sizeof(int));
    for(int i=0;i<n;++i)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<max;++i)
    {
        if(freq[i]>=2)
        {
        	rep[ct]=i;
            ct++;
        }
    }
    printf("The number of repeated elemnts are %d and the elements are\t", ct);
    for (int i = 0; i <ct; ++i)
    {
    	printf("%d \t",rep[i]);
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