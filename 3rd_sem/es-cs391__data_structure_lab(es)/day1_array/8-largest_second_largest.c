// 8. Write a program in C to find largest and second largest elements from an array of n numbers.
#include <stdio.h>
int main()
{
    int a[10],n;
    int l1,l2,i;
    printf("enter number of elements you want in array : ");
    scanf("%d",&n);
    printf("enter elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    l1=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>a[l1])
        {
            l1=i;
        }
    }
l2=0;
    for(i=0;i<n && i != l1 ;i++)
    {
        if(a[i]>a[l2])
            l2=i;
    }
    printf("First Largest Number is %d\nSecond Largest Number is %d ",a[l1],a[l2]);
}
