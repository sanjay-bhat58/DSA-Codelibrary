#include<stdio.h>
#include<stdlib.h>
void merging(int a[100],int i1,int j1,int i2,int j2)
{
    int temp[100],i=i1,j=i2,k=0;
    while(i<=j1 && j<=j2)
        if(a[i]<a[j])
        temp[k++]=a[i++];
        else
        temp[k++]=a[j++];
    while(i<=j1)
        temp[k++]=a[i++];
    while(j<=j2)
        temp[k++]=a[j++];
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}

void merge_sort(int a[100],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        merge_sort(a,i,mid);
        merge_sort(a,mid+1,j);
        merging(a,i,mid,mid+1,j);
    }
}
void main()
{
    int a[100],n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    merge_sort(a,0,n-1);
    printf("Sorted Array is:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
