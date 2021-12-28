// 6. Write a program in C to calculate the sum and average of elements present in an array.
#include  <stdio.h>
int main ()
{
    int i, num;
    float sum = 0.0, avg;
    printf ("Enter the size of the array \n");
    scanf("%d", &num);
    int arr[num];
 
    printf("Enter %d numbers \n", num);
 
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    printf("Input array elements \n");
 
    for (i = 0; i < num; i++)
    {
        printf("%+d\n", arr[i]);
    }
 
    for (i = 0; i < num; i++)
    {
        sum+=arr[i];
    }
 
    avg = sum / num;
 
    printf("\n Sum of all numbers =  %.2f\n", sum);
 
    printf("\n Average of all input numbers =  %.2f\n", avg);
 
}