// Define array of 1000 size Display the sum and index 10 number having the maximum sum
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a[1000];
    int i=0,j=0;
    int max=0;
    int value=0;
    int max_index=0;
    srand(time(NULL));

    for(i=0;i<1000;i++)
    {
    a[i]= rand()%1000+1;
    }

    for(i=0;i<1000;i++)
    {
        printf("%d\n", a[i]);
    }
    for(i=1;i<990;i++)
    {
    for(j=0;j<10;j++)
    {
        value= value + a[j];
    }
    value = value - a[i-1];
    if(value>max)
    {
        max=value;
        max_index=i;
    }
    }
    printf("maximum sum of 10 consecutive number is %d\n", max);
    printf("Index of maximum number is %d\n" , max_index);
    return 0;
}

