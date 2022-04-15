#include<stdio.h>
void bubble_sort(int a[100],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
        if(a[j]>a[j+1])
        {
            a[j]=a[j]+a[j+1];
            a[j+1]=a[j]-a[j+1];
            a[j]=a[j]-a[j+1];
        }
}

void main()
{
    int a[100],n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubble_sort(a,n);
    printf("Sorted elements are:\t");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
