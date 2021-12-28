//13.Write a C Program containing a function which will merge two arrays of same size sorted in descending order.

#include <stdio.h>
#include <stdlib.h>

void mergetwoarray(int arr1[], int n1, int arr2[], int n2) {
    int arr[n1+n2];
    for(int i=0;i<n1;++i)
    {
        arr[i]=arr1[i];
    }
    for(int j=0;j<n2;++j)
    {
        arr[n1+j]=arr2[j];
    }
    //Sorting
    for(int i=0;i<n1+n2;++i)
    {
        for(int j=0;j<n1+n2-i-1;++j)
        {
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n1+n2;++i)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr1[]={2,5,6,9,10};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={69,12,45,145,65};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    mergetwoarray(arr1,n1,arr2,n2);
    return 0;
}