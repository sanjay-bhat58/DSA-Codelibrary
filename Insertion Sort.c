#include<stdio.h>

void insertion_sort(int a[100],int n)
{
    int j,temp;
    for(int i=1;i<n;i++)
    {
        temp=a[i];
    j=i-1;
    while(j>=0 && a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
    }
}

void main()
{
    int a[100],n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertion_sort(a,n);
    printf("Array in sorted order is:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
