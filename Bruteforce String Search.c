#include<stdio.h>
#include<string.h>

void search(char input[200], char pattern[200])
{
    int n=strlen(input),m=strlen(pattern);
    for(int i=0;i<n-m;i++)
    {
        int j;
        for(j=0;j<m;j++)
            if(input[i+j] != pattern[j])
            break;
        if(j==m)
            printf("Pattern found between %d and %d characters of the input string",i+1,i+m);
    }
}

void main()
{
    char a[200],b[200];
    printf("Enter the input string:");
    gets(a);
    printf("Enter the pattern string to be searched:");
    gets(b);
    search(a,b);
}
