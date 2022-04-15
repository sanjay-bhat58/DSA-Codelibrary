#include<stdio.h>
#include<stdlib.h>
void read(int a[100][100],int r,int c)
{
    printf("Enter the Matrix Elements:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        scanf("%d",&a[i][j]);
}
void display(int a[100][100],int r,int c)
{
    printf("The Entered Matrix elements are:\n");
    for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            printf("%d\t",a[i][j]);
            printf("\n");
        }
}
void calc(int a[100][100],int r,int c);
void main()
{
    int a[100][100],r,c;
    printf("Enter the No. of Rows and Columns of the Matrix:");
    scanf("%d%d",&r,&c);
    if(r!=c)
    {
        printf("Sorry!!! The entered No. of Rows and Columns doesn't constitute a Square Matrix!!!");
        exit(0);
    }
    read(a,r,c);
    display(a,r,c);
    calc(a,r,c);
}
void calc(int a[100][100],int r,int c)
{
    int maj[100],sm[100];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(i==j)
            maj[i]=a[i][j];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if((i+j)==r-1)
            sm[i]=a[i][j];
    printf("Squares of Major Axis are:\n");
    for(int i=0;i<r;i++)
        printf("%d\t",maj[i]*maj[i]);
    printf("\nSquares of Minor Axis are:\n");
    for(int i=0;i<r;i++)
        printf("%d\t",sm[i]*sm[i]);
}
