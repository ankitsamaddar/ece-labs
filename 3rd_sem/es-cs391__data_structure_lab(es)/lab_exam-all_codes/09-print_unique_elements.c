//9.Write a C Program containing a function which will print all unique elements in an array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[]={20,20,30,65,41};
int n = sizeof(arr)/sizeof(arr[0]);
void display();
void unique();
int main () {
	display();
	unique();
	return 0;
}
void unique()
{
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	max++;
    int freq[max];
    memset(freq,0,max*sizeof(int));//ref:https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm
    for(int i=0;i<n;++i)
    {
        freq[arr[i]]++;
    }
    printf("The Unique Elemets are\n");
    for(int i=0;i<max;++i)
    {
        if(freq[i]==1)
        {
            printf("%d ", i);
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