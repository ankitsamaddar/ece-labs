//10.Write a C Program containing a function which will print frequency of every element in an array.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[]={10,20,30,65,41};
int n = sizeof(arr)/sizeof(arr[0]);
void display();
void printU();
int main () {
	display();
	printU();
	return 0;
}
void printU(){
int max=0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	max++;
    int freq[max];
    memset(freq,0,max*sizeof(int));
    for(int i=0;i<n;++i)
    {
        freq[arr[i]]++;
    }
   printf("Number\tFrequency\n");
    for(int i=0;i<max;++i)
    {
        if(freq[i]==0)
        {
            continue;
        }
        else
        {
             printf("%d\t%d\n", i,freq[i]);
        }
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