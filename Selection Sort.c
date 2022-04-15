#include<stdio.h>

void selection_sort(int a[100],int n)
{
    int small,temp;
    for(int i=0;i<n;i++)
    {
        small=i;
        for(int j=i+1;j<n;j++)
        if(a[small]>a[j])
            small=j;
        temp=a[small];
        a[small]=a[i];
        a[i]=temp;
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
    selection_sort(a,n);
    printf("Array in sorted order is:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
