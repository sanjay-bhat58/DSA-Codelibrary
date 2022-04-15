#include<stdio.h>

void quick_sort(int a[100],int first,int last)
{
    int partindex;
    if(first<last)
    {
        partindex=partition(a,first,last);
        quick_sort(a,first,partindex-1);
        quick_sort(a,partindex+1,last);
    }
}

int partition(int a[100],int first,int last)
{
    int pivot=a[last],pindex=first,i,temp;
    for(i=first;i<last;i++)
        if(a[i]<pivot)
    {
        temp=a[i];
        a[i]=a[pindex];
        a[pindex]=temp;
        pindex++;
    }
    temp=pivot;
    a[last]=a[pindex];
    a[pindex]=temp;
    return pindex;
}
void main()
{
    int a[100],n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    printf("Array in sorted order is:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}

