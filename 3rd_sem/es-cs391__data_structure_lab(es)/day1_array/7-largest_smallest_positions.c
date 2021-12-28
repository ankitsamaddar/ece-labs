// 7. Write a program in C to print largest and smallest elements and their corresponding positions from an array of n numbers.
#include<stdio.h>
int main()
{
int a[50],i,n,max,min;
printf("\nEnter the number of elements : ");
scanf("%d",&n);
printf("\nInput the array elements : ");
for(i=0;i<n;++i)
scanf("%d",&a[i]);
max = min=a[0];
for(i=1;i<n;++i)
{
if(a[i]>max)
max=a[i];
if(a[i]<min)
min=a[i];
}
printf("\nThe smallest element is %d\n",min);
printf("\nThe largest element is %d\n",max);
return 0;
}
